#pragma once
#include <vector>
#include <iostream>
#include <bitset>
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
    GraphAutomata(int size, int ourRule) : graphSize(size), rule(ourRule) {}

    void createCircularGraph(vector<CellNode*> &graph) {
        
        for (int i = 0; i < graphSize; i++) {
            graph.push_back(new CellNode());
        }
        
        for (int i = 0; i < graphSize; i++) {
            graph[i]->left = graph[((i-1) + graphSize) % graphSize];
            graph[i]->right = graph[((i+1) + graphSize) % graphSize];
        }
    }

    int applyRule(int leftState, int selfState, int rightState) {
        int combinedInt = leftState * 4 + selfState * 2 + rightState;
        bitset<8> ruleBit(rule % 256);
        return ruleBit[combinedInt];
    }

    void printGeneration() {
        for (int i = 0; i < graphSize; i++) {
            if (graph[i]->state == 0) {
                cout << " ";
            }
            else {
                cout << "*";
            }
        }
        cout << endl;

        vector<CellNode*> newVector;
        createCircularGraph(newVector);
        for (int i = 0; i < graphSize; i++) {
            newVector[i]->state = applyRule(graph[i]->left->state,graph[i]->state,graph[i]->right->state);
        }
        graph = newVector;
    }

    void applySeed() {
        if (graphSize % 2 == 0) {
            int index = graphSize / 2;
            graph[index]->state = 1;
            graph[index + 1]->state = 1;
        }
        else {
            int index = graphSize / 2;
            graph[index + 1]->state = 1;
        }
    }
};