// Standard library includes

// Project includes
#include "Airplane.h"

void Airplane::set_start_time(int start_in)
{
    start_time_ = start_in;
}

int Airplane::get_start_time()
{
    return start_time_;
}

void Airplane::set_crash_time(int crash_in)
{
    crash_time_ = crash_in;
}

int Airplane::get_crash_time()
{
    return crash_time_;
}

//TODO
bool Airplane::hasCrashed()
{
    return false;
}
