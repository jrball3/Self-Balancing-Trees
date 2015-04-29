#include <cstdlib>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include "AVLTree/AVLTree.h"
#include "RedBlackTree/RedBlackTree.h"
#include "BinarySearchTree/BinarySearchTree.h"
#include <sys/time.h>

using namespace std;

int main(int argc, char * argv[]){
	if(argc != 2){
		cout << "USAGE ./trees <input-file>" << endl;
		exit(1);
	}
	vector<int> inputs;
	string file(argv[1]);
	ifstream infile(file);
	ofstream output("output.txt");		
	string line;
	while(getline(infile, line)){
		if(line != ""){
			stringstream ss(line);
			int input;
			ss >> input;
			inputs.push_back(input);
		}
	}
	AVLTree AVL;
	RedBlackTree RBT;
	BinarySearchTree BST;
	struct timeval starttime, endtime;
	//AVL
	for(auto i : inputs){
		gettimeofday(&starttime, 0);
		AVL.insertNode(i);
		gettimeofday(&endtime, 0);
		time_t sec = endtime.tv_sec - starttime.tv_sec;
		int microsec = (endtime.tv_usec - starttime.tv_usec);
		cout << "Total CPU time for AVL inserting " << inputs.size() << " nodes: " << sec << "." << abs(microsec) << endl;
		output << "Total CPU time for AVL inserting " << inputs.size() << " nodes: " << sec << "." << abs(microsec) << endl;
	}
	//RBT
	for(auto i : inputs){
		gettimeofday(&starttime, 0);
		RBT.insertNode(i);
		gettimeofday(&endtime, 0);
		sec = endtime.tv_sec - starttime.tv_sec;
		microsec = (endtime.tv_usec - starttime.tv_usec);
		output << cout << "Total CPU time for RBT inserting " << inputs.size() << " nodes: " << sec << "." << abs(microsec) << endl;
		// output << "Total CPU time for RBT inserting " << inputs.size() << " nodes: " << sec << "." << abs(microsec) << endl;	
	}

	//BST
	for(auto i : inputs){
		gettimeofday(&starttime, 0);
		BST.insertNode(i);
		gettimeofday(&endtime, 0);
		sec = endtime.tv_sec - starttime.tv_sec;
		microsec = (endtime.tv_usec - starttime.tv_usec);
		cout << "Total CPU time for BST inserting " << inputs.size() << " nodes: " << sec << "." << abs(microsec) << endl;
		output << "Total CPU time for BST inserting " << inputs.size() << " nodes: " << sec << "." << abs(microsec) << endl;	
	}



	return 0;
}
	