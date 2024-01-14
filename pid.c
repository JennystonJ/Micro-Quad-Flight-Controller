#include "pid.h"

//forward routine declarations
float Abs(float x);

//public
float ComputePID(float setPoint, float actualPosition, PIDVar *pidVar)
{
    float error;
    float derivative;
    float output;
    
    //calculate P, I, D
    error = setPoint - actualPosition;
    
    //stop integration if error is too small
    if(Abs(error) > EPSILON)
    {
        pidVar->integral = pidVar->integral + error*DT;
    }
    
    if(pidVar->integral > I_MAX)
    {
        pidVar->integral = I_MAX;
    }
    else if(pidVar->integral < I_MIN)
    {
        pidVar->integral = I_MIN;
    }
    
    derivative = (error - pidVar->preError)/DT;
    output = (pidVar->kP)*error + (pidVar->kI)*(pidVar->integral) +
            (pidVar->kD)*derivative;
    
    //saturation filter
    if(output > MAX)
    {
        output = MAX;
    }
    else if(output < MIN)
    {
        output = MIN;
    }
    
    //update error
    pidVar->preError = error;
    
    return output;
    
}

//private
float Abs(float x)
{
    if(x < 0)
    {
        return x*-1;
    }
    else
    {
        return x;
    }
}