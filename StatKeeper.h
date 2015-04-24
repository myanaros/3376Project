#ifndef __CS3376_STATKEEPER_H__
#define __CS3376_STATKEEPER_H__

class StatKeeper {
    private:
        int sim_time_;
        int crashes_;
        int landings_;
        int takeoffs_;
        int landing_reqs_;
        int takeoff_reqs_;
        int remaining_landing_reqs_;
        int remaining_takeoff_reqs_;
        int landing_queue_time_;
        int takeoff_queue_time_;
    
        // Accessors
        int sim_time();
        int crashes();
        int landings();
        int takeoffs();
        int landing_reqs();
        int takeoff_reqs();
        int remaining_landing_reqs();
        int remaining_takeoff_reqs();
        int landing_queue_time();
        int takeoff_queue_time();

        // Private Mutators
        void set_sim_time(const int sim_time);
        void set_crashes(const int crashes);
        void set_landings(const int landings);
        void set_takeoffs(const int takeoffs);
        void set_landing_reqs(const int landing_reqs);
        void set_takeoff_reqs(const int takeoff_reqs);
        void set_remaining_landing_reqs(const int remaining_landing_reqs);
        void set_remaining_takeoff_reqs(const int remaining_takeoff_reqs);
        void set_landing_queue_time(const int landing_queue_time);
        void set_takeoff_queue_time(const int takeoff_queue_time);

    public:
        // Constructors /Destructors
        StatKeeper(const int start_time, const int end_time);
        ~StatKeeper() {};

        // Other
        void incCrashes(const int amt = 1);
        void incLandings(const int amt = 1);
        void incTakeoffs(const int amt = 1);
        void incLandingReqs(const int amt = 1);
        void incTakeoffReqs(const int amt = 1);
        void incRemainingLandingReqs(const int amt = 1);
        void incRemainingTakeoffReqs(const int amt = 1);
        void incLandingQueueTime(const int amt);
        void incTakeoffQueueTime(const int amt);
        void printStats();
};

#endif
