/*
*********************************************************************************************************
*
*	ģ������ : RoundScreen138TFTҺ����ʾ������ģ��
*	�ļ����� : lcdround138.c
*	��    �� : V0.2
*	˵    �� : LCD�ڲ�����оƬ�ͺ�Ϊ��R61505W
*			   ����оƬ�ķ��ʵ�ַΪ: 0x60000000
*	�޸ļ�¼ :
*		�汾��	����       	����    ˵��
*		v0.1	2014-02-22	JOY		ST�̼���汾 V3.5.0�汾��
*									��Ļ����ɿ�PB0��1-������, 0-������
*		V0.2	2014-08-02	JOY		�޸���ʾ�ַ����������ӱ���ɫ͸��
*
*********************************************************************************************************
*/
#include "uc1689u.h"

SPOINT3 SPoint3_Buf[160][54];
UPOINT3 uPiont;
//////////////////////////////////////////////////////////////////////////////////	
static void delay(uint32_t time)
{
	while(time--);
}

static void LCD_ILI9342C_CMD(uint16_t _ucRegAddr)
{
	ILI9342_REG = _ucRegAddr;	/* ���üĴ�����ַ */
}
static void LCD_ILI9342C_Parameter(uint16_t _ucRegValue)
{
	ILI9342_RAM = _ucRegValue;	/* д��Ĵ���ֵ */	/* ���üĴ�����ַ */
}

void ILI9342C_TM23_Initial(void) 
{ 
#define BR		0X01	   	//Set LCD Bias Ratio:1/10 bias	  
#define PC1     0X03        //power control set as internal power
#define TC      0x00        //set temperate compensation as 0%
#define PM      192         //Set Vbias Potentiometer       
#define LC_210  0X05        //set LCD Control
#define LC_43   0x03
#define LC_5    0X01
#define LC_76   0x01
#define LC_8    0X00
#define NIV     0X10        //n-line inversion
#define CSF     0X02        //23:enable FRC,PWM,LRM sequence      
#define WPC0    0x25        //Starting Column Address
#define WPP0    0           //Starting Row Address
#define WPC1	0x5A		//Ending Column Address
#define WPP1	159		    //Ending Row Address
#define	AC    	0x01		//Address  Control	  
#define CEN 	159 		//COM scanning end (last COM with full line cycle,0 based index)
    
	LCD_CLR_RES();	// RESET
	delay(20000);
	LCD_SET_RES();
	
	// ��ȡLCD����оƬID
	//id = R61505W_ReadID();

	delay(500000);	//DelayNS(1000);
    //************* Start Initial Sequence **********//
  
  	LCD_ILI9342C_CMD(0xe2); //�����λ
	delay(5000); //��ʱ
	LCD_ILI9342C_CMD(0x25); //�����¶Ȳ���ϵ���� TC1TC0 01=-0.05%
	LCD_ILI9342C_CMD(0x2b); //internal pump:0x2b
    
	LCD_ILI9342C_CMD(0xc4); //����LCD ��ת����
    //if(ScrSel==1)
    {
        //LCD_ILI9342C_CMD(0xc2); //����LCD ��ת����
    }
    
	LCD_ILI9342C_CMD(0xa3); //set line rate
	LCD_ILI9342C_CMD(0xd1); //set color pattem
	LCD_ILI9342C_CMD(0xd6); //����Ϊ64 ��ɫ*/
	LCD_ILI9342C_CMD(0xeb); //����ƫѹ��: 1/12bias:0xeb
	LCD_ILI9342C_CMD(0x81); //set Vbias potentiometer
	LCD_ILI9342C_CMD(0x8c); //�Աȶ�����08
	LCD_ILI9342C_CMD(0xf1); //��������0xf1
	LCD_ILI9342C_CMD(0x9f); //������������ֵΪ80 ��:4f,160 �У�9f
	LCD_ILI9342C_CMD(0xad); //����ʾ
    
    LCD_ILI9342C_CMD(0xE8|(BR&0X03));			
	LCD_ILI9342C_CMD(0x28|(PC1&0X03));		
	LCD_ILI9342C_CMD(0x24|(TC&0x03));		
	LCD_ILI9342C_CMD(0x81);		
	LCD_ILI9342C_CMD(PM );  	
	LCD_ILI9342C_CMD(0xc0|(LC_210&0X07) ); 				
	LCD_ILI9342C_CMD(0xa0|(LC_43 &0X03) ); 					
	LCD_ILI9342C_CMD(0xd0|(LC_5  &0X01) ); 				
	LCD_ILI9342C_CMD(0xd4|(LC_76 &0X03) );				
	LCD_ILI9342C_CMD(0x84|(LC_8  &0X01) );		
	LCD_ILI9342C_CMD(0xc8 );				 			
	LCD_ILI9342C_CMD( NIV );				 		
	LCD_ILI9342C_CMD(0xd8|(CSF&0X07) );	 		
	LCD_ILI9342C_CMD(0xf4 );				 	
	LCD_ILI9342C_CMD(WPC0 );				 		
	LCD_ILI9342C_CMD(0xf6 );				 		
	LCD_ILI9342C_CMD(WPC1 );				 		
	LCD_ILI9342C_CMD(0xf5 );				 	 	
	LCD_ILI9342C_CMD(WPP0 );				 		
	LCD_ILI9342C_CMD(0xf7 );				 	 	
	LCD_ILI9342C_CMD(WPP1 ); 			 	 	
	LCD_ILI9342C_CMD(0xf8|((AC>>3)&0x01) );	 										  
	LCD_ILI9342C_CMD(0x88| (0x07&AC) );	 	
	LCD_ILI9342C_CMD(0xf1 );			
	LCD_ILI9342C_CMD(CEN );		 	
	LCD_ILI9342C_CMD(0xad );		//18:display on,select on/off mode.Green Enhance mode disable 
	
} 

/*
*********************************************************************************************************
*	�� �� ��: LCD_CtrlLinesConfig
*	����˵��: ����LCD���ƿ��ߣ�FSMC�ܽ�����Ϊ���ù���
*	��    �Σ���
*	�� �� ֵ: ��
*********************************************************************************************************
*/
static void LCD_CtrlLinesConfig(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_FSMC, ENABLE);

	/* ʹ�� FSMC, GPIOD, GPIOE �� AFIO ʱ�� */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOD | RCC_APB2Periph_GPIOE |
	                     RCC_APB2Periph_AFIO, ENABLE);

	/* ���� PD.00(D2), PD.01(D3), PD.04(nRD), PD.05(nWR), PD.08(D13), PD.09(D14),
	 PD.10(D15), PD.14(D0), PD.15(D1) Ϊ����������� */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_4 | GPIO_Pin_5 |
	                             GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOD, &GPIO_InitStructure);

	/* ���� PE.07(D4), PE.08(D5), PE.09(D6), PE.10(D7), PE.11(D8), PE.12(D9), PE.13(D10),
	 PE.14(D11), PE.15(D12) Ϊ����������� */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 |
	                            GPIO_Pin_11 ;
	GPIO_Init(GPIOE, &GPIO_InitStructure);

	/* ���� PD.13(A18 (RS))  Ϊ����������� */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
	GPIO_Init(GPIOD, &GPIO_InitStructure);

	/* ���� PD.7(NE2 (LCD/CS)) Ϊ����������� */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
	GPIO_Init(GPIOD, &GPIO_InitStructure);
	
	/* ���� PB.12(Reset) Ϊ������� */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
    
    /* ���� PA.1(LCD ����)��H-�� */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	LCD_BKL_ON();							// ��������
}

/*
*********************************************************************************************************
*	�� �� ��: LCD_FSMCConfig
*	����˵��: ����FSMC���ڷ���ʱ��
*	��    �Σ���
*	�� �� ֵ: ��
*********************************************************************************************************
*/
static void LCD_FSMCConfig(void)
{
	FSMC_NORSRAMInitTypeDef  init;
	FSMC_NORSRAMTimingInitTypeDef  timing, timingW;

	/*-- FSMC Configuration ------------------------------------------------------*/
	/*----------------------- SRAM Bank 1 ----------------------------------------*/
	/* FSMC_Bank1_NORSRAM4 configuration */
	// ��ʱ��
	timing.FSMC_AddressSetupTime = 14;//1;	 	//��ַ����ʱ�䣬RD�ߵ�ƽ����ʱ��200ns < (ADDSET+1)*HCLK, HCLK=13.8ns @72MHz
	timing.FSMC_AddressHoldTime = 0;//1;		//��ַ����ʱ��
	timing.FSMC_DataSetupTime = 26;//20;		//���ݽ���ʱ�䣬RD�͵�ƽ����ʱ��400ns < (DATAST+3)*HCKL, HCLK=13.8ns @72MHz
	timing.FSMC_BusTurnAroundDuration = 0;//0
	timing.FSMC_CLKDivision = 0;
	timing.FSMC_DataLatency = 0;//1;
	timing.FSMC_AccessMode = FSMC_AccessMode_A;

	// дʱ��
	timingW.FSMC_AddressSetupTime = 2;		//��ַ����ʱ��, WR�ߵ�ƽ����ʱ��25ns < (ADDSET+1)*HCLK, HCLK=13.8ns @72MHz
	timingW.FSMC_AddressHoldTime = 1;		//��ַ����ʱ��
	timingW.FSMC_DataSetupTime = 2;			//���ݽ���ʱ��, WR�͵�ƽ����ʱ��30ns < (DATAST+1)*HCKL, HCLK=13.8ns @72MHz
	timingW.FSMC_BusTurnAroundDuration = 0;
	timingW.FSMC_CLKDivision = 0;
	timingW.FSMC_DataLatency = 0;
	timingW.FSMC_AccessMode = FSMC_AccessMode_A;

	/*
	 LCD configured as follow:
	    - Data/Address MUX = Disable
	    - Memory Type = SRAM
	    - Data Width = 16bit
	    - Write Operation = Enable
	    - Extended Mode = Enable
	    - Asynchronous Wait = Disable
	*/
	init.FSMC_Bank = FSMC_Bank1_NORSRAM2;
	init.FSMC_DataAddressMux = FSMC_DataAddressMux_Disable;
	init.FSMC_MemoryType = FSMC_MemoryType_SRAM;
	init.FSMC_MemoryDataWidth = FSMC_MemoryDataWidth_8b;
	init.FSMC_BurstAccessMode = FSMC_BurstAccessMode_Disable;
	init.FSMC_AsynchronousWait = FSMC_AsynchronousWait_Disable;	/* ע��ɿ��������Ա */
	init.FSMC_WaitSignalPolarity = FSMC_WaitSignalPolarity_Low;
	init.FSMC_WrapMode = FSMC_WrapMode_Disable;
	init.FSMC_WaitSignalActive = FSMC_WaitSignalActive_BeforeWaitState;
	init.FSMC_WriteOperation = FSMC_WriteOperation_Enable;
	init.FSMC_WaitSignal = FSMC_WaitSignal_Disable;
	init.FSMC_ExtendedMode = FSMC_ExtendedMode_Enable;	//��дʱ��ͬFSMC_ExtendedMode_Disable;
	init.FSMC_WriteBurst = FSMC_WriteBurst_Disable;

	init.FSMC_ReadWriteTimingStruct = &timing;
	init.FSMC_WriteTimingStruct = &timingW;

	FSMC_NORSRAMInit(&init);

	/* - BANK 1 (of NOR/SRAM Bank 1~4) is enabled */
	FSMC_NORSRAMCmd(FSMC_Bank1_NORSRAM2, ENABLE);
}

/************************************************************/
/*дҺ����ʾ�ĵ�ַ��y ���У�x ����*/
void LCD_SetAddress(u8 x,u8 y)
{
	u16 row_msb,row_lsb,column,column_msb,column_lsb;
	row_lsb = y&0x0f;
	row_msb = ((y>>4)&0x0f);
	LCD_ILI9342C_CMD(0x60+row_lsb);//�е�ַ��4 λ
	LCD_ILI9342C_CMD(0x70+row_msb);//�е�ַ��4 λ
	column=x+37;
	column_lsb =column&0x0f;
	column_msb =((column>>4)&0x0f);
	LCD_ILI9342C_CMD(0x00+column_lsb);///�е�ַ��4 λ
	LCD_ILI9342C_CMD(0x10+column_msb);//�е�ַ��4 λ
}


/************************************************************/
void clear_screen()
{
	u16 i,j;
	LCD_SetAddress(0,0);
    for(i=0;i<160;i++)
	{
		for(j=0;j<41;j++)
		{
            LCD_ILI9342C_Parameter(0x00);
            LCD_ILI9342C_Parameter(0x00);
		}
	}
}

//============================================================================= 
//�� �� ��: GUI_Point() 
//�� �ܣ�	��ָ��λ���ϻ���
//��ڲ�����  x		ָ���������е�λ��
//            y		ָ���������е�λ��
//            color	��ʾ��ɫ(Ϊ0ʱ��Ϊ1ʱ��ʾ)
//���ڲ����� ��
//�� �� ֵ�� ����ֵΪ1ʱ��ʾ�����ɹ���Ϊ0ʱ��ʾ����ʧ�ܡ�(����ʧ��ԭ����ָ����ַ������
//           Ч��Χ)
//˵��    �� ʹ�ô˺�������ʱ��LCM��ʾ�ͻ���������ͬʱ�ı䣬
//           ���Һ��ģ�鱾���������£��˺�����Ч�ʽϵͣ�ÿ�θ�����Ҫ������ͬʱ����
//============================================================================= 
u8  Lcd_PutPixel(u8 x, u8 y, u8 color)
{ 
    u8 PiontTemp;
    //�������� 
//    if(x>159) return(0);
//    if(y>159) return(0);
//    
    PiontTemp = x / 3;
    
    if(color)
        color = 0xFF;
    else
        color = 0;
    
    LCD_SetAddress(PiontTemp, y);
    
    if(x % 3 == 0)
    {   
        SPoint3_Buf[y][PiontTemp].GPiont = color;
    }
    else if(x % 3 == 1)
    {
        SPoint3_Buf[y][PiontTemp].RPiont = color;
    }
    else if(x % 3 == 2)
    {
        SPoint3_Buf[y][PiontTemp].BPiont = color;
    }
    
    uPiont.SPiont3 = SPoint3_Buf[y][PiontTemp];
    LCD_ILI9342C_Parameter(uPiont.Piont[0]);  				   //��������		
    LCD_ILI9342C_Parameter(uPiont.Piont[1]);  				   //��������
    
   return(1);
}

u8 Lcd_GetPixel(u8 x, u8 y)
{ 
    u8 PiontTemp, Data;
    /*
    //�������� 
    if(x>159) return(0);
    if(y>159) return(0);
    */
    PiontTemp = x / 3;
    
    if(x % 3 == 0)
    {
        Data = SPoint3_Buf[y][PiontTemp].GPiont;
    }
    else if(x % 3 == 1)
    {
        Data = SPoint3_Buf[y][PiontTemp].RPiont;
    }
    else if(x % 3 == 2)
    {
        Data = SPoint3_Buf[y][PiontTemp].BPiont;
    }
   return Data & 0x01;
}
/*
*********************************************************************************************************
*	�� �� ��: LCD_Init
*	����˵��: ��ʼ��LCD
*	��    �Σ���
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void LCD_Init(void)
{
	/* ����LCD���ƿ���GPIO */
	LCD_CtrlLinesConfig();

	/* ����FSMC�ӿڣ��������� */
	LCD_FSMCConfig();

	/* FSMC���ú������ӳٲ��ܷ��������豸  */
	delay(20000);
	
	// ��ʼ��LCD����оƬ
	ILI9342C_TM23_Initial();
    
    clear_screen();
}


