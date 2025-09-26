// Experiment 3.3b - Protected members inheritance example with students and marks
#include <iostream> // Include input-output stream
using namespace std;
// Base class for student
class Student {
protected:
    int marks; // Protected member for marks
public:
    void setMarks(int m){ // Set marks
        marks = m;
    }
};

// Marks publicly inherits Student
class Marks : public Student {
public:
    void displayMarks(){ // Display marks
        cout << "Marks obtained: " << marks << endl;
    }
};
int main(){
    Marks m; // Create Marks object
    m.setMarks(85); // Set marks
    m.displayMarks(); // Show marks
    return 0;
}