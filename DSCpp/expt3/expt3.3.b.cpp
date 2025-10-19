#include <iostream>
using namespace std;
class Student {
protected:
    int marks;
public:
    void setMarks(int m){
        marks = m;
    }
};
class Marks : public Student {
public:
    void displayMarks(){
        cout << "Marks obtained: " << marks << endl;
    }
};
int main(){
    Marks m;
    m.setMarks(85);
    m.displayMarks();
    return 0;
}