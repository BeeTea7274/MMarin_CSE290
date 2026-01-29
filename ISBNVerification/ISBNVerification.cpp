#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main() {
	// Vector for storing individual integers in an ISBN code
	vector<int> ISBNcodeVect;

	// Create ISBNcodes ifstream object and open in input mode
	ifstream ISBNcodes;
	ISBNcodes.open("ISBNcodes.txt", ios::in);
	string line;

	// For every ISBN code in ISBNcodes.txt
	if (ISBNcodes.is_open()) {
		while (getline(ISBNcodes, line)) {

			// String manipulation
			// First three numbers

			string first3Int = line.substr(0,3);
			cout << first3Int << " ";

			// Single number

			string loneInt = line.substr(4,1);
			cout << loneInt << " ";

			// Second three numbers

			string second3Int = line.substr(6,3);
			cout << second3Int << " ";

			// Five numbers

			string fiveInt = line.substr(10,5);
			cout << fiveInt << " ";

			// Identifying number
			string identifyingInt = line.substr();

			cout << endl;
		}
	}


	// If file is not found out put error code
	else {
		cerr << "File not found!";
	}
}
