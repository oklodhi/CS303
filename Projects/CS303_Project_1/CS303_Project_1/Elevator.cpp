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

void Elevator::Run()
{
	if (direction == 0) {
		if (System::Has_Down()) {

		}
		else if (System::Has_Up) {
		
		}
	}
	else {
		Let_Out();
		Let_In();
	}
	Move();
}

void Elevator::Move()
{
}

void Elevator::Let_Out()
{
}

void Elevator::Let_In()
{
}


}
