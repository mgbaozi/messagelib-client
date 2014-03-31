//
//  KyoumeClient.h
//  kyoume
//
//  Created by 吴昊 on 14-3-14.
//  Copyright (c) 2014年 penta. All rights reserved.
//

#ifndef KYOUME_CLIENT_H
#define KYOUME_CLIENT_H

#include "stringpiece.h"
#include <memory>
//#include <map>
#include <event2/event.h>
#include <event2/bufferevent.h>
#include <string>
#include "router.h"
class TCPConnection;
class ProtoRouter;
struct UserCallbacks;
struct chat_packet;
typedef std::shared_ptr<TCPConnection> ConnectionPtr;
class KyoumeClient
{
public:

    KyoumeClient(UserCallbacks *callbacks);
    KyoumeClient(UserCallbacks *callbacks, StringPiece server_address, int port);
    ~KyoumeClient();
    int start();
    int restart();
    int stop();
    int send_message(struct chat_packet& packet);
    int sign_in(struct sign_in_packet& packet);
    int device_register(struct reg_packet& packet);
private:
    ConnectionPtr conn_;
    std::shared_ptr<ProtoRouter> router_;
    std::unique_ptr<UserCallbacks> callbacks_;
    void on_connection(const ConnectionPtr& conn);
    void on_close(const ConnectionPtr& conn);
    void on_message(const ConnectionPtr& conn, const std::string& packet);
    void on_error(const ConnectionPtr& conn);
    void init();
    std::string server_address_;
    int port_;
    void onResponse(const ConnectionPtr& conn, const MessagePtr& message);
    void onResult(const ConnectionPtr& conn, const MessagePtr& message);
    void onReceive(const ConnectionPtr& conn, const MessagePtr& message);
    void messageResponse(const ConnectionPtr& conn, const MessagePtr& message);
};

#endif
