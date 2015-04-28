class Node{
	public:
		int key;
		Node * left;
		Node * right;
		Node * p;
		int balance_factor;
		int left_height;
		int right_height;
		int height;
		Node(int k):
			key(k){}
};
