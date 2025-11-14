#include <iostream>
using namespace std;

class graph {
private:
    int arr[8][8];
    int visited[8];

public:
    graph() {
        int i, j;
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++)
                arr[i][j] = 0;
        }

        arr[0][1] = arr[1][0] = 1;
        arr[0][2] = arr[2][0] = 1;
        arr[1][3] = arr[3][1] = 1;
        arr[1][4] = arr[4][1] = 1;
        arr[2][5] = arr[5][2] = 1;
        arr[2][6] = arr[6][2] = 1;
        arr[3][7] = arr[7][3] = 1;
        arr[4][7] = arr[7][4] = 1;
        arr[5][7] = arr[7][5] = 1;
        arr[6][7] = arr[7][6] = 1;

        for (i = 0; i < 8; i++)
            visited[i] = 0;
    }

    void dfs(int v, int sz) {
        cout << v + 1 << " ";
        visited[v] = 1;

        for (int i = 0; i < sz; i++) {
            if (arr[v][i] == 1 && visited[i] == 0)
                dfs(i, sz);
        }
    }
};

int main() {
    graph g;
    cout << "DFS Traversal: ";
    g.dfs(0, 8);
    return 0;
}

