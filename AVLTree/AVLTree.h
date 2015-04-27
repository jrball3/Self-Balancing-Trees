#include "Node.h"
#include <utility>

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
		Node * getRoot();
		std::pair<int,int> height(Node * n, int l_height, int r_height);
};
