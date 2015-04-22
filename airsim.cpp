// Standard library headers

// Project headers
#include "Airplane.h"
#include "BoolSource.h"
#include "Queue.h"
#include "Runway.h"
#include "StatKeeper.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char *argv[]) {
    //Needed to seed rand() calls at the beginning of the program.
    srand(time(NULL));

    if (argc < 8)
    {
        std::cout << "Not enough arguments passed. Needs 7 arguments. Terminating simulation.\n";
        return 1;
    }
    if (argc > 8)
    {
        std::cout << "Too many arguments. Requires 7 arguments. Terminating simulation. \n";
        return 1;
    }
    int time_to_land;
    int time_for_takeoff;
    double plane_enter_landing;
    double plane_enter_takeoff;
    int start_time;
    int end_time;
    int crash_time;
    for (int i = 1; i <= argc; i++)
    {
        if(i==1)
        time_to_land = atoi(argv[i]);
        else if (i==2)
        time_for_takeoff = atoi(argv[i]);
        else if (i==3)
        plane_enter_landing = atof(argv[i]);
        else if (i==4)
        plane_enter_takeoff = atof(argv[i]);
        else if (i==5)
        start_time = atoi(argv[i]);
        else if (i==6)
        end_time = atoi(argv[i]);
        else if (i==7)
        crash_time = atoi(argv[i]);
    }

    Queue takeoff_queue;
    Queue landing_queue;
    StatKeeper stats(start_time, end_time);
    BoolSource if_land(plane_enter_landing);
    BoolSource if_takeoff(plane_enter_takeoff);
    Runway runway(time_for_takeoff, time_to_land, start_time);
    int currentMinute;
    for(currentMinute = start_time; currentMinute > end_time; --currentMinute)
    {
        if(if_land.shouldAddToQueue() == true)
        landing_queue.push_back(Airplane(currentMinute, crash_time));

        if(if_takeoff.shouldAddToQueue() == true)
        takeoff_queue.push_back(Airplane(currentMinute, crash_time));

        if (runway.isClear(currentMinute))
        {
            if(!(landing_queue.empty()))
            {
                Airplane &tmp = landing_queue.front();
                stats.set_total_landing_time(stats.total_landing_time() + tmp.start_time() - currentMinute);
                if(tmp.hasCrashed(currentMinute))
                {
                    stats.set_total_crashes(stats.total_crashes() + 1);
                }
                else
                {
                    stats.set_total_landings(stats.total_landings() + 1);
                    runway.doLanding(currentMinute);
                }
                landing_queue.pop_front();
            }
            else if(!(takeoff_queue.empty()))
            {
                Airplane &tmp = takeoff_queue.front();
                stats.set_total_takeoff_time(stats.total_takeoff_time() + tmp.start_time() - currentMinute);
                stats.set_total_takeoffs(stats.total_takeoffs() + 1);
                runway.doTakeoff(currentMinute);
                takeoff_queue.pop_front();
            }
        
        }    
    }

    
    while(!landing_queue.empty() && landing_queue.front().hasCrashed(currentMinute))
    {
        Airplane &tmp = landing_queue.front();
        stats.set_total_crashes(stats.total_crashes()+1);
        stats.set_total_landing_time(stats.total_landing_time() + tmp.start_time() - currentMinute);
        landing_queue.pop_front();
    }
    stats.printStats();


    return 0;
}
