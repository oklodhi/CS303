#include "Simulator.h"



Simulator::Simulator(int num_floors = 10, int num_people = 5)
{
	for (unsigned i = 0; i < num_people; i++) {
		Passenger temp(num_f);
		RidersVec.push_back(temp);
	}
}

Simulator::~Simulator()
{
}

void Simulator::Run() {

}