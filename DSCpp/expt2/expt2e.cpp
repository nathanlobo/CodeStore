#include <iostream>
using namespace std;
class bank;  
class account {
private:
    string name;
    double balance;
public:
    account(string n, double b){
        name = n;
        balance = b;
    }
    void display() {
        cout << "Account Holder: " << name << ", Balance: " << balance << endl;
    }
    friend class bank;
};
class bank {
public:
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
    account acc1("Nathan", 1000);
    acc1.display();
    bank b;
    b.deposit(acc1, 500);
    acc1.display();
    b.deposit(acc1, 0);
    acc1.display();
    return 0;
}
