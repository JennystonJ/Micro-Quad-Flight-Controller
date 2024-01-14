#include "vbatt.h"
#include "adc.h"

void InitVBatt()
{
    InitADC();
}

void InitLowVBattInterupt(float cutOffVoltage)
{
    
}

void MeasureVBatt()
{
    
}

float GetVBatt()
{
    return 2.048f * (GetADCResult()/1023.0f) * 3;
}
