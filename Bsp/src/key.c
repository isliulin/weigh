/******************************************************************************
* 文 件 名:
* 作    者:zhaoxw
* 创建日期:
* 版    本:0
* 描    述:
* 
* History
*   1. Date: 2017/02/07   Author: Zhaoxw      Modification: build this moudle 
*   2. ... 
******************************************************************************/
#include "key.h"

__IO u8  KeyValue = 0;
__IO u32 KeyTimer = 0;

/******************************************************************************
* 名    称:
* 功    能:获取按键
* 入口参数:
* 出口参数:
******************************************************************************/
//void KeyInit(void)
//{
//    KeyValue = KEY_NULL;
//}

/*******************************************************************************
*名    称: 
*功    能: 获取键值
*入口参数: 
*出口参数: 
*说    明: 
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
	        if(KEY_PORT)//有键值？
	        {
	            KeyFsm++;
                StartKeyTimer = KeyTimer;
	        }
	        break;
	    case 1:
	        if(KeyTimer >= (StartKeyTimer + KEY_DELAY_PERIOD))  //消抖
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
	    case 2://执行过一次
	        KeyFsm++;
	        KeyValue = KeyTemp & KEY_IDLE;                      //清除附加状态
	        break;
	    case 3:
	        if(KEY_PORT == (KeyValue & 0x0F))                   //继续按下
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
	    case 4://执行过一次
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
	    case 6://执行过一次
	        KeyFsm--;
	        KeyValue = KeyTemp & KEY_IDLE;
	        break;
	}
}
