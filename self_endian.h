//
//  self_endian.h
//  kyoume
//
//  Created by 吴昊 on 14-3-25.
//  Copyright (c) 2014年 penta. All rights reserved.
//

#ifndef kyoume_self_endian_h
#define kyoume_self_endian_h

#include <string.h>
#ifdef __APPLE__
#include <Endian.h>
inline uint32_t be32toh(uint32_t x)
{
    return EndianS32_BtoN(x);
}
inline uint32_t htobe32(uint32_t x)
{
    return EndianS32_NtoB(x);
}
#else
#include <endian.h>
#endif

#endif
