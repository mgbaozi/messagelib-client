//
//  connection.cc
//  kyoume
//
//  Created by 吴昊 on 14-3-14.
//  Copyright (c) 2014年 penta. All rights reserved.
//

#include "connection.h"
#include <arpa/inet.h>
#include <event2/buffer.h>
#include <event2/util.h>
#include <assert.h>
#include <vector>
#include "self_endian.h"
struct conn_ctx
{
    ConnectionPtr conn;
};
const size_t k_buffer_length = 1024;
const size_t k_header_length = sizeof(uint32_t);

extern void (*log_method_)(const char *);
//static struct bufferevent *connection_bev;
static void read_callback(struct bufferevent *bev, void *ctx)
{
    //struct evbuffer *input = bufferevent_get_input(bev);
    //size_t length = evbuffer_get_length(input);
    struct conn_ctx *context = (struct conn_ctx*)ctx;
    ConnectionPtr conn = context -> conn;
    //assert(bev == connection_bev);
    conn -> on_message(bev);
}
static void event_callback(struct bufferevent *bev, short events, void *ctx)
{
    struct conn_ctx *context = (struct conn_ctx*)ctx;
    ConnectionPtr conn = context -> conn;
    if(events & BEV_EVENT_CONNECTED)
    {
        conn -> on_connect(bev);
        //on_connect
    }
    else if(events & BEV_EVENT_EOF)
    {
        if(!conn -> is_closed())
        {
            conn -> close();
        }
    }
    else if(events & BEV_EVENT_ERROR )
    {
        conn -> on_error(bev);
    }
}
TCPConnection::TCPConnection(const char *server_address, int port)
:state_(K_NOT_STARTED)
{
    memset(&sin_, 0, sizeof(sin_));
    sin_.sin_family = AF_INET;
    sin_.sin_addr.s_addr = inet_addr(server_address); /* 127.0.0.1 */
    sin_.sin_port = htons(port); /* Port 24842 */
}


TCPConnection::~TCPConnection()
{
    if(state_ != K_FAILED)
    {
        bufferevent_free(bufev_);
    }
}

bool TCPConnection::start()
{
    if(state_ != K_NOT_STARTED)
        return false;
    this -> ctx_ = new struct conn_ctx;
    ctx_ -> conn = shared_from_this();
    state_ = K_STARTING;
    base_ = event_base_new();
    bufev_ = bufferevent_socket_new(base_, -1, BEV_OPT_CLOSE_ON_FREE);
    //connection_bev = bufev_;
    bufferevent_setcb(bufev_, read_callback, NULL, event_callback, ctx_);
    bufferevent_enable(bufev_, EV_READ|EV_WRITE);
    if (bufferevent_socket_connect(bufev_,(struct sockaddr *)&sin_, sizeof(sin_)) < 0)
    { /* Error starting connection */
        bufferevent_free(bufev_);
        state_ = K_FAILED;
        return false;
    }
    state_ = K_CONNECTED;
    return !event_base_dispatch(base_);
    //return true;
}

void TCPConnection::send(const std::string &data)
{
    size_t length = data.size();
    length = htobe32(length);
    bufferevent_write(bufev_, &length, sizeof(int32_t));
    bufferevent_write(bufev_, data.data(), data.size());
}

void TCPConnection::on_connect(struct bufferevent *bev)
{
    assert(bev == this -> bufev_);
    connection_callback_(shared_from_this());
}

void TCPConnection::on_message(struct bufferevent *bev)
{
    assert(bev == this -> bufev_);
    struct evbuffer *input = bufferevent_get_input(bev);
    size_t length = 0;
    while((length=evbuffer_get_length(input)) > k_header_length)
    {
        uint32_t packet_len = 0;
        evbuffer_copyout(input, &packet_len, k_header_length);
        packet_len = be32toh(packet_len);
		log_method_("get message");
        if(length < k_header_length + packet_len)
        {
            break;
        }
        evbuffer_drain(input, k_header_length);
        std::vector<char> packet_buf(packet_len);
        evbuffer_remove(input, &packet_buf[0], packet_len);
        std::string packet(packet_buf.begin(), packet_buf.begin() + packet_len);
        message_callback_(shared_from_this(), packet);
    }
}
void TCPConnection::on_error(struct bufferevent *bev)
{
    assert(bev == this -> bufev_);
    state_ = K_FAILED;
    error_callback_(shared_from_this());
    close();
}

void TCPConnection::close()
{
    close_callback_(shared_from_this());
    if(state_ != K_FAILED)
    {
        state_ = K_CLOSED;
    }
    delete ctx_;
    event_base_loopbreak(base_);
}
