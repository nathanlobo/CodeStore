// 25LEC07 - Nathan Lobo
#include <iostream>
using namespace std;
// Class to store and manage college account details
class collegeAccount {
private:
    // Member variables to store college, department, and location
    string collegename;
    string deptname;
    string location;
public:
    // Function to get details from the user
    void getdetails() {
        cout << "Enter college name: ";
        getline(cin, collegename);
        cout << "Enter department name: ";
        getline(cin, deptname);
        cout << "Enter location: ";
        getline(cin, location);
    }
    // Function to display the stored details
    void displaydata() {
        cout << "\nCollege Name: " << collegename << endl;
        cout << "Department Name: " << deptname << endl;
        cout << "Location: " << location << endl;
    }
};
int main() {
    // Create an object of collegeAccount
    collegeAccount c;
    // Get details from the user
    c.getdetails();
    // Display the entered details
    c.displaydata();
    return 0;
}