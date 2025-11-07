#include <iostream>
using namespace std;
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
    friend void transferFunds(account& from, account& to, double amount);
};
void transferFunds(account& from, account& to, double amount) {
    if (amount <= 0) {
        cout << "Invalid transfer amount." << endl;
    }
    else if (from.balance < amount) {
        cout << "Insufficient balance in " << from.name << "'s account." << endl;
    }
    else {
        from.balance -= amount;
        to.balance += amount;
        cout << "Transfer of " << amount << " from " << from.name << " to " << to.name << " successful." << endl;
    }
}
int main() {
    account acc1("Nathan", 1000);
    account acc2("Mr. Lobo", 500);
    transferFunds(acc1, acc2, 300);
    transferFunds(acc2, acc1, 900);
    acc1.display();
    acc2.display();
    return 0;
}
