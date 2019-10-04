// Thomas Martin & Omer Khan
// CS 303 Project 1
// October 1, 2019

#include <iostream>
#include <thread>
#include "Passenger.h"
#include "Elevator.h"
#include "System.h"
#include "Simulator.h"




using namespace std;

const int TOTAL_FLOORS = 10; 
const int TOTAL_ELEVATORS = 1; 
const int TOTAL_PASSENGERS = 5;

int main() {
	//Initialize System(passing in num_floors and num_elevators
	System my_sys = System(TOTAL_FLOORS, TOTAL_ELEVATORS);
	thread sys(my_sys.Run);

	//System my_system = System(TOTAL_FLOORS, TOTAL_FLOORS);
	//Split threads to Run System
	//Initialize Simulator(passing in num_people)
	Simulator my_sim = Simulator(&my_sys, TOTAL_FLOORS, TOTAL_PASSENGERS);
	thread sim(my_sim.Run);
	//Run Simulator

	//Close Simulator
	//Close System

	sys.join();
	sim.join();



}