#include "RBTNode.h"
#include <string>
#include <sstream>
#include <fstream>

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
		long double test_search(std::string infile);
		RedBlackTree();
};
