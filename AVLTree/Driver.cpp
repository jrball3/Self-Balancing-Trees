#include <iostream>
#include <fstream>
#include <sstream>
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
	return EXIT_SUCCESS;
}
