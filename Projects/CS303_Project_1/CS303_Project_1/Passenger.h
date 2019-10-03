#pragma once

#include <string>
using namespace std; 

class Passenger
{
public:
	Passenger(int num_f);
	~Passenger();

	//Getters and Setters
	string getName() {return name; }
	int getStart_floor() { return start_floor; }
	int getExit_floor() { return exit_floor; }

	int getStart_time() { return start_time; }
	int getEnd_time() { return end_time; }

	void setStart(double x) { start_time = x; }
	void setEnd(double x) { end_time = x; }

private:
	virtual string name_array[10] = { "Thom", "Bob", "Jill", "Kathy","Matt", "Patrick", "Lauren", "Jennifer","Ashley", "Jackson" };
	string name; // random
	int start_floor; // random
	int exit_floor; // random, not start floor
	double start_time; // -1
	double end_time;  // -1

	string get_random_name();
	int get_random_floor(int num_f);
};

