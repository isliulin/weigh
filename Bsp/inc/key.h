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
#ifndef __KEY_H
#define __KEY_H

#include "stm32f10x.h"
#include "bsp.h"

//�жϱ�־
#define     KEY_CLS_FLAG        0x00U
#define     KEY_REMOTE_FLAG     0x55U
#define     KEY_LOCAL_FLAG      0xAAU

//��������
 
#define     KEY_0        	    0x01U
#define     KEY_1         	    0x02U
#define     KEY_2               0x04U
#define     KEY_NULL            0x00U

//��״̬ʱ��
#define     KEY_DELAY_PERIOD    10       //20 * 1ms = 20ms
#define     KEY_LONG_PERIOD     1500     //2s
#define     KEY_CONTINUE_PERIOD 500      //1s 10��

//�ӿ�
#define     KEY_PORT       		(GPIOC->IDR & 0x0007)


//���尴������ֵ״̬(����,����,��_��,�ͷ�)
#define     KEY_IDLE            0x07U
#define     KEY_PRESS           0x10U
#define     KEY_LONG           	0x20U
#define     KEY_CONTINUE       	0x40U
#define     KEY_FREE            0x80U        //���尴��״̬

typedef enum 
{
	KEY_STATE_INIT,
	KEY_STATE_WOBBLE,
	KEY_STATE_PRESS,
	KEY_STATE_LONG,
	KEY_STATE_CONTINUE,
	KEY_STATE_RELEASE
}KEY_STATE;

extern __IO u8 KeyValue;

extern void KeyInit(void);
extern void GetKeyValue(void);

#endif /* __KEY_H */

