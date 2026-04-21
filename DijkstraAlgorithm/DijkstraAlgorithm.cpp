#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Vertex {
public:
	Vertex* previous;
	double distance;
	int ID;
	bool visited;
	Vertex(int id) : previous(nullptr), distance(INFINITY), ID(id), visited(false) {}
};

class Edge {
public:
	double weight;
	Vertex* fromVertex;
	Vertex* toVertex;
	Edge(double weight, Vertex* from, Vertex* to) : weight(weight), fromVertex(from), toVertex(to) {};
};

class Graph {
public:
	vector<vector<Edge*>> adjacencyList;
	vector<Vertex*> vertices;
	int graphSize;

	Graph(int size) : graphSize(size), adjacencyList(size) {
		for (int i = 0; i < this->graphSize; i ++) {
			vertices.push_back(new Vertex(i));
		}
	}

	Vertex* Search(int v) {
		for (Vertex* vertex : vertices) {
			if (vertex->ID == v) {
				return vertex;
			}
		}
		return nullptr;
	}


	void AddEdge(int u, int v, int d) {
		adjacencyList[u].push_back(new Edge(d,Search(u),Search(v)));
	}

	Vertex* Dijkstra(Vertex* startVertex) {
		list<Vertex*> unvisited;

		for (Vertex* v : vertices) {
			v->distance = INFINITY;
			v->previous = nullptr;
			unvisited.push_back(v);
		}

		startVertex->distance = 0;

		Vertex* currVertex = startVertex;

		while (unvisited.size() > 0){
			// Mark the current vertex as visited
			unvisited.remove(currVertex);
			currVertex->visited = true;
			cout << "New current vertex: " << currVertex->ID << endl;
			
			// Find all adjacent edges
			vector<Edge*> adjacentEdges;
			for (int i = 0; i < adjacencyList[currVertex->ID].size(); i++) {
				adjacentEdges.push_back(adjacencyList[currVertex->ID][i]);
			}
			
			// For each adjacent edge
			for (Edge* edge : adjacentEdges) {
				double weight = edge->weight;
				double alternateDistance = currVertex->distance + weight;
				if (edge->toVertex->visited == false && alternateDistance <= edge->toVertex->distance) {
					edge->toVertex->distance = alternateDistance;
					edge->toVertex->previous = currVertex;
					cout << "Alternate Distance found!" << endl;
					cout << edge->toVertex->ID << endl;
				}
			}

			// Find an unvisited node with the shortest distance
			Vertex* newVertex = nullptr;
			double currentShortestDistance = INFINITY;

			for (Vertex* v : unvisited) {
				if (v->distance < currentShortestDistance) {
					currentShortestDistance = v->distance;
					newVertex = v;
				}
			}

			// Make the current vertex the one in the unvisited list with the shortest distance
			if (newVertex != nullptr) {
				currVertex = newVertex;
			}
			
		}
		return currVertex;
	}
};

int main()
{
	Graph g(4);
	g.AddEdge(0,1,3);
	g.AddEdge(0,2,7);
	g.AddEdge(1,2,5);
	g.AddEdge(1,3,1);
	g.AddEdge(2,3,9);
	g.AddEdge(3,2,2);

	Vertex* currVertex = g.Dijkstra(g.Search(0));
	cout << endl << "Last vertex ID -> " << currVertex->ID << endl;

	while (currVertex != nullptr) {
		cout << currVertex->ID << " ";
		currVertex = currVertex->previous;
	}

}
