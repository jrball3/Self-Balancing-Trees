#include "AVLTree.h"
#include <iostream>
#include <queue>
#include <unordered_map>

AVLTree::AVLTree(){
	root = nullptr;
}

AVLTree::~AVLTree(){
	if(root != nullptr)
		delete root;
}

AVLNode * AVLTree::getRoot(){
	return root;
}

int max(int x, int y){
	return (x > y) ? x : y;
}

// New recursive insert
AVLNode * AVLTree::insertHelper(AVLNode * n, AVLNode * p, int key){
	if(n == nullptr){
		AVLNode * newNode = new AVLNode(key);
		newNode->p = p;
		return newNode;
	}

	if(key < n->key){
		n->left = insertHelper(n->left, n, key);
	}
	else if(key > n->key){
		n->right = insertHelper(n->right, n, key);
	}
	else{
		AVLNode * d = search(key);
		bool sResult = true;
		if(d == nullptr)
			sResult = false;
		std::cout << "Key " << key << " is already in the tree. True? " << sResult << std::endl;
	}

	n->height = max(getHeight(n->left), getHeight(n->right)) + 1;
	// Check the balance of the current node
 
    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (getBalanceFactor(n) >= 2){ //TREE IS LEFT HEAVY
        if(getBalanceFactor(n->left) < 0){ //LEFT SUBTREE IS RIGHT HEAVU
			//n->left = 
			leftRotate(n->left); //LEFT RIGHT ROTATION, 'DOUBLE RIGHT'
			return rightRotate(n);
		}
		else{
			return rightRotate(n);
		}
    } 
    else if(getBalanceFactor(n) <= -2){ //TREE IS RIGHT HEAVY
		if(getBalanceFactor(n->right) > 0){ //RIGHT SUBTREE IS LEFT HEAVU
			//n->right = 
			rightRotate(n->right); //RIGHT LEFT ROTATION, 'DOUBLE RIGHT'
			return leftRotate(n);
		}
		else{
			return leftRotate(n);
		}
    }

	return n;
}

void AVLTree::insertNode(int key){
	root = insertHelper(root, nullptr, key);
//	std::cout << "Inserting " << key << std::endl;
}

int AVLTree::getHeight(AVLNode *n){
	if(n == nullptr)
		return 0;
	else return n->height;
}

int AVLTree::getBalanceFactor(AVLNode *n){
	return getHeight(n->left) - getHeight(n->right);
}

AVLNode * AVLTree::search(int key){
	AVLNode * n = root;

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

// Returns count of nodes walked
void inorderTreeWalk(AVLNode * x){
	if(x != nullptr){
		inorderTreeWalk(x->left);
		std::cout << x->key << " ";
		inorderTreeWalk(x->right);
	}
}

int size(AVLNode *n) {
	if(n == NULL) {
		return 0;
	} 
	else {
        	return size(n->left) + size(n->right) + 1;
	}
}

void AVLTree::printContents(){
	inorderTreeWalk(root);
	std::cout << std::endl;
	std::cout << "The number of the nodes in the tree is " << size(root) << std::endl;
} 

void preorderTreeWalk(AVLNode * x){
	if(x != nullptr){
		if(x != nullptr){
			std::cout << x->key << " parent: " << x->p->key << std::endl;
		}
		preorderTreeWalk(x->left);
		preorderTreeWalk(x->right);
	}
}
void AVLTree::showTree(){
	preorderTreeWalk(root);
	std::cout << std::endl;
}
	

// Working left rotate
AVLNode * AVLTree::leftRotate(AVLNode* x){
	AVLNode * y = x->right;
	x->right = y->left;
	if(y->left != nullptr){
		y->left->p = x;
	}
	y->p = x->p;
	if(x->p == nullptr){
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

	// Update the node values
	x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
	y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
	return y;
}

// Working right rotate
AVLNode * AVLTree::rightRotate(AVLNode* x){
	AVLNode * y = x->left;
	x->left = y->right;
	if(y->right != nullptr){
		y->right->p = x;
	}
	y->p = x->p;
	if(x->p == nullptr){
		root = y;
	}
	else if(x == x->p->right){
		x->p->right =y;
	}
	else{
		x->p->left = y;
	}
	y->right = x;
	x->p = y;

	// Update the node values
	y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
	x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

	return y;
}


double AVLTree::testInput(std::string file){
	std::string line;
	int num_success;
	double avg_ticks = 0;
	int num_input = 0;
	std::ifstream infile(file);
	while(getline(infile, line)){
		std::stringstream s(line);
		int input;
		num_input++;
		s >> input;
		int t1 = clock();
		AVLNode * n = search(input);
		int t2  = clock() - t1;
		std::cout << t2 << std::endl;
		avg_ticks += t2;
		if(n->key == input){
			num_success++;
		}
	}
	avg_ticks = avg_ticks / num_input;
	return avg_ticks;
}
