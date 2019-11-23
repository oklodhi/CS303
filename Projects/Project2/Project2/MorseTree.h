#pragma once

#include <iostream>
#include <string>
#include <map>

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
	void printEncode(); 
	void buildtree();
	string traverseTree(string s); 


private:
	node * root;
	map<char, string> str2morse;
	map<string, char> morse2str;
};

