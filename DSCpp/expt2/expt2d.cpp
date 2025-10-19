#include <iostream>
using namespace std;
class B;
class A {
private:
    int privateData;
public:
    A(int val){
        privateData = val;
    }
    friend class B;
};
class B {
public:
    void displayPrivateData(A& a) {
        cout << "Accessing private data of class A: " << a.privateData << endl;
    }
};
int main() {
    A objA(42);
    B objB;
    objB.displayPrivateData(objA);
    return 0;
}