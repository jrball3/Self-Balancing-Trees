#include <climits>
class RBTNode{
	public:
		int key;
		RBTNode * left;
		RBTNode * right;
		RBTNode * p;
		int color;
		RBTNode():
			key(0),color(1),left(nullptr),right(nullptr),p(nullptr){}
		~RBTNode(){
			if(left != nullptr)
				if(left->key != INT_MAX) delete left;
			if(right != nullptr)
				if(right->key != INT_MAX) delete right;
		}
};
