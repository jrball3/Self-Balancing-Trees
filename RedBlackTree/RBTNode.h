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
				delete left;
			if(right != nullptr)
				delete right;
		}
};
