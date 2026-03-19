#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <string>
#include <cstdlib>
#include "HashTable.h"
using namespace std;

int main()
{
    ifstream ISBNCodes;
    ISBNCodes.open("ValidCodes.txt", ios::in);
    string line;

    HashTable hashTable;

    // Initialize hash table with empty lists
    for (int i = 0; i < hashTable.totalBuckets; i++) {
        list<string> newlist;
        hashTable.table.push_back(newlist);
    }

    // If the txt file is open
    if (ISBNCodes.is_open()) {
        while (getline(ISBNCodes, line)) {

            if (hashTable.entries / (hashTable.totalBuckets * hashTable.listSize) > hashTable.capacity) {
                // Resize
                cout << "Resize occured" << endl << "Old totalbuckets: " << hashTable.totalBuckets << endl;
                hashTable.Resize();
                cout << "New total buckets: "<< hashTable.totalBuckets << endl;
                cout << "Entries: " << hashTable.entries << endl << endl;
            }

            int hash = hashTable.Hash(line);
            int index = hash % hashTable.totalBuckets;
            while (true) {
                if (hashTable.table[index % hashTable.totalBuckets].size() < hashTable.listSize) {
                    hashTable.table[index % hashTable.totalBuckets].push_back(line);
                    hashTable.entries++;
                    cout << "New entry at index: " << index << endl << "Line: " << line << endl << endl;
                    break;
                }
                else {
                    index++;
                }
            }

            
        }
    }

    // Print error if text file is not found
    else {
        cout << "File not found";
    }
}

