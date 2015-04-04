#ifndef __CS3376_STATKEEPER_H__
#define __CS3376_STATKEEPER_H__

class StatKeeper {
	private:
	//Set up class variables
		int total_time_;
		int total_takeoffs_;
		int total_landings_;
		int total_crashes_;
		int average_takeoff_;
		int average_landing_;
	
	public:
	//Constructor
		StatKeeper();
	//Class accessor methods.
		int get_total_time();
		int get_total_takeoffs();
		int get_total_landings();
		int get_total_crashes();
		int get_average_takeoff();
		int get_average_langing();

	//Class mutator methods.
		int set_total_time(int);
		int set_total_takeoffs(int);
		int set_total_landings(int);
		int set_total_crashes(int);
		int set_average_takeoff(int);
		int set_average_landing(int);


};

#endif
