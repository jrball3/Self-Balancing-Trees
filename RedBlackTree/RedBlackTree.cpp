#include "RedBlackTree.h"
#include <iostream>
#include <climits>
using namespace std;

RedBlackTree::RedBlackTree(){
	sentinel = new Node();
	root = sentinel;
	sentinel->left = nullptr;
	sentinel->right = nullptr;
	sentinel->color = BLACK;	
	sentinel->key = INT_MAX;
}
void RedBlackTree::leftRotate(Node* x){
	Node * y = x->right;
	x->right = y->left;
	if(y->left != sentinel){
		y->left->p = x;
	}
	y->p = x->p;
	if(x->p == sentinel){
		root = y;
	}
	else if(x == x->p->left){
		x->p->left =y;
	}
	else{
		x->p->right = y;
	}
	y->left = x;
	x->p = y;
}
void RedBlackTree::rightRotate(Node *y){
	Node *x = y->left; 	
	y->left = x->right;
	if (x->right != sentinel) {
		(x->right)->p = y;
	}
	x->p = y->p;
	if (y->p == sentinel) {
		root = x;
	} else if (y == y->p->right) {
		y->p->right = x;
	} else {
		y->p->left = x;
	}
	x->right = y;
	y->p = x;
	
}
void RedBlackTree::RB_fixup(Node *z){
	while(z->p->color == RED){
		if(z->p == z->p->p->left){
			Node * y = z->p->p->right;
			if(y->color == RED){
				z->p->color = BLACK;
				y->color = BLACK;
				z->p->p->color = RED;
				z = z->p->p;
			}
			else{
				if(z == z->p->right){
					z = z->p;
					leftRotate(z);
				}
				z->p->color = BLACK;
				z->p->p->color = RED;
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
				if(z == z->p->left){
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
	Node * y = sentinel;
	Node * x = root;
	Node * z = new Node();
	z->key = key;
	while(x != sentinel){
		y = x;
		if(z->key < x->key){
			x = x->left;
		}
		else{
			x = x->right;
		}
	}
	z->p = y;
	if(y == sentinel){
		root = z;
	}
	else if(z->key < y->key){
		y->left = z;
	}
	else{
		y->right = z;
	}
	z->left = sentinel;
	z->right = sentinel;
	z->color = RED;
	RB_fixup(z);
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
		if(x->key != INT_MAX){
			std::cout << x->key << " ";
		}
		inorderTreeWalk(x->right);
	}
}

void RedBlackTree::printContents(){
	inorderTreeWalk(root);
	std::cout << std::endl;	
} 

