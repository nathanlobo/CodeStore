// 25LEC07 - Nathan Lobo
// Aim:- To create 2 classes account and bank. The bank class should be fund of account and 
//       we should be able to access and modify the balance, when a desposit is made
#include <iostream>
using namespace std;
// Forward declaration of class bank
class bank;  
// Class representing a bank account
class account {
private:
    string name;    // Account holder's name
    double balance; // Account balance
public:
    // Constructor to initialize account with name and balance
    account(string n, double b){
        name = n;
        balance = b;
    }
    // Function to display account details
    void display() {
        cout << "Account Holder: " << name << ", Balance: " << balance << endl;
    }
    // Declare bank as a friend class to allow access to private members
    friend class bank;
};
// Class representing a bank that can operate on accounts
class bank {
public:
    // Function to deposit money into an account
    void deposit(account& acc, double amount) {
        if (amount > 0) {
            acc.balance += amount;
            cout << "Deposited " << amount << " to " << acc.name << "'s account.\n";
        } else {
            cout << "Deposit amount must be greater than 0.\n";
        }
    }
};
int main() {
    account acc1("Nathan", 1000); // Create account with initial balance
    acc1.display();                // Display account details
    bank b;                       // Create bank object
    b.deposit(acc1, 500);         // Deposit 500 to account
    acc1.display();               // Display updated account details
    b.deposit(acc1, 0);           // Attempt to deposit 0 (should fail)
    acc1.display();               // Display account details again
    return 0;
}