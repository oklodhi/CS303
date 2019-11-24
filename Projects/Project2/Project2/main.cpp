/*
Omer Khan, Thom Martin
CS - 303
Program #2
Professor Mayanka
11/24/19
*/

#include "MorseTree.h"

// This function reads the morse code file that is given to us as a part of the assignment. It parses the data and eventually builds a tree from the given data. 
void read_from_file(string file, MorseTree &m) {
	// create file stream object
	ifstream stream;
	
	// try to open file
	try {
		stream.open(file);
	}
	catch(exception e){
		// catch any errors if there is a problem with file
		cout << "Cant open file"; 
		exit(0); 
	};

	// while reading the file
	while (!stream.eof()) {
		// character stores alphabet
		char letter;
		// temp stores the morse equivalent as string
		string temp;

		// fu
		stream.get(letter);
		getline(stream, temp); 
		
		// parse the data into corresponding maps
		m.encode(letter, temp); 
		m.decode(temp, letter); 
	}

	// close file
	if (stream.is_open())
		stream.close();
}


int main(){
	// const file name that contains morse and alphabet conversion
	const string FILENAME = "Morse.txt";

	// const strings to convert to morse and back to letters
	// NOTE FOR GRADER: you can change these to your liking to test the program
	const string TO_ENCODE = "This is crazy";
	const string TO_DECODE = ".__ ___ _._ .._. ..._";

	// Binary tree object
	MorseTree M; 
	
	// read morse code conversion data 
	read_from_file(FILENAME, M);

	// build a binary tree based on the parsed data
	M.buildtree();

	// try to encode and decode the given strings from above
	try {
		cout << M.s2m(TO_ENCODE) << endl;
		cout << M.traverseTree(TO_DECODE) << endl;
	}
	catch (exception e) {
		// if any exception is thrown, catch that here and exit the program
		cout << "Not a valid string... Exiting Program!" << endl;
		exit(0);
	};

	return 0;
}