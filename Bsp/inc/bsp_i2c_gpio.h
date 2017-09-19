/*
*********************************************************************************************************
*
*	模块名称 : I2C总线驱动模块
*	文件名称 : bsp_i2c_gpio.h
*	版    本 : V1.0
*	说    明 : 头文件。
*
*	Copyright (C), 2012-2013, 安富莱电子 www.armfly.com
*
*********************************************************************************************************
*/

#ifndef _BSP_I2C_GPIO_H
#define _BSP_I2C_GPIO_H

#include "stm32f10x.h"
#include "stm32f10x_bitband.h"

/* 定义读写SCL和SDA的宏 */
#define I2C_SCL_OUT  GPIOB6_OUT
#define I2C_SDA_OUT  GPIOB7_OUT

#define I2C_SCL_IN   GPIOB6_IN
#define I2C_SDA_IN   GPIOB7_IN

#define I2C_WR	0		/* 写控制bit */
#define I2C_RD	1		/* 读控制bit */

void i2c_Init(void);
void i2c_Start(void);
void i2c_Stop(void);
void i2c_SendByte(uint8_t _ucByte);
uint8_t i2c_ReadByte(void);
uint8_t i2c_WaitAck(void);
void i2c_Ack(void);
void i2c_NAck(void);
uint8_t i2c_CheckDevice(uint8_t _Address);

#endif
