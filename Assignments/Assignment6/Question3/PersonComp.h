#include "Person.h"

struct PersonComp{

public:
	//THIS IS THE PROGRAMMING PART REQUIRED IN QUESTION #3 FROM ASSIGNMENT6
	bool operator ()(const Person& p1, const Person& p2){
		return p1.dependents < p2.dependents;
	}
};
