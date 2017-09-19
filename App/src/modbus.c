/**
  ******************************************************************************
  * @文件    modbus.c
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
#include "modbus.h"

MB_STATUS   MbStatus;
MB_unRICV   MbRicv;
MBFSM       MbFsm = R_CRC;
UMB_F0316 uMb_F0316;

u8 Len = 0;
u8 SendBuf[50];

void ModBusRun(void);
static void  ModBusFuc(void);
static void  ModBusRp(void);

//static void  ModBusFuc01(void);
//static void  ModBusFuc02(void);
static void  ModBusFuc03(void);
//static void  ModBusFuc04(void);
//static void  ModBusFuc05(void);
//static void  ModBusFuc06(void);
//static void  ModBusFuc07(void);
static void  ModBusFuc16(void);

/*******************************************************************************
*名    称: 
*功    能: 
*入口参数: 
*出口参数: 
*说    明: 
*******************************************************************************/
void ModBusInit(void)
{
    u8 i;
    for(i = 0; i < 10; i++)
    {
        uMb_F0316.Mb_F0316Data8[i] = i;
    }
}
/*******************************************************************************
*名    称: 
*功    能: 
*入口参数: 
*出口参数: 
*说    明: 
*******************************************************************************/
void ModBusRun(void)
{
    U32_U16_U8  MbTemp;
    /**********************************************/
    if(MbStatus.MbRicved)//接收到一帧
    {
        switch((u8)MbFsm)
        {
            case R_CRC:
                MbStatus.MbErr = 0;//错误
                if(MbRicv.MbstrRicv.FucCode == 16)
                {
                    MbTemp.Int = usMBCRC16(MbRicv.DataRicv, (MbRicv.MbstrRicv16.Cnt + 7));
                    if((MbTemp.sChar.CharL == MbRicv.DataRicv[MbRicv.MbstrRicv16.Cnt + 7]) && \
                       (MbTemp.sChar.CharH == MbRicv.DataRicv[MbRicv.MbstrRicv16.Cnt + 8]))
                    {
                        MbFsm = R_FUC;
                    }
                    else
                    {
                        MbStatus.MbErr = 1;//校验错误
                        MbFsm = R_RESPOND;
                    }
                }
                else
                {
                    MbTemp.Int = usMBCRC16(MbRicv.DataRicv, 6);
                    if((MbTemp.sChar.CharH == MbRicv.MbstrRicv.CrcHi) && (MbTemp.sChar.CharL == MbRicv.MbstrRicv.CrcLo))
                    {
                        MbFsm = R_FUC;
                    }
                    else
                    {
                        MbStatus.MbErr = 1;//校验错误
                        MbFsm = R_RESPOND;
                    }
                }
                break;
            case R_FUC:
                ModBusFuc();
                MbFsm = R_RESPOND;
                break;
            case R_RESPOND:
                ModBusRp();
                MbFsm = R_END;
                break;
            case R_END:
                MbFsm = R_CRC;
                MbStatus.MbRicved = 0;
                break;
            default:break;
        }
    }
}


static void  ModBusFuc(void)
{
    switch(MbRicv.MbstrRicv.FucCode)
    {
//        case 0x01://
//            break;
//        case 0x02://
//            break;
        case 0x03://
            ModBusFuc03();
            break;
//        case 0x04://
//            break;
//        case 0x05://
//            break;
//        case 0x06://
//            break;
//        case 0x07://
//            break;
        case 0x10://
            ModBusFuc16();
            break;
        default:
            MbStatus.MbErr = 1;     //非法的功能码
        break;
    }
}


static void  ModBusFuc03(void)//
{
    u8 i, len, Local;
    U32_U16_U8  MbTemp;
    
    MbTemp.sChar.CharH = MbRicv.MbstrRicv.NumHi;
    MbTemp.sChar.CharL = MbRicv.MbstrRicv.NumLo;
    len = MbTemp.Int;

    MbTemp.sChar.CharH = MbRicv.MbstrRicv.LocaHi;
    MbTemp.sChar.CharL = MbRicv.MbstrRicv.LocaLo;
    Local = MbTemp.Int;
    
    if(len == 0)
    {
        MbStatus.MbErr = 3;
        return;
    }

    for(i = 0; i < len; i++)
    {
        MbTemp.Int = uMb_F0316.Mb_F0316Data16[Local + i];
        
        SendBuf[i * 2 + 3] = MbTemp.sChar.CharH;
        SendBuf[i * 2 + 4] = MbTemp.sChar.CharL;
        if(Local + i > 32)
        {
            MbStatus.MbErr = 2;     //非法的数据地址
            return;
        }
    }
    
    len = len << 1;

    SendBuf[0] = MbRicv.MbstrRicv.Addr;
    SendBuf[1] = MbRicv.MbstrRicv.FucCode;
    SendBuf[2] = len;
    
    Len = len + 5;

    MbTemp.Int= usMBCRC16(SendBuf,len + 3);
    SendBuf[Len - 2] = MbTemp.sChar.CharL;
    SendBuf[Len - 1] = MbTemp.sChar.CharH;
}

static void  ModBusFuc16(void)//
{
    u8 i;
    U32_U16_U8 MbTemp;
    u8 Data, Local;
    
    MbTemp.sChar.CharH = MbRicv.MbstrRicv16.NumHi;
    MbTemp.sChar.CharL = MbRicv.MbstrRicv16.NumLo;
    Data = MbTemp.Int;
    
    MbTemp.sChar.CharH = MbRicv.MbstrRicv16.LocaHi;
    MbTemp.sChar.CharL = MbRicv.MbstrRicv16.LocaLo;
    Local = MbTemp.Int;
    
    SendBuf[0] = MbRicv.MbstrRicv16.Addr;
    SendBuf[1] = MbRicv.MbstrRicv16.FucCode;
    
    if(Data > 32 && (MbRicv.MbstrRicv16.Cnt != (Data << 1)))
    {
        MbStatus.MbErr = 3;//起始地址或数量出错
        return;
    }   
    
    if((Local < (33 - Data)) && (Local < 32))
    {
        for(i = 0; i < Data; i++)
        {
            MbTemp.sChar.CharH = MbRicv.MbstrRicv16.Data[i * 2];
            MbTemp.sChar.CharL = MbRicv.MbstrRicv16.Data[i * 2 + 1];
            
            uMb_F0316.Mb_F0316Data16[Local + i] = MbTemp.Int;
        }
    }
    else
    {
        MbStatus.MbErr = 2;//起始地址或数量出错
        return;
    }
   
    SendBuf[2] = MbRicv.MbstrRicv16.LocaHi;
    SendBuf[3] = MbRicv.MbstrRicv16.LocaLo;
    SendBuf[4] = MbRicv.MbstrRicv16.NumHi;
    SendBuf[5] = MbRicv.MbstrRicv16.NumLo;
    
    MbTemp.Int = usMBCRC16(SendBuf, 6);

    SendBuf[6] = MbTemp.sChar.CharL;
    SendBuf[7] = MbTemp.sChar.CharH;
    
    Len = 8;
}

static void  ModBusRp(void)
{
    U32_U16_U8 MbTemp;
    
    if(MbRicv.MbstrRicv.Addr)
    {
        if(MbStatus.MbErr)
        {
            SendBuf[0] = MbRicv.MbstrRicv.Addr;
            SendBuf[1] |= 0x80;
            SendBuf[2] = MbStatus.MbErr;
            
            MbTemp.Int = usMBCRC16(SendBuf,3);
            SendBuf[3] = MbTemp.sChar.CharL;
            SendBuf[4] = MbTemp.sChar.CharH;
            Len = 5;
        }

        USART1_SendArray(SendBuf,Len);
        Len = 0;
    }
}

///********************************END OF MODBUS**********************************/
