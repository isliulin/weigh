/*
*********************************************************************************************************
*
*	模块名称 : RoundScreen138TFT液晶显示器驱动模块
*	文件名称 : lcdround138.h
*	版    本 : V0.2
*	说    明 : LCD内部驱动芯片型号为：R61505W
*			   驱动芯片的访问地址为: 0x60000000
*	修改记录 :
*		版本号	日期       	作者    说明
*		v0.1	2014-02-22	JOY		ST固件库版本 V3.5.0版本。
*		V0.2	2014-08-02	JOY		修改显示字符函数，增加背景色透明
*
*********************************************************************************************************
*/
#ifndef __UC1689U_H
#define __UC1689U_H		

#include "stm32f10x.h"

/* 定义LCD驱动器的访问地址 */
#define ILI9342_REG		*(__IO uint8_t *)(0x60000000)		// 命令寄存器
#define ILI9342_RAM		*(__IO uint8_t *)(0x60080000)	    // 数据寄存器
 
// LCD 接口定义
#define	LCD_SET_RES()	GPIO_SetBits(GPIOB,GPIO_Pin_12)    	// LCDreset--1	
#define	LCD_CLR_RES()	GPIO_ResetBits(GPIOB,GPIO_Pin_12)   // LCDreset--0	

#define LCD_BKL_ON()	GPIO_SetBits(GPIOA,GPIO_Pin_1)    	// LCD背光点亮--1
#define LCD_BKL_OFF()	GPIO_ResetBits(GPIOA,GPIO_Pin_1)    // LCD背光熄灭--0

typedef struct 
{
    u16 RPiont:5;
    u16 GPiont:6;
    u16 BPiont:5;
}SPOINT3;

typedef union 
{
    u8 Piont[2];
    SPOINT3 SPiont3;
}UPOINT3;

extern void LCD_Init(void);
extern u8 Lcd_PutPixel(u8 x, u8 y, u8 color);
extern u8 Lcd_GetPixel(u8 x, u8 y);
#endif  

