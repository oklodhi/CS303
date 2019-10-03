#include "System.h"



System::System(int num_elevators = 1, int num_floors = 10)
{
	

	this->num_floors = num_floors;

	for (unsigned int i = 0; i < num_elevators; i++) {
		Elevator temp(num_floors)
		elevatorVec.push_back(temp);
	}

}

System::~System()
{
}

void System::add_call(Passenger* p) {
	if (p->getExit_floor < p->getStart_floor) {
		DownCalls.push_back(p);
	}
	else if (p->getExit_floor > p->getStart_floor) {
		UpCalls.push_back(p);
	}
}

void Run{
	if (DownCalls) {
		for each e in elevatorVec{
			if e.direcion == down {
				e.run
}
	}
}
	else if (UpCalls)
}