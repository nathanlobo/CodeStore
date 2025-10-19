#include <iostream>
#include <vector>
using namespace std;
// Base class 1
class Person {
protected:
    string name;
    int age;
public:
    void getPersonData(){
        cout << "Enter Name: ";
        getline(cin,name);
        cout << "Enter Age: ";
        cin >> age;
        cin.ignore();
    }
    void displayPersonData(){
        cout << "\n---Personal Info ---" << endl;
        cout << "Name: " << name << "\nAge: " << age << endl;
    }
};
//Base Class 2
class Skills {
protected:
    vector<string> skillList;
public:
    void getSkills(){
        int n;
        cout << "Enter number of skills: ";
        cin >> n;
        cin.ignore();
        skillList.resize(n);
        for(int i=0;i<n;i++){
            cout << "Enter skill " << i+1 <<": ";
            getline(cin,skillList[i]);
        }
    }
    void displaySkills() {
    cout << "--- Skills ---" << endl;
    for (size_t i = 0; i < skillList.size(); i++) {
      cout << (i + 1) << ". " << skillList[i] << endl;
    }
  }
};
// Base class 3
class Benefits {
protected:
  string healthInsurance;
  int leaveDays;
public:
    void getBenefits() {
        cout << "Enter Health Insurance Plan: ";
        getline(cin, healthInsurance);
        cout << "Enter Number of Leave Days: ";
        cin >> leaveDays;
        cin.ignore();
    }
    void displayBenefits() {
        cout << "--- Benefits ---" << endl;
        cout << "Health Insurance: " << healthInsurance << endl;
        cout << "Leave Days: " << leaveDays << endl;
    }
};
// Derived class (Multiple Inheritance)
class Employee : public Person, public Skills, public Benefits {
private:
    int employeeID;
public:
    void getEmployeeData() {
        cout << "Enter Employee ID: ";
        cin >> employeeID;
        cin.ignore();
    }
    void displayEmployeeData() {
        cout << "\n=== Employee Profile ===" << endl;
        cout << "Employee ID: " << employeeID << endl;
        displayPersonData();
        displaySkills();
        displayBenefits();
    }
};
// Main function
int main() {
    Employee e;
    e.getPersonData();
    e.getSkills();
    e.getBenefits();
    e.getEmployeeData();
    e.displayEmployeeData();
    int cont;
    cin >> cont;
    return 0;
}