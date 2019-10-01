#include "Passenger.h"



Passenger::Passenger()
{
	name = get_random_name();
	start_floor = get_random_floor();
	exit_floor = get_random_floor();
	//check that exit_floor != start_floor
	start_time = -1;
	end_time = -1;
}


Passenger::~Passenger()
{
}

string Passenger::get_random_name() {
	string name_array[10] = { "Tom", "Bob", "Jill", "Kathy","Matt", "Patrick", "Lauren", "Jennifer","Ashley", "Jackson"};
}
