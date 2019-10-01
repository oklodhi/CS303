#include "Simulator.h"



Simulator::Simulator(int num_people = 5)
{
	for (unsigned i = 0; i < num_people; i++) {
		Passenger temp;
		RidersVec.push_back(temp);
	}
}

Simulator::~Simulator()
{
}
