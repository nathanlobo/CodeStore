// 25LEC07 - Nathan Lobo
// Aim:- To create a class account, with private members as name and balance use a friend function 
//       to transfer funds from 1 acc to other, ensuring the source account has sufficient balance
#include <iostream>
using namespace std;
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
    // Friend function declaration to allow transferFunds to access private members
    friend void transferFunds(account& from, account& to, double amount);
};
// Friend function to transfer funds between two accounts
void transferFunds(account& from, account& to, double amount) {
    if (amount <= 0) {
        // Invalid transfer amount
        cout << "Invalid transfer amount." << endl;
    }
    else if (from.balance < amount) {
        // Not enough balance to transfer
        cout << "Insufficient balance in " << from.name << "'s account." << endl;
    }
    else {
        // Perform the transfer
        from.balance -= amount;
        to.balance += amount;
        cout << "Transfer of " << amount << " from " << from.name << " to " << to.name << " successful." << endl;
    }
}
int main() {
    // Create two account objects with initial balances
    account acc1("Nathan", 1000);
    account acc2("Zane", 500);
    // Transfer 300 from Nathan to Zane (should succeed)
    transferFunds(acc1, acc2, 300);
    // Attempt to transfer 900 from Zane to Nathan (should fail due to insufficient balance)
    transferFunds(acc2, acc1, 900);
    // Display final account details
    acc1.display();
    acc2.display();
    return 0;
}