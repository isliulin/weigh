#include "usart.h"	  

MB_STATUS    MbStatus;
MB_unRICV    MbRicv;
MB_unRICV16  MbRicv16;

MB_strSEND01020304  MbstrSEND01,MbstrSEND02,MbstrSEND03,MbstrSEND04;
MB_strSEND0506      MbstrSEND05,MbstrSEND06;
MB_strSEND16        Mb_strSEND16;

MBFSM       MbFsm = R_CRC;

UMBDATA     WMbData;
UMB_F0105   uMb_F0105;
UMB_F02     uMb_F02;
UMB_F030616 uMb_F030616;
UMB_F04     uMb_F04;

UMB_STATUS_ERR uMb_Status_Err;

u8 Len;
u8 SendBuf[50];
u32 T3_5,T1_5;
u16 MbTimes = 0;

u8 Bound = 3;
u8 MbTimeOut = 0;

u16 MbBound[8] = {1200, 2400, 4800, 9600, 19200, 38400, 56000, 57600};

/*********************************************************
function name: 初始化IO 串口1 

fun	:		bound:设置的波特率
*********************************************************/
void UartInit(u8 bound)
{
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);	//使能USART1，GPIOA时钟
 	USART_DeInit(USART1);  //复位串口1

    //USART 初始化设置

	USART_InitStructure.USART_BaudRate = MbBound[bound];//一般设置为9600;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//字长为8位数据格式
	USART_InitStructure.USART_StopBits = USART_StopBits_2;//一个停止位
	USART_InitStructure.USART_Parity = USART_Parity_No;//无奇偶校验位
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//无硬件数据流控制
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//收发模式

    USART_Init(USART1, &USART_InitStructure); //初始化串口

    //Usart1 NVIC 配置
    NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0 ;//抢占优先级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 4;		//子优先级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);	                        //根据指定的参数初始化VIC寄存器
   
    USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);          //开启中断

    USART_Cmd(USART1, ENABLE);                              //使能串口 
}

void USART1_SendArray(u8 *Data, u8 len)
{
    u8 i;
    u32 DelayTimer;
    
    RS485_TX_EN = 1;
   
    DelayTimer = GetSysTimer() + 1;
    while(GetSysTimer() < DelayTimer);
    
    for(i = 0; i < len; i++)
    {
        USART_SendData(USART1, Data[i]);
        while( USART_GetFlagStatus(USART1,USART_FLAG_TC)!= SET);
    }
    
    DelayTimer = GetSysTimer() + 1;
    while(GetSysTimer() < DelayTimer);
    
    RS485_TX_EN = 0;
}


