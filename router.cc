//
//  router.cc
//  kyoume
//
//  Created by 吴昊 on 14-3-14.
//  Copyright (c) 2014年 penta. All rights reserved.
//

#include "router.h"
#include "codec.h"
ProtoRouter::ProtoRouter()
{
    
}

ProtoRouter::~ProtoRouter()
{
    
}

void ProtoRouter::on_message(const std::string& data) const
{
    MessagePtr message = ProtobufCodec::parse(data);
    auto iter = function_map_.find(message -> GetDescriptor());
    if(iter != function_map_.end())
    {
        iter->second(message);
    }
}

std::string ProtoRouter::make_packet(MessagePtr message) const
{
    return ProtobufCodec::package(message);
}