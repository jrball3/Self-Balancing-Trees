#include "Node.h"
#include <utility>

class AVLTree{
	private:
		Node * root;
	public:
		void insertNode(int key);
		Node * search(int key);
		void printContents();
		AVLTree();
		Node * getRoot();
		std::pair<int,int> height(Node * n, int l_height, int r_height);
};
