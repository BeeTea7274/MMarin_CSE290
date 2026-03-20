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
            double entries = hashTable.entries;
            double totalBuckets = hashTable.totalBuckets;
            double listSize = hashTable.listSize;
            cout << (entries / (totalBuckets * listSize)) << endl;
            if ((entries / (totalBuckets * listSize)) > hashTable.capacity) {
                // Resize
                cout << "Resize occured" << endl << "Old totalbuckets: " << totalBuckets << endl;
                cout << entries / (totalBuckets * listSize) << endl << endl;
                hashTable.Resize();
                cout << "New total buckets: "<< totalBuckets << endl;
                cout << "Entries: " << entries << endl << endl;
            }

            hashTable.AddItem(line);
            
            
        }
        system("Pause");
        system("cls");
        hashTable.PrintTable();

        if (hashTable.SearchItem("182-0-987-67094-9")) {
            cout << "Item found!" << endl;
        }
        else {
            cout << "Item not found!" << endl;
        }
        if (hashTable.DeleteItem("182-0-987-67094-9")) {
            cout << "Deletion successful!" << endl;
        }
        if (hashTable.SearchItem("182-0-987-67094-9")) {
            cout << "Item found!" << endl;
        }
        else {
            cout << "Item not found!" << endl;
        }
    }

    // Print error if text file is not found
    else {
        cout << "File not found";
    }
}

