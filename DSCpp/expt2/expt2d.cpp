// 25LEC07 - Nathan Lobo
// Aim:- To create 2 classes class A & class B, let class B be friend class A, so that it can access and display private members of class B
#include <iostream>
using namespace std;
// Forward declaration of class B
class B;
// Class A with a private data member
class A {
private:
    int privateData; // Private data member
public:
    // Constructor to initialize privateData
    A(int val){
        privateData = val;
    }
    // Declare class B as a friend so it can access private members
    friend class B;
};
// Class B is a friend of class A and can access its private members
class B {
public:
    // Function to display the private data of class A
    void displayPrivateData(A& a) {
        cout << "Accessing private data of class A: " << a.privateData << endl;
    }
};
int main() {
    A objA(42);   // Create object of class A with privateData = 42
    B objB;       // Create object of class B
    objB.displayPrivateData(objA); // B accesses and displays A's private data
    return 0;
}