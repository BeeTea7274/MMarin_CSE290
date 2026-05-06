#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>

using namespace std;

class Graph {
public:
    vector<vector<int>> adj;
    int size;
    Graph(int s) : size(s), adj(s) {}

    bool addEdge(int from, int to) {
        if (from < 0 || from >= size) {
            return false;
        }
        else if (to < 0 || to >= size) {
            return false;
        }
        adj[from].push_back(to);
        return true;
    }

    void dfsIterative() {
        
    }

    bool dfsRecursive(int startIndex) {
        vector<bool> visited(size, false);
        dfsRecursiveAgent(startIndex, visited);

        for (bool b : visited) {
            cout << b << " ";
        }
        cout << endl;

        for (bool b : visited) {
            if (!b) {
                return false;
            }
        }
        return true;
    }

    void dfsRecursiveAgent(int v, vector<bool> &visited) {
        visited[v] = true;
        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                dfsRecursiveAgent(neighbor, visited);
            }
        }
    }

    bool bfs(int startVertex) {
        queue<int> frontierQueue;
        vector<int> discoveryList;

        frontierQueue.push(startVertex);
        int currVertex;

        while (frontierQueue.size() > 0) {
            currVertex = frontierQueue.front();
            frontierQueue.pop();
            discoveryList.push_back(currVertex);
            for (int neighbor : adj[currVertex]) {
                bool visited = false;
                for (int v: discoveryList) {
                    if (v == neighbor) {
                        visited = true;
                    }
                }
                if (!visited) {
                    frontierQueue.push(neighbor);
                }
            }
        }

        for (int v : discoveryList) {
            cout << v << " ";
        }
        cout << endl;

        // Returns true if all nodes have been visited
        if (discoveryList.size() == size) {
            return true;
        }
        else {
            return false;
        }
    }
};

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 0);
    g.addEdge(3, 1);
    g.addEdge(2, 3);

    g.bfs(0);

    if (g.dfsRecursive(0)) {
        cout << "All nodes visited via DFS!" << endl;
    }
    else {
        cout << "Some nodes remain unvisited via DFS!" << endl;
    }
}
