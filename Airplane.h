#ifndef __CS3376_AIRPLANE_H__
#define __CS3376_AIRPLANE_H__

class Airplane {
    private:
        int start_time_;
        int crash_time_;

    public:
        // Constructors/Destructors
        Airplane(const int cur_time, const int max_time);
        ~Airplane() {};

        // Accessors
        int start_time();
        int crash_time();

        // Mutators
        void set_start_time(const int start_time);
        void set_crash_time(const int crash_time);

        // Other
        bool hasCrashed(const int cur_time);
};

#endif
