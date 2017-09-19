/*
*********************************************************************************************************
*
*	ģ������ : RoundScreen138TFTҺ����ʾ������ģ��
*	�ļ����� : lcdround138.h
*	��    �� : V0.2
*	˵    �� : LCD�ڲ�����оƬ�ͺ�Ϊ��R61505W
*			   ����оƬ�ķ��ʵ�ַΪ: 0x60000000
*	�޸ļ�¼ :
*		�汾��	����       	����    ˵��
*		v0.1	2014-02-22	JOY		ST�̼���汾 V3.5.0�汾��
*		V0.2	2014-08-02	JOY		�޸���ʾ�ַ����������ӱ���ɫ͸��
*
*********************************************************************************************************
*/
#ifndef __UC1689U_H
#define __UC1689U_H		

#include "stm32f10x.h"

/* ����LCD�������ķ��ʵ�ַ */
#define ILI9342_REG		*(__IO uint8_t *)(0x60000000)		// ����Ĵ���
#define ILI9342_RAM		*(__IO uint8_t *)(0x60080000)	    // ���ݼĴ���
 
// LCD �ӿڶ���
#define	LCD_SET_RES()	GPIO_SetBits(GPIOB,GPIO_Pin_12)    	// LCDreset--1	
#define	LCD_CLR_RES()	GPIO_ResetBits(GPIOB,GPIO_Pin_12)   // LCDreset--0	

#define LCD_BKL_ON()	GPIO_SetBits(GPIOA,GPIO_Pin_1)    	// LCD�������--1
#define LCD_BKL_OFF()	GPIO_ResetBits(GPIOA,GPIO_Pin_1)    // LCD����Ϩ��--0

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

