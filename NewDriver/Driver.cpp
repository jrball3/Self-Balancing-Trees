#include "../BinarySearchTree/BinarySearchTree.h"
#include "../AVLTree/AVLTree.h"
#include "../RedBlackTree/RedBlackTree.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <chrono>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc, char * argv[]){

	if(argc != 2){
		cout << "USAGE: ./test <input_file>" << endl;
	}
	
	AVLTree avl;
	RedBlackTree rbt;
	BinarySearchTree bst;
	
	typedef std::chrono::high_resolution_clock Clock;
	typedef std::chrono::duration<int,std::nano> nanoseconds_type;
	
//	vector<std::chrono::time_point> AVL_times;
//	vector<std::chrono::time_point> RBT_times;
//	vector<std::chrono::time_point> BST_times;
	
	string filename(argv[1]);
	string line;
	
	ifstream infile(filename);
	while(getline(infile, line)){
		stringstream ss(line);
		int input = 0;
		ss >> input;		

		auto tAVL1 = Clock::now();
		avl.insertNode(input);
		auto tAVL2 = Clock::now();
		nanoseconds_type AVL_duration (std::chrono::duration_cast<nanoseconds_type>(tAVL2 - tAVL1));
		cout << "AVL insert taking: " << AVL_duration.count() << " nanoseconds" << endl;
		
		auto tRBT1 = Clock::now();
		rbt.insertNode(input);
		auto tRBT2 = Clock::now();
		nanoseconds_type RBT_duration (std::chrono::duration_cast<nanoseconds_type>(tRBT2 - tRBT1));
		cout << "RBT insert taking: " << RBT_duration.count() << " nanoseconds" << endl;
		
		auto tBST1 = Clock::now();
		bst.insertNode(input);
		auto tBST2 = Clock::now();
		nanoseconds_type BST_duration (std::chrono::duration_cast<nanoseconds_type>(tBST2 - tBST1));
		cout << "BST insert taking: " << BST_duration.count() << " nanoseconds" << endl;
		
	}

	cout << "Displaying AVL Contents..." << endl;
	avl.printContents();
	cout << "============= End AVL contents" << endl;
	cout << "Displaying RBT Contents..." << endl;
	rbt.printContents();
	cout << "============= End AVL contents" << endl;
	cout << "Displaying BST Contents..." << endl;
	bst.printContents();
	cout << "============= End AVL contents" << endl;

	return 0;
}
