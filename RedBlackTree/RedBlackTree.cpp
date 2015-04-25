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
void RedBlackTree::leftRotate(Node *x){

}
void RedBlackTree::rightRotate(Node *y){

}
void RedBlackTree::RB_fixup(Node *z){
	while(z->parent->color == RED){
		if(z->p == z->p->p->left){
			Node * y = z->p->p->right;
			if(y->color == RED){
				z->p->color = BLACK;
				y->color = BLACK;
				z->p->p->color = RED;
				z = z->p->p
			}
			else{
				if(z == z->p->right){
					z = z->p;
					leftRotate(z);
				}
				z->p->color = BLACK;
				z->p->p->color = RED:
				rightRotate(z->p->p);
			}
		}
		else{
			Node * y = z->p->p->left;
			if(y->color == RED){
				z->p->color = BLACK;
				y->color = BLACK;
				z->p->p->color = RED;
				z = z->p->p;
			}
			else{
				if(z == z->p->right){
					z = z->p;
					rightRotate(z);
				}
				z->p->color = BLACK;
				z->p->p->color = RED;
				leftRotate(z->p->p);
			}
		}
	}
	root->color = BLACK;
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
