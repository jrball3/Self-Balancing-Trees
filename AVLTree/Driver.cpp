#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include "AVLTree.h"

using namespace std;

int main(int argc, char * argv[]){
	if(argc != 2){
		cout << "USAGE ./trees <input-file>" << endl;
		exit(1);
	}
	
	string file(argv[1]);
	ifstream infile(file);	
	string line;
	AVLTree AVL;
	while(getline(infile, line)){
		stringstream ss(line);
		int input;
		ss >> input;
		AVL.insertNode(input);		
	}
	AVL.printContents();
	AVL.height(AVL.getRoot(), 0, 0);
	cout << "The balance factor from the root is " << AVL.getRoot()->balance_factor << endl;
	cout << "The left height from the root is " << AVL.getRoot()->left_height << endl;
	cout << "The right height from the root is " << AVL.getRoot()->right_height << endl;
	return EXIT_SUCCESS;
}
