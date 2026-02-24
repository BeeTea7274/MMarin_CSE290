#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main() {
    // Jeff implimented the file manipulation logic
    vector<vector<int>> ISBNVectors = { {9,7,8,0,3,0,6,4,0,6,1,5,7},{9,7,8,0,3,0,6,4,0,6,1,5,7},{9,7,8,0,3,0,6,4,0,6,1,5,7} }; // This is assuming that ISBNVectors is populated
    ofstream outputFile("ISBNCodes.txt", ios::out);

    if (!outputFile.is_open()) {
        cout << "File not found" << endl;
    }
    else {

        // Miguel did the Iteration logic
        for (vector<int> ISBNVect : ISBNVectors) {
            int count = 0;
            for (int num : ISBNVect) {
                // Appends a dash to complete an ISBN code
                if (count == 3 || count == 4 || count == 7 || count == 12) {
                    outputFile << "-";
                    cout << "-";
                }
                outputFile << ISBNVect[count];
                cout << ISBNVect[count];
                // 978-0-306-40615-7

                count++;
            }
            cout << endl;
            outputFile << endl;
        }

    }
}