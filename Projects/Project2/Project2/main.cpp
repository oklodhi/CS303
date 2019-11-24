/*
Omer Khan
Thom Martin
CS - 303
Program #2
Professor Mayanka
11/24/19
*/

#include <iostream>
#include <fstream>
#include <string>

#include "MorseTree.h"

using namespace std;

void read_from_file(string file, MorseTree &m) {
	ifstream stream;
	
	try {
		stream.open(file);
	}
	catch(exception e){
		cout << "Cant open file"; 
		exit(0); 
	};

	while (!stream.eof()) {
		char letter;
		string temp;

		stream.get(letter);
		getline(stream, temp); 
		 
		cout << letter << " = " << temp << endl;

		m.encode(letter, temp); 
		m.decode(temp, letter); 

	}

	if (stream.is_open())
		stream.close();
}


int main(){
	string to_encode = "This is dumb";
	string to_decode = "... ._ _..";

	MorseTree M; 
	
	read_from_file("Morse.txt", M);
	M.buildtree();

	cout << M.traverseTree(to_decode) << endl;

	return 0;
}