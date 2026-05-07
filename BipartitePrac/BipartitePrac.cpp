#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Graph {
public:
    int size;
    enum class Color {
        BLACK,
        WHITE
    };
    class Vertex {
    public:
        Color color;
        int id;
        bool visited;
        Vertex(int id) {
            this->id = id;
        }
    };
    vector<vector<Vertex*>> adj;
    vector<Vertex*> vertices;
    void AddEdge(int from, int to) {
        adj[from].push_back(vertices[to]);
    }
    void SetColor(int vertexID, Color color) {
        vertices[vertexID]->color = color;
    }
    Graph(int size) : size(size), adj(size) {
        for (int i = 0; i < size; i++) {
            vertices.push_back(new Vertex(i));
        }
    }

    bool BipartiteChecker(int startNode, vector<int>& discoveryList) {
        queue<int> frontierQueue;

        int currVertex;
        frontierQueue.push(startNode);
        Graph::Color currColor;

        for (Vertex* v : vertices) {
            v->visited = false;
        }

        while (frontierQueue.size() > 0) {
            // Set new current vertex
            currVertex = frontierQueue.front();
            frontierQueue.pop();

            // Visit it
            discoveryList.push_back(currVertex);
            vertices[currVertex]->visited = true;

            // Set new current color
            currColor = vertices[currVertex]->color;

            for (Vertex* v : adj[currVertex]) {
                if (v->color == currColor) {
                    return false;
                }
                if (!v->visited) {
                    frontierQueue.push(v->id);
                }
            }
        }

        if (discoveryList.size() == vertices.size()) {
            return true;
        }
        else {
            for (Vertex* v : vertices) {
                if (!v->visited) {
                    return BipartiteChecker(v->id, discoveryList);
                }
            }
        }
    }
};

int main()
{
    Graph g(3);
    g.SetColor(0, Graph::Color::BLACK);
    g.SetColor(1, Graph::Color::WHITE);
    g.SetColor(2, Graph::Color::WHITE);
    g.AddEdge(0, 1);
    g.AddEdge(0, 2);

    vector<int> discoveryList;
    bool isBipartite = g.BipartiteChecker(0, discoveryList);
    if (isBipartite) {
        cout << "The graph is bipartite!" << endl;
    }
    else {
        cout << "The graph is not bipartite!" << endl;
    }

}