#include <iostream>
using namespace std;

const int INF = 999;

int main()
{
    int arr[4][4];
    int cost[4][4] = {
        {7, 5, 0, 0},
        {7, 0, 0, 2},
        {0, 3, 0, 0},
        {4, 0, 1, 0}
    };
    int i, j, k;
    int n = 4;
    // Replace 0 with INF (no edge)
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (cost[i][j] == 0)
                arr[i][j] = INF;
            else
                arr[i][j] = cost[i][j];
        }
    }
    // Print the initial adjacency matrix
    cout << "Adjacency matrix of cost of edges:" << endl;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            cout << arr[i][j] << "\t";
        cout << endl;
    }
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (arr[i][j] > arr[i][k] + arr[k][j])
                    arr[i][j] = arr[i][k] + arr[k][j];
            }
        }
    }
    // Print the final shortest-path matrix
    cout << "\nAdjacency matrix of lowest cost between vertices:" << endl;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            cout << arr[i][j] << "\t";
        cout << endl;
    }
    return 0;
}