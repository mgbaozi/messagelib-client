//
//  connection.h
//  kyoume
//
//  Created by 吴昊 on 14-3-14.
//  Copyright (c) 2014年 penta. All rights reserved.
//

#ifndef kyoume_connection_h
#define kyoume_connection_h
#include <string>
#include <memory>
#include <functional>
#include <event2/event.h>
#include <event2/bufferevent.h>
#include <vector>
class TCPConnection;
typedef std::shared_ptr<TCPConnection> ConnectionPtr;

class TCPConnection : public std::enable_shared_from_this<TCPConnection>
{
public:
    typedef std::function<void (const ConnectionPtr&, const std::string&)> MessageCallback;
    typedef std::function<void (const ConnectionPtr&)> ConnectionCallback;
    typedef std::function<void (const ConnectionPtr&)> CloseCallback;
    typedef std::function<void (const ConnectionPtr&)> ErrorCallback;
    TCPConnection(const char *server_address, int port);
    ~TCPConnection();
    inline void set_connection_callback(ConnectionCallback callback)
    {
        connection_callback_ = callback;
    }
    inline void set_message_callback(MessageCallback callback)
    {
        message_callback_ = callback;
    }
    inline void set_close_callback(CloseCallback callback)
    {
        close_callback_ = callback;
    }
    inline void set_error_callback(ErrorCallback callback)
    {
        error_callback_ = callback;
    }
    bool start();
    inline void set_context(void *context)
    {
        context_ = context;
    }
    inline void* get_context()
    {
        return context_;
    }
    void send(const std::string& data);
    void close();
    bool is_started() const
    {
        return state_ != K_NOT_STARTED;
    }
    bool is_closed() const
    {
        return state_ == K_CLOSED;
    }
    bool has_error() const
    {
        return state_ == K_FAILED;
    }
private:
    struct event_base *base_;
    struct sockaddr_in sin_;
    struct bufferevent *bufev_;
    struct conn_ctx *ctx_;
    MessageCallback message_callback_;
    ConnectionCallback connection_callback_;
    CloseCallback close_callback_;
    ErrorCallback error_callback_;
    enum State
    {
        K_NOT_STARTED = 0,
        K_STARTING,
        K_CONNECTED,
        K_FAILED,
        K_CLOSED
    } state_;
    void *context_;
public:
    //void on_close(struct bufferevent *bev);
    void on_connect(struct bufferevent *bev);
    void on_message(struct bufferevent *bev);
    void on_error(struct bufferevent *bev);
};


#endif
