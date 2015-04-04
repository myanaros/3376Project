// Standard library includes

// Project includes
#include "Airplane.h"

//sets the start time
void Airplane::set_start_time(int start_in)
{
    start_time_ = start_in;
}

//gets the start time
int Airplane::get_start_time()
{
    return start_time_;
}

//sets the crash time
void Airplane::set_crash_time(int crash_in)
{
    crash_time_ = crash_in;
}

//gets the crash time
int Airplane::get_crash_time()
{
    return crash_time_;
}

//TODO determines whether or not the plane has crashed
bool Airplane::hasCrashed()
{
    return false;
}
