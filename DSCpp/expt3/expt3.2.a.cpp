// Experiment 3.2a - Single inheritance in private mode
#include <iostream> // Include input-output stream
using namespace std;
// Base class representing a vehicle
class Vehicle {
    public:
    void start() { // Function to start the vehicle
        cout << "Vehicle started." << endl;
    }
};
// Car privately inherits Vehicle
class Car : private Vehicle {
    public:
    void drive() { // Drive function calls start (from Vehicle)
        start();
        cout << "Car is being driven." << endl;
    }
};
int main() {
    Car c; // Create Car object
    c.drive(); // Call drive (which calls start)
    return 0;
}