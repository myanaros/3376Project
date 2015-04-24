// Standard library includes
#include <iomanip>
#include <iostream>

// Project includes
#include "StatKeeper.h"

using namespace std;

// ---------------------------------------------------------------------
// Constructors / Destructors
// ---------------------------------------------------------------------

StatKeeper::StatKeeper(const int start_time, const int end_time)
{
    set_sim_time(start_time - end_time);
    set_takeoffs(0);
    set_landings(0);
    set_takeoff_reqs(0);
    set_landing_reqs(0);
    set_remaining_landing_reqs(0);
    set_remaining_takeoff_reqs(0);
    set_crashes(0);
    set_takeoff_queue_time(0);
    set_landing_queue_time(0);
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

// Gets the total amount of landing requests.
int StatKeeper::landing_reqs() {
    return landing_reqs_;
}

// Gets the total amount of takeoff requests.
int StatKeeper::takeoff_reqs() {
    return takeoff_reqs_;
}

// Gets the number of planes remaining in the landing queue when the
// simulation has ended.
int StatKeeper::remaining_landing_reqs() {
    return remaining_landing_reqs_;
}

// Gets the number of planes remaining in the takeoff queue when the
// simulation has ended.
int StatKeeper::remaining_takeoff_reqs() {
    return remaining_takeoff_reqs_;
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

// Sets the total amount of landing requests.
void StatKeeper::set_landing_reqs(const int landing_reqs) {
    landing_reqs_ = landing_reqs;
}

// Sets the total amount of takeoff requests.
void StatKeeper::set_takeoff_reqs(const int takeoff_reqs) {
    takeoff_reqs_ = takeoff_reqs;
}

// Sets the total amount of landing requests remaining in the landing queue
// after the simulation has ended
void StatKeeper::set_remaining_landing_reqs(const int remaining_landing_reqs) {
    remaining_landing_reqs_ = remaining_landing_reqs;
}

// Sets the total amount of takeoff requests remaining in the takeoff queue
// after the simulation has ended
void StatKeeper::set_remaining_takeoff_reqs(const int remaining_takeoff_reqs) {
    remaining_takeoff_reqs_ = remaining_takeoff_reqs;
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

// Increments the number of crashes (default by 1)
void StatKeeper::incCrashes(const int amt) {
    set_crashes(crashes() + amt);
}

// Increments the number of landings (default by 1)
void StatKeeper::incLandings(const int amt) {
    set_landings(landings() + amt);
}

// Increments the number of takeoffs (default by 1)
void StatKeeper::incTakeoffs(const int amt) {
    set_takeoffs(takeoffs() + amt);
}

// Increments the number of landing requests (default by 1)
void StatKeeper::incLandingReqs(const int amt) {
    set_landing_reqs(landing_reqs() + amt);
}

// Increments the number of takeoff requests (default by 1)
void StatKeeper::incTakeoffReqs(const int amt) {
    set_takeoff_reqs(takeoff_reqs() + amt);
}

// Increments the number of landing requests remaining in the landing queue
// at the end of the simulation (default by 1)
void StatKeeper::incRemainingLandingReqs(const int amt) {
    set_remaining_landing_reqs(remaining_landing_reqs() + amt);
}

// Increments the number of takeoff requests remaining in the takeoff queue
// at the end of the simulation (default by 1)
void StatKeeper::incRemainingTakeoffReqs(const int amt) {
    set_remaining_takeoff_reqs(remaining_takeoff_reqs() + amt);
}

// Increments the amount of time spent by planes in the landing queue 
// by the specified amount
void StatKeeper::incLandingQueueTime(const int amt) {
    set_landing_queue_time(landing_queue_time() + amt);
}

// Increments the amount of time spent by planes in the takeoff queue 
// by the specified amount
void StatKeeper::incTakeoffQueueTime(const int amt) {
    set_takeoff_queue_time(takeoff_queue_time() + amt);
}


// Prints detailed statistics about the simulation
void StatKeeper::printStats() {
    float avg_takeoff_queue_time;
    if (takeoffs() > 0) {
        avg_takeoff_queue_time =
            (float)takeoff_queue_time() / (float)takeoff_reqs();
    }
    else {
        avg_takeoff_queue_time = 0;
    }

    float avg_landing_queue_time;
    if (landings() > 0) {
        avg_landing_queue_time =
            (float)landing_queue_time() / (float)landing_reqs();
    }
    else {
        avg_landing_queue_time = 0;
    }

    cout << setw(45) << left
        << "Total simulation time:"
        << setw(8) << right << sim_time() << endl;
    cout << setw(45) << left
        << "Total number of planes:"
        << setw(8) << right << takeoff_reqs() + landing_reqs() << endl;
    cout << setw(45) << left
        << "Number of planes that took off:"
        << setw(8) << right << takeoffs() << endl;
    cout << setw(45) << left
        << "Number of planes that landed:"
        << setw(8) << right << landings() << endl;
    cout << setw(45) << left
        << "Number of planes that crashed:"
        << setw(8) << right << crashes() << endl;
    cout << setw(45) << left
        << "Number of planes remaining in landing queue:"
        << setw(8) << right << remaining_landing_reqs() << endl;
    cout << setw(45) << left
        << "Number of planes remaining in takeoff queue:"
        << setw(8) << right << remaining_takeoff_reqs() << endl;
    cout << setw(45) << left
        << "Average take-off queuing time:"
        << setw(8) << right << fixed << setprecision(2)
        << avg_takeoff_queue_time << endl;
    cout << setw(45) << left
        << "Average landing queuing time:"
        << setw(8) << right << fixed << setprecision(2)
        << avg_landing_queue_time << endl;
}
