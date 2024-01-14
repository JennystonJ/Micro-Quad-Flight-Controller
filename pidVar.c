#include "pidVar.h"

static PIDVar pidVar[NUM_PID];

void InitPIDVar()
{
    for(unsigned int i = 0; i < NUM_PID; i++)
    {
        pidVar[i].integral = 0;
        pidVar[i].preError = 0;
    }
    
    pidVar[PITCH].kP = DEFAULT_KP;
    pidVar[PITCH].kI = DEFAULT_KI;
    pidVar[PITCH].kD = DEFAULT_KD;
    
    pidVar[ROLL].kP = DEFAULT_KP;
    pidVar[ROLL].kI = DEFAULT_KI;
    pidVar[ROLL].kD = DEFAULT_KD;

    pidVar[YAW].kP = DEFAULT_KP;
    pidVar[YAW].kI = DEFAULT_KI;
    pidVar[YAW].kD = DEFAULT_KD;
    
    pidVar[PITCH_ANGLE].kP = DEFAULT_ANGLE_KP;
    pidVar[PITCH_ANGLE].kI = DEFAULT_ANGLE_KI;
    pidVar[PITCH_ANGLE].kD = DEFAULT_ANGLE_KD;
    
    pidVar[ROLL_ANGLE].kP = DEFAULT_ANGLE_KP;
    pidVar[ROLL_ANGLE].kI = DEFAULT_ANGLE_KI;
    pidVar[ROLL_ANGLE].kD = DEFAULT_ANGLE_KD;

}

void SetPIDVar(PIDVar pid, unsigned int axis)
{
    pidVar[axis] = pid;
}

void SetKP(float kP, unsigned int axis)
{
    pidVar[axis].kP = kP;
}

void SetKI(float kI, unsigned int axis)
{
    pidVar[axis].kI = kI;
}

void SetKD(float kD, unsigned int axis)
{
    pidVar[axis].kD = kD;
}

PIDVar GetPIDVar(unsigned int axis)
{
    return pidVar[axis];
}

PIDVar *GetPIDVarPtr(unsigned int axis)
{
    return &(pidVar[axis]);
}

float GetKP(unsigned int axis)
{
    return pidVar[axis].kP;
}

float GetKI(unsigned int axis)
{
    return pidVar[axis].kI;
}

float GetKD(unsigned int axis)
{
    return pidVar[axis].kD;
}

void ResetPIDVarIntegral(unsigned int axis)
{
    pidVar[axis].integral = 0;
}