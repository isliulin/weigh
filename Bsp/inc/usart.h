#ifndef __USART_H
#define __USART_H

#include "main.h"

#define RS485_TX_EN		GPIOA8_OUT			//485模式控制.0,接收;1,发送.


typedef struct
{
    u8 MbMotoBlock:1;       
    u8 MbPhaseLost:1;     
    u8 MbErrOts:1;     
    u8 MbErrCts:1;      
    u8 MbErrFw:1;      
    u8 MbAuxSwErr:1;    
    
    u8 :2;
    
}MB_STATUS_ERR;

typedef union
{
    u8 ErrData;
    MB_STATUS_ERR Mb_Status_Err;
}UMB_STATUS_ERR;


typedef struct
{
    u8 F0105RStop:1;
    u8 F0105RClose:1;
    u8 F0105ROpen:1;
    u8 F0105REsd:1;
    
    u8 F0105Nc:4;
}MB_F0105;

typedef union
{
    u8 Mb_F0105Data;
    MB_F0105 sMb_F0105;
}UMB_F0105;


typedef struct
{
    u8 F02Moving:1;
    u8 F02CloseLimit:1;
    u8 F02OpenLimit:1;
    u8 F02MotoHeat:1;
    u8 F02RelayAL:1;
    u8 F02ModeLocal:1;
    u8 F02ModeRemote:1;
    u8 F02Nc0:1;
    
    u8 F02MotoClose:1;      
    u8 F02MotoOpen:1;
    u8 F02Timer:1;          //中断定时器
    u8 F02FwAdjust:1;       //正在执行位置调节命令
    u8 F02Nc1:2;            //保留
    u8 F02FwAdjEn:1;        //位置调节命令有效
    u8 F02MbErr:1;          //内部数据通讯错误
    
    u8 F02S1:1;
    u8 F02S2:1;
    u8 F02S3:1;
    u8 F02S4:1;
    u8 F02AuxIn3:1;         //辅助输入3 远程点动保持
    u8 F02AuxIn2:1;         //辅助输入2 远程关闭
    u8 F02AuxIn1:1;         //辅助输入1 远程打开
    u8 F02AuxIn4:1;         //辅助输入4 远程ESD
}MB_F02;

typedef union
{
    u32 _Mb_F02Data;
    u8 Mb_F02Data[3];
    MB_F02 sMb_F02;
}UMB_F02;


typedef struct
{
    u16 F030616VaCtrR;      //执行器控制寄存器
    u16 F030616FwCtrR;      //阀位控制寄存器
    u16 F030616Dead;        //死区
    u16 F030616Nc;          //保留
    u16 F030616LowFw;       //低信阀位
    u16 F030616HigFw;       //高信阀位    
}MB_F030616;

typedef union
{
    u16 Mb_F030616Data[6];
    MB_F030616 sMb_F030616;
}UMB_F030616;


typedef struct
{
    u16 F04Nc;
    u16 F04FwFb;            //执行器阀位反馈
    u16 F04AdjFwFb;         //执行器调节阀位反馈
}MB_F04;

typedef union
{
    u16 Mb_F04Data[3];
    MB_F04 sMb_F04;
}UMB_F04;


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

typedef union
{
    MB_strRICV  MbstrRicv;
    u8 DataRicv[8];
}MB_unRICV;

typedef struct
{
    u8 Addr;
    u8 FucCode;
    u8 LocaHi;
    u8 LocaLo;
    u8 NumHi;
    u8 NumLo;
    u8 Cnt;
    u8 Data[14];
    //u8 CrcLo;
    //u8 CrcHi;
}MB_strRICV16;

typedef union
{
    MB_strRICV16  MbstrRicv16;
    u8 DataRicv16[21];
}MB_unRICV16;


typedef struct
{
    u8 Addr;
    u8 FucCode;
    u8 Num;
    u8 Data[12];
    u8 CrcLo;
    u8 CrcHi;
}MB_strSEND01020304;

typedef struct
{
    u8 Addr;
    u8 FucCode;
    u8 LocaHi;
    u8 LocaLo;
    u8 DataHi;
    u8 DataLo;
    u8 CrcLo;
    u8 CrcHi;
}MB_strSEND0506;

typedef struct
{
    u8 Addr;
    u8 FucCode;
    u8 LocaHi;
    u8 LocaLo;
    u8 NumHi;
    u8 NumLo;
    u8 Data[12];
    u8 CrcLo;
    u8 CrcHi;
}MB_strSEND16;//0x10

typedef union
{
    u16 Word;
    struct
    {
        u8 ByteL;
        u8 ByteH;
    }Byte;
}WB;//字与字节
typedef union
{
    u32 Long;
    u8 LongData[4];
}WL;//字与字节

typedef struct
{
    u16 MbSwitch;          //开关量
    u16 MbVavlePer;        //阀位百分比
    u16 MbCloseDir;        //关方向
    u16 MbCloseMode;       //关模式
    u16 MbEsdMode;         //ESD动作
    u16 MbLow;             //丢信动作
    u16 MbRemotMode;       //远程模式 模拟量或开关量
    u16 MbRelay[9];        //继电器组态信息
    u16 MbCPUTemp;         //CPU温度
    u16 MbVmaPer;          //模拟量百分比
    u16 MbSN;              //序列号
    u16 MbTime;           //生产日期
    u16 MbVer;             //版本
    u16 MbAl;             //错误报警
}SMBDATA;                  //Modbus写入参数缓冲区

typedef union
{
    u16 MbDataArray[22];
    SMBDATA sMbData;
}UMBDATA;                  //Modbus写入参数缓冲区

//extern UMBDATA RMbData, WMbData;
//extern MB_STATUS MbStatus;
//extern u32 T3_5,T1_5;
//extern u16 MbTimes;
//extern u16 MbFrameTime[8];
//extern u16 MbBound[8];

extern u8 Bound;
//extern u8 MbTimeOut;
//extern u8 MbEsd;


extern void UartInit(u8 bound);
extern void USART1_SendArray(u8 *Data, u8 len);

#endif


