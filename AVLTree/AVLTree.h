#include "AVLNode.h"
#include <utility>
#include <string>
#include <fstream> 
#include <sstream>

class AVLTree{
	private:
		AVLNode * root;
	public:
		void insertNode(int key);
		AVLNode * insertHelper(AVLNode * n, AVLNode *p, int key);
		AVLNode * search(int key);
		void printContents();
		AVLNode * leftRotate(AVLNode * x);
		AVLNode * rightRotate(AVLNode * x);
		void balanceTree(AVLNode * n);
		AVLTree();
		~AVLTree();
		AVLNode * getRoot();
		std::pair<int,int> height(AVLNode * n, int l_height, int r_height, bool verbose);
		int getHeight(AVLNode *n);
		int getHeightOfSubtree(AVLNode *n);
		int getBalanceFactor(AVLNode *n);
		double testInput(std::string file);
		void showTree();
};
