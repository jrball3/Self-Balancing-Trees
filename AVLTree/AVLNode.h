class AVLNode{
	public:
		int key;
		AVLNode * left;
		AVLNode * right;
		AVLNode * p;
		int balance_factor;
		int left_height;
		int right_height;
		int height;
		AVLNode(int k):
			key(k), height(1){}
};
