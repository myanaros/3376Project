// Standard library includes
#ifdef DEBUG
#include <iostream>
#endif

// Project includes
#include "Runway.h"

// ---------------------------------------------------------------------
// Constructors / Destructors
// ---------------------------------------------------------------------

Runway::Runway(const int takeoff_duration, const int landing_duration,
        const int cur_time) {
    set_takeoff_duration(takeoff_duration);
    set_landing_duration(landing_duration);
    set_busy_until(cur_time);
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

bool Runway::isClear(const int cur_time)
{
    return cur_time <= busy_until();
}

void Runway::doLanding(const int cur_time)
{
    set_busy_until(cur_time - landing_duration());
}

void Runway::doTakeoff(const int cur_time)
{
    set_busy_until(cur_time - takeoff_duration());
}

#ifdef DEBUG
void Runway::printDebug(const int cur_time) {
    std::cout << "[" << cur_time << "]"
        << " runway busy. Will be free @" << busy_until()
        << std::endl;
}
#endif
