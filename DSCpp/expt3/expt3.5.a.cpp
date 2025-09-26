// Experiment 3.5a - Multiple inheritance
#include <iostream> // Include input-output stream
#include <vector>
using namespace std;
// Base class 1: Person info
class Person {
protected:
    string name;
    int age;
public:
    void getPersonData(){ // Input person data
        cout << "Enter Name: ";
        getline(cin,name);
        cout << "Enter Age: ";
        cin >> age;
        cin.ignore();
    }
    void displayPersonData(){ // Display person data
        cout << "\n---Personal Info ---" << endl;
        cout << "Name: " << name << "\nAge: " << age << endl;
    }
};

//Base Class 2: Skills info
class Skills {
protected:
    vector<string> skillList;
public:
    void getSkills(){ // Input skills
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
    void displaySkills() { // Display skills
    cout << "--- Skills ---" << endl;
    for (size_t i = 0; i < skillList.size(); i++) {
      cout << (i + 1) << ". " << skillList[i] << endl;
    }
  }
};
// Base class 3: Benefits info
class Benefits {
protected:
  string healthInsurance;
  int leaveDays;
public:
    void getBenefits() { // Input benefits
        cout << "Enter Health Insurance Plan: ";
        getline(cin, healthInsurance);
        cout << "Enter Number of Leave Days: ";
        cin >> leaveDays;
        cin.ignore();
    }
    void displayBenefits() { // Display benefits
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
    void getEmployeeData() { // Input employee ID
        cout << "Enter Employee ID: ";
        cin >> employeeID;
        cin.ignore();
    }
    void displayEmployeeData() { // Display all info
        cout << "\n=== Employee Profile ===" << endl;
        cout << "Employee ID: " << employeeID << endl;
        displayPersonData();
        displaySkills();
        displayBenefits();
    }
};
// Main function
int main() {
    Employee e; // Create Employee object
    e.getPersonData();
    e.getSkills();
    e.getBenefits();
    e.getEmployeeData();
    e.displayEmployeeData();
    int cont;
    cin >> cont;
    return 0;
}