#include <iostream>
using namespace std;
class collegeAccount {
private:
    string collegename;
    string deptname;
    string location;
public:
    void getdetails() {
        cout << "Enter college name: ";
        getline(cin, collegename);
        cout << "Enter department name: ";
        getline(cin, deptname);
        cout << "Enter location: ";
        getline(cin, location);
    }
    void displaydata() {
        cout << "\nCollege Name: " << collegename << endl;
        cout << "Department Name: " << deptname << endl;
        cout << "Location: " << location << endl;
    }
};
int main() {
    collegeAccount c;
    c.getdetails();
    c.displaydata();
    return 0;
}