class AVLNode{
	public:
		int key;
		AVLNode * left;
		AVLNode * right;
		AVLNode * p;
		int height;
		AVLNode(int k):
			key(k), height(1),left(nullptr),right(nullptr),p(nullptr){}
		~AVLNode(){
			if(left != nullptr)
				delete left;
			if(right != nullptr)
				delete right;	
		}
};
