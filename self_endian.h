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
#include <machine/endian.h>
#define be32toh(x) ntohl(x)
#define htobe32(x) htonl(x)

#endif
