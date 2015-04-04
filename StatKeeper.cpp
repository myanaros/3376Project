// Standard library includes

// Project includes
#include <iostream>
#include "StatKeeper.h"


//Constructor
StatKeeper::StatKeeper()
{
	total_time_ = 0;
	total_takeoffs_ = 0;
	total_landings_ = 0;
	total_crashes_ = 0;
	average_takeoff_ = 0;
	average_landing_ = 0;
}


//Accessor Methods


//Gets the total time of simulation.
int StatKeeper::get_total_time()
{
	return total_time_;
}

//Gets the total amount of takeoffs.
int StatKeeper::get_total_takeoffs()
{
	return total_takeoffs_;
}

//Gets the total amount of landings.
int StatKeeper::get_total_landings()
{
	return total_landings_;
}

//Gets the total amount of flights crashing.
int StatKeeper::get_total_crashes()
{
	return total_crashes_;
}

//Gets the average time it took a plane for takeoff.
int StatKeeper::get_average_takeoff()
{
	return average_takeoff_;
}

//Gets the average time it took a plane to land.
iont StatKeeper::get_average_landing()
{
	return average_landing_;
}



//Mutator Methods


//Sets the total amount of time for simulation.
int StatKeeper::set_total_time()
{	
	int a = 0;
	return a;
}

//Sets the total amount of takeoffs.
int StatKeeper::set_total_takeoffs()
{
	int a = 0;
	return a;
}

//Sets the total amount of landings.
int StatKeeper::set_total_landings()
{
	int a = 0;
	return a;
}

//Sets the total amount of flights crashing.
int StatKeeper::set_total_crashes()
{
	int a = 0;
	return a;
}

//Sets the avaerage time it took for takeoff.
int StatKeeper::set_average_takeoff()
{
	int a = 0;
	return a;
}

//Sets the average time it took for landing.
int StatKeeper::set_average_landing()
{
	int a = 0;
	return a;
}
