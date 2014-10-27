//
//  BGRAVideoFrame.h
//  5
//
//  Created by LTT on 10/20/14.
//  Copyright (c) 2014 PDL. All rights reserved.
//

#ifndef __BGRAVideoFrame_h
#define __BGRAVideoFrame_h

#include <cstddef>
struct BGRAVideoFrame{
    size_t width;
    size_t height;
    size_t stride;
    
    unsigned char *data;
};

#endif
