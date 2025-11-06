// Graph to Matrix and List
#include <iostream>
#include <vector>
using namespace std;

// Graph using Adjacency Matrix
class GraphMatrix {
int vertices;
vector<vector<int> > adjMatrix;
public:
// Constructor
GraphMatrix(int v) {
vertices = v;
adjMatrix = vector<vector<int> >(v, vector<int>(v, 0));
}

// Add edge (undirected)
void addEdge(int u, int v) {
adjMatrix[u][v] = 1;
adjMatrix[v][u] = 1; // comment this line for directed graph
}

// Display Adjacency Matrix
void display() {
cout << "\nAdjacency Matrix Representation:\n";
for (int i = 0; i < vertices; i++) {
for (int j = 0; j < vertices; j++) {
cout << adjMatrix[i][j] << " ";
}
cout << endl;
}
}
};

// Graph using Adjacency List
class GraphList {
int vertices;
vector<vector<int> > adjList;

public:
// Constructor
GraphList(int v) {
vertices = v;
adjList = vector<vector<int> >(v);
}

// Add edge (undirected)
void addEdge(int u, int v) {
adjList[u].push_back(v);
adjList[v].push_back(u); // comment this line for directed graph
}

// Display Adjacency List
void display() {
cout << "\nAdjacency List Representation:\n";
for (int i = 0; i < vertices; i++) {
cout << i << " -> ";
for (int j = 0; j < adjList[i].size(); j++)
cout << adjList[i][j] << " ";
cout << endl;

}
}
};

// Main function
int main() {
int V = 5; // number of vertices

GraphMatrix gm(V);
gm.addEdge(0, 1);
gm.addEdge(0, 4);
gm.addEdge(1, 2);
gm.addEdge(1, 3);
gm.addEdge(1, 4);
gm.addEdge(2, 3);
gm.addEdge(3, 4);
gm.display();

GraphList gl(V);
gl.addEdge(0, 1);
gl.addEdge(0, 4);
gl.addEdge(1, 2);
gl.addEdge(1, 3);
gl.addEdge(1, 4);
gl.addEdge(2, 3);
gl.addEdge(3, 4);
gl.display();
return 0;
}
