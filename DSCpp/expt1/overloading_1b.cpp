// 25LEC07 - Nathan Lobo
#include <iostream>
using namespace std;
// Class representing a bank account with basic operations
class BankAccount {
private:
    // Member variables to store account details
    string depositor_name;
    string account_number;
    string account_type;
    double balance_amount;
public:
    // Function to input account details from the user
    void setData() {
        cout << "===Enter Bank Account Details===\nEnter depositor name: ";
        getline(cin, depositor_name);
        cout << "Enter account number: ";
        getline(cin, account_number);
        cout << "Enter account type: ";
        getline(cin, account_type);
        cout << "Enter initial balance: ";
        cin >> balance_amount;
    }
    // Function to deposit an amount into the account
    void deposit(double amount) {
        if (amount > 0) {
            balance_amount += amount;
            cout << "Amount deposited successfully.\n";
            cout << "Balance: " << balance_amount << endl;
        } else {
            cout << "Invalid deposit amount.\n";
        }
    }
    // Function to withdraw an amount from the account
    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount.\n";
        } else if (amount > balance_amount) {
            cout << "Insufficient balance.\n";
        } else {
            balance_amount -= amount;
            cout << "Amount withdrawn successfully.\n";
            cout << "Balance: " << balance_amount << endl;
        }
    }
    // Function to display account details
    void display() {
        cout << "Depositor Name: " << depositor_name << endl;
        cout << "Account Number: " << account_number << endl;
        cout << "Account Type: " << account_type << endl;
        cout << "Balance Amount: " << balance_amount << endl;
    }
};
int main() {
    // Create a BankAccount object
    BankAccount acc;
    // Get account details from the user
    acc.setData();
    int choice;
    double amount;
    // Menu-driven loop for account operations
    while (true){
        cout << ">>> Choose From Below Options:\n1. Deposit\n2. Withdraw\n3. Display Account Info\n4. Exit\nEnter choice: ";
        cin >> choice;
        if (choice == 1) {
            // Deposit money
            cout << "Enter amount to deposit: ";
            cin >> amount;
            acc.deposit(amount);
        } else if (choice == 2) {
            // Withdraw money
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            acc.withdraw(amount);
        } else if (choice == 3) {
            // Display account information
            acc.display();
        } else if (choice == 4) {
            // Exit the program
            cout << "Exiting Program";
            break;
        }
        else {
            cout << "Invalid choice.\n";
        }
    }
    return 0;
}