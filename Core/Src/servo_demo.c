#include "servoMotorDriver.h"

#define ONE_THOUSAND_MILLISECONDS (1000)
#define ONE_SECOND ONE_THOUSAND_MILLISECONDS

void servo_demo(TIM_HandleTypeDef* thePWMhandle)
{
    initServoMotorDriver(thePWMhandle);

    for(int i = 0; i<=36; ++i)
    {
        HAL_Delay(ONE_SECOND);
        setServoAngle(i*10, 1);
    }

}


void PWM_delay(int milliseconds)
{
    HAL_Delay(milliseconds);
}
