#pragma once

// include necessary libraries
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cctype>
#include <fstream>

using namespace std; 

// node structure that contains value (or alphabet), and left child node and right child node
struct node {
public:
	char letter;
	node * lnode = nullptr;
	node * rnode = nullptr;
};

// morse tree class that contains main functions regarding the binary tree
class MorseTree
{
public:
	MorseTree();
	~MorseTree();
	void encode(char c, string s);
	void decode(string s, char c); 
	void buildtree();
	string traverseTree(string s);
	string s2m(string s);
	
private:
	node * root;
	string currpath = "";
	map<char, string> str2morse;
	map<string, char> morse2str;
	bool search(char c, node * current);
	string searchTree(char c);
};

