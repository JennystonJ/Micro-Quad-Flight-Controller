#include "flightMode.h"

static FlightMode m_FlightMode = RATE_MODE;

FlightMode GetFlightMode()
{
    return m_FlightMode;
}

void SetFlightMode(FlightMode flightMode)
{
    m_FlightMode = flightMode;
}