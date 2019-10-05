#pragma once

#include "Passenger.h"
#include <set>
#include <cstdlib>
#include <time.h>

using namespace std; 



class Elevator
{
public:
	Elevator(int num_floors);
	Elevator(Elevator&);
	~Elevator();

	// getters and setters
	int getCurrent_floor() { return current_floor; }
	int getDirection() { return direction; } 
	int getSpeed() { return speed; }
	int getStop_time() { return stop_time; }
	void setDirection(int d) { this->direction = d; }

	void Move() { this->current_floor += direction; }
	void Let_Out();
	void Let_In();

private: 
	set <Passenger&> Riders; // empty
	int total_floors;
	int current_floor; // random
	int direction; // 0 defalt
	int speed = 5; 
	int stop_time; // random between 1-10
};

