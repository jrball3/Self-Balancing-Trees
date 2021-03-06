#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include "AVLTree.h"

using namespace std;

int main(int argc, char * argv[]){
	if(argc != 2){
		cout << "USAGE ./trees <input-file>" << endl;
		exit(1);
	}
	
	string file(argv[1]);
	ifstream infile(file);	
	string line;
	AVLTree AVL;
	while(getline(infile, line)){
		if(line != ""){
			stringstream ss(line);
			int input;
			ss >> input;
			AVL.insertNode(input);		

	/*		cout << "The height at the root is " << AVL.getHeight(AVL.getRoot()) << endl;
			cout << "The balance factor from the root is " << AVL.getBalanceFactor(AVL.getRoot()) << endl;
			cout << "The height of the root's left subtree is " << AVL.getHeight(AVL.getRoot()->left) << endl;
			cout << "The height of the root's right subtree is " << AVL.getHeight(AVL.getRoot()->right) << endl;
*/
		}
	}
	AVL.printContents();
	infile.close();
//	double avg_ticks  = AVL.testInput(file);
//	cout << "Average number of ticks: " << avg_ticks << endl;
	// This will test a tree up to a height of 2
	// with 8 nodes (complete tree)
	bool testRotations = false;
	if(testRotations){
		cout << "Enter a node to rotate : ";
		int rotNode;
		cin >> rotNode;
		int direction;
		cout << "What direction? (left = 1, right = 2): ";
		cin >> direction;
		AVLNode * n = AVL.search(rotNode);
		if(n == nullptr){
			cout << "Node is not in the tree" << endl;
			return 1;
		}
		if(direction == 1){
			AVL.leftRotate(n);
			cout << "Rotation done." << endl;
		}
		else if(direction == 2){
			AVL.rightRotate(n);
			cout << "Rotation done." << endl;
		}
		else{
			cout << "Invalid entry." << endl;
			return 1;
		}
		AVLNode * rootAfterRotate = AVL.getRoot();
		cout << "Root = " << rootAfterRotate->key << endl;
		AVLNode * rightChild = rootAfterRotate->right;
		AVLNode * leftChild = rootAfterRotate->left;
		if(rightChild != nullptr){
			cout << "Root->right = " << rootAfterRotate->right->key << endl;
			AVLNode * rightRightChild = rootAfterRotate->right->right;
			if(rightRightChild != nullptr){
				cout << "Root->right->right = " << rootAfterRotate->right->right->key << endl;
			}
			AVLNode * rightLeftChild = rootAfterRotate->right->left;
			if(rightLeftChild != nullptr){
				cout << "Root->right->left = " << rootAfterRotate->right->left->key << endl;
			}
		}
		if(leftChild != nullptr){
			cout << "Root->left = " << rootAfterRotate->left->key << endl;
			AVLNode * leftLeftChild = rootAfterRotate->left->left;
			if(leftLeftChild != nullptr){
				cout << "Root->left->left = " << rootAfterRotate->left->left->key << endl;
			}
			AVLNode * leftRightChild = rootAfterRotate->left->right;
			if(leftRightChild != nullptr){
				cout << "Root->left->right = " << rootAfterRotate->left->right->key << endl;
			}
		}
		cout << "n now points to " << n->key << endl;
	}
	//AVL.height(AVL.getRoot(), 0, 0, false);

	return 0;
}
