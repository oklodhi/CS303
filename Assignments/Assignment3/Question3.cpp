#include <iostream>
#include <string>
#include <stack>
#include <sstream>

using namespace std;

int main()
{
	stack<string> _stack ;
	string str("The quick brown fox jumps over the lazy dog.");
  
  string token; 
  stringstream ss(str); 
  
  while (ss >> token){
    _stack.push(token);
  }    

	while(!_stack.empty())
	{
    cout << _stack.top() << " "; 
		_stack.pop();
	}

	return 0;
}
