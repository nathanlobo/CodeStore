// Experiment 3.1a Single inheritance in public mode
#include <iostream> // Include input-output stream
using namespace std;
// Base class representing a generic vehicle
class Vehicle {
    public:
    void start() { // Function to start the vehicle
        cout << "Vehicle started." << endl;
    }
};
// Derived class representing a car, inherits Vehicle
class Car: public Vehicle {
    public:
    void drive() { // Function to drive the car
        cout << "Car is being driven." << endl;
    }
};
int main() {
    Car c; // Create Car object
    c.start(); // Call base class function
    c.drive(); // Call derived class function
    return 0;
}