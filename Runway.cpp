// Standard library includes

// Project includes
#include "Runway.h"

// ---------------------------------------------------------------------
// Constructors / Destructors
// ---------------------------------------------------------------------

Runway::Runway(const int takeoff_duration, const int landing_duration) {
    set_takeoff_duration(takeoff_duration);
    set_landing_duration(landing_duration);
}

// ---------------------------------------------------------------------
// Accessors
// ---------------------------------------------------------------------

int Runway::busy_until()
{
    return busy_until_;
}

int Runway::landing_duration()
{
    return landing_duration_;
}

int Runway::takeoff_duration()
{
    return takeoff_duration_;
}

// ---------------------------------------------------------------------
// Mutators
// ---------------------------------------------------------------------

void Runway::set_busy_until(const int busy_until)
{
    busy_until_ = busy_until;
}

void Runway::set_landing_duration(const int landing_duration)
{
    landing_duration_ = landing_duration;
}

void Runway::set_takeoff_duration(const int takeoff_duration)
{
    takeoff_duration_ = takeoff_duration;
}

// ---------------------------------------------------------------------
// Other Member Functions
// ---------------------------------------------------------------------

// TODO
bool Runway::isClear(const int cur_time)
{
    return false;
}

// TODO
void Runway::doLanding(const int cur_time)
{

}

// TODO
void Runway::doTakeoff(const int cur_time)
{

}
