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

#pragma once

// include necessary libraries
#include <vector>
#include <set>
#include <iostream>
#include <string>

// using standard namespace std::
using namespace std;

// enumerator for elevator movement state
enum { up = 1, idle = 0, down = -1 };

// template for pair. it will hold <from floor, to floor>
typedef pair<int, int> pairs;

// single elevator struct
// includes current calls, movement state, and current floor
struct each_elevator {
	// stores call requests made for elevator
	set<int> calls;
	// movement state. idle by default. 1 for up, -1 for down
	int direction = idle;
	// current elevator floor. 1 by default
	int cur_floor = 1;

	int id = 0; 
};

// all elevators struct
// includes up and down wait lists, and vector of elevators 
struct elevators {
	// up_wait will store floor requests for in up direction
	set<pairs> up_wait;
	// down_wait will store floor requests for in down direction
	set<pairs> down_wait;

	vector <each_elevator*> v_ee;
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

// return the enum in text format
string get_enum_direction(int dir) {
	if (dir == -1) {
		// return down if direction is -1
		return "down";
	}
	else if (dir == 0) {
		// return idle if direction is 0
		return "idle";
	}
	else if (dir == 1) {
		// return up if direction is 1
		return "up";
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

// from all elevators, find the best one to pick up people
each_elevator& choose_best_elevator(int in_floor, int out_floor, elevators & v_e) {
	// from all elevators in the vector
	cout << "Finding best elevator..." << endl;
	for (each_elevator * e : v_e.v_ee) {
		// if the elevator is moving up, call is made from above, and call direction is up
		if (e->direction == up && call_direction(in_floor, out_floor) == up && e->cur_floor <= in_floor) {
			// return this elevator 
			cout << "Sending elevator [" << e->id << "]" << endl;
			return *e;
		}
		// if elevator is moving down, call is made from below, and call direction is down
		else if (e->direction == down && call_direction(in_floor, out_floor) == down && e->cur_floor >= in_floor) {
			cout << "Sending elevator [" << e->id << "]" << endl;
			// return this elevator
			return *e;
		}
	}
	// from all elevators in the vector
	for (each_elevator * e : v_e.v_ee) {
		// if any have idle state
		if (e->direction == idle) {
			cout << "Sending elevator [" << e->id << "]" << endl;
			// set its current floor to in floor
			e->cur_floor = in_floor;
			// set its direction to call direction
			e->direction = call_direction(in_floor, out_floor);
			// and return this elevator
			return *e;
		}
	}
	// if no elevators are available, return a nullptr
	each_elevator * e = nullptr;
	return *e;
}
// adds the elevator request to calls. stores from floor, to floor, and takes elevator reference
void add_call(int in_floor, int out_floor, elevators & v_e) {
	// best available elevator object
	cout << "Adding call (" << in_floor << "," << out_floor << ")..." <<  endl;
	each_elevator * e = &choose_best_elevator(in_floor, out_floor, v_e);

	// if elevator is available
	if (e) {
		// if current floor is not in floor
		if (e->cur_floor != in_floor) {
			// queue in call list
			e->calls.insert(in_floor);
			cout << "Adding in floor to list... " << in_floor << endl;
		}
		// queue out floor to call list
		e->calls.insert(out_floor);
		cout << "Adding out floor to list... " << out_floor << endl;
	}
	// no elevator is avaible 
	else {
		cout << "All elevators busy..." << endl;
		// if call is made from above
		if (call_direction(in_floor, out_floor) == up) {
			// queue in up wait list
			v_e.up_wait.emplace(in_floor, out_floor);
			cout << "Adding call to up wait list... " << in_floor << endl;
		}
		// if call is made from below
		else if (call_direction(in_floor, out_floor) == down) {
			// queue in down wait list
			v_e.down_wait.emplace(in_floor, out_floor);
			cout << "Adding call to down wait list... " << in_floor << endl;
		}
	}
}

// checks the waiting queues for calls 
void load_wait(each_elevator & e, elevators & v_e) {
	// if elevator is going up, and people are waiting up top to be picked up
	cout << "Checking wait lists..." << endl;
	if (e.direction == up && v_e.up_wait.size()) {
		cout << "Checking up wait list... " << endl;
		// iterate through waiting list of people
		for (set<pairs>::const_iterator it = v_e.up_wait.begin(); it != v_e.up_wait.end(); ++it) {
			cout << "Iterating through up wait list..." << endl;
			// queue their from floor and to floor calls
			if (e.cur_floor != it->first) {
				cout << "Current floor is not first floor in wait list..." << endl;
				e.calls.insert(it->first);
				cout << "Adding from floor " << it->first << " to call list..." << endl;
			}
			e.calls.insert(it->second);
			cout << "Adding to floor " << it->second << " to call list..." << endl;
		}
		// once every person is queues, clear the waiting list
		v_e.up_wait.clear();
		cout << "Up wait list iteration complete... Clearing up wait list" << endl;
	}
	// if elevator is going down, and people are waiting down below to be picked up
	else if (e.direction == down && v_e.down_wait.size()) {
		// iterate though the waiting list of people
		cout << "Checking down wait list... " << endl;
		for (set<pairs>::const_iterator it = v_e.down_wait.begin(); it != v_e.down_wait.end(); ++it) {
			cout << "Iterating through down wait list..." << endl;
			// queue their from floor and to floor calls
			if (e.cur_floor != it->first) {
				cout << "Current floor is not first floor in wait list..." << endl;
				e.calls.insert(it->first);
				cout << "Adding from floor " << it->first << " to call list..." << endl;
			}
			e.calls.insert(it->second);
			cout << "Adding to floor " << it->second << " to call list..." << endl;
		}
		// once every person is queued, clear the waiting list
		v_e.down_wait.clear();
		cout << "Down wait list iteration complete... Clearing down wait list" << endl;
	}
}

// this is the main system logic that the elevator uses to step through every instruction recieved 
void system_step(elevators & v_e, int steps = 1) {
	cout << "\nStepping elevator... stand by..." << endl;
	for (int s = 0; s < steps; ++s) {
		for (each_elevator *e : v_e.v_ee) {

			// if calls currently exist
			if (e->calls.size()) {
				cout << "Processing calls..." << endl;
				// move the elevator in the direction of those calls. Up or down
				e->cur_floor += e->direction;
				cout << "Moving elevator [" << e->id << "] ... " << get_enum_direction(e->direction) << endl;
				// again... check (in the background), if a call was made for current floor we are moving through
				if (e->calls.count(e->cur_floor)) {
					cout << "Reached call floor... " << e->cur_floor << endl;
					// if so, remove it because we are now visiting
					e->calls.erase(e->cur_floor);
					cout << "Removing from call list... " << e->cur_floor << endl;
				}
			}
			// if no calls exist, check the waiting list for any people waiting
			else {
				cout << "No calls... Processing up and down wait list..." << endl;
				if (v_e.up_wait.size() || v_e.down_wait.size()) {
					// create temporary pair structure to hold to and from floors
					pairs temp;
					cout << "Created temp set..." << endl;
					// if elevator is going up
					if (e->direction == up) {
						cout << "Moving elevator [" << e->id << "] ... " << get_enum_direction(e->direction) << endl;
						// but if calls are made from floors below 
						if (v_e.down_wait.size()) {
							cout << "Down wait list has people waiting..." << endl;
							// find lowest floor needed to visit
							temp = find_max(v_e.down_wait);
							cout << "Max down floor to visit... " << temp.second << endl;
							// remove that from down wait list
							v_e.down_wait.erase(temp);
							cout << "Removing from wait list... " << temp.second << endl;
						}
						// but if calls are made from floors above
						else if (v_e.up_wait.size()) {
							cout << "Up wait list has people waiting..." << endl;
							// find max floor needed to visit
							temp = find_min(v_e.up_wait);
							cout << "Max up floor to visit... " << temp.second << endl;
							// remove that from up wait list
							v_e.up_wait.erase(temp);
							cout << "Removing from wait list... " << temp.second << endl;
						}
					}
					// if elevator is going down
					else if (e->direction == down) {
						cout << "Moving elevator [" << e->id << "] ... " << get_enum_direction(e->direction) << endl;
						// but if calls are made from floors above
						if (v_e.up_wait.size()) {
							cout << "Up wait list has people waiting..." << endl;
							// find max floor needed to visit
							temp = find_min(v_e.up_wait);
							cout << "Max up floor to visit... " << temp.second << endl;
							// remove from up wait list
							v_e.up_wait.erase(temp);
							cout << "Removing from wait list... " << temp.second << endl;
						}
						// but if calls are made from floors below
						else if (v_e.down_wait.size()) {
							cout << "Down wait list has people waiting..." << endl;
							// find lowest floor needed to visit
							temp = find_max(v_e.down_wait);
							cout << "Max down floor to visit... " << temp.second << endl;
							// remove from down wait list
							v_e.down_wait.erase(temp);
							cout << "Removing from wait list... " << temp.second << endl;
						}
					}

					// insert those wait list calls, stored in temp, to main calls queue
					e->calls.insert(temp.second);
					cout << "Inserting wait list calls to main calls... " << temp.second << endl;
					// current floor = passenger pickup floor
					e->cur_floor = temp.first;
					cout << "Moving to pick up floor... " << temp.first << endl;
					// Set direction based on start passenger's call
					e->direction = call_direction(temp.first, temp.second);
					cout << "Setting direction state... " << get_enum_direction(e->direction) << endl;

					// checks waiting requests for elevator
					cout << "Checking wait list requests..." << endl;
					load_wait(*e, v_e);
					cout << "Wait list request checked..." << endl;
				}
				// if no calls exist still, then elevator is put into idle state
				else {
					cout << "No calls currently exist..." << endl;
					e->direction = idle;
					cout << "Elevator state set to... " << get_enum_direction(e->direction) << endl;
				}
			}
		}
	}
}

int main() {
	//vector<elevator> vec_elevators;
	// elevator object called e1

	elevators e;
	each_elevator e1;
	each_elevator e2;
	cout << "Created Elevator objects..." << endl;

	e.v_ee.push_back(&e1);
	e.v_ee.push_back(&e2);

	for (int i = 0; i < e.v_ee.size(); i++){
		e.v_ee.at(i)->id = i;
	}
	int total_elevators = e.v_ee.size(); 
	cout << "Elevator object pushed into vectors list..." << endl;
	cout << "There are " << total_elevators << " elevators..." << endl;

	// manually adding calls for elevator pickup and dropoff requests
	// and elevator system steps through the simulation

	add_call(1, 4, e);
	system_step(e);

	add_call(8, 1, e);
	system_step(e);

	add_call(1, 8, e);
	system_step(e);

	add_call(5, 2, e);
	add_call(3, 1, e);
	system_step(e);

	add_call(8, 1, e);
	add_call(6, 2, e);

	// while the elevator is moving either up or down, it is stepping and constantly making changes to
	// the pick up, drop off, and call requests lists. 
	while (e1.direction != idle) {
		system_step(e);
	}

	return 0;
}
