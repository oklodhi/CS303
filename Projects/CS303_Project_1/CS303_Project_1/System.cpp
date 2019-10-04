#include "System.h"



System::System(int num_elevators = 1, int num_floors = 10)
{
	this->num_floors = num_floors;

	for (int i = 0; i < num_elevators; i++) {
		Elevator temp(num_floors);
		elevatorVec.push_back(temp);
	}
	this->Run();
}

System::~System()
{
}

void System::Run()
{
	for (Elevator e : elevatorVec) {
		e.Move();
		e.Let_Out();
		e.Let_In();
	}
}

void System::add_call(Passenger* p) {
	if (p->getExit_floor() < p->getStart_floor()) {
		DownCalls.insert(p);
	}
	else if (p->getExit_floor() > p->getStart_floor()) {
		UpCalls.insert(p);
	}
	p->setStart = time(NULL);
}

