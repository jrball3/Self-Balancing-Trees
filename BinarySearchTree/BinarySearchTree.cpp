#include "BinarySearchTree.h"
#include <iostream>

void BinarySearchTree::insertNode(int key){
	Node * n = new Node();
	n->key = key;
	
	Node * y = nullptr;
	Node * x = root;

	while(x != nullptr){
		y = x;
		if(n->key < x->key){
			x = x->left;
		}
		else{
			x = x->right;
		}
	}
	n->parent = y;
	if(y == nullptr){
		root = n;
	}
	else if(n->key < y->key){
		y->left = n;
	}
	else{
		y->right = n;
	}
}

Node * BinarySearchTree::search(int key){
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

void BinarySearchTree::printContents(){
	inorderTreeWalk(root);
	std::cout << std::endl;	
} 
