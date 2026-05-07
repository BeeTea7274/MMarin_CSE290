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

	bool isCyclic() {
		vector<bool> visited(size, false);
		for (int v : vertices) {
			if (!visited[v]) {
				if (isCyclicRecursive(visited, -1, v)) {
					return true;
				}
			}	
		}
		return false;
	}

	bool isCyclicRecursive(vector<bool> &visited, int parent, int vertex) {
		visited[vertex] = true;
		for (int v : graph[vertex]) {
			if (!visited[v]) {
				if (isCyclicRecursive(visited, vertex, v)) {
					return true;
				}
			}
			else if (v != parent) {
				return true;
			}
		}
		return false;
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

	

	if(g.isCyclic()){
		cout << "Graph is cyclic!";
	}
	else {
		cout << "Graph is not cyclic!";
	}
}
