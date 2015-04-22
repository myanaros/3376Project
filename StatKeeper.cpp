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
    set_sim_time(start_time - end_time);
    set_takeoffs(0);
    set_landings(0);
    set_crashes(0);
    set_takeoff_queue_time(0);
    set_landing_queue_time(0);
}

StatKeeper::~StatKeeper(void)
{
}

// ---------------------------------------------------------------------
// Accessors
// ---------------------------------------------------------------------

// Gets the total time of simulation.
int StatKeeper::sim_time()
{
    return sim_time_;
}

// Gets the total amount of takeoffs.
int StatKeeper::takeoffs()
{
    return takeoffs_;
}

// Gets the total amount of landings.
int StatKeeper::landings()
{
    return landings_;
}

// Gets the total amount of flights crashing.
int StatKeeper::crashes()
{
    return crashes_;
}

// Gets the total time spent by planes in takeoff queue
int StatKeeper::takeoff_queue_time()
{
    return takeoff_queue_time_;
}

// Gets the total time spent by planes in landing queue
int StatKeeper::landing_queue_time()
{
    return landing_queue_time_;
}

// ---------------------------------------------------------------------
// Mutators
// ---------------------------------------------------------------------

// Sets the total amount of time for simulation.
void StatKeeper::set_sim_time(const int sim_time)
{
    sim_time_ = sim_time;
}

// Sets the total amount of takeoffs.
void StatKeeper::set_takeoffs(const int takeoffs)
{
    takeoffs_ = takeoffs;
}

// Sets the total amount of landings.
void StatKeeper::set_landings(const int landings)
{
    landings_ = landings;
}

// Sets the total amount of flights crashing.
void StatKeeper::set_crashes(const int crashes)
{
    crashes_ = crashes;
}

// Sets the total time spent by planes in takeoff queue
void StatKeeper::set_takeoff_queue_time(int takeoff_queue_time)
{
    takeoff_queue_time_ = takeoff_queue_time;
}

// Sets the total time spent by planes in landing queue
void StatKeeper::set_landing_queue_time(int landing_queue_time)
{
    landing_queue_time_ = landing_queue_time;
}

// ---------------------------------------------------------------------
// Other Member Functions
// ---------------------------------------------------------------------

void StatKeeper::incCrashes(const int amt) {
    set_crashes(crashes() + amt);
}

void StatKeeper::incLandings(const int amt) {
    set_landings(landings() + amt);
}

void StatKeeper::incTakeoffs(const int amt) {
    set_takeoffs(takeoffs() + amt);
}

void StatKeeper::incLandingQueueTime(const int amt) {
    set_landing_queue_time(landing_queue_time() + amt);
}

void StatKeeper::incTakeoffQueueTime(const int amt) {
    set_takeoff_queue_time(takeoff_queue_time() + amt);
}

void StatKeeper::printStats() {
    cout << setw(30) << left << "Total simulation time: " << sim_time() << endl;
    cout << setw(30) << "# of planes that took off: " << takeoffs() << endl;
    cout << setw(30) << "# of planes that landed: " << landings() << endl;
    cout << setw(30) << "# of planes that crashed: " << crashes() << endl;
    float avg_takeoff_queue_time;
    if (takeoffs() > 0) {
        avg_takeoff_queue_time = (float)takeoff_queue_time() / (float)takeoffs();
    }
    else avg_takeoff_queue_time = 0;
    float avg_landing_queue_time;
    if (landings() > 0) {
        avg_landing_queue_time = (float)landing_queue_time() / (float)landings();
    }
    else avg_landing_queue_time = 0;
    cout << setw(30) << "Average take-off queuing time: " << avg_takeoff_queue_time << endl;
    cout << setw(30) << "Average landing queuing time: " << avg_landing_queue_time << endl;
}
