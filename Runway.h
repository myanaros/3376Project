#ifndef __CS3376_RUNWAY_H__
#define __CS3376_RUNWAY_H__

class Runway {
    private:
        int busy_until_;
        int landing_duration_;
        int takeoff_duration_;

        // Private Accessors
        int busy_until();
        int landing_duration();
        int takeoff_duration();

        // Private Mutators
        void set_busy_until(const int busy_until);
        void set_landing_duration(const int landing_duration);
        void set_takeoff_duration(const int takeoff_duration);

    public:
        // Constructors/Destructors
        Runway(const int takeoff_duration, const int landing_duration,
                const int cur_time);
        ~Runway() {};

        // Other
        bool isClear(const int cur_time);
        void doLanding(const int cur_time);
        void doTakeoff(const int cur_time);
#ifdef DEBUG
        void printDebug(const int cur_time);
#endif
};

#endif
