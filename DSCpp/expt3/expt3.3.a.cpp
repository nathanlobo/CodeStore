// Experiment 3.3a - Making private members inheritance using protected access
#include <iostream> // Include input-output stream
using namespace std;
// Base class for vehicles
class Vehicle {
protected:
    int maxSpeed; // Protected member for speed
public:
    void setSpeed(int speed){ // Set max speed
        maxSpeed = speed;
    }
};

// Car publicly inherits Vehicle
class Car : public Vehicle {
public:
    void display(){ // Display max speed
        cout << "Max speed of the car: " << maxSpeed << " km/h" << endl;
    }
};
int main(){
    Car c; // Create Car object
    c.setSpeed(180); // Set speed
    c.display(); // Show speed
    return 0;
}