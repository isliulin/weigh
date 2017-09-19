/**
  ******************************************************************************
  * @�ļ�    main.c 
  * @����    zhaoxw
  * @�汾    V0.0.0
  * @����    2016-08-18
  * @����    Main program body
  ******************************************************************************
  * @attention
  *
  * 
  *
  ******************************************************************************
  */ 
#include "main.h"

u8 Tx1_Buffer[] = "123456789abcdef0123";
u8 Rx1_Buffer[50] = "";

U32_U16_U8 Test;
/*******************************************************************************
*��    ��: 
*��    ��: 
*��ڲ���: 
*���ڲ���: 
*˵    ��: 
*******************************************************************************/
int main(void)
{
//    u8 i;
    char str[20];
    
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
    
    /* Setup SysTick Timer for 1 msec interrupts */
    SysTick_Config(SystemCoreClock / 1000);

    /* Enable the CRC Module */
    //RCC_AHBPeriphClockCmd(RCC_AHBPeriph_CRC, ENABLE);
    
    BspInit();
    
    SetFont(EN8X16);
    DisplayString(0,0,(char *)Rx1_Buffer);
    Test.Long = 0x12345678;
    
    while(1)
    {
        ModBusRun();
        
        if(TimeMs % 100 == 0)
        {
            sprintf(str, "%dHz",TIM8Freq);
            DisplayString(0,16,str);
        }
    }
}


/*********************************END OF MAIN**********************************/
