#include "AVLTree.h"
#include <iostream>

AVLTree::AVLTree(){
	root = nullptr;
}

void AVL::insertNode(int key){
	
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
