#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
public:
	Node* previous;
	int distance;
	int ID;
	Node(int id) : previous(nullptr), distance(INFINITY), ID(id) {}
};

class Edge {
public:
	int weight;
	Node* fromVertex;
	Node* toVertex;
	Edge(int weight, Node* from, Node* to) : weight(weight), fromVertex(from), toVertex(to) {};
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
		adjacencyList[u].push_back(new Edge(d,Search(u),Search(v)));
	}

	bool Dijkstra(Node* startNode) {
		vector<Node*> unvisited;
		for (Node* node : vertices) {
			node->distance = INFINITY;
			node->previous = nullptr;
			unvisited.push_back(node);
		}

		startNode->distance = 0;

		while (unvisited.size() > 0){
			vector<Edge*> adjacentEdges;
			for (int i = 0; i < adjacencyList[startNode->ID].size(); i++) {
				adjacentEdges.push_back(adjacencyList[startNode->ID][i]);
			}
			Node* currentVertex = nullptr;
		}
	}
};

int main()
{
   
}
