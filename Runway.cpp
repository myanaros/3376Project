// Standard library includes

// Project includes
#include "Runway.h"

int Runway::get_landing_duration()
{
    return landing_duration_;
}

void Runway::set_landing_duration(int landing_in)
{
    landing_duration_ = landing_in;
}

int Runway::get_takeoff_duration_()
{
    return takeoff_duration_;
}

void Runway::set_takeoff_duration_(int takeoff_in)
{
    takeoff_duration_ = takeoff_in;
}

int Runway::get_busy_until()
{
    return busy_until_;
}

void Runway::set_busy_until(int busy_in)
{
    busy_until_ = busy_in;
}

//TODO
bool Runway::isClear()
{
    return false;
}

//TODO
void Runway::doLanding()
{

}

//TODO
void Runway::doTakeoff()
{

}
