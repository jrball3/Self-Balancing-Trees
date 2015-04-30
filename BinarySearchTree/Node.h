class Node{
	public:
		int key;
		Node * left;
		Node * right;
		Node * parent;
		Node():key(0),left(nullptr),right(nullptr),parent(nullptr){}
		~Node(){
			if(left != nullptr)
				delete left;
			if(right != nullptr)
				delete right;
		}
};
