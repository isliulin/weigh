/**
  ******************************************************************************
  * @文件    bsp.h
  * @作者    zhaoxw
  * @版本    V0.0.0
  * @日期    2017-08-21
  * @概述    
  ******************************************************************************
  * @attention
  *
  * 
  *
  ******************************************************************************
  */ 
#ifndef __BSP_H
#define __BSP_H

#include "stm32f10x.h"
#include "uc1689u.h"
#include "bsp_i2c_gpio.h"
#include "mbcrc.h"
#include "key.h"

#define LED_0     GPIOC6_OUT
#define LED_1     GPIOC7_OUT
#define LED_2     GPIOC8_OUT
#define LED_3     GPIOC9_OUT

#define BUZZER    GPIOA8_OUT

#define RS485_TX_EN		GPIOA8_OUT			//485模式控制.0,接收;1,发送.

extern void BspInit(void);
extern u32 GetSysTimer(void);
extern void USART1_SendArray(u8 *Data, u8 len);
#endif /* __BSP_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
