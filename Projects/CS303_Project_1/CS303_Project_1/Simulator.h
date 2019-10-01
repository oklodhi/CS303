#pragma once

#include <vector>
#include "Passenger.h"
#include "System.h"

using namespace std; 

class Simulator
{
public:
	Simulator(int num_people);
	~Simulator();

private: 
	vector <Passenger> RidersVec; 
	double rand_waitTime; // wait time is around 5xfloors
};

