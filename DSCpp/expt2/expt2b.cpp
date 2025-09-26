// 25LEC07 - Nathan Lobo
// Aim:- To create to classes student1, student2, each with private data members marks, use a friend function 
//       to access both marks and calculate their total marks
#include <iostream>
using namespace std;
// Forward declaration of class student2
class student2;
// Class representing student1 with marks
class student1 {
private:
    int marks; // Marks of student1
public:
    // Function to set marks for student1
    void setMarks(int m) {
        marks = m;
    }
    // Declare totalMarks as a friend function
    friend void totalMarks(student1&, student2&);
};
// Class representing student2 with marks
class student2 {
private:
    int marks; // Marks of student2
public:
    // Function to set marks for student2
    void setMarks(int m) {
        marks = m;
    }
    // Declare totalMarks as a friend function
    friend void totalMarks(student1&, student2&);
};
// Friend function to calculate and print total marks of both students
void totalMarks(student1& s1, student2& s2) {
    cout << "Total marks of student1 and student2: " << (s1.marks + s2.marks) << endl;
}
int main() {
    student1 s1; // Create student1 object
    student2 s2; // Create student2 object
    s1.setMarks(75); // Set marks for student1
    s2.setMarks(85); // Set marks for student2
    totalMarks(s1,s2); // Calculate and display total marks
    return 0;
}