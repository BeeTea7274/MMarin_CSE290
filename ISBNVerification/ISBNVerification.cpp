#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

// Initialized functions
void CutString(string, int, int, vector<int>*);
void PrintVect(vector<int>);

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


			int stringLength = line.length();
			int readableInts = stringLength - 4;

			// String manipulation
			// First three numbers

			CutString(line, 0, 3, &ISBNcodeVect);
			
			// Single number

			CutString(line, 4, 1, &ISBNcodeVect);

			// Second three numbers

			CutString(line, 6, 3, &ISBNcodeVect);

			// Five numbers

			CutString(line, 10, 5, &ISBNcodeVect);


			// Identifying number

			string identifyingNumber = line.substr(16, readableInts - 12);

			ISBNcodeVect.push_back(stoi(identifyingNumber));

			PrintVect(ISBNcodeVect);

			cout << endl;



			// Reset for next ISBN code
			ISBNcodeVect.clear();
		}
	}


	// If file is not found out put error code
	else {
		cerr << "File not found!";
	}
}

// Implimented Functions
void CutString(string ogString, int startIndex, int length, vector<int>* isbnVect) {
	string newString = ogString.substr(startIndex, length);
	for (int i = 0; i < length; i++) {
		isbnVect->push_back(stoi(newString.substr(i, 1)));
	}
}

// Function for printing int Vectors
void PrintVect(vector<int> vect) {
	for (int i = 0; i < vect.size(); i++) {
		cout << vect[i] << " ";
	}
}

