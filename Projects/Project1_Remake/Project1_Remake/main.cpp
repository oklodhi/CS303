#pragma once

#include <vector>
#include <set>


using namespace std;

enum { up = 1, idle = 0, down = -1 };

typedef pair<int, int> pairs;

struct elevator {
	set<pairs> up_wait;
	set<pairs> down_wait;
	set<int> calls;
	int direction = idle;
	int cur_floor = 1;
};

int call_direction(int i, int o) {
	if (i < o) { return up; }
	else if (i > o) { return down; }
	else { return idle; }
}

pairs find_max(set<pairs> wait_set) {
	pairs max(-1, -1);
	for (set<pairs>::const_iterator it = wait_set.begin(); it != wait_set.end(); ++it) {
		if (it->first > max.first) { 
			max.first = it->first; 
			max.second = it->second;
		}
	 }
	return max;
}

pairs find_min(set<pairs> wait_set) {
	pairs min(100000, 100000);
	for (set<pairs>::const_iterator it = wait_set.begin(); it != wait_set.end(); ++it) {
		if (it->first < min.first) {
			min.first = it->first;
			min.second = it->second;
		}
	}
	return min;
}

void add_call(int in_floor, int out_floor, elevator & e) {
	if (e.direction == idle) {
		e.cur_floor = in_floor;
		e.calls.insert(in_floor);
		e.calls.insert(out_floor);
		e.direction = call_direction(in_floor, out_floor);
	}
	else if (e.direction == up) {
		if (call_direction(in_floor, out_floor) == up) {
			if (e.cur_floor <= in_floor) {
				e.calls.insert(in_floor);
				e.calls.insert(out_floor);
			}
			else { e.up_wait.emplace(in_floor, out_floor); }
		}
		else { e.down_wait.emplace(in_floor, out_floor); }
	}
	else if (e.direction == down) {
		if (call_direction(in_floor, out_floor) == down) {
			if (e.cur_floor >= in_floor) {
				e.calls.insert(in_floor);
				e.calls.insert(out_floor);
			}
			else { e.down_wait.emplace(in_floor, out_floor); }
		}
		else { e.up_wait.emplace(in_floor, out_floor); }
	}

}

void load_wait(elevator & e) {
	if (e.direction == up && e.up_wait.size()) {
		for (set<pairs>::const_iterator it = e.up_wait.begin(); it != e.up_wait.end(); ++it) {
			e.calls.insert(it->first);
			e.calls.insert(it->second);
		}
		e.up_wait.clear();
	}
	else if (e.direction == down && e.down_wait.size()) {
		for (set<pairs>::const_iterator it = e.down_wait.begin(); it != e.down_wait.end(); ++it) {
			e.calls.insert(it->first);
			e.calls.insert(it->second);
		}
		e.down_wait.clear();
	}
}

void system_step(elevator & e, int steps = 1){
	for (int s = 0; s < steps; ++s) {
		if (e.calls.size()) {
			if (e.calls.count(e.cur_floor)) { e.calls.erase(e.cur_floor); }
			if (e.calls.size()) { e.cur_floor += e.direction; }
			if (e.calls.count(e.cur_floor)) { e.calls.erase(e.cur_floor); }
		}
		else {
			if (e.up_wait.size() || e.down_wait.size()) {
				pairs temp;

				if (e.direction == up) { 
					if (e.down_wait.size()) {
						temp = find_max(e.down_wait);
						e.down_wait.erase(temp);
					}
					else if (e.up_wait.size()) {
						temp = find_min(e.up_wait);
						e.up_wait.erase(temp);
					}
				}
				else if (e.direction == down) { 
					if (e.up_wait.size()) {
						temp = find_min(e.up_wait);
						e.up_wait.erase(temp);
					}
					else if (e.down_wait.size()) {
						temp = find_max(e.down_wait);
						e.down_wait.erase(temp);
					}
				}

				e.calls.insert(temp.first);
				e.calls.insert(temp.second);
				e.cur_floor = temp.first; //Move to start floor to pick up passenger
				e.direction = call_direction(temp.first, temp.second); //Set direction based on start passenger's call
				
				load_wait(e);
			}
			else { e.direction = idle; }
		}	
	}
}

int main(){
	elevator e1;

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

	while (e1.direction != idle) {
		system_step(e1);
	}



	return 0;
}
