/**
  ******************************************************************************
  * @文件    weigh.h
  * @作者    zhaoxw
  * @版本    V0.0.0
  * @日期    2017-09-17
  * @概述    Main program body
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
    u16 Sensor;             //脉宽
    u16 Weigh;              //重量
}WEIGH;

extern WEIGH WeightNow[MAX_CHANNEL];                //传感器数值
extern WEIGH WeightEmpty[MAX_CHANNEL];              //空载传感器值
extern WEIGH WeightSet[MAX_CHANNEL];                //设定的报警值
extern WEIGH WeightCalibration[MAX_CHANNEL];        //标定值

extern void WeighInit(void);
#endif /* __WEIGH_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
