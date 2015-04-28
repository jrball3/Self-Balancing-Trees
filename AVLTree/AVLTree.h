#include "Node.h"
#include <utility>

class AVLTree{
	private:
		Node * root;
	public:
		void insertNode(int key);
		Node * insertHelper(Node * n, Node *p, int key);
		Node * search(int key);
		void printContents();
		Node * leftRotate(Node * x);
		Node * rightRotate(Node * x);
		void balanceTree(Node * n);
		AVLTree();
		Node * getRoot();
		std::pair<int,int> height(Node * n, int l_height, int r_height, bool verbose);
		int getHeight(Node *n);
		int getHeightOfSubtree(Node *n);
		int getBalanceFactor(Node *n);
};
