#include "Node.h"

class BinarySearchTree{
	private:
		Node * root;

	public:
		void insertNode(int key);
		Node * search(int key);
		void printContents();
};
