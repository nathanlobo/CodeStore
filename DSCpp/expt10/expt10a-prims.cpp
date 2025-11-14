#include <iostream>
#include <cstring>
using namespace std;

#define INF 9999
#define V 5   // number of vertices

// Adjacency matrix for the graph
int G[V][V] = {
    {0, 2, 0, 6, 0},
    {2, 0, 3, 8, 5},
    {0, 3, 0, 0, 7},
    {6, 8, 0, 0, 9},
    {0, 5, 7, 9, 0}
};
int main() {
    int no_edge;               // number of edges in MST
    bool selected[V];          // keeps track of selected vertices
    memset(selected, false, sizeof(selected));
    no_edge = 0;
    selected[0] = true;        // start from vertex 0
    cout << "Prim's Algorithm\n";
    cout << "Edge : Weight\n";
    while (no_edge < V - 1) {
        int min = INF;
        int x = 0, y = 0;
        for (int i = 0; i < V; i++) {
            if (selected[i]) {
                for (int j = 0; j < V; j++) {
                    if (!selected[j] && G[i][j]) {
                        if (min > G[i][j]) {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        cout << x << " - " << y << " : " << G[x][y] << endl;
        selected[y] = true;
        no_edge++;
    }
    return 0;
}