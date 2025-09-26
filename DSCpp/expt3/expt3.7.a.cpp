#include <iostream> // Include input-output stream
using namespace std;
// Base Class for university info
class University {
protected:
	string universityName;
	string location;
public:
	void setUniversityDetails(string name, string loc) { // Set university info
		universityName = name;
		location = loc;
	}
	void displayUniversityDetails() { // Display university info
		cout << "University Name: " << universityName << endl;
		cout << "Location: " << location << endl;
	}
};
// Department inherits University
class Department: public University {
protected:
	string departmentName;
	string headOfDepartment;
	int numFaculty;
public:
	void setDepartmentDetails(string deptName, string head, int faculty) { // Set dept info
		departmentName = deptName;
		headOfDepartment = head;
		numFaculty = faculty;
	}
	void displayDepartmentDetails() { // Display dept info
		cout << "Department: " << departmentName << endl;
		cout << "Head: " << headOfDepartment << endl;
		cout << "Number of Faculty: " << numFaculty << endl;
	}
};
// Specialized Departments (Hierarchical Inheritance)
class ElectronicsAndComputers: public Department {
public:
	void displaySpecialDetails() { // ECE dept focus
		cout << "Electronics & Computers Dept focuses on embedded systems and AI.\n";
	}
};

class Mechanical : public Department {
public:
	void displaySpecialDetails() { // Mech dept focus
		cout << "Mechanical Dept focuses on robotics and thermal systems.\n";
	}
};

class Computers : public Department {
public:
	void displaySpecialDetails() { // Comp dept focus
		cout << "Computers Dept focuses on software engineering and ML.\n";
	}
};
// Research Center base class
class ResearchCenter {
protected:
	string researchArea;
	int numProjects;
public:
	void setResearchDetails(string area, int projects) { // Set research info
		researchArea = area;
		numProjects = projects;
	}
	void displayResearchDetails() { // Display research info
		cout << "Research Area: " << researchArea << endl;
		cout << "Number of Projects: " << numProjects << endl;
	}
};
// Hybrid Inheritance: ResearchDepartment inherits from Department and ResearchCenter
class ResearchDepartment : public Department, public ResearchCenter {
private:
	double funding;
	string ongoingResearch;
public:
	void setResearchDeptDetails(double fund, string research) { // Set funding & research
		funding = fund;
		ongoingResearch = research;
	}
	void displayResearchDeptDetails() { // Display all research dept info
		displayUniversityDetails();
		displayDepartmentDetails();
		displayResearchDetails();
		cout << "Funding: $" << funding << " million" << endl;
		cout << "Ongoing Research: " << ongoingResearch << endl;
	}
};

int main() {
	// University & Departments
	ElectronicsAndComputers eceDept;
	eceDept.setUniversityDetails("Global Tech University", "Mumbai");
	eceDept.setDepartmentDetails("Electronics & Computers", "Dr. Sharma", 25);
	Mechanical mechDept;
	mechDept.setUniversityDetails("Global Tech University", "Mumbai");
	mechDept.setDepartmentDetails("Mechanical", "Dr. Verma", 20);
	Computers compDept;
	compDept.setUniversityDetails("Global Tech University", "Mumbai");
	compDept.setDepartmentDetails("Computers", "Dr. Rao", 22);
	// Research Department
	ResearchDepartment resDept;
	resDept.setUniversityDetails("Global Tech University", "Mumbai");
	resDept.setDepartmentDetails("Electronics & Computers", "Dr. Sharma", 25);
	resDept.setResearchDetails("AI and Robotics", 5);
	resDept.setResearchDeptDetails(2.5, "Autonomous Drones");
	// Display Details
	cout << "\n--- Electronics & Computers Dept ---\n";
	eceDept.displayUniversityDetails();
	eceDept.displayDepartmentDetails();
	eceDept.displaySpecialDetails();
	cout << "\n--- Mechanical Dept ---\n";
	mechDept.displayUniversityDetails();
	mechDept.displayDepartmentDetails();
	mechDept.displaySpecialDetails();
	cout << "\n--- Computers Dept ---\n";
	compDept.displayUniversityDetails();
	compDept.displayDepartmentDetails();
	compDept.displaySpecialDetails();
	cout << "\n--- Research Department ---\n";
	resDept.displayResearchDeptDetails();
	return 0;
}
