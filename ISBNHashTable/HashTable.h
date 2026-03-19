#pragma once
#include <vector>
#include <list>
#include <string>

using namespace std;

class HashTable {
public:
    vector<list<string>> table;
    int totalBuckets = 3;
    int listSize = 10;
    float capacity = 0.75;
    int entries = 0;

    void Resize() {
        // Temporary tables
        vector<list<string>> oldTable = table;
        vector<list<string>> newTable;

        // Double total buckets
        this->totalBuckets *= 2;

        // Initialize the new table with new total buckets
        for (int i = 0; i < this->totalBuckets; i++) {
            list<string> newList;
            newTable.push_back(newList);
        }

        // For every item in the old table
        for (int i = 0; i < oldTable.size(); i++) {
            list<string>::iterator it;
            for (it = oldTable[i].begin(); it != oldTable[i].end(); it++) {
                // Rehash and add it to the new table
                int hashCode = Hash(*it);
                while (true) {
                    if (newTable[hashCode % this->totalBuckets].size() < this->listSize) {
                        newTable[hashCode % this->totalBuckets].push_back(*it);
                        break;
                    }
                    else {
                        hashCode++;
                    }
                }
                
            }
        }

        this->table = newTable;
    }

    int Hash(string code) {
        int hashCode = 0;
        for (char c : code) {
            hashCode += c;
        }
        return hashCode;
    }

    bool addItem(string code) {
    
    
    }

};