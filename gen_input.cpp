#include <string>
#include <iostream>
#include <fstream>
#include <math.h>
#include <stdlib.h>     

using namespace std;

int main(int argc, char const *argv[]) {
	ofstream output;
	int num_nodes, low_range, up_range, choice;

	output.open("input_file.txt");
	cout << "Enter number of nodes: ";
	cin >> num_nodes;
	cout << "Random? (1 for yes, 0 for no) ";
	cin >> choice;
	cout << "Enter lower range for values (inclusive): ";
	cin >> low_range;
	//random numbers within specified range
	if (choice == 0) {
		cout << "Enter upper range for values (inclusive): ";
		cin >> up_range;
		for (int i = 0; i < num_nodes; i++) {
			int num = rand() % (up_range - low_range + 1) + low_range;	 //generate random number
			output << num << "\n";
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