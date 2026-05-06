#include <iostream>
#include <vector>

using namespace std;

class Graph {
public:
    vector<vector<int>> adjacencyList;
    int graphSize;
    Graph(int size) : graphSize(size), adjacencyList(size) {}

    void AddEdge(int from, int to) {
        adjacencyList[from].push_back(to);
    }

    bool IsSafe(int vertex, vector<int> path, int pos) {
        bool isAdjacent = false;
        for (int v : adjacencyList[path[pos - 1]]) {
            if (v == vertex) {
                isAdjacent = true;
            }
        }
        if (!isAdjacent) {
            return false;
        }
        for (int v : path) {
            if (v == vertex) {
                return false;
            }
        }
        return true;

    }

    void SolveHamiltonianPath(int pos, vector<int> path) {
        if (pos == graphSize) {
            for (int v : path) {
                cout << v << " ";
            }
            cout << endl;
            return;
        }

        // Try all numbers
        for (int i = 0; i < graphSize; i++) {
            if (IsSafe(i, path, pos)) {
                path[pos] = i;
                SolveHamiltonianPath(pos + 1, path);
                path[pos] = -1;
                
            }
        }
        return;
    }
};

int main()
{
    Graph g(4);
    g.AddEdge(0,1);
    g.AddEdge(1,0);
    g.AddEdge(1,2);
    g.AddEdge(1,3);
    g.AddEdge(2,3);
    g.AddEdge(3,2);
    vector<int> path(g.graphSize, -1);
    // start vertex
    path[0] = 0;
    g.SolveHamiltonianPath(1, path);
}


