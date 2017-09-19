//================================================================================================
// 文件名称: GUI.h 
// 芯片类型: STM32F103VBT6                                           
// 开发软件: Keil, Windows XP2 
// 开发时间: 2009年09月08日                                                               
// 程序功能: 液晶显示GUI 
// 编写人员: 崔超                                                                       
// 联系方式: 13686036830  cuichao@xrd-lcd.com 深圳市欣瑞达电子有限公司  
//================================================================================================ 
#ifndef __UC1689UGUI_H
#define __UC1689UGUI_H

#include "stm32f10x.h"
#include "uc1689u.h"

#define GUI_LCM_XMAX  160
#define GUI_LCM_YMAX  160



////显示模式
//#define GUI_TEXTMODE_NORMAL      (0)
//#define GUI_TEXTMODE_REVERSE     (1<<0)
//#define GUI_TEXTMODE_UNDERLINE   (1<<1)
//#define GUI_TEXTMODE_XOR         (1<<2)
////对齐方式
//#define GUI_TA_LEFT              (0<<4)
//#define GUI_TA_HCENTER           (1<<4)
//#define GUI_TA_RIGHT             (2<<4)
//#define GUI_JUST_TEXT            (1<<7)

#define EN8X16         (0)
#define EN8X14         (1)
#define EN8X12         (2)
#define ZH16X24        (3)
#define ZH16X16        (4)
#define ZH14X14        (5)
#define ZH12X12        (6)
#define ICON48X29      (7)
#define NUM16X24       (8)

//英文字体宽度定义
#define En_8x16_XSIZE  8
#define En_8x16_YSIZE  16
#define En_8x8_XSIZE   8
#define En_8x8_YSIZE   8

//中文字体宽度定义
#define Chinese_XSIZE  16
#define Chinese_YSIZE  16

typedef struct 
{
    u8 xsize;//8的倍数 48 就写6
    u8 ysize;
    u8 len;
    u8 const *data;
}DOT;

extern unsigned char const hzdot[3264];
extern unsigned char const hz1624[];

//字体宽度定义
extern u8 Char_XSIZE;
extern u8 Char_YSIZE; 

extern void SetFont(u8 Font);
extern void DisplayLine(u8 xs, u8 ys,u8 xe, u8 ye, u8 w);
extern void DisplayDot(u8 x, u8 y, u8 Char);
extern void DisplayBigPer(u8 x,u8 y,int Percent);
extern void DisplayString(u8 x,u8 y,char str[]);

#endif

