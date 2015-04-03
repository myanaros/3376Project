#ifndef __CS3376_AIRPLANE_H__
#define __CS3376_AIRPLANE_H__

class Airplane {
    private:
        int start_time_;
        int crash_time_;
    public:
        void set_start_time(int);
        int get_start_time();
        void set_crash_time(int);
        int get_crash_time();

        bool hasCrashed();
};

#endif
