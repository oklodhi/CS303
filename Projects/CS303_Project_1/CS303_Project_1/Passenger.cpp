#include "Passenger.h"





Passenger::Passenger(int num_f = 10)
{
	name = get_random_name();

	start_floor = get_random_floor(num_f);
	do {
		exit_floor = get_random_floor(num_f);
	} while (start_floor == exit_floor);
	
	start_time = -1;
	end_time = -1;
}


Passenger::~Passenger()
{
}

string Passenger::get_random_name() {
	srand(time(NULL));
	return name_vec.at(rand() % 10);
}

int Passenger::get_random_floor(int num_f) {
	srand(time(NULL));
	return rand() % num_f + 1;
}
