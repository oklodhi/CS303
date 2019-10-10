#include <vector>
#include <iostream>

using namespace std;

int linear_search(vector<int>& items, int target, size_t pos_last) { 
	if (pos_last == -1) 
		return -1; 
	if (target == items.at(pos_last))
		return pos_last;
	else 
		return linear_search(items, target, pos_last - 1); 
}

int main(){
	vector<int> vec_x = { 4,6,78,2,346,4,84,653,2,346,7,87,9 };
	int x = linear_search(vec_x, 2, vec_x.size() - 1);
	cout << x;
	return 0;
}
