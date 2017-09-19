/**
  ******************************************************************************
  * @文件    main.c 
  * @作者    zhaoxw
  * @版本    V0.0.0
  * @日期    2016-08-18
  * @概述    Main program body
  ******************************************************************************
  * @attention
  *
  * 
  *
  ******************************************************************************
  */ 
#include "main.h"
#include "bsp.h"

#define ADC1_DR_Address    ((uint32_t)0x4001244C)

__IO uint16_t ADCConvertedValue[8];

void IoInit(void);
void UsartInit(void);
void Timer8Init(void);
void NVIC_Configuration(void);
/*******************************************************************************
*名    称: 
*功    能: 
*入口参数: 
*出口参数: 
*说    明: 
*******************************************************************************/
void BspInit(void)
{
    IoInit();
    i2c_Init();
    WeighInit();
    
    UsartInit();
    Timer8Init();
    NVIC_Configuration();
    
    LCD_Init();
}

/*******************************************************************************
*名    称: 
*功    能: 
*入口参数: 
*出口参数: 
*说    明: 
*******************************************************************************/
u32 GetSysTimer(void)
{
    return TimeMs;
}

/*******************************************************************************
*名    称: 
*功    能: 
*入口参数: 
*出口参数: 
*说    明: 
*******************************************************************************/
void IoInit(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA | 
                            RCC_APB2Periph_GPIOB | 
                            RCC_APB2Periph_GPIOC | 
                            //RCC_APB2Periph_GPIOD | 
                            //RCC_APB2Periph_GPIOE |
                            RCC_APB2Periph_AFIO, ENABLE);

    //模拟输入
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
    
    //开关量输出
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
    
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
    
    //输入
    //KEY
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
    
    //I2C
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
    
    //USART1_485_CC   PA.8
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;				        //PA.8端口配置
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;		        //推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	RS485_TX_EN = 0;		   					                    //默认为接收模式//485模式控制.0,接收;1,发送.
	
    //USART1_TX   PA.9
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;                       //PA.9
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	                //复用推挽输出
    GPIO_Init(GPIOA, &GPIO_InitStructure);                          //初始化PA9

    //USART1_RX	  PA.10
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;           //浮空输入
    GPIO_Init(GPIOA, &GPIO_InitStructure);                          //初始化PA10
}

/*******************************************************************************
*名    称: 
*功    能: 
*入口参数: 
*出口参数: 
*说    明: 
*******************************************************************************/
void SpiInit(void)
{
    
}

/*******************************************************************************
*名    称: 
*功    能: 
*入口参数: 
*出口参数: 
*说    明: 
*******************************************************************************/
void UsartInit(void)
{
    USART_InitTypeDef USART_InitStructure;
	 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
    
    //USART 初始化设置
    USART_DeInit(USART1);
	USART_InitStructure.USART_BaudRate = 9600;                                          //一般设置为9600;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;                         //字长为8位数据格式
	USART_InitStructure.USART_StopBits = USART_StopBits_2;                              //一个停止位
	USART_InitStructure.USART_Parity = USART_Parity_No;                                 //无奇偶校验位
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;     //无硬件数据流控制
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	                    //收发模式

    USART_Init(USART1, &USART_InitStructure);                                           //初始化串口
    USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);                                      //开启中断
    USART_Cmd(USART1, ENABLE);                                                          //使能串口 
}

/*******************************************************************************
*名    称: 
*功    能: 
*入口参数: 
*出口参数: 
*说    明: 
*******************************************************************************/
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
/*******************************************************************************
*名    称: 
*功    能: 
*入口参数: 
*出口参数: 
*说    明: 
*******************************************************************************/
void AdcInit(void)
{
    ADC_InitTypeDef ADC_InitStructure;
    DMA_InitTypeDef DMA_InitStructure;
    
    /* Enable DMA1 clock */
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);

    /* Enable ADC1 and GPIOC clock */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);

    /* DMA1 channel1 configuration ----------------------------------------------*/
    DMA_DeInit(DMA1_Channel1);
    DMA_InitStructure.DMA_PeripheralBaseAddr = ADC1_DR_Address;
    DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)&ADCConvertedValue;
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
    DMA_InitStructure.DMA_BufferSize = 8;
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
    DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
    DMA_InitStructure.DMA_Priority = DMA_Priority_High;
    DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
    DMA_Init(DMA1_Channel1, &DMA_InitStructure);

    /* Enable DMA1 channel1 */
    DMA_Cmd(DMA1_Channel1, ENABLE);

    /* ADC1 configuration ------------------------------------------------------*/
    ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
    ADC_InitStructure.ADC_ScanConvMode = ENABLE;
    ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
    ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
    ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
    ADC_InitStructure.ADC_NbrOfChannel = 8;
    ADC_Init(ADC1, &ADC_InitStructure);

    /* ADC1 regular channel1~8 configuration */ 
    ADC_RegularChannelConfig(ADC1, ADC_Channel_0, 1, ADC_SampleTime_55Cycles5);
    ADC_RegularChannelConfig(ADC1, ADC_Channel_1, 2, ADC_SampleTime_55Cycles5);
    ADC_RegularChannelConfig(ADC1, ADC_Channel_2, 3, ADC_SampleTime_55Cycles5);
    ADC_RegularChannelConfig(ADC1, ADC_Channel_3, 4, ADC_SampleTime_55Cycles5);
    ADC_RegularChannelConfig(ADC1, ADC_Channel_4, 5, ADC_SampleTime_55Cycles5);
    ADC_RegularChannelConfig(ADC1, ADC_Channel_5, 6, ADC_SampleTime_55Cycles5);
    ADC_RegularChannelConfig(ADC1, ADC_Channel_6, 7, ADC_SampleTime_55Cycles5);
    ADC_RegularChannelConfig(ADC1, ADC_Channel_7, 8, ADC_SampleTime_55Cycles5);
    

    /* Enable ADC1 DMA */
    ADC_DMACmd(ADC1, ENABLE);

    /* Enable ADC1 */
    ADC_Cmd(ADC1, ENABLE);

    /* Enable ADC1 reset calibration register */   
    ADC_ResetCalibration(ADC1);
    /* Check the end of ADC1 reset calibration register */
    while(ADC_GetResetCalibrationStatus(ADC1));

    /* Start ADC1 calibration */
    ADC_StartCalibration(ADC1);
    /* Check the end of ADC1 calibration */
    while(ADC_GetCalibrationStatus(ADC1));
     
    /* Start ADC1 Software Conversion */ 
    ADC_SoftwareStartConvCmd(ADC1, ENABLE);
}

/*******************************************************************************
*名    称: 
*功    能: 
*入口参数: 
*出口参数: 
*说    明: 
*******************************************************************************/
void IrInit(void)
{

}

/*******************************************************************************
*名    称: 
*功    能: 
*入口参数: 
*出口参数: 
*说    明: 
*******************************************************************************/
void Timer2Init(void)
{
    //TIM2 
    //CH2 LCD PWM背光
    
}

/*******************************************************************************
*名    称: 
*功    能: 
*入口参数: 
*出口参数: 
*说    明: 
*******************************************************************************/
void Timer8Init(void)
{
    TIM_ICInitTypeDef  TIM_ICInitStructure;
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
    //    
    //    uint16_t PrescalerValue = 0;
    
    //TIM8  输入捕获
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM8,ENABLE);	//TIM8 时钟使能 
    
    //PrescalerValue = (uint16_t) (SystemCoreClock / 12000000) - 1;
    
    TIM_TimeBaseStructure.TIM_Period = 65535; //设定计数器自动重装值 最大10ms溢出  
	TIM_TimeBaseStructure.TIM_Prescaler = 0; 	//预分频器,1M的计数频率,1us加1.	   
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
    
    TIM_TimeBaseInit(TIM8, &TIM_TimeBaseStructure); //根据指定的参数初始化TIMx
    
    //TIM_PrescalerConfig(TIM8, PrescalerValue, TIM_PSCReloadMode_Immediate);
    
    //CH1   红外
    //CH3   PhaseA
    //CH4   PhaseB

    TIM_ICInitStructure.TIM_Channel = TIM_Channel_3;
    TIM_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_BothEdge;
    TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;
    TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;
    TIM_ICInitStructure.TIM_ICFilter = 0x0;
    
    TIM_ICInit(TIM8, &TIM_ICInitStructure);

    /* TIM enable counter */
    TIM_Cmd(TIM8, ENABLE);

    /* Enable the CC1 Interrupt Request */
    TIM_ITConfig(TIM8, TIM_IT_CC3, ENABLE);
}

/**
  * @brief  Configure the nested vectored interrupt controller.
  * @param  None
  * @retval None
  */
void NVIC_Configuration(void)
{
    NVIC_InitTypeDef NVIC_InitStructure;

    /* Enable the TIM3 global Interrupt */
    NVIC_InitStructure.NVIC_IRQChannel = TIM8_CC_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    
    //Usart1 NVIC 配置
    NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0 ;//抢占优先级
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 4;		//子优先级
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
    NVIC_Init(&NVIC_InitStructure);	                        //根据指定的参数初始化VIC寄存器
}

/*********************************END OF BSP**********************************/
