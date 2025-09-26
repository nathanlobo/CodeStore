// Experiment 3.4a - Multilevel inheritance
#include <iostream> // Include input-output stream
using namespace std;
// Base class for student info
class Student {
    protected:
    int rollNo;
    string name;
    public:
    void getStudentData() { // Input student data
        cout << "Enter Roll Number: ";
        cin >> rollNo;
        cin.ignore(); // to clear buffer
        cout << "Enter Name: ";
        getline(cin, name);
    }
    void displayStudentData() { // Display student data
        cout << "\n--- Student Details ---" << endl;
        cout << "Roll Number: " << rollNo << endl;
        cout << "Name: " << name << endl;
    }
};

// Academic inherits Student
class Academic : public Student {
    protected:
    int marks[3];
    public:
    void getMarks() { // Input marks
        cout << "Enter marks of 3 subjects: ";
        for (int i = 0; i < 3; i++) {
            cin >> marks[i];
        }
    }
    void displayMarks() { // Display marks
        cout << "Marks: ";
        for (int i = 0; i < 3; i++) {
            cout << marks[i] << " ";
        }
        cout << endl;
    }
};
// Result inherits Academic
class Result : public Academic {
    private:
    int total;
    float percentage;

    public:
    void calculateResult() { // Calculate total and percentage
        total = 0;
        for (int i = 0; i < 3; i++) {
            total += marks[i];
        }
        percentage = (float)total / 3;
    }

    void displayResult() { // Display result
        cout << "Total Marks: " << total << endl;
        cout << "Percentage: " << percentage << "%" << endl;
    }
};
//Main function
int main(){
    Result r; // Create Result object
    r.getStudentData();
    r.getMarks();
    r.calculateResult();
    r.displayStudentData();
    r.displayMarks();
    r.displayResult();
    return 0;
}