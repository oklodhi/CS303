#include <string>

using namespace std;

class Person{
public:
	Person(string n, int d) : name(n), dependents(d) {};
	string name;
	int dependents;
	//bool operator <(P)
};
