#include <iostream>
using namespace std;
class Vehicle {
    public:
    void start() {
        cout << "Vehicle started." << endl;
    }
};
class Car : private Vehicle {
    public:
    void drive() {
        start();
        cout << "Car is being driven." << endl;
    }
};
int main() {
    Car c;
    c.drive();
    return 0;
}