#include <iostream>
#define MAX 5
using namespace std;
class Queue {
    int queue[MAX]; // Array to store queue elements
    int front, rear; // Front index and rear index
    public:
    Queue(){
        front = -1; // Initialize front
        rear =-1; // Initialize rear
    }
    // Function to insert element (Enqueue)
    void enqueue(int value) {
        if (rear == MAX - 1) { // Check if queue is full
            cout << "\nQueue Overflow! Cannot insert " << value << ".\n"; // Queue is full
        } else {
        if (front == -1) // If queue is empty, set front to 0
            front = 0;
        rear++; // Increment rear index
        queue[rear] = value; // Insert value at rear
        cout << value <<" inserted into queue.\n"; // Confirmation message
        }
    }
    // Function to delete element (Dequeue)
    void dequeue() {
        if (front ==-1 || front > rear) { // Check if queue is empty
            cout << "\nQueue Underflow! No element to delete.\n"; // Queue is empty
        } else {
            cout << queue[front] << " deleted from queue.\n"; // Display deleted element
            front++;
        }
    }
    // Function to display queue elements
    void display() {
        if (front ==-1 || front > rear) { // Check if queue is empty
            cout << "\nQueue is empty.\n"; // Prints Queue is empty
        }else {
            cout << "\nQueue elements: "; // Display elements from front to rear
        for (int i = front; i <= rear; i++) { // Loop through queue
            cout << queue[i] <<" "; // Print each element
        }
            cout << endl;}
    }
};
int main() {
    Queue q;
    int choice, value;
    cout << "***** QUEUE IMPLEMENTATION USING ARRAY *****\n";
    do {
        cout <<"\n------ MENU ------\n1. Insert (Enqueue)\n2. Delete (Dequeue)";
        cout << "\n3. Display\n4. Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);
    return 0;
}