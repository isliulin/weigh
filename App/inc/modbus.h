/**
  ******************************************************************************
  * @文件    modbus.h
  * @作者    zhaoxw
  * @版本    V0.0.0
  * @日期    2017-09-17
  * @概述    Main program body
  ******************************************************************************
  * @attention
  *
  * 
  *
  ******************************************************************************
  */ 
#ifndef __MODBUS_H
#define __MODBUS_H

#include "bsp.h"
#include "type.h"
#include "weigh.h"

#define MB_ADDR		    1
#define MB_TIMEOUT      2500                //5S

typedef enum {R_CRC,R_FUC,R_RESPOND,R_END}MBFSM;//modbus运行状态机

typedef struct
{
    u8 MbStart:1;       //开始接收
    u8 MbInData:1;      //输入数据是否有变
    u8 MbRicved:1;      //成功接收
    u8 MbOnline:1;      //Modbus在线
    u8 MbSend:1;        //响应
    u8 MbErr:3;         //错误码
    
    u8 MbCtrMode:8;     //只有一种控制信号发生作用
}MB_STATUS;

typedef struct
{
    u8 Addr;
    u8 FucCode;
    u8 LocaHi;
    u8 LocaLo;
    u8 NumHi;
    u8 NumLo;
    u8 CrcLo;
    u8 CrcHi;
}MB_strRICV;

typedef struct
{
    u8 Addr;
    u8 FucCode;
    u8 LocaHi;
    u8 LocaLo;
    u8 NumHi;
    u8 NumLo;
    u8 Cnt;
    u8 Data[93];
//    u8 CrcLo;
//    u8 CrcHi;
}MB_strRICV16;

typedef struct
{
    u16 F0316Sensor[8];      //传感器1 AD 值   
    WEIGH F0316Weigh[8];      //传感器1 AD 值
    u16 F0316SetSensorAD[8];      //传感器1 AD 值   
}MB_F0316;

typedef union
{
    MB_strRICV   MbstrRicv;
    MB_strRICV16 MbstrRicv16;
    u8 DataRicv[100];
}MB_unRICV;

typedef union
{
    u16 Mb_F0316Data16[32];
    u8 Mb_F0316Data8[64];
    MB_F0316 sMb_F0316;
}UMB_F0316;

//typedef struct
//{
//    u8 Addr;
//    u8 FucCode;
//    u8 Num;
//    u8 Data[45];
//    u8 CrcLo;
//    u8 CrcHi;
//}MB_strSEND01020304;

//typedef struct
//{
//    u8 Addr;
//    u8 FucCode;
//    u8 LocaHi;
//    u8 LocaLo;
//    u8 NumHi;
//    u8 NumLo;
//    u8 Data[42];
//    u8 CrcLo;
//    u8 CrcHi;
//}MB_strSEND16;//0x10

extern u8 MbAddr;
extern MB_STATUS MbStatus;
extern MB_unRICV MbRicv;

extern void ModBusRun(void);
#endif /* __MODBUS_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
