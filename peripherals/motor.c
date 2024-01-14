#include "motor.h"
#include "pwm.h"

static unsigned short motorOutput[NUM_MOTORS];

void InitMotor(int motor)
{
    InitPWM(motor);
    SetPWMDutyCycle(0, motor);
    motorOutput[motor] = 0;
}

void SetMotorPower(unsigned short power, int motor)
{
    //scale power down (for debugging)
    //power = (unsigned short)(((double)power) * 0.8);
    
    SetPWMDutyCycle(power, motor);
    motorOutput[motor] = power;
}

unsigned int GetMotorPower(int motor)
{
    return motorOutput[motor];
}
