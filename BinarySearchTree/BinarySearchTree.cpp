#include "BinarySearchTree.h"
#include <iostream>

BinarySearchTree::BinarySearchTree(){
	root = nullptr;
}

BinarySearchTree::~BinarySearchTree(){
	if(root != nullptr)
		delete root;
}

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

void preorderTreeWalk(Node * x){
	if(x != nullptr){
		if(x->parent != nullptr){
			std::cout << x->key << " parent: " << x->parent->key << std::endl;
		}
		preorderTreeWalk(x->left);
		preorderTreeWalk(x->right);		
	}
}
void BinarySearchTree::showTree(){
	preorderTreeWalk(root);
	std::cout << std::endl;
}
