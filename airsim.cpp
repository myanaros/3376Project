#define PRINTVAR(x) std::cout << "DEBUG: " << #x << ": " << x << std::endl

// Standard library headers
#include <iostream>
#include <string>
#include <cstdlib>
#include <unistd.h>

// Project headers
#include "Airplane.h"
#include "BoolSource.h"
#include "Queue.h"
#include "Runway.h"
#include "StatKeeper.h"

int main(int argc, char *argv[]) {
    srand(time(NULL));

    if (argc < 8)
    {
        std::cout << "Not enough arguments passed. Needs 7 arguments. "
            << "Terminating simulation.\n";
        return 1;
    }
    if (argc > 8)
    {
        std::cout << "Too many arguments. Requires 7 arguments. "
            << "Terminating simulation. \n";
        return 1;
    }

    int time_to_land;
    int time_for_takeoff;
    double plane_enter_landing;
    double plane_enter_takeoff;
    int start_time;
    int end_time;
    int crash_time;
    

    time_to_land = atoi(argv[1]);
    time_for_takeoff = atoi(argv[2]);
    plane_enter_landing = atof(argv[3]);
    plane_enter_takeoff = atof(argv[4]);
    start_time = atoi(argv[5]);
    end_time = atoi(argv[6]);
    crash_time = atoi(argv[7]);

    Queue takeoff_queue;
    Queue landing_queue;
    StatKeeper stats(start_time, end_time);
    BoolSource if_land(plane_enter_landing);
    BoolSource if_takeoff(plane_enter_takeoff);
    Runway runway(time_for_takeoff, time_to_land, start_time);

    int currentMinute;
    for(currentMinute = start_time; currentMinute > end_time; --currentMinute)
    {
        if(if_land.shouldAddToQueue() == true) {
            landing_queue.push_back(Airplane(currentMinute, crash_time));
#ifdef DEBUG
            Airplane &tmp = landing_queue.back();
            tmp.printDebug(currentMinute, DBG_LREQ);
#endif
        }

        if(if_takeoff.shouldAddToQueue() == true) {
            takeoff_queue.push_back(Airplane(currentMinute, crash_time));
#ifdef DEBUG
            Airplane &tmp = landing_queue.back();
            tmp.printDebug(currentMinute, DBG_TREQ);
#endif
        }

        if (runway.isClear(currentMinute))
        {
            while (!landing_queue.empty()
                && landing_queue.front().hasCrashed(currentMinute)) {
                Airplane &tmp = landing_queue.front();
#ifdef DEBUG
                tmp.printDebug(currentMinute, DBG_CRASH);
#endif
                stats.incCrashes();
                stats.incLandingQueueTime(tmp.lifeSpan(currentMinute));
                landing_queue.pop_front();
            }
            if(!(landing_queue.empty()))
            {
                Airplane &tmp = landing_queue.front();
#ifdef DEBUG
                tmp.printDebug(currentMinute, DBG_LAND);
#endif
                stats.incLandingQueueTime(tmp.lifeSpan(currentMinute));
                stats.incLandings();
                runway.doLanding(currentMinute);
                landing_queue.pop_front();
            }
            if(!takeoff_queue.empty())
            {
                Airplane &tmp = takeoff_queue.front();
#ifdef DEBUG
                tmp.printDebug(currentMinute, DBG_TOFF);
#endif
                stats.incTakeoffQueueTime(tmp.lifeSpan(currentMinute));
                stats.incTakeoffs();
                runway.doTakeoff(currentMinute);
                takeoff_queue.pop_front();
            }
        }    
#ifdef DEBUG
        runway.printDebug(currentMinute);
#endif
    }

    
    while(!landing_queue.empty()
            && landing_queue.front().hasCrashed(currentMinute))
    {
        Airplane &tmp = landing_queue.front();
        stats.incCrashes();
        stats.incLandingQueueTime(tmp.lifeSpan(currentMinute));
        landing_queue.pop_front();
    }
    // TODO:
    // Queuing time stats don't reflect planes still in the queues when
    // the simulation ends. Making this work will require making some
    // changes to the design of StatTracker.
    stats.printStats();

    return 0;
}
