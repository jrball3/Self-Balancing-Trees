#include "AVLTree.h"
#include <iostream>

AVLTree::AVLTree(){
	root = nullptr;
}

void AVLTree::insertNode(int key){
	
}
std::pair<int,int> AVLTree::height(Node * n, int l_height, int r_height){
	Node * left_tree = n;	
	Node * right_tree = n;
	if(left_tree->left != nullptr){
		l_height++;
		l_height = height(left_tree->left, l_height, r_height).first;
	}
	else if(right_tree->right != nullptr){
		r_height++;
		r_height = height(right_tree->right, l_height, r_height).second;			
	}
	else{
		n->left_height = 0;
		n->right_height = 0;
		n->balance_factor = 0;
		return std::pair<int,int>(l_height, r_height);
	}
	
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
