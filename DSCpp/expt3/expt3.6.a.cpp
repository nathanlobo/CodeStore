
#include <iostream> // Include input-output stream
using namespace std;
// Base class for university
class University {
protected:
    string universityName;
public:
    void setUniversityDetails(string name) { // Set university name
        universityName = name; }
    void showUniversityDetails() { // Display university name
        cout<< "University Name: " << universityName << endl;
    }
};
// Department inherits University
class Department : public University {
protected:
    string deptName;
    int totalStudents;
public:
    void setDepartmentDetails(string name, int students) { // Set dept info
    deptName = name;
    totalStudents = students;
    }
    void showDepartmentDetails() { // Display dept info
        cout << "Department Name: "<< deptName << endl;
        cout << "Total Students: "<< totalStudents << endl;
    }
};

// Specialized Departments
class ElectronicsAndComputers: public Department {
    string hodName;
public:
    void setElectronicsDetails(string hod) { // Set HOD name
        hodName = hod;
    }
    void showElectronicsDetails() { // Display ECE dept info
        cout << "--- Electronics & Computers Department ---"<< endl;
        showDepartmentDetails();
        cout << "HOD: " << hodName << endl;
    }
};

class Mechanical: public Department {
    string labName;
public:
    void setMechanicalDetails(string lab) { // Set lab name
        labName = lab;
    }
    void showMechanicalDetails() { // Display Mech dept info
        cout << "--- Mechanical Department ---" << endl;
        showDepartmentDetails();
        cout << "Lab: " << labName << endl;
    }
};

class Computers : public Department {
    string projectName;
public:
    void setComputersDetails(string project) { // Set project name
        projectName = project;
    }
    void showComputersDetails() { // Display Comp dept info
        cout << "--- Computers Department ---" << endl;
        showDepartmentDetails();
        cout<< "Project: " << projectName << endl;
    }
};
// Library inherits University
class Library: public University {
    int totalBooks;
public:
    void setLibraryDetails(int books) { // Set total books
        totalBooks = books;
    }
    void showLibraryDetails() { // Display books
        cout << "Library Total Books: " << totalBooks << endl;
    }
};
// Hostel inherits University
class Hostel : public University {
    int totalRooms;
public:
    void setHostelDetails(int rooms) { // Set total rooms
        totalRooms = rooms;
    }
    void showHostelDetails() { // Display rooms
        cout << "Hostel Total Rooms: " << totalRooms << endl;
    }
};
int main() {
    // University
    University uni;
    uni.setUniversityDetails("Global Tech University");
    // Electronics & Computers Department
    ElectronicsAndComputers ece;
    ece.setUniversityDetails("Global Tech University");
    ece.setDepartmentDetails("Electronics & Computers", 120);
    ece.setElectronicsDetails("Dr. Smith");
    // Mechanical Department
    Mechanical mech;
    mech.setUniversityDetails("Global Tech University");
    mech.setDepartmentDetails("Mechanical", 100);
    mech.setMechanicalDetails("Thermodynamics Lab");
    // Computers Department
    Computers comp;
    comp.setUniversityDetails("Global Tech University");
    comp.setDepartmentDetails("Computers", 90);
    comp.setComputersDetails("Al Project");
    // Library
    Library lib;
    lib.setUniversityDetails("Global Tech University");
    lib.setLibraryDetails(5000);
    // Hostel
    Hostel host;
    host.setUniversityDetails("Global Tech University");
    host.setHostelDetails(200);
    // Display
    cout << "=========== UNIVERSITY DETAILS ===========" << endl;
    uni.showUniversityDetails();
    cout << "\n=========== DEPARTMENT DETAILS ===========" << endl;
    ece.showElectronicsDetails();
    mech.showMechanicalDetails();
    comp.showComputersDetails();
    cout << "\n=========== LIBRARY DETAILS ===========" << endl;
    lib.showLibraryDetails();
    cout << "\n=========== HOSTEL DETAILS ===========" << endl;
    host.showHostelDetails();
    return 0;
}