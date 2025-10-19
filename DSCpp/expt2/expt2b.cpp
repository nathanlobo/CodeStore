#include <iostream>
using namespace std;
class student2;
class student1 {
private:
    int marks;
public:
    void setMarks(int m) {
        marks = m;
    }
    friend void totalMarks(student1&, student2&);
};
class student2 {
private:
    int marks;
public:
    void setMarks(int m) {
        marks = m;
    }
    friend void totalMarks(student1&, student2&);
};
void totalMarks(student1& s1, student2& s2) {
    cout << "Total marks of student1 and student2: " << (s1.marks + s2.marks) << endl;
}
int main() {
    student1 s1;
    student2 s2;
    s1.setMarks(75);
    s2.setMarks(85);
    totalMarks(s1,s2);
    return 0;
}
