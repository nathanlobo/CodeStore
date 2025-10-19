#include <iostream>
using namespace std;
class Employee {
    public:
    string name;
    int empID;
    void display() {
        cout << "Name: "<<name << "\nEmployee ID: " << empID <<endl;
    }
};
class Programmer: public Employee {
public:
    void showSkills() {
        cout << "Skills: C, C++, Python, HTML, PHP" << endl;
    }
};
int main() {
    Programmer p;
    p.name = "Nathan";
    p.empID = 22;
    p.display();
    p.showSkills();
    return 0;
}