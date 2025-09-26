// Experiment 3.1b Public inheritance example with employee and programmer
#include <iostream> // Include input-output stream
using namespace std;
// Base class for employee details
class Employee {
    public:
    string name; // Employee name
    int empID;   // Employee ID
    void display() { // Display employee details
        cout << "Name: "<<name << "\nEmployee ID: " << empID <<endl;
    }
};
// Derived class for programmer, inherits Employee
class Programmer: public Employee {
public:
    void showSkills() { // Display programmer skills
        cout << "Skills: C, C++, Python, HTML, PHP" << endl;
    }
};
int main() {
    Programmer p; // Create Programmer object
    p.name = "Nathan";
    p.empID = 22;
    p.display(); // Show employee details
    p.showSkills(); // Show programmer skills
    return 0;
}