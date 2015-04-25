#include "RedBlackTree.h"
#include <iostream>
using namespace std;

RedBlackTree::RedBlackTree(){
	root = nullptr;
	sentinel = new Node();
	sentinel->left = nullptr;
	sentinel->right = nullptr;
	sentinel->color = BLACK;	
}
void RedBlackTree::insertNode(int key){
	
}

Node * RedBlackTree::search(int key){
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

void RedBlackTree::printContents(){
	inorderTreeWalk(root);
	std::cout << std::endl;	
} 
