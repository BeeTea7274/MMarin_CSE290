#include <iostream>
#include <vector>

using namespace std;

class Graph {
public:
	vector<vector<int>> graph;
	vector<int> vertices;
	int size;

	Graph(int s) : size(s), graph(s) {
		for (int i = 0; i < s; i++) {
			vertices.push_back(i);
		}
	}

	bool addEdge(int from, int to) {
		if (from >= size || from < 0) {
			return false;
		}
		if (to >= size || to < 0) {
			return false;
		}
		graph[from].push_back(to);
		return true;
	}

	bool isSafe(int pos, vector<int> path, int vertex) {
		// Check if vertex is adjacent
		bool isAdjacent = false;

		cout << "Iterating through graph\n";
		for (int v: graph[path[pos - 1]]) {
			if (v == vertex) {
				isAdjacent = true;
			}
		}
		if (!isAdjacent) {
			return false;
		}

		cout << "Iterating through path\n";
		// Check if vertex already exists in path
		for (int v : path) {
			if (v == vertex) {
				return false;
			}
		}
		
		return true;

	}

	void hamiltonianPath(int pos, vector<int> path) {
		// base case
		if (pos == size) {
			for (int v: path) {
				cout << v << " ";
			}
			cout << endl;
			return;
		}

		// Check all vertices
		for (int v : vertices) {
			if (isSafe(pos, path, v)) {
				cout << "New next vertex found! -> " << v << endl;
				path[pos] = v;
				hamiltonianPath(pos + 1, path);
				path[pos] = -1;
			}
		}
		return;
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

	// Initialize path vector and starting vertex
	vector<int> path(g.size, -1);
	path[0] = 0;
	
	g.hamiltonianPath(1, path);
}

