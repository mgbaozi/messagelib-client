//
//  router.h
//  kyoume
//
//  Created by 吴昊 on 14-3-14.
//  Copyright (c) 2014年 penta. All rights reserved.
//

#ifndef kyoume_router_h
#define kyoume_router_h

#include <map>
#include <functional>
#include <memory>
#include <google/protobuf/message.h>
#include <string>
typedef std::shared_ptr<google::protobuf::Message> MessagePtr;

class ProtobufCodec;
class TCPConnection;

typedef std::shared_ptr<TCPConnection> ConnectionPtr;
typedef std::function<void (MessagePtr& message)> ProtoCallback;

class ProtoRouter
{
public:
    ProtoRouter();
    ~ProtoRouter();
    //MessagePtr get_message(const std::string& data) const;
    void on_message(const std::string& data) const;
    std::string make_packet(MessagePtr message) const;
    template<typename U>
    void register_message_callback(const ProtoCallback& callback)
    {
        function_map_[U::descriptor()] = callback;
    }
private:
    std::map<const google::protobuf::Descriptor *, ProtoCallback> function_map_;

};

#endif
