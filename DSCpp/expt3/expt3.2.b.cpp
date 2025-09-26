// Experiment 3.2b - Private inheritance example with bank and account
#include <iostream> // Include input-output stream
using namespace std;
// Base class for bank details
class Bank {
    public:
    void bankDetails() { // Display bank info
        cout << "Bank: ABC Bank\nBranch: Main Branch" << endl;
    }
};

// Account privately inherits Bank
class Account : private Bank {
    public:
    void createAccount() { // Calls bankDetails and shows account creation
        bankDetails();
        cout << "Account created successfully." << endl;
    }
};
int main() {
    Account a; // Create Account object
    a.createAccount(); // Create account and show details
    return 0;
}