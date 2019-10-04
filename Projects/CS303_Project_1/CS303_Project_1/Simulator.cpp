#include "Simulator.h"
#include "System.h"
//#include <omp.h>



Simulator::Simulator(System * the_system, int num_floors = 10, int num_people = 5)
{
	my_system = the_system;
	for (int i = 0; i < num_people; i++) {
		Passenger temp(num_floors);
		RidersVec.push_back(temp);
		this->Run();
	}
}

Simulator::~Simulator()
{
}

void Simulator::Run() {
	//make run parallel
	for (Passenger p : RidersVec){
		my_system->add_call(&p);
			//system wait (time = 2 to 6 floors)
	}
}