#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Graph {
private:

	int numVertices;

	// Adjacency list
	vector<vector<int>> graph;

public:

	Graph(int numVert) : numVertices(numVert), graph(numVert) {}
	
	void addEdge(int u, int v) {
		// Assert statement to check if u and v are in the graph
		if (u >= numVertices || v >= numVertices) {
			cout << "u or v are out of bounds!\n";
			return;
		}
		graph[u].push_back(v);
	}

	void addBiDirectionalEdge(int u, int v) {
		// Assert statement to check if u and v are in the graph
		if (u >= numVertices || v >= numVertices) {
			cout << "u or v are out of bounds!\n";
			return;
		}
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	void depthFirstSearch(vector<bool>& visited, int u) {

		visited[u] = true;
		cout << u << endl;
		for (int v : graph[u]) {
			if (!visited[v]) {
				depthFirstSearch(visited, v);
			}

		}
	}
};

int main() {
	Graph g(10);

	// Adding edge from 0 to 3
	g.addEdge(0,3);
	g.addEdge(3,4);
	g.addEdge(4,5);
	g.addEdge(5,3);
	g.addEdge(0,2);
	g.addEdge(5,2);

	vector<bool> visited(6);
	visited[0] = true;
	g.depthFirstSearch(visited, 0);

}