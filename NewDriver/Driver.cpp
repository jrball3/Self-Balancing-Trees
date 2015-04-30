#include "../BinarySearchTree/BinarySearchTree.h"
#include "../AVLTree/AVLTree.h"
#include "../RedBlackTree/RedBlackTree.h"
#include <iostream>

using namespace std;

int main(int argc, char * argv[]){

	AVLTree avl;
	RedBlackTree rbt;
	BinarySearchTree bst;

	for(int i = 0; i < 10; i++){
		avl.insertNode(i);
		rbt.insertNode(i);
		bst.insertNode(i);
	}

	cout << "Displaying AVL Contents..." << endl;
	avl.printContents();
	cout << "============= End AVL contents" << endl;
	cout << "Displaying RBT Contents..." << endl;
	rbt.printContents();
	cout << "============= End AVL contents" << endl;
	cout << "Displaying BST Contents..." << endl;
	bst.printContents();
	cout << "============= End AVL contents" << endl;

	return 0;
}
