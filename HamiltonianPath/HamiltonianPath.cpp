#include <iostream>
#include <vector>

using namespace std;

// Miguel's change: original allPaths anf isSafe functions remain untouched

// Number of vertices in the graph
#define V 5
vector<vector<int>> allPaths;

// Check if vertex v can be added at index 'pos' in the current path
bool isSafe(int v, bool graph[V][V], vector<int>& path, int pos) {
    // Check if this vertex is an adjacent neighbor of the previously added vertex
    if (graph[path[pos - 1]][v] == 0) return false;

    // Check if the vertex has already been included in the path
    for (int i = 0; i < pos; i++) {
        if (path[i] == v) return false;
    }
    return true;
}

// Recursive function to solve the Hamiltonian Path problem

// Miguel's change: Changed bool return to void return, because there's not really a simple way of returning true because you'd be finding more than one path. Instead opting for appending found hamiltonian paths to a vector the carries all of them. Also removing the memory address for path parameter allows the function to find multiple paths simultaneously while saving their seperate paths and not overwritting one vector.

void solveHamPath(bool graph[V][V], vector<int> path, vector<vector<int>>& allPaths, int pos) {
    // Base Case: All vertices are included in the path
    if (pos == V) {
        for (int v : path) {
            std::cout << v << " ";
        }

        // Miguel's change: in the base case it now pushes back the found hamiltonian path to the global allPaths vector

        allPaths.push_back(path);
        std::cout << endl;
        return;
    }

    // Try different vertices as the next candidate in the path
    for (int v = 0; v < V; v++) {
        bool foundPath = false;
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v; // Choose

            solveHamPath(graph, path, allPaths, pos + 1);

            path[pos] = -1; // Backtrack: Remove choice and try next
        }
    }
    return;
}

int main() {
    // Adjacency Matrix representation of the graph
    bool graph[V][V] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };

    vector<int> path(V, -1);
    path[0] = 0; // Start at vertex 0

    solveHamPath(graph, path, allPaths, 1);

    if (allPaths.size() > 0) {
        cout << endl;
        cout << "Total paths: " << allPaths.size();
    }
    else {
        cout << "No Hamiltonian Path exists." << endl;
    }

    return 0;
}