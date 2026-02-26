#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include "DoublyLinkedList.h"
#include <cstdlib>

using namespace std;

// Initialized functions
void CutString(string, int, int, vector<int>*, bool);
void PrintVect(vector<int>);
bool VerifyISBN(vector<int>);
int CalculateSubjectNumber(vector<int>);

int main() {
	// Vector for storing individual integers in an ISBN code and identifying prime numbers
	vector<int> ISBNcodeVect;
	vector<int> PrimeNumbers;
	vector<DoublyLinkedList*> ListHeads;

	// Map for subjects and their respective prime numbers
	map<int, string> SubjectNums = { {61,"Biology"},{71,"English"},
		{97,"Math"},{73,"Physics"},{103,"Psychology"},{79,"Computer Science"}, 
		{53,"Spanish"}, {83,"French"},{113,"Chemistry"}};

	// Create ISBNcodes ifstream object and open in input mode
	ifstream ISBNcodes;
	ISBNcodes.open("ISBN_Codes.txt", ios::in);
	string line;

	// bool for first line parsing
	bool isFirstLine = true;

	// Creation of all list heads and pushback to vector that holds it
	for (auto it = SubjectNums.begin(); it != SubjectNums.end(); it++) 
	{
		// Debug terminal message
		cout << it->first << " " << it->second << endl;

		DoublyLinkedList* ListHead = new DoublyLinkedList(it->first, it->second);
		ListHeads.push_back(ListHead);
	}
	
	cout << endl;

	// For every ISBN code in ISBNcodes.txt
	if (ISBNcodes.is_open()) {
		while (getline(ISBNcodes, line)) {
			int stringLength = line.length();

			// Prime numbers for subjects
			if (isFirstLine) {

				//first line parsing for prime numbers
				CutString(line, 0, stringLength, &PrimeNumbers, isFirstLine);
				isFirstLine = false;
				PrintVect(PrimeNumbers);
				cout << endl;
			}
			else {
			
				// String manipulation

				CutString(line, 0, stringLength, &ISBNcodeVect, isFirstLine);

				// If ISBN is valid then add it to its appropriate list
				if (VerifyISBN(ISBNcodeVect)) 
				{
					int SubjectNum = CalculateSubjectNumber(ISBNcodeVect);
					cout << SubjectNums[SubjectNum] << endl;

					// Make a linked list node and append it
					DoublyLinkedListNode* newNode = new DoublyLinkedListNode(ISBNcodeVect, line, SubjectNums[SubjectNum]);

					for (int i = 0; i < ListHeads.size(); i++) 
					{
						if (ListHeads[i]->identifyingNum == SubjectNum) {
							ListHeads[i]->appendNode(newNode);
							i = ListHeads.size();
						}
					}
				}
				else 
				{
					cout << "ISBN not added to list\n";
				}
	
				PrintVect(ISBNcodeVect);

				cout << endl;

				// Reset for next ISBN code
				ISBNcodeVect.clear();
			}
		}
		system("PAUSE");
		system("cls");
	}


	// If file is not found out put error code
	else {
		cerr << "File not found!";
	}

	// Print from list traversal
	for (int i = 0; i < ListHeads.size(); i++) 
	{
		ListHeads[i]->printList();
	}
}

// Implimented Functions
void CutString(string ogString, int startIndex, int length, vector<int>* isbnVect, bool isFirstLine) {
	
	// Set new string to the line
	string newString = ogString.substr(startIndex, length);

	// If the line is an ISBN code then parse it
	if (!isFirstLine) 
	{
		for (int i = 0; i < length; i++) {
			string newStringpart = newString.substr(i, 1);
			if (newStringpart != "-" && newStringpart != " " && newStringpart != ",") {
				isbnVect->push_back(stoi(newString.substr(i, 1)));
			}
		}
	}
	// First line of prime numbers
	else 
	{
		string newPrime;
		for (int i = 0; i < length; i++) {
			string newStringpart = newString.substr(i, 1);
			if (newStringpart != ":") {
				newPrime += newStringpart;
			}
			else {
				isbnVect->push_back(stoi(newPrime));
				newPrime = "";
			}
		}
	}
	
}

// Function for printing int Vectors
void PrintVect(vector<int> vect) {
	for (int i = 0; i < vect.size(); i++) {
		cout << vect[i] << " ";
	}
	cout << endl;
}

// ISBN Verifier
bool VerifyISBN(vector<int> ISBNVect) 
{	// Weighted addition
	int sum = 0;
	for (int i = 0; i < ISBNVect.size() - 1; i++) 
	{
		if (i % 2 == 0) 
		{
			sum += ISBNVect[i];
		}
		else {
			sum += ISBNVect[i];
		}
	}

	// If the remainder is 0 sjip to the check
	if (sum % 10 == 0) {
		if (sum == ISBNVect[12])
		{
			cout << "VALID ISBN\n";
			return true;
		}
		else {
			cout << "INVALID ISBN\n";
			return false;
		}
	}
	// Else take the remainder and subtract it from 10 and perform the check
	else{
		sum = 10 - (sum % 10);
		if (sum == ISBNVect[12]) 
		{
			cout << "VALID ISBN\n";
			return true;
		}
		else {
			cout << "INVALID ISBN\n";
			return false;
		}

	}
}

// Simple addition of the first 12 numbers
int CalculateSubjectNumber(vector<int> ISBNVect) 
{
	int sum = 0;
	for (int i = 0; i < ISBNVect.size() - 1; i++) 
	{
		sum += ISBNVect[i];
	}
	return sum;
}

