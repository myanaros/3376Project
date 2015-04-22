#ifndef __CS3376_AIRPLANE_H__
#define __CS3376_AIRPLANE_H__

#ifdef DEBUG
enum planeDebugType {
    DBG_LREQ =  0,
    DBG_TREQ =  1,
    DBG_LAND =  2,
    DBG_TOFF =  3,
    DBG_CRASH = 4
};
#endif

class Airplane {
    private:
        int start_time_;
        int crash_time_;

        // Private Accessors
        int start_time();
        int crash_time();

        // Private Mutators
        void set_start_time(const int start_time);
        void set_crash_time(const int crash_time);

    public:
        // Constructors/Destructors
        Airplane(const int cur_time, const int max_time);
        ~Airplane() {};

        // Other
        bool hasCrashed(const int cur_time);
        int lifeSpan(const int cur_time);
#ifdef DEBUG
        void printDebug(const int cur_time, const planeDebugType dtype);
#endif
};

#endif
