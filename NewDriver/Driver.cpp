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
	
	string filename(argv[1]);
	string line;
	int input_count = 0;	
	
	double AVL_avg_time;
	double RBT_avg_time;
	double BST_avg_time;
	std::vector<int> test_input;
	ifstream infile(filename);
	while(getline(infile, line)){
		stringstream ss(line);
		int input = 0;
		ss >> input;		
		input_count++;
		test_input.push_back(input);
	}
	infile.close();

	auto tAVL1 = Clock::now();
	for(int i = 0; i < test_input.size(); i++){
		avl.insertNode(test_input[i]);
	}
	auto tAVL2 = Clock::now();
	nanoseconds_type AVL_duration (std::chrono::duration_cast<nanoseconds_type>(tAVL2 - tAVL1));
	
	auto tRBT1 = Clock::now();
	for(int i = 0; i < test_input.size(); i++){
		rbt.insertNode(test_input[i]);
	}
	auto tRBT2 = Clock::now();
	nanoseconds_type RBT_duration (std::chrono::duration_cast<nanoseconds_type>(tRBT2 - tRBT1));

	auto tBST1 = Clock::now();
	for(int i = 0; i < test_input.size(); i++){
		bst.insertNode(test_input[i]);
	}
	auto tBST2 = Clock::now();
	nanoseconds_type BST_duration (std::chrono::duration_cast<nanoseconds_type>(tBST2 - tBST1));


	cout << "Displaying AVL Contents..." << endl;
	avl.showTree();
	cout << "============= End AVL contents" << endl;
	cout << "Displaying RBT Contents..." << endl;
	rbt.showTree();
	cout << "============= End RBT contents" << endl;
	cout << "Displaying BST Contents..." << endl;
	bst.showTree();
	cout << "============= End BST contents" << endl;

	cout << "AVL insertion time: " << AVL_duration.count() << " nanoseconds" << endl;
	cout << "RBT insertion time: " << RBT_duration.count() << " nanoseconds" << endl;
	cout << "BST insertion time: " << BST_duration.count() << " nanoseconds" << endl;

	cout << "Proceeding to test search \n" << "============================" << endl;
	
	double avl_avg_search = 0;
	double rbt_avg_search = 0;
	double bst_avg_search = 0;
	
	for(int i = 0; i < input_count; i++){
		int target = rand() % input_count;
		
		auto tAVL1 = Clock::now();
		avl.search(target);
		auto tAVL2 = Clock::now();
		nanoseconds_type AVL_duration (std::chrono::duration_cast<nanoseconds_type>(tAVL2 - tAVL1));
//		cout << "AVL search taking: " << AVL_duration.count() << " nanoseconds" << endl;
		avl_avg_search += AVL_duration.count();

		auto tRBT1 = Clock::now();
		rbt.search(target);
		auto tRBT2 = Clock::now();
		nanoseconds_type RBT_duration (std::chrono::duration_cast<nanoseconds_type>(tRBT2 - tRBT1));
//		cout << "RBT search taking: " << RBT_duration.count() << " nanoseconds" << endl;
		rbt_avg_search += RBT_duration.count();

		auto tBST1 = Clock::now();
		bst.search(target);
		auto tBST2 = Clock::now();
		nanoseconds_type BST_duration (std::chrono::duration_cast<nanoseconds_type>(tBST2 - tBST1));
//		cout << "BST search taking: " << BST_duration.count() << " nanoseconds" << endl;
		bst_avg_search += BST_duration.count();
	}
	
	cout << "AVL average search time: " << avl_avg_search/input_count << " nanoseconds" << endl;
	cout << "RBT average search time: " << rbt_avg_search/input_count << " nanoseconds" << endl;
	cout << "BST average search time: " << bst_avg_search/input_count << " nanoseconds" << endl;

	return 0;
}
