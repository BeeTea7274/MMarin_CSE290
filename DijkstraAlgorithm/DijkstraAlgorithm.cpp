#include <iostream>
#include <vector>
#include <queue>
#include <iterator>
using namespace std;

class Node {
public:
	Node* previous;
	double distance;
	int ID;
	bool visited;
	Node(int id) : previous(nullptr), distance(INFINITY), ID(id), visited(false) {}
};

class Edge {
public:
	double weight;
	Node* fromVertex;
	Node* toVertex;
	Edge(Node* from, Node* to, double weight) : weight(weight), fromVertex(from), toVertex(to) {};
};

class Graph {
public:
	vector<vector<Edge*>> adjacencyList;
	vector<Node*> vertices;
	int graphSize;

	Graph(int size) : graphSize(size), adjacencyList(size) {
		for (int i = 0; i < this->graphSize; i ++) {
			vertices.push_back(new Node(i));
		}
	}

	Node* Search(int v) {
		for (Node* node : vertices) {
			if (node->ID == v) {
				return node;
			}
		}
		return nullptr;
	}


	void AddEdge(int u, int v, int d) {
		adjacencyList[u].push_back(new Edge(Search(u),Search(v),d));
	}

	Node* Dijkstra(Node* startNode) {
		Node* currNode = startNode;
		int unvisited = 0;
		

		for (Node* node : vertices) {
			node->previous = nullptr;
			node->distance = INFINITY;
			unvisited++;
			cout << "Node: " << node->ID << " added to unvisited vector" << endl;
		}

		currNode->distance = 0;

		while (unvisited > 0) {
			currNode->visited = true;

			vector<Edge*> adjacentEdges;
			for (Edge* edge : adjacencyList[currNode->ID]) {
				adjacentEdges.push_back(edge);
				cout << "Added Edge to adjacent edges of Node: " << currNode->ID << endl;
				cout << "EDGE) FROMVERTEX " << edge->fromVertex->ID << " TOVERTEX " << edge->toVertex->ID << endl;
			}

			for (Edge* edge : adjacentEdges) {
				int alternateDistance = edge->weight + currNode->distance;
				if (alternateDistance < edge->toVertex->distance && edge->toVertex->visited == false) {
					edge->toVertex->distance = alternateDistance;
					edge->toVertex->previous = currNode;
				}
			}

			double currentShortestPath = INFINITY;
			Node* currentShortestNode = nullptr;
			for (Edge* edge : adjacentEdges) {
				if (edge->toVertex->distance < currentShortestPath && edge->toVertex->visited == false) {
					currentShortestNode = edge->toVertex;
					currentShortestPath = edge->toVertex->distance;
				}
			}

			adjacentEdges.clear();
			currNode = currentShortestNode;
			unvisited--;
		}

		return currNode;
	}
};

int main()
{
	Graph g(6);
	// AddEdge(int u, int v, int d);
	g.AddEdge(0, 1, 2);
	g.AddEdge(0, 2, 8);
	g.AddEdge(1, 2, 5);
	g.AddEdge(1, 4, 6);
	g.AddEdge(2, 3, 2);
	g.AddEdge(2, 4, 3);
	g.AddEdge(4, 5, 9);
	g.AddEdge(3, 5, 3);
	g.AddEdge(3, 4, 1);

	Node* lastNode = g.Dijkstra(g.Search(0));
}
