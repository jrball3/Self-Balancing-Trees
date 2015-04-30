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

/*
void AVLTree::insertNode(int key){
	AVLNode * n = new Node();
	n->key = key;
	
	AVLNode * y = nullptr;
	AVLNode * x = root;

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

	// Update the node values
	//height(root, 0, 0, true);
	// if(n == root->left || n == root->right)
		// n->height = 1;
	// else
		// n->height = max(getHeight(n->right), getHeight(n->left));
	if(n->p != nullptr)
		n->height = n->p->height + 1;
	else
		n->height = 0;

	// Call fixup function to balance the tree
	//balanceTree(n);
}
*/

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
	// if(wentLeft)
	// 	balanceTree(n->left);
	// else
	// 	balanceTree(n->right);

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

// function that iterates up from a node,
// checking and balancing as it goes up
void AVLTree::balanceTree(AVLNode * n){
	AVLNode * p = n->p;
	while(p != nullptr){
		// If n's balance factor is 0, then a
		// rotation will not affect it's height.
		// Skip this iteration
		if(getBalanceFactor(n) != 0){
			if(getBalanceFactor(p) > 1){
				if(getBalanceFactor(n) < 0){
					// left right case
					leftRotate(n);
				}
				// Left left case
				rightRotate(p);
			}
			else if(getBalanceFactor(p) < -1){
				// If n's balance factor is 0, then a
				// rotation will not affect it's height.
				// Skip this iteration
				if(getBalanceFactor(n) > 0){
					// Right left case
					rightRotate(n);
				}
				// Right right case
				leftRotate(p);
			}
		}
		
		// Move up a node
		n = p;
		p = n->p;
	}
}
/*
std::pair<int,int> AVLTree::height(AVLNode * n, int l_height, int r_height, bool verbose){	
	if(n->left != nullptr){
		l_height++;
		l_height = height(n->left, l_height, r_height, verbose).first
	}
	if(n->right != nullptr){
		r_height++;
		r_height = height(n->right, l_height, r_height, verbose).second;			
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
	if(verbose){
		if(n->balance_factor < -1 || n->balance_factor > 1){
			std::cerr << "WARNING: TREE UNBALANCED(" 
				<< n->balance_factor << ") AT NODE WITH KEY " << n->key << std::endl;
		}
	}
	// Negative balance factor > 1 is too high on the right
	// Positive balance factor > 1 is too high on the left
	return std::pair<int,int>(l_height, r_height);
}
*/

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
