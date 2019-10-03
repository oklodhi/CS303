#include "Elevator.h"




Elevator::Elevator(int num_floors = 10)
{
	//Set total floors
	total_floors = num_floors;
	//Set current floor (Random)
	srand(time(NULL));
	current_floor = rand() % num_floors + 1;
	//Set Direction as Idle
	direction = 0;
}


Elevator::~Elevator()
{
}

	void Elevator::Let_Out()
	{
		for (Passenger* p : Riders) {
			if (p->getExit_floor == current_floor) {
				p->setEnd = time(NULL);
				Riders.erase(p*);
			}
	}

	void Elevator::Let_In()
{
	for ()
}


}
