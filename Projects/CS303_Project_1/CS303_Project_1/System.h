#pragma once

#include "Elevator.h"
#include "Passenger.h"
#include <vector>
#include <set>


using namespace std; 

class System
{
public:
	System(int num_elevators, int num_floors);
	~System();

	enum direction { up = 1, idle = 0, down = -1 };

	//Getters and Setters
	int getNum_floors() {return num_floors; }
	int getNum_elevators() { return elevatorVec.size(); }
	
	void Run();
	void add_call(Passenger* p);
	
private: 
	vector<Elevator> elevatorVec;
	set <Passenger*> UpCalls;
	set <Passenger*> DownCalls;
	int num_floors; 
};

