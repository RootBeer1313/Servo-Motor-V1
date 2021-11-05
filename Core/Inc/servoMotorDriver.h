#ifndef SERVOMOTORDRIVER_H
#define SERVOMOTORDRIVER_H


// #include whatever_the_stm32_HAL_driver_is_called
#include "stm32f1xx_hal.h"
//0 is no error
//1 is there is an error

//defines
#define PWM_COUNTER_PERIOD (1000)
#define PWM_DEGREE_TO_PERCENT (100/180) //100% = 180deg, 0% = 0deg. 100/180 = conversion constant


//global variables
extern TIM_HandleTypeDef * PWM_TIM_HANDLE;

void initServoMotorDriver(TIM_HandleTypeDef* thePWMhandle);

int setServoAngle(float degrees, int motorSticker);

void setPWMwidth(float PWMwidth, int motorSticker);

void setHandle_PWM_TIM_HANDLE(TIM_HandleTypeDef* theHandle);
TIM_HandleTypeDef* getHandle_PWM_TIM_HANDLE();

void PWM_stop();
void PWM_start();

void PWM_setPhasePercent(float PWMpercent);
void PWM_setPhaseWidth(uint16_t PWMphaseWidth);


#endif
