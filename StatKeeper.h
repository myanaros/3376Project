#ifndef __CS3376_STATKEEPER_H__
#define __CS3376_STATKEEPER_H__

class StatKeeper {
	private:
		int total_sim_time_;
		int total_crashes_;
		int total_landings_;
		int total_takeoffs_;
        int total_landing_time_;
        int total_takeoff_time_;
	
	public:
        // Constructors /Destructors
		StatKeeper(const int start_time, const int end_time);
        ~StatKeeper();

        // Accessors
		int total_sim_time();
		int total_crashes();
		int total_landings();
		int total_takeoffs();
        int total_landing_time();
        int total_takeoff_time();

        // Mutators
		void set_total_sim_time(const int total_sim_time);
		void set_total_crashes(const int total_crashes);
		void set_total_landings(const int total_landings);
		void set_total_takeoffs(const int total_takeoffs);
		void set_total_landing_time(const int total_landing_time);
		void set_total_takeoff_time(const int total_takeoff_time);

        // Other
        void printStats();
};

#endif
