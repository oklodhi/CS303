// Omer Khan, Thomas Martin
// Project 1C


/* HOW THE PROGRAM WORKS: 

	Multiple elevator struct objects are created. They are given current floor, direction of movement / state,
	and call requests in the form of a set data structure. The elevators then process calls on a first come first
	serve queue method. Elevator will pick up people who all want to go to a floor in the same direction, but if
	elevator is moving up and someone wants to get off on a floor below, the elevator adds that to a waiting
	list. As the elevator is moving through floors, and changing direction going up or down, it is constantly
	updating its calls list and wait lists to adjust and efficiently repond to all requests. This simulation is 
	a very close, non-complicated, example of how an actual elevator works. 
*/

// This is Omer's Git Branch test

#pragma once

// include necessary libraries
#include <vector>
#include <set>
#include <iostream>

// using standard namespace std::
using namespace std;

// enumerator for elevator movement state
enum { up = 1, idle = 0, down = -1 };

// template for pair. it will hold <from floor, to floor>
typedef pair<int, int> pairs;

// elevator struct
// includes up and down wait lists, current calls, movement state, and current floor
struct elevator {
	// up_wait will store floor requests for in up direction
	set<pairs> up_wait;
	// down_wait will store floor requests for in down direction
	set<pairs> down_wait;
	// stores call requests made for elevator
	set<int> calls;
	// movement state. idle by default. 1 for up, -1 for down
	int direction = idle;
	// current elevator floor. 1 by default
	int cur_floor = 1;
};

// sets the call direction based on from floor and to floor
// returns up and down from enum
int call_direction(int i, int o) {
	if (i < o) {
		// if person wants to go up
		return up;
	}
	else if (i > o) {
		// if person wants to go down
		return down;
	}
	else {
		// no call was made / what if person wants to get off on same floor as they got on
		// returns idle state
		return idle;
	}
}

// from the the entire set, return the highest floor the elevator needs to go to
pairs find_max(set<pairs> wait_set) {
	// in case the set is empty, -1 is the max until new max is found
	pairs max(-1, -1);
	// iterate through set to find max
	for (set<pairs>::const_iterator it = wait_set.begin(); it != wait_set.end(); ++it) {
		if (it->first > max.first) {
			// stores max pair
			max.first = it->first;
			max.second = it->second;
		}
	}
	// returns the new found max
	return max;
}

// from the entire set, return the lowest floor the elevator needs to go to
pairs find_min(set<pairs> wait_set) {
	// in case the set is empty, 100000 is the low until new low is found
	pairs min(100000, 100000);
	// iterate through set to find low
	for (set<pairs>::const_iterator it = wait_set.begin(); it != wait_set.end(); ++it) {
		if (it->first < min.first) {
			// stores low pair
			min.first = it->first;
			min.second = it->second;
		}
	}
	// returns the new found low
	return min;
}

// adds the elevator request to calls. stores from floor, to floor, and takes elevator reference
void add_call(int in_floor, int out_floor, elevator & e) {
	// if direction is idle then... 
	if (e.direction == idle) {
		// current floor = the floor that the call came from

		cout << "Elevator is idle..." << endl; 
		e.cur_floor = in_floor;
		cout << "Elevator moving to..." << e.cur_floor << endl;

		// insert the out floor to calls list
		e.calls.insert(out_floor);
		cout << "Adding call to list... " << out_floor << endl;
		// get the direction that the elevator needs to move
		e.direction = call_direction(in_floor, out_floor);
		cout << "Elevator now moving in..." << e.direction << endl;
	}
	// if the elevator is moving up...
	else if (e.direction == up) {
		// if the request is made from a floor higher than elevator current floor
		if (call_direction(in_floor, out_floor) == up) {
			// current elevator floor is below the floor person wants to get in from
			if (e.cur_floor <= in_floor) {
				// queue the floor to calls
				e.calls.insert(out_floor);
			}
			else { 
				// if call was placed from floor below, then queue it in waiting list
				e.up_wait.emplace(in_floor, out_floor); 
			}
		}
		else { 
			// if call was made from bottom, but elevator is going up, queue the calls in waiting
			e.down_wait.emplace(in_floor, out_floor); 
		}
	}
	// if elevator is moving down
	else if (e.direction == down) {
		// if call came from floor below
		if (call_direction(in_floor, out_floor) == down) {
			// if elevator is above the floor call came from
			if (e.cur_floor >= in_floor) {
				// queue floor calls
				e.calls.insert(out_floor);
			}
			else { 
				// if current floor is below the call floor, then queue the call in wait list
				e.down_wait.emplace(in_floor, out_floor); 
			}
		}
		else { 
			// if call was made from top, but elevator is doing down, queue the calls in waiting 
			e.up_wait.emplace(in_floor, out_floor); 
		}
	}
}

// checks the waiting queues for calls 
void load_wait(elevator & e) {
	// if elevator is going up, and people are waiting up top to be picked up
	if (e.direction == up && e.up_wait.size()) {
		// iterate through waiting list of people
		for (set<pairs>::const_iterator it = e.up_wait.begin(); it != e.up_wait.end(); ++it) {
			// queue their from floor and to floor calls
			e.calls.insert(it->first);
			e.calls.insert(it->second);
		}
		// once every person is queues, clear the waiting list
		e.up_wait.clear();
	}
	// if elevator is going down, and people are waiting down below to be picked up
	else if (e.direction == down && e.down_wait.size()) {
		// iterate though the waiting list of people
		for (set<pairs>::const_iterator it = e.down_wait.begin(); it != e.down_wait.end(); ++it) {
			// queue their from floor and to floor calls
			e.calls.insert(it->first);
			e.calls.insert(it->second);
		}
		// once every person is queued, clear the waiting list
		e.down_wait.clear();
	}
}

// this is the main system logic that the elevator uses to step through every instruction recieved 
void system_step(elevator & e, int steps = 1) {
	for (int s = 0; s < steps; ++s) {
		// if calls currently exist
		if (e.calls.size()) {
			// move the elevator in the direction of those calls. Up or down
			e.cur_floor += e.direction;
			// again... check (in the background), if a call was made for current floor we are moving through
			if (e.calls.count(e.cur_floor)) {
				// if so, remove it because we are now visiting
				e.calls.erase(e.cur_floor);
			}
		}
		// if no calls exist, check the waiting list for any people waiting
		else {
			if (e.up_wait.size() || e.down_wait.size()) {
				// create temporary pair structure to hold to and from floors
				pairs temp;

				// if elevator is going up
				if (e.direction == up) {
					// but if calls are made from floors below 
					if (e.down_wait.size()) {
						// find lowest floor needed to visit
						temp = find_max(e.down_wait);
						// remove that from down wait list
						e.down_wait.erase(temp);
					}
					// but if calls are made from floors above
					else if (e.up_wait.size()) {
						// find max floor needed to visit
						temp = find_min(e.up_wait);
						// remove that from up wait list
						e.up_wait.erase(temp);
					}
				}
				// if elevator is going down
				else if (e.direction == down) {
					// but if calls are made from floors above
					if (e.up_wait.size()) {
						// find max floor needed to visit
						temp = find_min(e.up_wait);
						// remove from up wait list
						e.up_wait.erase(temp);
					}
					// but if calls are made from floors below
					else if (e.down_wait.size()) {
						// find lowest floor needed to visit
						temp = find_max(e.down_wait);
						// remove from down wait list
						e.down_wait.erase(temp);
					}
				}

				// insert those wait list calls, stored in temp, to main calls queue
				e.calls.insert(temp.second);
				// current floor = passenger pickup floor
				e.cur_floor = temp.first;
				// Set direction based on start passenger's call
				e.direction = call_direction(temp.first, temp.second);

				// checks waiting requests for elevator 
				load_wait(e);
			}
			// if no calls exist still, then elevator is put into idle state
			else { 
				e.direction = idle; 
			}
		}
	}
}

int main() {
	// elevator object called e1
	elevator e1;

	// manually adding calls for elevator pickup and dropoff requests
	// and elevator system steps through the simulation

	add_call(1, 4, e1);
	system_step(e1);

	add_call(8, 1, e1);
	system_step(e1);

	add_call(1, 8, e1);
	system_step(e1);

	add_call(5, 2, e1);
	add_call(3, 1, e1);
	system_step(e1);

	add_call(8, 1, e1);
	add_call(6, 2, e1);

	// while the elevator is moving either up or down, it is stepping and constantly making changes to
	// the pick up, drop off, and call requests lists. 
	while (e1.direction != idle) {
		system_step(e1);
	}

	return 0;
}
