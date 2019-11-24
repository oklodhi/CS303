#pragma once

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cctype>

using namespace std; 

struct node {

public:
	char letter;
	node * lnode = nullptr;
	node * rnode = nullptr;

private:

};

class MorseTree
{
public:
	MorseTree();
	~MorseTree();
	void encode(char c, string s);
	void decode(string s, char c); 
	void buildtree();
	string traverseTree(string s);
	string searchTree(char c, string code, node * current); 


private:
	node * root;
	map<char, string> str2morse;
	map<string, char> morse2str;
};

