/**
  ******************************************************************************
  * @�ļ�    weigh.h
  * @����    zhaoxw
  * @�汾    V0.0.0
  * @����    2017-09-17
  * @����    Main program body
  ******************************************************************************
  * @attention
  *
  * 
  *
  ******************************************************************************
  */ 
#ifndef __WEIGH_H
#define __WEIGH_H

#include "stm32f10x.h"

#define MAX_CHANNEL             8

typedef struct
{
    u16 Sensor;             //����
    u16 Weigh;              //����
}WEIGH;

extern WEIGH WeightNow[MAX_CHANNEL];                //��������ֵ
extern WEIGH WeightEmpty[MAX_CHANNEL];              //���ش�����ֵ
extern WEIGH WeightSet[MAX_CHANNEL];                //�趨�ı���ֵ
extern WEIGH WeightCalibration[MAX_CHANNEL];        //�궨ֵ

extern void WeighInit(void);
#endif /* __WEIGH_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
