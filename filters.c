#include "filters.h"

float ComputeComplementaryAngle(float currentAngle, float gyroRate,
        float accelAngle, float dt)
{
    return GYRO_PERCENT*(currentAngle + gyroRate*dt) +
        ACCEL_PERCENT*accelAngle;
}