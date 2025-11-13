#include <iostream>
using namespace std;
// Base class
class Student {
    protected:
    string rollNo;
    string name;
    public:
    void getStudentData() {
        cout << "Enter Roll Number: ";
        cin >> rollNo;
        cin.ignore(); // to clear buffer
        cout << "Enter Name: ";
        getline(cin, name);
    }
    void displayStudentData() {
        cout << "\n--- Student Details ---" << endl;
        cout << "Roll Number: " << rollNo << endl;
        cout << "Name: " << name << endl;
    }
};
// Derived class from Student
class Academic : public Student {
    protected:
    int marks[3];
    public:
    void getMarks() {
        cout << "Enter marks of 3 subjects: ";
        for (int i = 0; i < 3; i++) {
            cin >> marks[i];
        }
    }
    void displayMarks() {
        cout << "Marks: ";
        for (int i = 0; i < 3; i++) {
            cout << marks[i] << " ";
        }
        cout << endl;
    }
};
// Derived class from Academic
class Result : public Academic {
    private:
    int total;
    float percentage;

    public:
    void calculateResult() {
        total = 0;
        for (int i = 0; i < 3; i++) {
            total += marks[i];
        }
        percentage = (float)total / 3;
    }

    void displayResult() {
        cout << "Total Marks: " << total << endl;
        cout << "Percentage: " << percentage << "%" << endl;
    }
};
//Main function
int main(){
    Result r;
    r.getStudentData();
    r.getMarks();
    r.calculateResult();
    r.displayStudentData();
    r.displayMarks();
    r.displayResult();
    return 0;
}