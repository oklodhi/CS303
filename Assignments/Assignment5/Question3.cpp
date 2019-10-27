#include <iostream>
#include "btree.cpp"

using namespace std;

// using btree.cpp --> https://gist.github.com/toboqus/def6a6915e4abd66e922

int sum_tree(node *head){
    if (head == NULL){
        return 0;
    } else {
        return head->value + sum_tree(head->left) + sum_tree(head->right);
    }
}

int main(){

	//btree tree;
	btree *tree = new btree();

	tree->insert(5);
	tree->insert(6);
	tree->insert(14);
	tree->insert(5);
	tree->insert(8);
	tree->insert(11);
	tree->insert(18);

    cout << sum_tree(tree->getNode()); 

}
