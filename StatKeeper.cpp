// Standard library includes

// Project includes
#include <iostream>
#include "StatKeeper.h"
#include <iomanip>

using namespace std;

// ---------------------------------------------------------------------
// Constructors / Destructors
// ---------------------------------------------------------------------

StatKeeper::StatKeeper(const int start_time, const int end_time)
{
    set_total_sim_time(start_time - end_time);
    set_total_takeoffs(0);
    set_total_landings(0);
    set_total_crashes(0);
    set_total_takeoff_time(0);
    set_total_landing_time(0);
}

StatKeeper::~StatKeeper(void)
{
}

// ---------------------------------------------------------------------
// Accessors
// ---------------------------------------------------------------------

// Gets the total time of simulation.
int StatKeeper::total_sim_time()
{
    return total_sim_time_;
}

// Gets the total amount of takeoffs.
int StatKeeper::total_takeoffs()
{
    return total_takeoffs_;
}

// Gets the total amount of landings.
int StatKeeper::total_landings()
{
    return total_landings_;
}

// Gets the total amount of flights crashing.
int StatKeeper::total_crashes()
{
    return total_crashes_;
}

// Gets the total time spent by planes in takeoff queue
int StatKeeper::total_takeoff_time()
{
    return total_takeoff_time_;
}

// Gets the total time spent by planes in landing queue
int StatKeeper::total_landing_time()
{
    return total_landing_time_;
}

// ---------------------------------------------------------------------
// Mutators
// ---------------------------------------------------------------------

// Sets the total amount of time for simulation.
void StatKeeper::set_total_sim_time(const int total_sim_time)
{
    total_sim_time_ = total_sim_time;
}

// Sets the total amount of takeoffs.
void StatKeeper::set_total_takeoffs(const int total_takeoffs)
{
    total_takeoffs_ = total_takeoffs;
}

// Sets the total amount of landings.
void StatKeeper::set_total_landings(const int total_landings)
{
    total_landings_ = total_landings;
}

// Sets the total amount of flights crashing.
void StatKeeper::set_total_crashes(const int total_crashes)
{
    total_crashes_ = total_crashes;
}

// Sets the total time spent by planes in takeoff queue
void StatKeeper::set_total_takeoff_time(int total_takeoff_time)
{
    total_takeoff_time_ = total_takeoff_time;
}

// Sets the total time spent by planes in landing queue
void StatKeeper::set_total_landing_time(int total_landing_time)
{
    total_landing_time_ = total_landing_time;
}

// ---------------------------------------------------------------------
// Other Member Functions
// ---------------------------------------------------------------------

// TODO: print stats
void StatKeeper::printStats() {
    cout << setw(30) << left << "Total simulation time: " << total_sim_time_ << endl;
    cout << setw(30) << "# of planes that took off: " << total_takeoffs_ << endl;
    cout << setw(30) << "# of planes that landed: " << total_landings_ << endl;
    cout << setw(30) << "# of planes that crashed: " << total_crashes_ << endl;
    float avg_takeoff_time;
    if (total_takeoffs() > 0) {
        avg_takeoff_time = (float)total_takeoff_time_ / (float)total_takeoffs_;
    }
    else avg_takeoff_time = 0;
    float avg_landing_time;
    if (total_landings() > 0) {
        avg_landing_time = (float)total_landing_time_ / (float)total_landings_;
    }
    else avg_landing_time = 0;
    cout << setw(30) << "Average take-off queuing time: " << avg_takeoff_time << endl;
    cout << setw(30) << "Average landing queuing time: " << avg_landing_time << endl;
}
