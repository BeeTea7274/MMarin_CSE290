#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

class Vertex{
public:
    enum Color {
        RED,
        BLACK,
    };
    Color color;
    int ID;
    Vertex(int id) : ID(id){}

    void SetColor(Color col) {
        color = col;
    }
};

class Edge {
public:
    Vertex* fromVertex;
    Vertex* toVertex;
    Edge(Vertex* from, Vertex* to) : fromVertex(from), toVertex(to) {}
};

class Graph {
public:
    vector<vector<Edge*>> adjacencyList;
    vector<Vertex*> vertices;
    int graphSize;
    Graph(int size) : graphSize(size), adjacencyList(size) {
        for (int i = 0; i < size; i++) {
            Vertex* tempVertex = new Vertex(i);
            vertices.push_back(tempVertex);
        }
    }

    void AddEdge(int from, int to) {
        Edge* newEdge = new Edge(vertices[from], vertices[to]);
        adjacencyList[from].push_back(newEdge);
    }

    bool BipartiteCheckRecursive(Vertex* startNode, vector<bool>& visitedVertices) {
        Vertex::Color currColor = startNode->color;
        visitedVertices[startNode->ID] = true;
        for (Edge* edge : adjacencyList[startNode->ID]) {
            if (edge->toVertex->color == currColor){
                return false;
            }
            else if(!visitedVertices[edge->toVertex->ID]) {
                return BipartiteCheckRecursive(edge->toVertex, visitedVertices);
            }
        }
        // Disjointed graph check
        bool allNodesTraversed = true;
        for (bool v : visitedVertices) {
            if (v == false) {
                allNodesTraversed = false;
            }
        }
        if (allNodesTraversed) {
            return true;
        }
        else {
            for (int i = 0; i < visitedVertices.size(); i++) {
                if (!visitedVertices[i]) {
                    return BipartiteCheckRecursive(vertices[i], visitedVertices);
                }
            }
        }
    }

    bool BipartiteCheckBFS(vector<bool> &visited, int startNode, set<int> &discoverySet) {
        queue<int> frontierQueue;

        int currVertex;
        frontierQueue.push(startNode);
        

        while (frontierQueue.size() > 0) {
            currVertex = frontierQueue.front();
            frontierQueue.pop();
            discoverySet.insert(currVertex);
            visited[currVertex] = true;
            Vertex::Color currColor = vertices[currVertex]->color;

            for (Edge* edge : adjacencyList[currVertex]) {
                frontierQueue.push(edge->toVertex->ID);
                if (edge->toVertex->color == currColor) {
                    return false;
                }
            }
        }

        if (discoverySet.size() == visited.size()) {
            return true;
        }
        else {
            for (int i = 0; i < visited.size(); i++) {
                if (!visited[i]) {
                    return BipartiteCheckBFS(visited, i, discoverySet);
                } 
            }
        }
    }

};

int main()
{
    // Bipartite graph
    Graph g1(3);
    g1.vertices[0]->color = Vertex::Color::BLACK;
    g1.vertices[1]->color = Vertex::Color::RED;
    g1.vertices[2]->color = Vertex::Color::RED;
    
    g1.AddEdge(0, 1);
    g1.AddEdge(0, 2);

    vector<bool> visited(3, 0);
    set<int> discovery;
    bool isBipartite = g1.BipartiteCheckBFS(visited, 0, discovery);
    cout << "Is Graph 1 bipartite? -> " << isBipartite << endl;

    // Not Bipartite graph
    Graph g2(3);
    g2.vertices[0]->color = Vertex::Color::BLACK;
    g2.vertices[1]->color = Vertex::Color::BLACK;
    g2.vertices[2]->color = Vertex::Color::RED;

    g2.AddEdge(0, 1);
    g2.AddEdge(0, 2);

    vector<bool> visited2(3, 0);
    set<int> discovery2;
    bool isBipartite2 = g2.BipartiteCheckBFS(visited2, 0, discovery2);
    cout << "Is Graph 2 bipartite? -> " << isBipartite2 << endl;

    // Fully disjointed graph
    Graph g3(3);
    g3.vertices[0]->color = Vertex::Color::BLACK;
    g3.vertices[1]->color = Vertex::Color::BLACK;
    g3.vertices[2]->color = Vertex::Color::RED;

    vector<bool> visited3(3, 0);
    set<int> discovery3;
    bool isBipartite3 = g3.BipartiteCheckBFS(visited3, 0, discovery3);
    cout << "Is Graph 3 bipartite? -> " << isBipartite3 << endl;
}

