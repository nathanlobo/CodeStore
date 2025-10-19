#include <iostream>
using namespace std;

// Node structure for Doubly Linked List
struct Node {
    int data; // data part
    Node* prev; // previous node pointer
    Node* next; // next node pointer
};

// Head pointer
Node* head = NULL; // initially empty list (head is NULL)

// Function to create and return a new node
Node* createNode(int value) {
    Node* newNode = new Node(); // allocate memory
    newNode->data = value; // set data
    newNode->prev = NULL; // previous is NULL
    newNode->next = NULL; // next is NULL
    return newNode;
}

// Function to insert at the beginning
void insertAtBeginning(int value) {
    Node* newNode = createNode(value); // create new node
    if (head == NULL) { // if list is empty
        head = newNode; // new node becomes head
    } else {
        newNode->next = head; // new node points to current head
        head->prev = newNode; // current head's previous points to new node
        head = newNode; // update head to new node
    }
    cout << "Inserted " << value << " at the beginning.\n"; // Confirmation message
}

// Function to insert at the end
void insertAtEnd(int value) {
    Node* newNode = createNode(value); // create new node
    if (head == NULL) { // if list is empty
        head = newNode; // new node becomes head
        return;
    }
    Node* temp = head; // traverse to the end
    while (temp->next != NULL) { // till last node (next is NULL)
        temp = temp->next; // continue traversal
    }
    temp->next = newNode; // last node's next points to new node
    newNode->prev = temp; // new node's previous points to last node
    cout << "Inserted " << value << " at the end.\n"; // Confirmation message
}

// Function to insert after a specific value (middle)
void insertAfterValue(int value, int after) {
    Node* temp = head; // start from head
    while (temp != NULL && temp->data != after) { // search for the 'after' value and stop if end reached (NULL)
        temp = temp->next; // continue traversal
    }
    if (temp == NULL) { // if 'after' value not found
        cout << "Value " << after << " not found in the list.\n"; // Not found message
        return;
    }
    Node* newNode = createNode(value); // create new node
    newNode->next = temp->next; // new node's next points to temp's next
    newNode->prev = temp; // new node's previous points to temp
    if (temp->next != NULL) // if temp is not the last node
        temp->next->prev = newNode; // temp's next's previous points to new node
    temp->next = newNode; // temp's next points to new node
    cout << "Inserted " << value << " after " << after << ".\n";// Confirmation message
}

// Function to delete from the beginning
void deleteFromBeginning() {
    if (head == NULL) { // if list is empty
        cout << "List is empty.\n"; // Print Empty list message
        return;
    }
    Node* temp = head; // store current head
    head = head->next; // move head to next node
    if (head != NULL) // if list is not empty after deletion
        head->prev = NULL; // set new head's previous to NULL
    cout << "Deleted " << temp->data << " from the beginning.\n"; // Confirmation message
    delete temp; // free memory by deleting temp (old last node)
}

// Function to delete from the end
void deleteFromEnd() {
    if (head == NULL) { // if list is empty
        cout << "List is empty.\n"; // Print Empty list message
        return;
    }
    Node* temp = head; // start from head
    while (temp->next != NULL) { // traverse to the last node
        temp = temp->next; // continue traversal
    }
    if (temp->prev != NULL) // if more than one node exists
        temp->prev->next = NULL; // second last node's next set to NULL
    else
        head = NULL; // if only one node, set head to NULL
    cout << "Deleted " << temp->data << " from the end.\n"; // Confirmation message
    delete temp; // free memory by deleting temp (old last node)
}

// Function to delete a specific value (middle)
void deleteValue(int value) {
    if (head == NULL) { // if list is empty
        cout << "List is empty.\n"; // Print Empty list message
        return; 
    }
    Node* temp = head;
    while (temp != NULL && temp->data != value) { // search for the value to delete
        temp = temp->next; // continue traversal until found or end reached
    }
    if (temp == NULL) { // if value not found
        cout << "Value " << value << " not found.\n"; // Not found message
        return;
    }
    if (temp->prev != NULL) // if not deleting head
        temp->prev->next = temp->next; // bypass temp node
    else
        head = temp->next; // deleting head
    if (temp->next != NULL) // if not deleting last node
        temp->next->prev = temp->prev; // bypass temp node
    cout << "Deleted " << value << " from the list.\n"; // Confirmation message
    delete temp;
}

// Function to display the list
void displayList() { // display all elements
    if (head == NULL) { // if list is empty
        cout << "List is empty.\n"; // Print Empty list message
        return;
    }
    Node* temp = head; // start from head
    cout << "Doubly Linked List: "; // Display message
    while (temp != NULL) {
        cout << temp->data << " "; // Print each element
        temp = temp->next;
    }
    cout << endl;
}

// Menu-driven program
int main() {
    int choice, value, after;
    do {
        cout << "\n--- Doubly Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After Value\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete Specific Value\n";
        cout << "7. Display List\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value to insert: ";
                cin >> value;
                insertAtEnd(value);
                break;
            case 3:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter value after which to insert: ";
                cin >> after;
                insertAfterValue(value, after);
                break;
            case 4:
                deleteFromBeginning();
                break;
            case 5:
                deleteFromEnd();
                break;
            case 6:
                cout << "Enter value to delete: ";
                cin >> value;
                deleteValue(value);
                break;
            case 7:
                displayList();
                break;
            case 0:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while(choice != 0);

    return 0;
}

