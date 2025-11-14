#include <iostream>
using namespace std;

#define MAX 30

class Edge {
public:
    int u, v, w;
};
int parent[MAX];
int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}
void union_set(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}
int main() {
    int n = 5;    // number of vertices
    int e = 7;    // number of edges
    Edge edge[MAX] = {
        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7},
        {3, 4, 9}
    };
    for (int i = 0; i < n; i++)
        parent[i] = i;
    // Sort edges by weight (simple bubble sort)
    for (int i = 0; i < e; i++) {
        for (int j = 0; j < e - 1; j++) {
            if (edge[j].w > edge[j + 1].w) {
                Edge temp = edge[j];
                edge[j] = edge[j + 1];
                edge[j + 1] = temp;
            }
        }
    }
    int total = 0;
    cout << "\nKruskal's Algorithm\n";
    cout << "Edge : Weight\n";
    for (int i = 0; i < e; i++) {
        int u = edge[i].u;
        int v = edge[i].v;
        int w = edge[i].w;

        int a = find(u);
        int b = find(v);

        if (a != b) {
            cout << u << " - " << v << " : " << w << endl;
            total += w;
            union_set(a, b);
        }
    }
    cout << "\nTotal weight of MST = " << total << endl;
    return 0;
}