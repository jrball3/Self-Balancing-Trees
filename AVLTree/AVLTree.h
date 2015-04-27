#include "Node.h"

class AVLTree{
	private:
		Node * root;
	public:
		void insertNode(int key);
		Node * search(int key);
		void printContents();
		AVLTree();
		void height(Node * n);
		Node * getRoot();
};
