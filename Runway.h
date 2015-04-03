#ifndef __CS3376_RUNWAY_H__
#define __CS3376_RUNWAY_H__

class Runway {
    public:
        int get_landing_duration();
        void set_landing_duration(int);
        int get_takeoff_duration_();
        void set_takeoff_duration_(int);
        int get_busy_until();
        void set_busy_until(int);

        bool isClear();
        void doLanding();
        void doTakeoff();
    private:
        int landing_duration_;
        int takeoff_duration_;
        int busy_until_;
};

#endif
