// Standard library includes
#ifdef DEBUG
#include <iostream>
#endif

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

// returns the duration the plane has existed
int Airplane::lifeSpan(const int cur_time) {
    return start_time() - cur_time;
}

#ifdef DEBUG
void Airplane::printDebug(const int cur_time, const planeDebugType dtype) {
    std::cout << "[" << cur_time << "]";
    switch (dtype) {
    case DBG_LREQ:   
        std::cout << " new landing req: will crash @" << crash_time();
        break;
    case DBG_TREQ:   
        std::cout << " new takeoff req";
        break;
    case DBG_LAND:
        std::cout << " landed plane: entered @" << start_time()
            << ", would crash @" << crash_time();
        break;
    case DBG_TOFF:
        std::cout << " plane takeoff: entered @" << start_time();
        break;
    case DBG_CRASH:
        std::cout << " found crashed plane: entered @" << start_time()
            << ", crashed @" << crash_time();
        break;
    }
    std::cout << std::endl;
}
#endif
