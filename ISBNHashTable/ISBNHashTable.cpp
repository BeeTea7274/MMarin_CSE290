#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <string>
#include <cstdlib>
using namespace std;

int Hash(string);
void Resize(vector<list<string>>*, int);

int main()
{
    ifstream ISBNCodes;
    ISBNCodes.open("ValidCodes.txt", ios::in);
    string line;

    vector<list<string>> hashTable;
    int totalBuckets = 3;
    int listSize = 10;
    float capacity = 0.75;
    int entries = 0;

    // Initialize hash table with empty lists
    for (int i = 0; i < totalBuckets; i++) {
        list<string> newlist;
        hashTable.push_back(newlist);
    }

    // If the txt file is open
    if (ISBNCodes.is_open()) {
        while (getline(ISBNCodes, line)) {

            if (entries / (totalBuckets * listSize) > capacity) {
                // Resize
                totalBuckets *= 2;
                Resize(&hashTable, totalBuckets);
            }

            cout << "Hash: " << Hash(line) << endl;
            cout << Hash(line) % totalBuckets << endl;
            entries++;
            
        }
    }

    // Print error if text file is not found
    else {
        cout << "File not found";
    }
}

int Hash(string code) {
    int hashCode = 0;
    for (char c : code) {
        hashCode += c;
    }
    return hashCode;
}

void Resize(vector<list<string>>* hashTable, int buckets) {
    vector<list<string>> oldTable = *hashTable;
    vector<list<string>>* newTable = new vector<list<string>>;
    
    for (int i = 0; i < buckets; i++) {
        list<string> newList;
        newTable->push_back(newList);
    }

    for (int i = 0; i < oldTable.size(); i++) {
        list<string>::iterator it;
        for (it = oldTable[i].begin(); it != oldTable[i].end(); it++) {

        }
    }

}