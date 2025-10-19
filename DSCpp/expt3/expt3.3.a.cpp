#include <iostream>
using namespace std;
class Vehicle {
protected:
    int maxSpeed;
public:
    void setSpeed(int speed){
        maxSpeed = speed;
    }
};
class Car : public Vehicle {
public:
    void display(){
        cout << "Max speed of the car: " << maxSpeed << " km/h" << endl;
    }
};
int main(){
    Car c;
    c.setSpeed(180);
    c.display();
    return 0;
}