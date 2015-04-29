#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "RedBlackTree.h"

using namespace std;

int main(int argc, char * argv[]){
	if(argc != 2){
		cout << "USAGE ./trees <input-file>" << endl;
		return 1;
	}
	
	string file(argv[1]);
	ifstream infile(file);	
	string line;
	RedBlackTree RBT;
	while(getline(infile, line)){
		stringstream ss(line);
		int input;
		ss >> input;	
		RBT.insertNode(input);
	}
	RBT.printContents();
	RBT.showTree();
	return 0;
}
