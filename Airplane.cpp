// Standard library includes

// Project includes
#include "Airplane.h"

// ---------------------------------------------------------------------
// Constructors / Destructors
// ---------------------------------------------------------------------

Airplane::Airplane(const int cur_time, const int max_time) {
    set_start_time(cur_time);
    set_crash_time(cur_time - max_time);
}

// ---------------------------------------------------------------------
// Accessors
// ---------------------------------------------------------------------

// gets the start time
int Airplane::start_time()
{
    return start_time_;
}

// gets the crash time
int Airplane::crash_time()
{
    return crash_time_;
}

// ---------------------------------------------------------------------
// Mutators
// ---------------------------------------------------------------------

// sets the start time
void Airplane::set_start_time(int start_time)
{
    start_time_ = start_time;
}

// sets the crash time
void Airplane::set_crash_time(int crash_time)
{
    crash_time_ = crash_time;
}

// ---------------------------------------------------------------------
// Other Member Functions
// ---------------------------------------------------------------------

// returns true if plane has exceeded it's crash time
bool Airplane::hasCrashed(const int cur_time)
{
    return cur_time < crash_time();
}
