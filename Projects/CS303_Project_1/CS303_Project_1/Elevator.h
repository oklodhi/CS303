#pragma once

#include "Passenger.h"
#include <vector>

using namespace std; 

class Elevator
{
public:
	Elevator();
	~Elevator();

	// getters and setters
	int getCurrent_floor() { return current_floor; }
	int getDirection() {
		return direction; } 
	int getSpeed() { return speed; }
	int getStop_time() { return stop_time; }

private: 
	vector <Passenger*> Riders; // empty
	int current_floor; // random
	int direction; // 0 defalt
	int speed = 5; 
	int stop_time; // random between 1-10
};

