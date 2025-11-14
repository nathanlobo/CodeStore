#include <iostream>
using namespace std;

const int MAX = 10;

class queue {
private:
    int arr[MAX], front, rear;

public:
    queue() {
        front = rear = -1;
    }

    // Add an element to the queue
    void addq(int item) {
        if (rear == MAX - 1) {
            cout << "Queue is full" << endl;
            return;
        }
        rear++;
        arr[rear] = item;
        if (front == -1)
            front = 0;
    }

    // Remove an element from the queue
    int delq() {
        int data;
        if (front == -1) {
            cout << "Queue is Empty" << endl;
            return -1; // Return -1 instead of NULL (since it's int)
        }

        data = arr[front];
        arr[front] = 0;

        if (front == rear)
            front = rear = -1;
        else
            front++;

        return data;
    }

    // Check if queue is empty
    bool isempty() {
        return (front == -1 && rear == -1);
    }
};

// Graph class
class graph {
private:
    int arr[8][8];
    int visited[8];

public:
    graph() {
        int i, j;
        // Initialize adjacency matrix and visited array
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

    void bfs(int sz) {
        queue q;
        int idx, i;

        q.addq(0); // Start BFS from node 0

        while (!q.isempty()) {
            idx = q.delq();
            if (visited[idx] == 0) {
                visited[idx] = 1;
                cout << idx + 1 << " ";

                for (i = 0; i < sz; i++) {
                    if (visited[i] == 0 && arr[idx][i] == 1)
                        q.addq(i);
                }
            }
        }
    }
};

int main() {
    graph g;
    cout << "BFS Traversal: ";
    g.bfs(8);
    return 0;
}

