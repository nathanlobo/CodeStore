#include <iostream>
using namespace std;
class Bank {
    public:
    void bankDetails() {
        cout << "Bank: ABC Bank\nBranch: Main Branch" << endl;
    }
};
class Account : private Bank {
    public:
    void createAccount() {
        bankDetails();
        cout << "Account created successfully." << endl;
    }
};
int main() {
    Account a;
    a.createAccount();
    return 0;
}