#include "AVLTree.h"
#include <iostream>

AVLTree::AVLTree(){
	root = nullptr;
}

void AVLTree::insertNode(int key){
	
}
void AVLTree::height(Node * n){
	Node * left_tree = n;	
	Node * right_tree = n;
	if(left_tree->left != nullptr){
		left_tree->left_height++;
		height(left_tree->left);
	}
	else if(right_tree->right != nullptr){
		right_tree->right_height++;
		height(right_tree->right);			
	}
	else{
		n->left_height = 0;
		n->right_height = 0;
		n->balance_factor = 0;
		return;
	}
	
	return;
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
