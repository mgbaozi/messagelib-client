//
//  KyoumeClient.cc
//  kyoume
//
//  Created by 吴昊 on 14-3-14.
//  Copyright (c) 2014年 penta. All rights reserved.
//


#include "KyoumeClient.h"
#include "message.h"
#include "connection.h"
#include "router.h"
#include "packet/login.pb.h"
#include "packet/chat.pb.h"

//struct UserCallbacks
//{
//    ::ConnectionCallback conn_cb;
//    ::RegCallback reg_cb;
//    ::SignInCallback sing_in_cb;
//    ::ChatCallback chat_cb;
//    ::MessageCallback msg_cb;
//};
using namespace std::placeholders;
extern void (*log_method_)(const char *);
KyoumeClient::KyoumeClient(UserCallbacks *callbacks)
:server_address_("127.0.0.1"),port_(24842),
router_(new ProtoRouter),
callbacks_(callbacks)
{
    
}

KyoumeClient::KyoumeClient(UserCallbacks *callbacks, StringPiece server_address, int port)
:server_address_(server_address.data()),port_(port),
router_(new ProtoRouter),
callbacks_(callbacks)
{
    
}

KyoumeClient::~KyoumeClient()
{
    
}

void KyoumeClient::init()
{
    conn_ = ConnectionPtr(new TCPConnection(server_address_.data(), port_));
    conn_ -> set_close_callback(std::bind(&KyoumeClient::on_close, this, _1));
    conn_ -> set_connection_callback(std::bind(&KyoumeClient::on_connection, this, _1));
    conn_ -> set_message_callback(std::bind(&KyoumeClient::on_message, this, _1, _2));
    conn_ -> set_error_callback(std::bind(&KyoumeClient::on_error, this, _1));
    router_ -> register_message_callback<login::Response>(std::bind(&KyoumeClient::onResponse, this, conn_, _1));
    router_ -> register_message_callback<login::Result>(std::bind(&KyoumeClient::onResult, this, conn_, _1));
    router_ -> register_message_callback<chat::Receive>(std::bind(&KyoumeClient::onReceive, this, conn_, _1));
	router_ -> register_message_callback<chat::Response>(std::bind(&KyoumeClient::messageResponse, this, conn_, _1));
}

int KyoumeClient::start()
{
    init();
    if (!conn_ -> start())
    {
        return -1;
    }
//    if (conn_ -> has_error())
//    {
//        callbacks_ -> error_cb();
//        return -1;
//    }
    return 0;
}

int KyoumeClient::stop()
{
    conn_ -> close();
    return !conn_ -> is_closed();
}

int KyoumeClient::restart()
{
    stop();
    return start();
}

void KyoumeClient::on_connection(const ConnectionPtr& conn)
{
    assert(conn == conn_);
    callbacks_ -> conn_cb();
}
void KyoumeClient::on_close(const ConnectionPtr& conn)
{
    assert(conn == conn_);
    if(conn -> has_error())
    {
        //do something when got an error
    }
}

void KyoumeClient::on_message(const ConnectionPtr& conn, const std::string& packet)
{
    assert(conn == conn_);
    router_ -> on_message(packet);
}

void KyoumeClient::on_error(const ConnectionPtr& conn)
{
    assert(conn == conn_);
    callbacks_ -> error_cb();
}
void KyoumeClient::onResponse(const ConnectionPtr& conn, const MessagePtr& message)
{
    auto response = std::static_pointer_cast<login::Response>(message);
    struct reg_response rep = {reg_response::UNKNOWN_DEVICE};
    std::string user_id, user_token;
    if(response -> err() == login::Response_Error_SUCCESS)
    {
        rep.err = reg_response::SUCCESS;
        user_id = response -> user_id();
        user_token = response -> user_token();
        rep.user_id = user_id.data();
        rep.user_token = user_token.data();
    }
    callbacks_ -> reg_cb(rep);
}
void KyoumeClient::onResult(const ConnectionPtr& conn, const MessagePtr& message)
{
    auto result = std::static_pointer_cast<login::Result>(message);
    struct sign_in_response rep = {sign_in_response::TOKEN_NOT_AVAILABLE};
    std::string online_token;
    if(result -> err() == login::Result_Error_SUCCESS)
    {
        rep.err = sign_in_response::SUCCESS;
        online_token = result -> login_token();
        rep.online_token = online_token.data();
    }
    callbacks_ -> sing_in_cb(rep);
}
void KyoumeClient::onReceive(const ConnectionPtr& conn, const MessagePtr& message)
{
    auto receive = std::static_pointer_cast<chat::Receive>(message);
    struct chat_packet packet;
    packet.other_id = receive -> from_user().data();
    packet.message = receive -> content().data();
    packet.message_id = receive -> message_id();
    callbacks_ -> msg_cb(packet);
}

void KyoumeClient::messageResponse(const ConnectionPtr& conn, const MessagePtr& message)
{
    auto response = std::static_pointer_cast<chat::Response>(message);
    struct chat_response packet = {chat_response::UNKNOWN_ERROR};
    if(response -> err() == chat::Response_Error_SUCCESS)
    {
        packet.err = chat_response::SUCCESS;
        packet.message_id = response -> message_id();
    }
    else if(response -> err() == chat::Response_Error_OTHER_OFFLINE)
    {
        packet.err = chat_response::OTHER_SIDE_OFFLINE;
    }
    else if(response ->err() == chat::Response_Error_WAIT_FOR_OTHER_REPLY)
    {
        packet.err = chat_response::WAIT_FOR_OTHER_REPLY;
    }
    callbacks_ -> chat_cb(packet);
}

int KyoumeClient::send_message(struct chat_packet& packet)
{
    std::shared_ptr<chat::Send> send(new chat::Send);
    send -> set_message_id(packet.message_id);
    send -> set_to_user(packet.other_id);
    send -> set_content(packet.message);
    conn_ -> send(router_ -> make_packet(send));
    return 0;
}

int KyoumeClient::sign_in(struct sign_in_packet& packet)
{
    std::shared_ptr<login::Login> message(new login::Login);
    message -> set_user_id(packet.user_id);
    message -> set_user_token(packet.user_token);
    conn_ -> send(router_ -> make_packet(message));
    return 0;
}
int KyoumeClient::device_register(struct reg_packet& packet)
{
    std::shared_ptr<login::Register> message(new login::Register);
    message -> set_device_type(packet.type);
    message -> set_device_token(packet.token);
    message -> set_device_uuid(packet.uuid);
    message -> set_system_version(packet.sys_version);
    message -> set_software_version(packet.soft_version);
	message -> set_secret_key("test_secret_key");
    conn_ -> send(router_ -> make_packet(message));
    return 0;
}
