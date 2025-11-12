#include <iostream>
using namespace std;

// Base class
class University {
protected:
    string universityName;
public:
    void setUniversityDetails(string name) {
        universityName = name; }
    void showUniversityDetails() {
        cout<< "University Name: " << universityName << endl;
    }
};

// Derived class 1
class Department : public University {
protected:
    string deptName;
    int totalStudents;
public:
    void setDepartmentDetails(string name, int students) {
    deptName = name;
    totalStudents = students;
    }
    void showDepartmentDetails() {
        cout << "Department Name: "<< deptName << endl;
        cout << "Total Students: "<< totalStudents << endl;
    }
};

// Derived class 1.1 (Specialized Departments)
class ElectronicsAndComputers: public Department {
    string hodName;
public:
    void setElectronicsDetails(string hod) {
        hodName = hod;
    }
    void showElectronicsDetails() {
        cout << "--- Electronics & Computers Department ---"<< endl;
        showDepartmentDetails();
        cout << "HOD: " << hodName << endl;
    }
};

class Mechanical: public Department {
    string labName;
public:
    void setMechanicalDetails(string lab) {
        labName = lab;
    }
    void showMechanicalDetails() {
        cout << "--- Mechanical Department ---" << endl;
        showDepartmentDetails();
        cout << "Lab: " << labName << endl;
    }
};

class Computers : public Department {
    string projectName;
public:
    void setComputersDetails(string project) {
        projectName = project;
    }
    void showComputersDetails() {
        cout << "--- Computers Department ---" << endl;
        showDepartmentDetails();
        cout<< "Project: " << projectName << endl;
    }
};
// Derived class 2
class Library: public University {
    int totalBooks;
public:
    void setLibraryDetails(int books) {
        totalBooks = books;
    }
    void showLibraryDetails() {
        cout << "Library Total Books: " << totalBooks << endl;
    }
};
// Derived class 3
class Hostel : public University {
    int totalRooms;
public:
    void setHostelDetails(int rooms) {
        totalRooms = rooms;
    }
    void showHostelDetails() {
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