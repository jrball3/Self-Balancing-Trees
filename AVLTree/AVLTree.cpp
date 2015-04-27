#include "AVLTree.h"
#include <iostream>

AVLTree::AVLTree(){
	root = nullptr;
}

void AVL::insertNode(int key){
	Node * x = new Node();
	x->key = key;
}

Node * AVLTree::search(int key){
	Node * n = root;

	while(n != nullptr && key != n->key){
		if(key < n->key){
			n = n->left;
		}
		else{
			n = n->right;
		}
	}
	return n;
}

void inorderTreeWalk(Node * x){
	if(x != nullptr){
		inorderTreeWalk(x->left);
		std::cout << x->key << " ";
		inorderTreeWalk(x->right);
	}
}

void AVLTree::printContents(){
	inorderTreeWalk(root);
	std::cout << std::endl;	
} 

void AVLTree::leftRotate(Node * x) {
	Node * y = x->right;	
	// if (y->left != nullptr)	x->right = y->left;
	// else x->right = nullptr;
	x->right = y->left;
	y->left = x;
	if (x->p != nullptr) {
		Node * z = x->p;						
		z->left = y;
		y->p = z;	
	} else {
		y->p = nullptr;
	}
	x->p = y;							
}

void AVLTree::rightRotate(Node * x) {
	Node * y = x->left;	
	// if (y->left != nullptr)	x->right = y->left;
	// else x->right = nullptr;
	x->left = y->right;
	y->right = x;
	if (x->p != nullptr) {
		Node * z = x->p;						
		z->right = y;
		y->p = z;	
	} else {
		y->p = nullptr;
	}
	x->p = y;	
}