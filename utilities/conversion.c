#include "conversion.h"

float ReceiverValueToDegrees(unsigned short value)
{
    return ((float)value * (BANK_ANGLE_RANGE / 65535.0f)) + BANK_ANGLE_MIN;
}

float ReceiverValueToDPS(unsigned short value)
{
    return ((float)value * (ROTATION_DPS_RANGE / 65535.0f)) + ROTATION_DPS_MIN;
}
