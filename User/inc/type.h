#ifndef __HEADER_H
#define __HEADER_H

#include "stm32f10x.h"

typedef enum{FALSE, TRUE}BOOL;

typedef union
{
    u32 Long;
    u16 IntArray[2];
    u16 Int;
    u8  CharArray[4];
    struct 
    {
        u16 IntL;
        u16 IntH;
    }sInt;
    struct 
    {
        u8 CharL;
        u8 CharH;
    }sChar;
}U32_U16_U8;

#endif /* __HEADER_H */
