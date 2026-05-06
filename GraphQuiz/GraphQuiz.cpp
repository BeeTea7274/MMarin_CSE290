#include <iostream>
#include <vector>

using namespace std;

class Graph {
public:
	class Vertex {
	public:
		bool color;
		int ID;
		Vertex(int id) : ID(id), color(false) {}
	};

	vector<vector<Vertex*>> adjacencyList;
	vector<Vertex*> vertices;

	Graph(int size) : adjacencyList(size){
		for (int i = 0; i < size; i++) {
			Vertex* tempVertex = new Vertex(i);
			vertices.push_back(tempVertex);
		}
	}

	void AddEdges(int source, int destination) {
		adjacencyList[source].push_back(vertices[destination]);
	}

	void AddColor(int vertex, bool color) {
		vertices[vertex]->color = color;
	}



};

int main()
{

}

