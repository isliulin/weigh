/******************************************************************************
* �� �� ��:
* ��    ��:zhaoxw
* ��������:
* ��    ��:0
* ��    ��:
* 
* History
*   1. Date: 2017/02/07   Author: Zhaoxw      Modification: build this moudle 
*   2. ... 
******************************************************************************/
#include "key.h"

__IO u8  KeyValue = 0;
__IO u32 KeyTimer = 0;

/******************************************************************************
* ��    ��:
* ��    ��:��ȡ����
* ��ڲ���:
* ���ڲ���:
******************************************************************************/
//void KeyInit(void)
//{
//    KeyValue = KEY_NULL;
//}

/*******************************************************************************
*��    ��: 
*��    ��: ��ȡ��ֵ
*��ڲ���: 
*���ڲ���: 
*˵    ��: 
*******************************************************************************/
void GetKeyValue(void)
{
    static unsigned char KeyTemp = 0;
	static unsigned char KeyFsm = 0;
    static uint32_t StartKeyTimer = 0;
	
    KeyTimer = GetSysTimer();
    
	switch(KeyFsm)
	{
	    case 0:
	        if(KEY_PORT)//�м�ֵ��
	        {
	            KeyFsm++;
                StartKeyTimer = KeyTimer;
	        }
	        break;
	    case 1:
	        if(KeyTimer >= (StartKeyTimer + KEY_DELAY_PERIOD))  //����
	        {
    	        KeyFsm++;
	            StartKeyTimer = KeyTimer;
	            if(KEY_PORT)
    		    {
        		    KeyTemp = (u8)(KEY_PORT);
        		    KeyValue = KeyTemp | KEY_PRESS;
        		}
        		else
        		{
            		KeyFsm = 0;
            		KeyValue = KEY_NULL;
        		}
	        }
	        break;
	    case 2://ִ�й�һ��
	        KeyFsm++;
	        KeyValue = KeyTemp & KEY_IDLE;                      //�������״̬
	        break;
	    case 3:
	        if(KEY_PORT == (KeyValue & 0x0F))                   //��������
    		{
    	        if(KeyTimer >= (StartKeyTimer + KEY_LONG_PERIOD))
    	        {
        		    KeyFsm++;
	                StartKeyTimer = KeyTimer;
	                KeyValue = KeyTemp | KEY_LONG;
        		}
	        }
	        else
	        {
	            KeyFsm = 0;
	            KeyValue = KEY_NULL;
	        }
	        break;
	    case 4://ִ�й�һ��
	        KeyFsm++;
	        KeyValue = KeyTemp & KEY_IDLE;
	        break;
	    case 5:
	        if(KEY_PORT)
    		{
    	        if(KeyTimer >= (StartKeyTimer + KEY_CONTINUE_PERIOD))
    	        {
        		    KeyFsm++;
	                StartKeyTimer = KeyTimer;
	                KeyValue = KeyTemp | KEY_CONTINUE;
        		}
	        }
	        else
	        {
	            KeyFsm = 0;
	            KeyValue = KEY_NULL;
	        }
	        break;
	    case 6://ִ�й�һ��
	        KeyFsm--;
	        KeyValue = KeyTemp & KEY_IDLE;
	        break;
	}
}
