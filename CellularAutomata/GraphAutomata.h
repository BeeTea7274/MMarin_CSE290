#pragma once
#include <vector>
using namespace std;

class GraphAutomata {
public:

    class CellNode {
    public:
        CellNode* left;
        CellNode* right;
        int state;
        CellNode(int initialState = 0) : state(initialState), left(nullptr), right(nullptr) {}
    };
    std::vector<CellNode*> graph;
    int graphSize;
    int rule;

    // Constructor function 
    GraphAutomata(int size, int ourRule) : graphSize(size), graph(size), rule(ourRule) {}

    void createCircularGraph() {
        // For loop to initialize cell node -> new CellNode()

        // Another loop to assign right and left pointers

        //  left  ptr ->  i -1 + graphSize  % graphSize - = 9

        // right  i + 1   %  graphSize : 0 -> 1, 1 -> 2


    }

    int applyRule(int leftState, int selfState, int rightState) {

        //  1 0 1   ->  3
        // leftState << 2;  // leftState = 4
        // selftState << 1   // selfState  -> 2 ^ 1  = 2  
        // focusedDigit = leftState | selftState | rightState   // in this case focused digit is 7

        //  RUle # 224    
        //  1  1  1  0  1  0  0  0
            //128
            //64
            //32
            //2 2 4

            //retrun(rule >> focusedDigit) % 1

        return 0;
    }

    void printGeneration() {
    
    }
};