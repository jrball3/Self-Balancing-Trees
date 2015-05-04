#include <string>
#include <iostream>
#include <fstream>
#include <math.h>
#include <stdlib.h>     
#include <limits.h>

using namespace std;

int main(int argc, char const *argv[]) {
	srand(time(NULL));
	string outputname;
	ofstream output;
	int num_nodes, low_range, up_range;
	string choice;
	cout << "Enter name of output file: ";
	cin >> outputname;
	output.open(outputname.c_str());
	cout << "Enter number of nodes: ";
	cin >> num_nodes;
	cout << "Random? (y/n) ";
	cin >> choice;
	cout << "Enter lower range for values (inclusive): ";
	cin >> low_range;
	int *table = new int[num_nodes];
	for (int i = 0; i < num_nodes; i++) table[i] = INT_MAX;	
	//random numbers within specified range
	if (choice == "y") {
		cout << "Enter upper range for values (inclusive): ";
		cin >> up_range;
		if (up_range - low_range < num_nodes) {
			cout << "Range must be greater than number of nodes." << endl;
			return 1;	
		}
		int i = 0;
		while(i < num_nodes) {
			int num = rand() % (up_range - low_range + 1) + low_range;	 //generate random number
			if (table[num-low_range] == INT_MAX){
				table[num-low_range] = num;
				output << num << "\n";
				i++;
			} 	
		}
	}
	//numbers in order
	else {
		for (int i = low_range; i < (num_nodes + low_range); i++) {
			output << i << "\n";
		}
	}

	output.close();
	return 0;
}
