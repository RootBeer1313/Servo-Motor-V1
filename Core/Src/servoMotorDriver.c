
#include "servoMotorDriver.h"

TIM_HandleTypeDef * PWM_TIM_HANDLE;

void initServoMotorDriver(TIM_HandleTypeDef* thePWMhandle)
{
    setHandle_PWM_TIM_HANDLE(thePWMhandle);
}


/*
degrees is in units of degrees
*/
int setServoAngle(float degrees, int motorSticker)
{
    float PWMphasePercent;
	//check if angle is possible
    switch(motorSticker){
		case 1:
			if (degrees < 0 || degrees > 180)
			{
				return 1;
			}
			break;
    }

    //convert degrees to PWM width
    PWMphasePercent = degrees*PWM_DEGREE_TO_PERCENT;

    //set PWM output
    // if (setPWMwidth(PWMwidth, motorSticker) == 1)
    //     return 1;
    // else
    //     return 0;
    PWM_setPhasePercent(PWMphasePercent);
    return 0;
}

void setHandle_PWM_TIM_HANDLE(TIM_HandleTypeDef* theHandle)
{

}

TIM_HandleTypeDef* getHandle_PWM_TIM_HANDLE()
{
    return PWM_TIM_HANDLE;
}

void PWM_start()
{
    HAL_TIM_PWM_Start_IT(PWM_TIM_HANDLE, TIM_CHANNEL_1); //TIM_CHANNEL_1 defined in HAL
}

void PWM_stop()
{
    HAL_TIM_PWM_Stop(PWM_TIM_HANDLE, TIM_CHANNEL_1); //TIM_CHANNEL_1 defined in HAL
}

/*
Purpose: automatically converts a percent to the appropriate number of ticks for
         PWM_setPhaseWidth(), then input into PWMphaseWidth().

Input:
    PWMpercent is expected to be a value between 0.00 and 100.00.
*/
void PWM_setPhasePercent(float PWMpercent)
{
    if(PWMpercent > 100 || PWMpercent < 0)
    {
        return;
    }
    uint16_t ticks = PWM_COUNTER_PERIOD*(PWMpercent / 100); //divide by 100 so we get a fraction of PWM_COUNTER_PERIOD
    PWM_setPhaseWidth(ticks);
    return;
}
/*
Purpose: set the phase width to be equal to the input number of ticks given.
*/
void PWM_setPhaseWidth(uint16_t PWMphaseWidth)
{
    __HAL_TIM_SET_COMPARE(PWM_TIM_HANDLE, TIM_CHANNEL_1, PWMphaseWidth);
    return;
}
