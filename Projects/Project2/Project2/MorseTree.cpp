#include "MorseTree.h"

// constructor sets the default values
MorseTree::MorseTree()
{
	root = new node;
	root->letter = '$';
	root->lnode = nullptr;
	root->rnode = nullptr;
}

// destructor. Can leave empty
MorseTree::~MorseTree()
{
}

// this functions adds a letter and its corresponding morse value to a map
void MorseTree::encode(char c, string s) {
	str2morse.emplace(c, s);
}

// this functions adds a morse value and its corresponding letter to a map
void MorseTree::decode(string s, char c)
{
	morse2str.emplace(s, c);
}

// given a morse code string of dots(.) and dashes(_), convert the string to an alphabet string
string MorseTree::traverseTree(string s) {
	// whitespace delimiter
	string delim = "";
	// vector of strings to temporarily hold each character of a string
	vector<string> vec;

	// pointer to root of the binary morse tree
	node * current = root;

	// iterate through the morse string and push back elements (separated by whitepsace), into a new index of a vector
	for (auto x : s) {
		if (x == ' ') {
			vec.push_back(delim);
			delim = "";
		}
		else {
			delim = delim + x;
		}
	}
	vec.push_back(delim);

	// create a vector of characters to hold the alphabet equivalent of the morse string
	vector<char> charvec;

	// iterate over every index of the morse code vector
	for (unsigned int i = 0; i < vec.size(); i++) {
		string code = vec[i];
		// iterate over every single dot(.) or dash(_) inside each vector index
		for (unsigned int k = 0; k < code.length(); k++) {
			// if root is null that means no tree exists
			if (current == NULL) {
				cout << "Error: No valid tree exists..." << endl;
				exit(0);
			}
			// if dot(.) then go to left child node
			if (code[k] == '.') {
				current = current->lnode;
			}
			// if dash(_) then go to right child node
			else if (code[k] == '_') {
				current = current->rnode;
			}
		}
		// assuming that we found the correct conversion for the morse to alphabet, store the letter into the character vector
		if (current != root) {
			charvec.push_back(current->letter);
		}
		// at the end of every letter that is converted, start at the root of tree
		current = root;
	}

	// convert the character vector to a string and return to the function call
	string finalString(charvec.begin(), charvec.end());
	return finalString;
}

// this function converts from a string of letters into morse code
string MorseTree::s2m(string s)
{
	// temporary empty result string 
	string result = "";
	// iterate over every letter in string
	for (unsigned int i = 0; i < s.length(); i++) {
		// take into account for the whitespaces in a string
		if (s.at(i) == ' ') {
			result += " ";
		}
		// for every letter, search the tree for its morse code equivalent
		else {
			result += searchTree(tolower(s.at(i))) + " ";
		}
	}
	return result;
}

// this is a helper function to traverse through the morse binary tree
string MorseTree::searchTree(char c) {
	this->currpath = "";
	// if a valid path to a letter is found, print the path in reverse because the call stack is in opposite order
	if (search(c, root)) {
		reverse(currpath.begin(), currpath.end());
		return this->currpath;
	}
}

// this function recursively traverses the binary morse tree until it finds the correct letter we need. When found, it keeps a track of the path it took
bool MorseTree::search(char c, node * current)
{
	// if the current node is null, then path node does not exist
	if (current == NULL) {
		return false;
	}

	// if current node is the destination node return true
	if (c == current->letter) {
		return true;
	}
	// else if the current node is the left child node, then append dot(.) to path
	else if (search(c, current->lnode)) {
		currpath.append(".");
		return true;
	}
	// else if the current node is the right child node, then append dash(_) to path
	else if (search(c, current->rnode)) {
		currpath.append("_");
		return true;
	}

	// if this return executes then no destination node was found. 
	return false;
}

// this function builds the binary morse tree
void MorseTree::buildtree()
{
	// starting at the root of the tree
	node * current = root;

	// iterate over the mapped data of letters and its key morse values 
	for (map<char, string>::const_iterator it = str2morse.begin(); it != str2morse.end(); ++it) {
		// iterate over the morse string of that specific letter
		for (unsigned int i = 0; i < it->second.length(); i++) {
			// if the index of that morse string is a dot(.)
			if (it->second[i] == '.') {
				// then check if a left child node exists or not
				if (current->lnode == nullptr) {
					// if it doesnt exists then create a left child node
					current->lnode = new node;
				}
				// and set pointer to that left child node
				current = current->lnode;
			}
			// if the index of that morse string is a dash(_)
			else if (it->second[i] == '_') {
				// then check if a right child node exists or not
				if (current->rnode == nullptr) {
					// if it doesnt exists then create a right child node
					current->rnode = new node;
				}
				// and set pointer to that right child node
				current = current->rnode;
			}
		}
		// set the value of each node to its corresponding alphabet letter
		current->letter = it->first;
		// reset current pointer back to root
		current = root;
	}
}


