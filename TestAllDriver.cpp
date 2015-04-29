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
	
	if(argc != 1){
		cout << "USAGE: ./a.out" << endl;
		exit(1);
	}

	ofstream output("output.txt");	
	
	string quit = "n";
	while (quit != "y") {
		string input;
		string rand_choice;
		string dupe_choice;
		cout << "Enter name of input file: ";
		cin >> input;
		cout << "Is input file in random order? (y/n)";
		cin >> rand_choice;
		if (rand_choice == "y") {
			cout << "Does the random file contain duplicates? (y/n)";
			cin >> dupe_choice;
		}
		ifstream infile(input);
		vector<int> inputs;
			
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
		
		time_t sec;
		int microsec;
		
		struct timeval starttime, endtime;
		
		//==========================AVL Insert==========================//
		gettimeofday(&starttime, 0);
		for(auto i : inputs){
			AVL.insertNode(i);
		}
		gettimeofday(&endtime, 0);
		sec = endtime.tv_sec - starttime.tv_sec;
		microsec = (endtime.tv_usec - starttime.tv_usec);
		if (rand_choice == "y") {
			cout << "Total CPU time for AVL inserting " << inputs.size() << " randomly ordered nodes: " << sec << "." << abs(microsec) << endl;
			output << "Total CPU time for AVL inserting " << inputs.size() << " randomly ordered nodes: " << sec << "." << abs(microsec) << endl;
		} else {
			cout << "Total CPU time for AVL inserting " << inputs.size() << " sequentially ordered nodes: " << sec << "." << abs(microsec) << endl;
			output << "Total CPU time for AVL inserting " << inputs.size() << " sequentially ordered nodes: " << sec << "." << abs(microsec) << endl;
		}

		//==========================RBT Insert==========================//
		// gettimeofday(&starttime, 0);
		// for(auto i : inputs){
		// 	AVL.insertNode(i);
		// }
		// gettimeofday(&endtime, 0);
		// sec = endtime.tv_sec - starttime.tv_sec;
		// microsec = (endtime.tv_usec - starttime.tv_usec);
		// if (rand_choice == "y") {
		// 	cout << "Total CPU time for RBT inserting " << inputs.size() << " randomly ordered nodes: " << sec << "." << abs(microsec) << endl;
		// 	output << "Total CPU time for RBT inserting " << inputs.size() << " randomly ordered nodes: " << sec << "." << abs(microsec) << endl;
		// } else {
		// 	cout << "Total CPU time for RBT inserting " << inputs.size() << " sequentially ordered nodes: " << sec << "." << abs(microsec) << endl;
		// 	output << "Total CPU time for RBT inserting " << inputs.size() << " sequentially ordered nodes: " << sec << "." << abs(microsec) << endl;
		// }

		//==========================BST Insert==========================//
		gettimeofday(&starttime, 0);
		for(auto i : inputs){
			AVL.insertNode(i);
		}
		gettimeofday(&endtime, 0);
		sec = endtime.tv_sec - starttime.tv_sec;
		microsec = (endtime.tv_usec - starttime.tv_usec);
		if (rand_choice == "y") {
			cout << "Total CPU time for BST inserting " << inputs.size() << " randomly ordered nodes: " << sec << "." << abs(microsec) << endl;
			output << "Total CPU time for BST inserting " << inputs.size() << " randomly ordered nodes: " << sec << "." << abs(microsec) << endl;
		} else {
			cout << "Total CPU time for BST inserting " << inputs.size() << " sequentially ordered nodes: " << sec << "." << abs(microsec) << endl;
			output << "Total CPU time for BST inserting " << inputs.size() << " sequentially ordered nodes: " << sec << "." << abs(microsec) << endl;
		}
	
		//==========================AVL Search==========================//
		gettimeofday(&starttime, 0);
		for(auto i : inputs){
			AVL.seach(i);
		}
		gettimeofday(&endtime, 0);
		sec = endtime.tv_sec - starttime.tv_sec;
		microsec = (endtime.tv_usec - starttime.tv_usec);
		if (rand_choice == "y") {
			cout << "Total CPU time for AVL searching " << inputs.size() << " randomly ordered nodes: " << sec << "." << abs(microsec) << endl;
			output << "Total CPU time for AVL searching " << inputs.size() << " randomly ordered nodes: " << sec << "." << abs(microsec) << endl;
		} else {
			cout << "Total CPU time for AVL seraching " << inputs.size() << " sequentially ordered nodes: " << sec << "." << abs(microsec) << endl;
			output << "Total CPU time for AVL searching " << inputs.size() << " sequentially ordered nodes: " << sec << "." << abs(microsec) << endl;
		}


		//==========================RBT Search==========================//
		// gettimeofday(&starttime, 0);
		// for(auto i : inputs){
		// 	RBT.seach(i);
		// }
		// gettimeofday(&endtime, 0);
		// sec = endtime.tv_sec - starttime.tv_sec;
		// microsec = (endtime.tv_usec - starttime.tv_usec);
		// if (rand_choice == "y") {
		// 	cout << "Total CPU time for RBT searching " << inputs.size() << " randomly ordered nodes: " << sec << "." << abs(microsec) << endl;
		// 	output << "Total CPU time for RBT searching " << inputs.size() << " randomly ordered nodes: " << sec << "." << abs(microsec) << endl;
		// } else {
		// 	cout << "Total CPU time for RBT seraching " << inputs.size() << " sequentially ordered nodes: " << sec << "." << abs(microsec) << endl;
		// 	output << "Total CPU time for RBT searching " << inputs.size() << " sequentially ordered nodes: " << sec << "." << abs(microsec) << endl;
		// }

		//==========================BST Search==========================//
		gettimeofday(&starttime, 0);
		for(auto i : inputs){
			BST.seach(i);
		}
		gettimeofday(&endtime, 0);
		sec = endtime.tv_sec - starttime.tv_sec;
		microsec = (endtime.tv_usec - starttime.tv_usec);
		if (rand_choice == "y") {
			cout << "Total CPU time for BST searching " << inputs.size() << " randomly ordered nodes: " << sec << "." << abs(microsec) << endl;
			output << "Total CPU time for BST searching " << inputs.size() << " randomly ordered nodes: " << sec << "." << abs(microsec) << endl;
		} else {
			cout << "Total CPU time for BST seraching " << inputs.size() << " sequentially ordered nodes: " << sec << "." << abs(microsec) << endl;
			output << "Total CPU time for BST searching " << inputs.size() << " sequentially ordered nodes: " << sec << "." << abs(microsec) << endl;
		}

		int size = vector.size()-1;
		int random_index = rand() % size;
		int random_num = vector.at(random_index);

		//==========================AVL Search On Random Num==========================//
		gettimeofday(&starttime, 0);
		AVL.seach(i);
		gettimeofday(&endtime, 0);
		sec = endtime.tv_sec - starttime.tv_sec;
		microsec = (endtime.tv_usec - starttime.tv_usec);
		if (rand_choice == "y") {
			cout << "Total CPU time for AVL search on " << random_num << " over "<< inputs.size() << " randomly ordered nodes: " << sec << "." << abs(microsec) << endl;
			output << "Total CPU time for AVL search on " << random_num << " over "<< inputs.size() << " randomly ordered nodes: " << sec << "." << abs(microsec) << endl;
		} else {
			cout << "Total CPU time for AVL search on " << random_num << " over "<< inputs.size() << " sequentially ordered nodes: " << sec << "." << abs(microsec) << endl;
			output << "Total CPU time for AVL search on " << random_num << " over "<< inputs.size() << " sequentially ordered nodes: " << sec << "." << abs(microsec) << endl;
		}

		//==========================RBT Search On Random Num==========================//
		// gettimeofday(&starttime, 0);
		// RBT.seach(i);
		// gettimeofday(&endtime, 0);
		// sec = endtime.tv_sec - starttime.tv_sec;
		// microsec = (endtime.tv_usec - starttime.tv_usec);
		// if (rand_choice == "y") {
		// 	cout << "Total CPU time for RBT search on " << random_num << " over "<< inputs.size() << " randomly ordered nodes: " << sec << "." << abs(microsec) << endl;
		// 	output << "Total CPU time for RBT search on " << random_num << " over "<< inputs.size() << " randomly ordered nodes: " << sec << "." << abs(microsec) << endl;
		// } else {
		// 	cout << "Total CPU time for RBT search on " << random_num << " over "<< inputs.size() << " sequentially ordered nodes: " << sec << "." << abs(microsec) << endl;
		// 	output << "Total CPU time for RBT search on " << random_num << " over "<< inputs.size() << " sequentially ordered nodes: " << sec << "." << abs(microsec) << endl;
		// }

		//==========================BST Search On Random Num==========================//
		gettimeofday(&starttime, 0);
		BST.seach(i);
		gettimeofday(&endtime, 0);
		sec = endtime.tv_sec - starttime.tv_sec;
		microsec = (endtime.tv_usec - starttime.tv_usec);
		if (rand_choice == "y") {
			cout << "Total CPU time for BST search on " << random_num << " over "<< inputs.size() << " randomly ordered nodes: " << sec << "." << abs(microsec) << endl;
			output << "Total CPU time for BST search on " << random_num << " over "<< inputs.size() << " randomly ordered nodes: " << sec << "." << abs(microsec) << endl;
		} else {
			cout << "Total CPU time for BST search on " << random_num << " over "<< inputs.size() << " sequentially ordered nodes: " << sec << "." << abs(microsec) << endl;
			output << "Total CPU time for BST search on " << random_num << " over "<< inputs.size() << " sequentially ordered nodes: " << sec << "." << abs(microsec) << endl;
		}

		cout << "Quit? (y/n) " << endl;
		cin >> quit;
		infile.close();
	
	}
	
	return 0;
}
	