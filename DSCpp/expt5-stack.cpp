#include <iostream>
using namespace std;
#define MAX 5 // maximum size of stack
class Stack {
    private:
        int top; // index of top element
        int stack[MAX]; // array to hold stack elements
    public:
        Stack(){top =-1;} // constructor, empty stack
        // Push operation
        void push(int value) {
            if (top == MAX - 1) { // Checks if stack is full
                cout << "Stack Overflow! Cannot insert " << value << endl; // Overflow message
            } else {
                top++; // Increment top index
                stack[top] = value; // Insert value to array at top index
                cout << value <<" pushed into stack.\n"; // Confirmation message
            }
        }
        // Pop operation
        void pop() {
            if (top == -1) { // Checks if stack is empty
                cout << "Stack Underflow! Nothing to pop.\n"; // Underflow message
            } else {
                cout << stack[top] <<" popped from stack.\n"; // Display popped value
                top--;} // Decrement top index
        }
        // Peek / Top element
        void peek() {
            if (top == -1) { // Checks if stack is empty
                cout << "Stack is empty.\n"; // Empty stack message
            } else {
                cout << "Top element: " << stack[top] << endl;} // Display top element
        }
        // Display all elements
        void display() {
            if (top == -1) { // Checks if stack is empty
                cout << "Stack is empty.\n"; // Empty stack message
            } else {
                cout << "Stack elements (top to bottom): "; // Display message
            for (int i = top; i >= 0; i--) { // Loop from top to bottom
                cout << stack[i] <<" "; // Print each element
            }
            cout << endl;
            }
        }
};
int main() {
    Stack s;
    int choice, value;
    do {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.peek();
                break;
            case 4:
                s.display();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5); // Loop until user chooses to exit (5)
    return 0;
}