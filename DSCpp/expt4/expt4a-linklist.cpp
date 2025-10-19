#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

// Linked List Class
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    // Insert at beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Insert at end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Insert at given position (1-based index)
    void insertAtPosition(int value, int position) {
        if (position <= 0) {
            cout << "Invalid position!" << endl;
            return;
        }

        if (position == 1) {
            insertAtBeginning(value);
            return;
        }

        Node* newNode = new Node(value);
        Node* temp = head;

        for (int i = 1; i < position - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Position out of range!" << endl;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Delete at beginning
    void deleteAtBeginning() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Delete at end
    void deleteAtEnd() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }

    // Delete at given position
    void deleteAtPosition(int position) {
        if (head == NULL || position <= 0) {
            cout << "Invalid position or empty list!" << endl;
            return;
        }

        if (position == 1) {
            deleteAtBeginning();
            return;
        }

        Node* temp = head;
        for (int i = 1; i < position - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL || temp->next == NULL) {
            cout << "Position out of range!" << endl;
            return;
        }

        Node* delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;
    }

    // Display the list
    void display() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

// Main function with Menu
int main() {
    LinkedList list;
    int choice, subChoice, value, position;

    while (true) {
        cout << "\n===== MAIN MENU =====" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: // Insert Menu
            cout << "\n--- INSERT MENU ---" << endl;
            cout << "1. Insert at Beginning" << endl;
            cout << "2. Insert at End" << endl;
            cout << "3. Insert at Position" << endl;
            cout << "Enter your choice: ";
            cin >> subChoice;

            cout << "Enter value: ";
            cin >> value;

            if (subChoice == 1) list.insertAtBeginning(value);
            else if (subChoice == 2) list.insertAtEnd(value);
            else if (subChoice == 3) {
                cout << "Enter position: ";
                cin >> position;
                list.insertAtPosition(value, position);
            }
            else cout << "Invalid Insert Choice!" << endl;
            break;

        case 2: // Delete Menu
            cout << "\n--- DELETE MENU ---" << endl;
            cout << "1. Delete at Beginning" << endl;
            cout << "2. Delete at End" << endl;
            cout << "3. Delete at Position" << endl;
            cout << "Enter your choice: ";
            cin >> subChoice;

            if (subChoice == 1) list.deleteAtBeginning();
            else if (subChoice == 2) list.deleteAtEnd();
            else if (subChoice == 3) {
                cout << "Enter position: ";
                cin >> position;
                list.deleteAtPosition(position);
            }
            else cout << "Invalid Delete Choice!" << endl;
            break;

        case 3:
            cout << "Linked List: ";
            list.display();
            break;

        case 4:
            cout << "Exiting program..." << endl;
            return 0;

        default:
            cout << "Invalid choice!" << endl;
        }
    }
}

