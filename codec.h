//
//  codec.h
//  kyoume
//
//  Created by 吴昊 on 14-3-14.
//  Copyright (c) 2014年 penta. All rights reserved.
//

#ifndef kyoume_codec_h
#define kyoume_codec_h
#include <string>
#include <memory>
#include <google/protobuf/message.h>

typedef std::shared_ptr<google::protobuf::Message> MessagePtr;

class ProtobufCodec
{
public:
    static MessagePtr parse(const std::string& data);
    static std::string package(MessagePtr& message);
private:
    static const int k_header_len;
    static google::protobuf::Message* create_message(const std::string& name);
};

#endif
