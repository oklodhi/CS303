#pragma once
#include <iostream>
#include "btree.h"

using namespace std;

// using btree.cpp --> https://gist.github.com/toboqus/def6a6915e4abd66e922

int Bst_Util(node *node, int min, int max) {
	if (node == NULL)
		return 1;
	if (node->value < min || node->value > max)
		return 0;
	return
		Bst_Util(node->left, min, node->value - 1) &&
		Bst_Util(node->right, node->value + 1, max);
}

int is_bst(node *head) {
	return Bst_Util(head, INT_MIN, INT_MAX);
}

int main() {

	//btree tree;
	btree *tree = new btree();

	tree->insert(5);
	tree->insert(6);
	tree->insert(14);
	tree->insert(5);
	tree->insert(8);
	tree->insert(11);
	tree->insert(18);

	if (is_bst(tree->getNode()))
		cout << "This tree is a BST" << endl;
	else
		cout << "This tree is not a BST" << endl;

	return 0;

}
