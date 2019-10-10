#include <iostream>
#include <string>
#include <ctype.h>

//Homework #4 : Question #2

using namespace std;

int to_number(string s) {
	if (!s.size()) {
	    return 0;
	}
	
	char n = s.at(0);
	if (isdigit(n)) {
		return n-'0' + to_number(s.substr(1));
	}
	else {
		return to_number(s.substr(1));
	}
}

int main() {
	string tester = "3ac4";
	int x = to_number(tester);
	cout << x;
}
