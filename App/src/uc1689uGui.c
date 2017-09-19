//================================================================================================
// 文件名称: GUI.C 
// 芯片类型: STM32F103VBT6                                           
// 开发软件: Keil, Windows XP2 
// 开发时间: 2009年09月08日                                                               
// 程序功能: 液晶显示GUI 
// 编写人员: 崔超                                                                       
// 联系方式: 13686036830  cuichao@xrd-lcd.com 深圳市欣瑞达电子有限公司  
//================================================================================================ 
#include "uc1689uGui.h"
#include <stdio.h>
#include <string.h>

#include "Chinese.h"
#include "ASCII.h"
#include "icon.h"

//============================================================================= 
#define GUI_DISP_COLOR 1
#define GUI_BACK_COLOR 0 
//============================================================================= 
//   GUI相关全局变量
//============================================================================= 
u8 CharFont = ZH16X16;
//u8  GUITextMode = GUI_TEXTMODE_NORMAL;  //显示模式

u8 Char_XSIZE;   //英文字体X宽度
u8 Char_YSIZE;   //英文字体Y宽度	  

//#define EN8X16         (0)
//#define EN8X14         (1)
//#define EN8X8          (2)
//#define ZH16X24        (3)
//#define ZH16X16        (4)
//#define ZH14X14        (5)
//#define ZH12X12        (6)
//#define ICON48X29      (7)
//#define NUM16X24       (8)

DOT Dot[9] = 
{
    {8,16,16,ascii816},
    {8,14,14,ascii814},
    {8,12,12,ascii812},
    {16,24,48,hz1624},
    {16,16,32,hz1616},
    {14,14,28,hz1414},
    {12,12,24,hz1212},
    {48,29,174,Icon},
    {16,24,48,Num1624},
};

void SetFont(u8 Font)
{
    CharFont = Font;
}

//============================================================================= 
//函 数 名: GUI_PutChinese() 
//功 能：	指定位置显示一个16x16的汉字
//入口参数：UniCode:汉字内码 x:X轴坐标0--(160-16) Y轴坐标0--(160-16)
//出口参数： 无
//返 回 值： 无
//说明    ： 函数显示的文字列地址是8的整数倍，参数不是8的整数倍时自动向左调整
//============================================================================= 
/*
void GUI_PutChinese(u16 UniCode, u8 x, u8 y)
{
  u16 CodeID;
  u8 i,j;
  u8 const *ImgDataPtr;
     //参数过滤 
   if(x>GUI_LCM_XMAX-Chinese_XSIZE) return;
   if(y>GUI_LCM_YMAX-Chinese_YSIZE) return;
  // 在字库里搜索汉字
    for(CodeID=0; CodeID < hzNum; CodeID++){
        // 找到 指定汉字的 Index 后, 跳出循环
        if ( (hzIndex[2*CodeID] == UniCode/256) && (hzIndex[2*CodeID+1] == UniCode%256) ){
            break;
        }else if(CodeID == (hzNum-1)){//未检索到的汉字,显示个"##"提示吧
            GUI_DispChar('#',x,y);
            GUI_DispChar('#',x+Char_XSIZE,y);
            return;
        }
    }
	 x = x>>3;
//----------------------------------
    switch (GUITextMode) {
        case GUI_TEXTMODE_NORMAL :
//-------------------------------------------------------------------------
 			
			ImgDataPtr = hzdot+CodeID*((Chinese_XSIZE+7)/8*Chinese_YSIZE);
   	   	   	for(i=0; i<Chinese_YSIZE; i++)        // 显示共16行
   	   	   	{  for(j=0; j<Chinese_XSIZE/8; j++)   // 每行共16点
   	   	   	   	{  
   	   	   	   		gui_disp_buf[y][x] =*ImgDataPtr++ ; 	   	   	   	 
   	   	   	   	    x++;
                }     
   	   	   	  y++;						// 指向下一行
      		  x -= Chinese_XSIZE/8;					// 恢复x值
            }
       		
//-------------------------------------------------------------------------
             break;
        case GUI_TEXTMODE_REVERSE :
//-------------------------------------------------------------------------
			 
			ImgDataPtr = hzdot+CodeID*((Chinese_XSIZE+7)/8*Chinese_YSIZE);
   	   	   	for(i=0; i<Chinese_YSIZE; i++)      // 显示共16行
   	   	   	{  for(j=0; j<Chinese_XSIZE/8; j++)  // 每行共16点
   	   	   	   	{     
   	   	   	   		gui_disp_buf[y][x] =(*ImgDataPtr++)^0xff ; 	   	   	   	 
   	   	   	   	    x++;
                }     
   	   	   	  y++;						// 指向下一行
      		  x -= Chinese_XSIZE/8;					// 恢复x值
            }
       		
//-------------------------------------------------------------------------
             break;
        case GUI_TEXTMODE_UNDERLINE :
//-------------------------------------------------------------------------
    	
			ImgDataPtr = hzdot+CodeID*((Chinese_XSIZE+7)/8*Chinese_YSIZE);
   	   	   	for(i=0; i<Chinese_YSIZE-1; i++)     // 显示共16行
   	   	   	{  for(j=0; j<Chinese_XSIZE/8; j++)  // 每行共16点
   	   	   	   	{     	   	   	   	        
   	   	   	   		gui_disp_buf[y][x] =*ImgDataPtr++; 	   	   	   	 
   	   	   	   	    x++;
                }     
   	   	   	  y++;	                           // 指向下一行
      		  x -= Chinese_XSIZE/8;                    // 恢复x值
            }
		  
			for(j=0; j<Chinese_XSIZE/8; j++)             
  			{
			    gui_disp_buf[y][x] = 0xff; 
				x++;
			}
			y++;	
       		
			x -= Chinese_XSIZE/8;           // 恢复x值
			

//-------------------------------------------------------------------------
             break;
        default :
             break;
    }
	x *= 8;				// 恢复x值
	GUI_RefreshBlock(x,y-Chinese_YSIZE,x+Chinese_XSIZE,y);	  //刷新汉字的区域
} 
*/

void Display_Byte(u8 x,u8 y,u8 Char)
{
    u8 i;

    for(i=0;i<8;i++){
        if((Char << i) & 0x80)
        {
            Lcd_PutPixel(x + i,y,1);	  //刷新字符的区域
        }
        else
        {
            Lcd_PutPixel(x + i,y,0);	  //刷新字符的区域
        }
    }
}

//============================================================================= 
//函 数 名: DisplayDot() 
//功 能：	指定位置显示一个x * y 大小的点阵
//入口参数：
//出口参数： 无
//返 回 值： 无
//说明    ： 单色点阵的X应为8的倍数
//============================================================================= 
//void DisplayDot(u8 x,u8 y,ICON icon)
//{
//    u8 i, j;
//    
//    for(i=0;i< icon.Ylen;i++)
//    {
//        for(j=0;j < icon.Xlen;j++)
//        {
//            Display_Byte(x + j * 8, y + i,icon.data[j + i * icon.Xlen]);
//        }
//    }
//}

//============================================================================= 
//函 数 名: DisplayLine() 
//功 能：	
//入口参数：
//出口参数： 无
//返 回 值： 无
//说明    ： 
//============================================================================= 
void DisplayLine(u8 xs, u8 ys,u8 xe, u8 ye, u8 w)
{
    u8 i;
    u8 xlen,ylen;
    
    xlen = xe - xs;
    ylen = ye - ys;

    for(i = 0; i < xlen; i++)
    {
        Lcd_PutPixel(xs + i,ys,1);	  //刷新字符的区域
    }
    
    for(i = 0; i < ylen; i++)
    {
        Lcd_PutPixel(xs,ys + i,1);	  //刷新字符的区域
    }

}

//============================================================================= 
//函 数 名: DisplayDot() 
//功 能：	画任意大小的点阵图形
//入口参数：
//出口参数： 无
//返 回 值： 无
//说明    ： 
//============================================================================= 
void DisplayDot(u8 x, u8 y, u8 Char)
{
    u8 i, j, k = 0;
    u8 xsize,ysize;
    u8 const *ImgData;

    xsize = Dot[CharFont].xsize;
    ysize = Dot[CharFont].ysize;
    
    ImgData = Dot[CharFont].data + Char * Dot[CharFont].len;
    
    for(j = 0; j < ysize; j++)
    {
        for(i = 0; i < xsize;)
        {   
            if((*ImgData << k) & 0x80)
            {
                Lcd_PutPixel(x + i, y + j, 1);	  //刷新字符的区域
            }
            else
            {
                Lcd_PutPixel(x + i, y + j, 0);	  //刷新字符的区域
            }
            i++;
            k++;
            if(i % 8 == 0)
            {
                ImgData++;
                k = 0;
            }
        }
        if(i % 8 != 0)
        {
            ImgData++;
            k = 0;
        }
    }
}

//============================================================================= 
//函 数 名: DisplayBigPer() 
//功 能：	显示大的百分比，右对齐
//入口参数：
//出口参数： 无
//返 回 值： 无
//说明    ： 
//============================================================================= 
void DisplayBigPer(u8 x,u8 y,int Percent)
{
    u8 i, len;
    char str[10];
    
//    Num[0] = 11; //%
//    Num[2] = 10; //.
    
    len = sprintf(str, "%.1f;", Percent * 0.1);
    if(Percent < 0)str[0] = 0x30 + 12;
    str[len - 3] = 0x30 + 10;
    for(i = 0; i < len; i++)
    {
        DisplayDot(x - 16 * i, y, (str[len - i - 1] - 0x30));
    }
}

//============================================================================= 
//函 数 名: DisplayBigPer() 
//功 能：	显示大的百分比，右对齐
//入口参数：
//出口参数： 无
//返 回 值： 无
//说明    ： 
//============================================================================= 
void DisplayString(u8 x,u8 y,char str[])
{
    u8 i, len;

    
    len = strlen(str);

    for(i = 0; i < len; i++)
    {
        DisplayDot(x + Dot[CharFont].xsize * i, y, (str[i] - 0x20));
    }
}

//============================================================================= 
//函 数 名: GUI_PutChinese() 
//功 能：	指定位置显示一个16x16的汉字
//入口参数：UniCode:汉字内码 x:X轴坐标0--(160-16) Y轴坐标0--(160-16)
//出口参数： 无
//返 回 值： 无
//说明    ： 函数显示的文字列地址是8的整数倍，参数不是8的整数倍时自动向左调整
//============================================================================= 
void LcdPutChinese(char UniCode[], u8 x, u8 y)
{
    u16 CodeID;
    u8 i,j;
    u8 const *ImgDataPtr;
    
    //参数过滤 
    if(x>GUI_LCM_XMAX-Chinese_XSIZE) return;
    if(y>GUI_LCM_YMAX-Chinese_YSIZE) return;
    // 在字库里搜索汉字
    for(CodeID = 0; CodeID < hzNum; CodeID++)
    {
        // 找到 指定汉字的 Index 后, 跳出循环
        if((hzIndex[2 * CodeID] == UniCode[0]) && (hzIndex[2 * CodeID + 1] == UniCode[1]) )
        {
            break;
        }
        else if(CodeID == (hzNum-1))
        {//未检索到的汉字,显示个"##"提示吧
//            Display_ASCII('#',x,y);
//            Display_ASCII('#',x+Char_XSIZE,y);
            return;
        }
    }
    ImgDataPtr = hzdot + CodeID * 32;
    for(i=0;i<16;i++)
    {
        for(j=0;j < 2;j++)
        {
            Display_Byte(x + j * 8, y + i,*(ImgDataPtr + j + i * 2));
        }
    }
}

//================================================================================================= 
//                                   0ooo
//                          ooo0     (   ) 
//                          (   )     ) /
//                           \ (     (_/
//                            \_) 
//================================================================================================= 

