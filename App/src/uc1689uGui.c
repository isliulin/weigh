//================================================================================================
// �ļ�����: GUI.C 
// оƬ����: STM32F103VBT6                                           
// �������: Keil, Windows XP2 
// ����ʱ��: 2009��09��08��                                                               
// ������: Һ����ʾGUI 
// ��д��Ա: �޳�                                                                       
// ��ϵ��ʽ: 13686036830  cuichao@xrd-lcd.com �����������������޹�˾  
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
//   GUI���ȫ�ֱ���
//============================================================================= 
u8 CharFont = ZH16X16;
//u8  GUITextMode = GUI_TEXTMODE_NORMAL;  //��ʾģʽ

u8 Char_XSIZE;   //Ӣ������X���
u8 Char_YSIZE;   //Ӣ������Y���	  

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
//�� �� ��: GUI_PutChinese() 
//�� �ܣ�	ָ��λ����ʾһ��16x16�ĺ���
//��ڲ�����UniCode:�������� x:X������0--(160-16) Y������0--(160-16)
//���ڲ����� ��
//�� �� ֵ�� ��
//˵��    �� ������ʾ�������е�ַ��8������������������8��������ʱ�Զ��������
//============================================================================= 
/*
void GUI_PutChinese(u16 UniCode, u8 x, u8 y)
{
  u16 CodeID;
  u8 i,j;
  u8 const *ImgDataPtr;
     //�������� 
   if(x>GUI_LCM_XMAX-Chinese_XSIZE) return;
   if(y>GUI_LCM_YMAX-Chinese_YSIZE) return;
  // ���ֿ�����������
    for(CodeID=0; CodeID < hzNum; CodeID++){
        // �ҵ� ָ�����ֵ� Index ��, ����ѭ��
        if ( (hzIndex[2*CodeID] == UniCode/256) && (hzIndex[2*CodeID+1] == UniCode%256) ){
            break;
        }else if(CodeID == (hzNum-1)){//δ�������ĺ���,��ʾ��"##"��ʾ��
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
   	   	   	for(i=0; i<Chinese_YSIZE; i++)        // ��ʾ��16��
   	   	   	{  for(j=0; j<Chinese_XSIZE/8; j++)   // ÿ�й�16��
   	   	   	   	{  
   	   	   	   		gui_disp_buf[y][x] =*ImgDataPtr++ ; 	   	   	   	 
   	   	   	   	    x++;
                }     
   	   	   	  y++;						// ָ����һ��
      		  x -= Chinese_XSIZE/8;					// �ָ�xֵ
            }
       		
//-------------------------------------------------------------------------
             break;
        case GUI_TEXTMODE_REVERSE :
//-------------------------------------------------------------------------
			 
			ImgDataPtr = hzdot+CodeID*((Chinese_XSIZE+7)/8*Chinese_YSIZE);
   	   	   	for(i=0; i<Chinese_YSIZE; i++)      // ��ʾ��16��
   	   	   	{  for(j=0; j<Chinese_XSIZE/8; j++)  // ÿ�й�16��
   	   	   	   	{     
   	   	   	   		gui_disp_buf[y][x] =(*ImgDataPtr++)^0xff ; 	   	   	   	 
   	   	   	   	    x++;
                }     
   	   	   	  y++;						// ָ����һ��
      		  x -= Chinese_XSIZE/8;					// �ָ�xֵ
            }
       		
//-------------------------------------------------------------------------
             break;
        case GUI_TEXTMODE_UNDERLINE :
//-------------------------------------------------------------------------
    	
			ImgDataPtr = hzdot+CodeID*((Chinese_XSIZE+7)/8*Chinese_YSIZE);
   	   	   	for(i=0; i<Chinese_YSIZE-1; i++)     // ��ʾ��16��
   	   	   	{  for(j=0; j<Chinese_XSIZE/8; j++)  // ÿ�й�16��
   	   	   	   	{     	   	   	   	        
   	   	   	   		gui_disp_buf[y][x] =*ImgDataPtr++; 	   	   	   	 
   	   	   	   	    x++;
                }     
   	   	   	  y++;	                           // ָ����һ��
      		  x -= Chinese_XSIZE/8;                    // �ָ�xֵ
            }
		  
			for(j=0; j<Chinese_XSIZE/8; j++)             
  			{
			    gui_disp_buf[y][x] = 0xff; 
				x++;
			}
			y++;	
       		
			x -= Chinese_XSIZE/8;           // �ָ�xֵ
			

//-------------------------------------------------------------------------
             break;
        default :
             break;
    }
	x *= 8;				// �ָ�xֵ
	GUI_RefreshBlock(x,y-Chinese_YSIZE,x+Chinese_XSIZE,y);	  //ˢ�º��ֵ�����
} 
*/

void Display_Byte(u8 x,u8 y,u8 Char)
{
    u8 i;

    for(i=0;i<8;i++){
        if((Char << i) & 0x80)
        {
            Lcd_PutPixel(x + i,y,1);	  //ˢ���ַ�������
        }
        else
        {
            Lcd_PutPixel(x + i,y,0);	  //ˢ���ַ�������
        }
    }
}

//============================================================================= 
//�� �� ��: DisplayDot() 
//�� �ܣ�	ָ��λ����ʾһ��x * y ��С�ĵ���
//��ڲ�����
//���ڲ����� ��
//�� �� ֵ�� ��
//˵��    �� ��ɫ�����XӦΪ8�ı���
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
//�� �� ��: DisplayLine() 
//�� �ܣ�	
//��ڲ�����
//���ڲ����� ��
//�� �� ֵ�� ��
//˵��    �� 
//============================================================================= 
void DisplayLine(u8 xs, u8 ys,u8 xe, u8 ye, u8 w)
{
    u8 i;
    u8 xlen,ylen;
    
    xlen = xe - xs;
    ylen = ye - ys;

    for(i = 0; i < xlen; i++)
    {
        Lcd_PutPixel(xs + i,ys,1);	  //ˢ���ַ�������
    }
    
    for(i = 0; i < ylen; i++)
    {
        Lcd_PutPixel(xs,ys + i,1);	  //ˢ���ַ�������
    }

}

//============================================================================= 
//�� �� ��: DisplayDot() 
//�� �ܣ�	�������С�ĵ���ͼ��
//��ڲ�����
//���ڲ����� ��
//�� �� ֵ�� ��
//˵��    �� 
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
                Lcd_PutPixel(x + i, y + j, 1);	  //ˢ���ַ�������
            }
            else
            {
                Lcd_PutPixel(x + i, y + j, 0);	  //ˢ���ַ�������
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
//�� �� ��: DisplayBigPer() 
//�� �ܣ�	��ʾ��İٷֱȣ��Ҷ���
//��ڲ�����
//���ڲ����� ��
//�� �� ֵ�� ��
//˵��    �� 
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
//�� �� ��: DisplayBigPer() 
//�� �ܣ�	��ʾ��İٷֱȣ��Ҷ���
//��ڲ�����
//���ڲ����� ��
//�� �� ֵ�� ��
//˵��    �� 
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
//�� �� ��: GUI_PutChinese() 
//�� �ܣ�	ָ��λ����ʾһ��16x16�ĺ���
//��ڲ�����UniCode:�������� x:X������0--(160-16) Y������0--(160-16)
//���ڲ����� ��
//�� �� ֵ�� ��
//˵��    �� ������ʾ�������е�ַ��8������������������8��������ʱ�Զ��������
//============================================================================= 
void LcdPutChinese(char UniCode[], u8 x, u8 y)
{
    u16 CodeID;
    u8 i,j;
    u8 const *ImgDataPtr;
    
    //�������� 
    if(x>GUI_LCM_XMAX-Chinese_XSIZE) return;
    if(y>GUI_LCM_YMAX-Chinese_YSIZE) return;
    // ���ֿ�����������
    for(CodeID = 0; CodeID < hzNum; CodeID++)
    {
        // �ҵ� ָ�����ֵ� Index ��, ����ѭ��
        if((hzIndex[2 * CodeID] == UniCode[0]) && (hzIndex[2 * CodeID + 1] == UniCode[1]) )
        {
            break;
        }
        else if(CodeID == (hzNum-1))
        {//δ�������ĺ���,��ʾ��"##"��ʾ��
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

