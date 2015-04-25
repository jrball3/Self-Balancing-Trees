#include <iostream>
#include <sstream>
#include <string>
#include "BinarySearchTree.h"

using namespace std;

int main(int argc, char * argv[]){
	BinarySearchTree bst;
	bst.insert(10);
	if(argc != 2){
		cout << "USAGE ./trees <input-file>" << endl;
	}
	
	string file(argv[1]);
	ofstream infile(file);	
	string line;
	BinarySearchTree BST;
	while(getline(infile, line)){
		stringstream ss(line);
		int input;
		ss >> input;
		BST.insert(input);		
	}
	BST.printContents();
	return EXIT_SUCCESS;
}
