#pragma once
#include<vector>
#include"Employee.h"

// Class to handle writing reports
class Reports
{
public:
	// Constructors
	Reports(void);
	~Reports(void);

	// Invokes the menu
	void run(void);
private:
	// Variables
	std::vector<Employee> allEmployees; // Holds all employees
	std::string filePath; // Path that the data file should be located at

	// Class Methods
	void loadEmployees(void); // Loads the employees from the data file to the vector

	// Reports - Screen Output
	void plainReport(void);
	void grossReport(void);
	void departmentReport(void);

	// Reports - Print Output
	void plainReport(std::ofstream& write);
	void grossReport(std::ofstream& write);
	void departmentReport(std::ofstream& write);

	// Menus
	void menu(void); // Main menu for class
	void printReport(int r); // Internal menu for print prompting
};

