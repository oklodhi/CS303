/*
Omer Khan
Thom Martin
CS - 303
Program #2
Professor Mayanka
11/24/19
*/

#include "MorseTree.h"
#include "main.h"

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
		
		m.encode(letter, temp); 
		m.decode(temp, letter); 

	}

	if (stream.is_open())
		stream.close();
}


int main(){
	const string FILENAME = "Morse.txt";

	const string TO_ENCODE = "This is crazy";
	const string TO_DECODE = ".__ ___ _._ .._. ..._";

	MorseTree M; 
	
	read_from_file(FILENAME, M);

	M.buildtree();

	try {
		cout << M.s2m(TO_ENCODE) << endl;
		cout << M.traverseTree(TO_DECODE) << endl;
	}
	catch (exception e) {
		cout << "Not a valid string... Exiting Program!" << endl;
		exit(0);
	};

	return 0;
}