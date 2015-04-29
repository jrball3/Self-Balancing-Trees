#include "AVLTree.h"
#include <iostream>
#include <queue>
#include <unordered_map>

AVLTree::AVLTree(){
	root = nullptr;
}

Node * AVLTree::getRoot(){
	return root;
}

int max(int x, int y){
	return (x > y) ? x : y;
}

/*
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
Node * AVLTree::insertHelper(Node * n, Node * p, int key){
	if(n == nullptr){
		Node * newNode = new Node(key);
		newNode->p = p;
		return newNode;
	}

	if(key < n->key){
		n->left = insertHelper(n->left, n, key);
	}
	else
		n->right = insertHelper(n->right, n, key);

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
		n->left = leftRotate(n->left); //LEFT RIGHT ROTATION, 'DOUBLE RIGHT'
		return rightRotate(n);
	}
	else{
		return rightRotate(n);
	}
    } 
    else if(getBalanceFactor(n) <= -2){ //TREE IS RIGHT HEAVY
	if(getBalanceFactor(n->right) > 0){ //RIGHT SUBTREE IS LEFT HEAVU
		n->right = rightRotate(n->right); //RIGHT LEFT ROTATION, 'DOUBLE RIGHT'
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
}
//-----------------------


// Alternative height gathering functions
int heightHelper(Node* n) {
   if (n == nullptr) 
       return 0;
   else{
       int lHeight = heightHelper(n->left);
       int rHeight = heightHelper(n->right);
 
 		if(lHeight > rHeight)
 			return (lHeight+1);
 		else return (rHeight+1);
   }
} 

int AVLTree::getHeightOfSubtree(Node * n){
	return heightHelper(n) - 1;
}
//-------------------------------------


int AVLTree::getHeight(Node *n){
	if(n == nullptr)
		return 0;
	else return n->height;
}

int AVLTree::getBalanceFactor(Node *n){
	return getHeight(n->left) - getHeight(n->right);
}

// function that iterates up from a node,
// checking and balancing as it goes up
void AVLTree::balanceTree(Node * n){
	Node * p = n->p;
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

std::pair<int,int> AVLTree::height(Node * n, int l_height, int r_height, bool verbose){	
	if(n->left != nullptr){
		l_height++;
		l_height = height(n->left, l_height, r_height, verbose).first;
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

// Working left rotate
Node * AVLTree::leftRotate(Node* x){
	Node * y = x->right;
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
	y->height = max(getHeight(y->right), x->height) + 1;
	return y;
}

// Working right rotate
Node * AVLTree::rightRotate(Node* x){
	Node * y = x->left;
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
	x->height = max(getHeight(x->left), y->height) + 1;

	return y;
}


/* // Root not being reassigned
void AVLTree::rightRotate(Node *x){
	Node * y = x->left;
	x->left = y->right;
	if(y->right != nullptr){
		y->right->p = x;
	}
	x->p = y->p;
	if (y->p == nullptr) {
		root = x;
	} else if (y == y->p->right) {
		y->p->right = x;
	} else {
		y->p->left = x;
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
	}
}*/
