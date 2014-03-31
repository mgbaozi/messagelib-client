//
//  codec.cc
//  kyoume
//
//  Created by 吴昊 on 14-3-14.
//  Copyright (c) 2014年 penta. All rights reserved.
//

#include "codec.h"
#include "self_endian.h"
#include <vector>
#include <google/protobuf/descriptor.h>
const int ProtobufCodec::k_header_len = sizeof(int);
MessagePtr ProtobufCodec::parse(const std::string& data)
{
    const char *buffer = data.data();
    int32_t name_len = be32toh(*reinterpret_cast<int32_t*>(const_cast<char *>(buffer)));
    std::string name(buffer + k_header_len, name_len);
    size_t header_length = sizeof(name_len) + name_len;
    auto message = create_message(name);
    message -> ParseFromArray(data.data() + header_length, data.size() - header_length);
    return MessagePtr(message);
}

std::string ProtobufCodec::package(MessagePtr& message)
{
    const std::string& name = message -> GetTypeName();
    int32_t name_len = name.size() + 1;
    int32_t message_len = message -> ByteSize();
    std::vector<char> buffer(k_header_len + name_len + message_len);
    int32_t be_name_len = htobe32(name_len);
    char *buff = buffer.data();
    memcpy(buff, &be_name_len, k_header_len);
    buff += k_header_len;
    memcpy(buff, name.data(), name_len);
	buff[name_len-1] = '\0';
    buff += name_len;
    message -> SerializeToArray(buff, message_len);
    
    size_t packet_length = k_header_len + name_len + message_len;
    return std::string(buffer.begin(), buffer.begin() + packet_length);
}

google::protobuf::Message* ProtobufCodec::create_message(const std::string& name)
{
    google::protobuf::Message* message = NULL;
    const google::protobuf::Descriptor* descriptor = google::protobuf::DescriptorPool::generated_pool()->FindMessageTypeByName(name);
    if (descriptor)
    {
        const google::protobuf::Message* prototype =
        google::protobuf::MessageFactory::generated_factory()->GetPrototype(descriptor);
        if (prototype)
        {
            message = prototype->New();
        }
    }
    return message;
}
