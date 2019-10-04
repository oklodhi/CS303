#pragma once

#include <vector>
#include "Passenger.h"
#include "System.h"

using namespace std; 

class Simulator
{
public:
	Simulator(System * the_system, int num_floors, int num_people);
	~Simulator();

private: 
	vector <Passenger> RidersVec; 
	System * my_system;
	void Run();

};

