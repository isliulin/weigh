#ifndef __USART_H
#define __USART_H

#include "main.h"

#define RS485_TX_EN		GPIOA8_OUT			//485ģʽ����.0,����;1,����.


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
    u8 F02Timer:1;          //�ж϶�ʱ��
    u8 F02FwAdjust:1;       //����ִ��λ�õ�������
    u8 F02Nc1:2;            //����
    u8 F02FwAdjEn:1;        //λ�õ���������Ч
    u8 F02MbErr:1;          //�ڲ�����ͨѶ����
    
    u8 F02S1:1;
    u8 F02S2:1;
    u8 F02S3:1;
    u8 F02S4:1;
    u8 F02AuxIn3:1;         //��������3 Զ�̵㶯����
    u8 F02AuxIn2:1;         //��������2 Զ�̹ر�
    u8 F02AuxIn1:1;         //��������1 Զ�̴�
    u8 F02AuxIn4:1;         //��������4 Զ��ESD
}MB_F02;

typedef union
{
    u32 _Mb_F02Data;
    u8 Mb_F02Data[3];
    MB_F02 sMb_F02;
}UMB_F02;


typedef struct
{
    u16 F030616VaCtrR;      //ִ�������ƼĴ���
    u16 F030616FwCtrR;      //��λ���ƼĴ���
    u16 F030616Dead;        //����
    u16 F030616Nc;          //����
    u16 F030616LowFw;       //���ŷ�λ
    u16 F030616HigFw;       //���ŷ�λ    
}MB_F030616;

typedef union
{
    u16 Mb_F030616Data[6];
    MB_F030616 sMb_F030616;
}UMB_F030616;


typedef struct
{
    u16 F04Nc;
    u16 F04FwFb;            //ִ������λ����
    u16 F04AdjFwFb;         //ִ�������ڷ�λ����
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
}WB;//�����ֽ�
typedef union
{
    u32 Long;
    u8 LongData[4];
}WL;//�����ֽ�

typedef struct
{
    u16 MbSwitch;          //������
    u16 MbVavlePer;        //��λ�ٷֱ�
    u16 MbCloseDir;        //�ط���
    u16 MbCloseMode;       //��ģʽ
    u16 MbEsdMode;         //ESD����
    u16 MbLow;             //���Ŷ���
    u16 MbRemotMode;       //Զ��ģʽ ģ�����򿪹���
    u16 MbRelay[9];        //�̵�����̬��Ϣ
    u16 MbCPUTemp;         //CPU�¶�
    u16 MbVmaPer;          //ģ�����ٷֱ�
    u16 MbSN;              //���к�
    u16 MbTime;           //��������
    u16 MbVer;             //�汾
    u16 MbAl;             //���󱨾�
}SMBDATA;                  //Modbusд�����������

typedef union
{
    u16 MbDataArray[22];
    SMBDATA sMbData;
}UMBDATA;                  //Modbusд�����������

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


