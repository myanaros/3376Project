// Standard library includes

// Project includes
#include <iostream>
#include "StatKeeper.h"

// ---------------------------------------------------------------------
// Constructors / Destructors
// ---------------------------------------------------------------------

StatKeeper::StatKeeper(const int start_time, const int end_time)
{
	set_total_sim_time(end_time - start_time);
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
    std::cout << "Total simulation time: " << total_sim_time_ << std::endl;
    std::cout << "# of planes that took off: " << total_takeoffs_ << std::endl;
    std::cout << "# of planes that landed: " << total_landings_ << std::endl;
    std::cout << "# of planes that crashed: " << total_crashes_ << std::endl;
    float avg_takeoff_time = (float)total_takeoff_time_ / (float)total_takeoffs_;
    float avg_landing_time = (float)total_landing_time_ / (float)total_landings_;
    std::cout << "Average take-off time: " << avg_takeoff_time << std::endl;
    std::cout << "Average landing time: " << avg_landing_time << std::endl;
}
