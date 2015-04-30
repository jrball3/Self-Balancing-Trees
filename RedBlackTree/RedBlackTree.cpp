#include "RedBlackTree.h"
#include <iostream>
#include <climits>
#include <sys/time.h>
using namespace std;

RedBlackTree::RedBlackTree(){
	sentinel = new RBTNode();
	sentinel->left = nullptr;
	sentinel->right = nullptr;
	sentinel->color = BLACK;	
	sentinel->key = INT_MAX;
	root = sentinel;
}

RedBlackTree::~RedBlackTree(){
	if(root != nullptr)
		delete root;	
	delete sentinel;
}

void RedBlackTree::leftRotate(RBTNode* x){
	RBTNode * y = x->right;
	x->right = y->left;
	if(y->left != sentinel){
		y->left->p = x;
	}
	y->p = x->p;
	if(x->p == sentinel){
		root = y;
	}
	else if(x == x->p->left){
		x->p->left = y;
	}
	else{
		x->p->right = y;
	}
	y->left = x;
	x->p = y;
}
void RedBlackTree::rightRotate(RBTNode *x){
	RBTNode * y = x->left;
	x->left = y->right;
	if(y->right != sentinel){
		y->right->p = x;
	}
	y->p = x->p;
	if (x->p == sentinel) {
		root = y;
	} 
	else if (x == x->p->right) {
		x->p->right = y;
	} 
	else {
		x->p->left = y;
	}	
	y->right = x;
	x->p = y;
}
void RedBlackTree::RB_fixup(RBTNode *z){
	while(z->p->color == RED){
		if(z->p == z->p->p->left){
			RBTNode * y = z->p->p->right;
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
			RBTNode * y = z->p->p->left;
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
	RBTNode * y = sentinel;
	RBTNode * x = root;
	RBTNode * z = new RBTNode();
	z->key = key;
	while(x != sentinel){
		y = x;
		if(z->key < x->key){
			x = x->left;
		}
		else if(z->key > x->key){
			x = x->right;
		}
		else{
			RBTNode * d = search(key);
			bool sResult = true;
			if(d == nullptr)
				sResult = false;
			std::cout << "Key " << key << " is already in the tree. True? " << sResult << std::endl;
			return;
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
RBTNode * RedBlackTree::search(int key){
	RBTNode * n = root;

	while(n != sentinel && key != n->key){
		if(key < n->key){
			n = n->left;
		}
		else{
			n = n->right;
		}
	}
	
	return n;
}

void inorderTreeWalk(RBTNode * x){
	if(x != nullptr){
		inorderTreeWalk(x->left);
		if(x->key != INT_MAX){
			std::cout << x->key << " ";
		}
		inorderTreeWalk(x->right);
	}
}
int RedBlackTree::size(RBTNode *n) {
	if(n == sentinel) {
		return 0;
	} 
	else {
        	return size(n->left) + size(n->right) + 1;
	}
}

void RedBlackTree::printContents(){
	inorderTreeWalk(root);
	std::cout << std::endl;
	std::cout << "The number of the nodes in the tree is " << size(root) << std::endl;
} 

void preorderTreeWalk(RBTNode * x){
	if(x != nullptr){
		if(x->key != INT_MAX){
			std::cout << x->key << " parent: " << x->p->key << " color: RED 1 BLACK 2 " << x->color << endl;
		}
		preorderTreeWalk(x->left);
		preorderTreeWalk(x->right);
	}
}
void RedBlackTree::showTree(){
	preorderTreeWalk(root);
	std::cout << std::endl;
}

long double RedBlackTree::test_search(string file){
	string line;
	int num_success;
	long double avg_ticks = 0;
	int num_input = 0;
	struct timeval t1, t2;
	ifstream infile(file);
	while(getline(infile, line)){
		stringstream s(line);
		int input;
		num_input++;
		s >> input;
		gettimeofday(&t1, NULL);
		double time1 = t1.tv_sec + (t1.tv_usec/1000000.0);
		RBTNode * n = this->search(input);
		gettimeofday(&t1, NULL);
		double time2 = t1.tv_sec + (t1.tv_usec/1000000.0);
		cout << time2 - time1 << endl;
		if(n->key == input){
			num_success++;
		}
	}
	cout << "avg ticks: " <<  avg_ticks / num_input << endl;
	return avg_ticks;
}




