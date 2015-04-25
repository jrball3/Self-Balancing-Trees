#include "Node.h"

#define RED 1
#define BLACK 2

class RedBlackTree{
	private:
		Node * root;
		Node * sentinel;
	public:
		void insertNode(int key);
		Node * search(int key);
		void leftRotate(Node * x);
		void rightRotate(Node * y);
		void RB_fixup(Node * z);
		void printContents();
		RedBlackTree();
};
