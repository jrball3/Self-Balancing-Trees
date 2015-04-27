#include "AVLTree.h"
#include <iostream>

AVLTree::AVLTree(){
	root = nullptr;
}

Node * AVLTree::getRoot(){
	return root;
}

void AVLTree::insertNode(int key){
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
	n->p = y;
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

std::pair<int,int> AVLTree::height(Node * n, int l_height, int r_height){	
	if(n->left != nullptr){
		l_height++;
		l_height = height(n->left, l_height, r_height).first;
	}
	if(n->right != nullptr){
		r_height++;
		r_height = height(n->right, l_height, r_height).second;			
	}
	if(n->right == nullptr && n->left == nullptr){
		n->left_height = 0;
		n->right_height = 0;
		n->balance_factor = 0;
		return std::pair<int,int>(l_height, r_height);
	}
	n->right_height = r_height;
	n->left_height = l_height;
	n->balance_factor = l_height - r_height;
	// Negative balance factor > 1 is too high on the right
	// Positive balance factor > 1 is too high on the left
	return std::pair<int,int>(l_height, r_height);
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
