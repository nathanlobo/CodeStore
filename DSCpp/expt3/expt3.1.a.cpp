#include <iostream>
using namespace std;
class Vehicle {
    public:
    void start() {
        cout << "Vehicle started." << endl;
    }
};
class Car: public Vehicle {
    public:
    void drive() {
        cout << "Car is being driven." << endl;
    }
};
int main() {
    Car c;
    c.start();
    c.drive();
    return 0;
}