#include "RBTNode.h"

#define RED 1
#define BLACK 2

class RedBlackTree{
	private:
		RBTNode * root;
		RBTNode * sentinel;
	public:
		void insertNode(int key);
		RBTNode * search(int key);
		void leftRotate(RBTNode * x);
		void rightRotate(RBTNode * y);
		void RB_fixup(RBTNode * z);
		int size(RBTNode *n);
		void printContents();
		void showTree();
		RedBlackTree();
};
