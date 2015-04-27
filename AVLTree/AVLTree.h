#include "Node.h"

class AVLTree{
	private:
		Node * root;

	public:
		void insertNode(int key);
		Node * search(int key);
		void printContents();
		void leftRotate(Node * x);
		void rightRotate(Node * x);
		AVLTree();
};
