#include "MorseTree.h"



MorseTree::MorseTree()
{
	root = new node;
	root->letter = '$';
	root->lnode = nullptr;
	root->rnode = nullptr;
}


MorseTree::~MorseTree()
{
}

void MorseTree::encode(char c, string s) {
	str2morse.emplace(c, s); 
}

void MorseTree::decode(string s, char c)
{
	morse2str.emplace(s, c);
}

string MorseTree::traverseTree(string s) {
	string delim = ""; 
	vector<string> vec; 

	node * current = root; 

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

	vector<char> charvec; 

	for (unsigned int i = 0; i < vec.size(); i++) {
		string code = vec[i]; 
		for (unsigned int k = 0; k < code.length(); k++) {
			if (current == NULL) {
				cout << "Error: No valid tree exists..." << endl;
				exit(0); 
			}
			if (code[k] == '.') {
				current = current->lnode; 
			}
			else if (code[k] == '_') {
				current = current->rnode;
			}
		}
		charvec.push_back(current->letter);
		current = root; 
	}

	string finalString(charvec.begin(), charvec.end());
	return finalString; 
}

string MorseTree::searchTree(char c, string code = "", node * current) {
	
}

void MorseTree::buildtree()
{
	node * current = root;

	for (map<char, string>::const_iterator it = str2morse.begin(); it != str2morse.end(); ++it) {
		for (unsigned int i = 0; i < it->second.length(); i++) {
			if (it->second[i] == '.') {
				if (current->lnode == nullptr) {
					current->lnode = new node;
				}
				current = current->lnode;
			}
			else if (it->second[i] == '_') {
				if (current->rnode == nullptr) {
					current->rnode = new node;
				}
				current = current->rnode;
			}
		}
			current->letter = it->first;
			current = root;
	}
}


