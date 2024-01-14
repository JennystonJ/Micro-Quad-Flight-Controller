#include "statusLED.h"

void SetRedStatusLED(bool enabled)
{
    RED_STATUS_LED = enabled;
}

void SetGreenStatusLED(bool enabled)
{
    GREEN_STATUS_LED = enabled;
}

void SetBlueStatusLED(bool enabled)
{
    BLUE_STATUS_LED = enabled;
}

void SetYellowStatusLED(bool enabled)
{
    YELLOW_STATUS_LED = enabled;
}

void SetStatusLEDArmed()
{
    ClearStatusLED();
    SetRedStatusLED(true);
}

void SetStatusLEDDisarmed()
{
    ClearStatusLED();
    SetGreenStatusLED(true);
}

void SetStatusLEDWarning()
{
    ClearStatusLED();
    SetYellowStatusLED(true);
}

void ClearStatusLED()
{
    SetRedStatusLED(false);
    SetGreenStatusLED(false);
    SetBlueStatusLED(false);
    SetYellowStatusLED(false);
}