// Standard library headers
#include <iomanip>
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

void printUsage(const char *const progName);

int main(int argc, char *argv[]) {
    if (argc < 8)
    {
        std::cout << "Insufficient arguments." << std::endl;
        printUsage(argv[0]);
        return 1;
    }
    if (argc > 8)
    {
        std::cout << "Excessive arguments." << std::endl;
        printUsage(argv[0]);
        return 1;
    }

    // Parse arguments
    int landDuration = atoi(argv[1]);
    int toffDuration = atoi(argv[2]);
    double probLand = atof(argv[3]);
    double probToff = atof(argv[4]);
    int startTime = atoi(argv[5]);
    int endTime = atoi(argv[6]);
    int ttl = atoi(argv[7]);

    // Initialize objects
    Queue toffQueue, landQueue;
    StatKeeper stats(startTime, endTime);
    BoolSource
        landSource(probLand),
        toffSource(probToff);
    Runway runway(toffDuration, landDuration, startTime);

    // Time loop
    int t;
    for(t = startTime; t > endTime; t--)
    {
        // Check if we should add a plane to the landing queue
        if(landSource.decide()) {
            landQueue.push_back(Airplane(t, ttl));
            stats.incLandingReqs();
#ifdef DEBUG
            Airplane &plane = landQueue.back();
            plane.printDebug(t, DBG_LREQ);
#endif
        }

        // Check if we should add a plane to the takeoff queue
        if(toffSource.decide()) {
            toffQueue.push_back(Airplane(t, ttl));
            stats.incTakeoffReqs();
#ifdef DEBUG
            Airplane &plane = landQueue.back();
            plane.printDebug(t, DBG_TREQ);
#endif
        }

        // If the runway isn't busy...
        if (runway.isClear(t))
        {
            // Seek from the front of the landing queue, discarding crashed
            // planes until we either empty the queue or find an uncrashed
            // plane.
            while (!landQueue.empty()
                && landQueue.front().hasCrashed(t))
            {
                Airplane &plane = landQueue.front();
#ifdef DEBUG
                plane.printDebug(t, DBG_CRASH);
#endif
                stats.incCrashes();
                stats.incLandingQueueTime(plane.lifeSpan(t));
                landQueue.pop_front();
            }

            // if there are uncrashed planes in the landing queue, land one.
            if(!(landQueue.empty()))
            {
                Airplane &plane = landQueue.front();
#ifdef DEBUG
                plane.printDebug(t, DBG_LAND);
#endif
                stats.incLandingQueueTime(plane.lifeSpan(t));
                stats.incLandings();
                runway.doLanding(t);
                landQueue.pop_front();
            }

            // otherwise, if there are planes in the takeoff queue, let one
            // takeoff.
            else if(!toffQueue.empty())
            {
                Airplane &plane = toffQueue.front();
#ifdef DEBUG
                plane.printDebug(t, DBG_TOFF);
#endif
                stats.incTakeoffQueueTime(plane.lifeSpan(t));
                stats.incTakeoffs();
                runway.doTakeoff(t);
                toffQueue.pop_front();
            }
        }    
        // Runway is busy. Nothing to do this tick.
#ifdef DEBUG
        runway.printDebug(t);
#endif
    }

    // After the simulation, empty the landing queue, updating StatKeeper
    // with whatever you find there.
    while(!landQueue.empty()) {
        Airplane &plane = landQueue.front();
        if (plane.hasCrashed(t)) {
            stats.incCrashes();
        }
        else {
            stats.incRemainingLandingReqs();
        }
        stats.incLandingQueueTime(plane.lifeSpan(t));
        landQueue.pop_front();
    }
    // After the simulation, empty the takeoff queue, updating StatKeeper
    // with whatever you find there.
    while(!toffQueue.empty()) {
        Airplane &plane = toffQueue.front();
        stats.incRemainingTakeoffReqs();
        stats.incTakeoffQueueTime(plane.lifeSpan(t));
        toffQueue.pop_front();
    }
    stats.printStats();

    return 0;
}

void printUsage(const char *const progName) {
        std::cout << "Usage: " << progName << " "
            << "LDUR TDUR PLAND PTOFF START STOP TTL" << std::endl;
        std::cout << std::endl;
        std::cout << std::setw(4) << " "
            << std::setw(8) << std::left << "LDUR"
            << "Amount of time it takes a plane to land"
            << std::endl;
        std::cout << std::setw(4) << " "
            << std::setw(8) << std::left << "TDUR"
            << "Amount of time it takes a plane to takeoff"
            << std::endl;
        std::cout << std::setw(4) << " "
            << std::setw(8) << std::left << "PLAND"
            << "Probability that a plane will enter the"
            " landing queue (per min.)"
            << std::endl;
        std::cout << std::setw(4) << " "
            << std::setw(8) << std::left << "PTOFF"
            << "Probability that a plane will enter the"
            " takeoff queue (per min.)"
            << std::endl;
        std::cout << std::setw(4) << " "
            << std::setw(8) << std::left << "START"
            << "Start time in minutes before midnight"
            << std::endl;
        std::cout << std::setw(4) << " "
            << std::setw(8) << std::left << "STOP"
            << "Stop time in minutes before midnight"
            << std::endl;
        std::cout << std::setw(4) << " "
            << std::setw(8) << std::left << "TTL"
            << "Amount of time a plane can spend in the" 
            << "landing queue before " << std::endl
            << std::setw(12) << std::left << ""
            << "crashing"
            << std::endl;
}
