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

void MorseTree::printEncode()
{
	for (map<char, string>::const_iterator it = str2morse.begin(); it != str2morse.end(); ++it) {
		cout << it->first << endl;
	}
}

string MorseTree::traverseTree(string s) {
	if (isalpha(s.c_str)) {
		if (s.c_str == this->root->letter) {

		}
	}
	else {

	}
}

void MorseTree::buildtree()
{
	node * current = root;

	for (map<char, string>::const_iterator it = str2morse.begin(); it != str2morse.end(); ++it) {
		for (int i = 0; i < it->second.length(); i++) {
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


