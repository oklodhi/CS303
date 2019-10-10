#include <iostream>
#include <string>
#include <ctype.h>
#include <pshpck16.h>

//Homework #4 : Question #2

using namespace std;

int recur_ints(const string & s, int inc = 0) {
	if (!s.size()) return 0;
	if (isdigit(s.at(inc))) {
		int x = inc;
		return static_cast<int>(s.at(x)) + recur_ints(s, inc++);
	}
	else {
		return recur_ints(s, inc++);
	}
}

int main() {
	const string tester = "3ac4";
	int x = recur_ints(tester);
	std::cout << x;
}
