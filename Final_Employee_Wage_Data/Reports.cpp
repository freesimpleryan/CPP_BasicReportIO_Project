#include "Reports.h"
#include "Employee.h"
#include <vector>
#include <fstream>
#include <iostream>

Reports::Reports(void)
{
	filePath = "C:\\employees.dat"; // Initialze input file path
}


Reports::~Reports(void)
{
}

// Runs the menu
void Reports::run(void){
	loadEmployees(); // Get employees from file first
	menu();
}

// Loads the employees from the employees.dat file
void Reports::loadEmployees(void){

	allEmployees.clear();

	std::string fName; // First name
	std::string lName; // Last name
	double dTemp; // Double temp variable
	int iTemp; // Integer temp variable

	std::ifstream read;
	read.open(filePath);

	if(read.is_open()){ // If file opens...
		while(!read.eof()){

			Employee temp = Employee(); // Create new blank employee

			// Load each value in its place to the file
			// Name
			read >> fName;
			read >> lName;
			temp.setName(fName + ' ' + lName);

			// ID
			read >> iTemp;
			temp.setId(iTemp);

			// Type
			read >> iTemp;
			temp.setType(iTemp);

			// Rate
			read >> dTemp;
			temp.setRate(dTemp);

			// Value
			read >> dTemp;
			temp.setValue(dTemp);

			// Store temp Employee to vector
			allEmployees.push_back(temp);
		}
	} // End if
	else{
		std::cout << "Please check that the file is located at " << filePath << std::endl;
		std::system("pause");
	}
} // End loadEmployees


// Menu for the reporting module
void Reports::menu(void){
	bool loopMenu = true; // Keeps menu active
	int menu; // Holds menu seleciton

	do{ // Menu loop
		// Menu output
		std::system("cls");
		std::cout << "Employee Management Application -> Reporting" << std::endl;
		std::cout << "--------------------------------------------" << std::endl;
		std::cout << "1. Basic Report" << std::endl;
		std::cout << "2. Gross Pay Report" << std::endl;
		std::cout << "3. Deparment Report" << std::endl;
		std::cout << "4. Refresh Data" << std::endl;
		std::cout << "5. Return to Main Menu" << std::endl;
		std::cout << std::endl;
		std::cout << "Please select a menu item." << std::endl;
		std::cin >> menu;

		// Menu controls
		switch(menu){
			case 1: // Display plain report
				plainReport();
				printReport(1);
				break;
			case 2: // Display Gross Pay Report
				grossReport();
				printReport(2);
				break;
			case 3: // Display Department Report
				departmentReport();
				printReport(3);
				break;
			case 4: // Refresh data file
				loadEmployees();
				break;
			case 5: // Exit menu
				loopMenu = false;
				break;
			default: // Invalid selection
				break;
		} // End menu controls

	}while(loopMenu); // End menu loop
} // End menu


// Report 1 - Basic Report
void Reports::plainReport(void){

	// Clear Screen
	std::system("cls");

	// Set divider lines
	std::string line = "----------------------------------------------------------";

	// Header
	std::cout << "Employee Management Application -> Reporting: Basic Report" << std::endl;
	std::cout << line << std::endl;
	std::cout << "Name\t\tID\tType\t\tRate\tValue" << std::endl;
	std::cout << line << std::endl;

	// Print data
	for(int i = 0; i < allEmployees.size(); i++){
		std::cout << allEmployees[i].getName() << '\t';
		std::cout << allEmployees[i].getId() << '\t';
		std::cout << allEmployees[i].getType() << '\t';
		if(allEmployees[i].getType() == "Hourly")
			std::cout << '\t';
		if(allEmployees[i].getRate() < 1)
			std::cout << allEmployees[i].getRate() * 100 << '%' << '\t';
		else
			std::cout << '$' << allEmployees[i].getRate() << '\t';
		std::cout << '$' << allEmployees[i].getValue() << std::endl;
	} // End print loop

	std::system("pause");

} // End plainReport


// Report 2 - Print gross pay
void Reports::grossReport(void){

	std::system("cls");

	double totalGross = 0; // Holds total for Gross
	double totalOt = 0; // Holds total for overtime/commission overage

	// Formatting
	std::string line = "---------------------------------------------------------------";

	// Header
	std::cout << "Employee Management Application -> Reporting: Basic Report" << std::endl;
	std::cout << line << std::endl;
	std::cout << "Name\t\tID\tType\t\tTotal Gross\tOverage" << std::endl;
	std::cout << line << std::endl;

	// Print loop
	for(int i = 0; i < allEmployees.size(); i++){
		std::cout << allEmployees[i].getName() << '\t';
		std::cout << allEmployees[i].getId() << '\t';
		std::cout << allEmployees[i].getType() << '\t';
		if(allEmployees[i].getType() == "Hourly")
			std::cout << '\t';
		std::cout << '$' << allEmployees[i].getWages() << "\t\t";
		std::cout << '$' << allEmployees[i].getOvertimePay() << std::endl;
		totalGross += allEmployees[i].getWages();
		totalOt += allEmployees[i].getOvertimePay();
	}

	// Footer
	std::cout << line << std::endl;
	std::cout << "\t\t\t\tTotal:  $" << totalGross << "\t$" << totalOt << std::endl;

	std::system("pause");

} // End grossReport


// Report 3 - Employees by department
void Reports::departmentReport(void){

	std::system("cls");

	// Department vectors by number
	std::vector<Employee> dept1000;
	std::vector<Employee> dept2000;
	std::vector<Employee> dept3000;
	std::vector<Employee> dept0; // Used for employees that do not fit a department number

	double totalGross = 0; // Holds total gross for department
	double totalGrossAllDept = 0; // Holds total gross for all departments

	// Formatting strings
	std::string line = "---------------------------------------------------------------";
	std::string subtotal = "Subtotal:\t$";
	std::string deptHeader = "Name\t\tTotal Gross\t\t\t   | Dept. ";

	// Set department vectors
	for(int i = 0; i < allEmployees.size(); i++){
		int dept;
		dept = allEmployees[i].getId();
		if(dept >= 1000 && dept < 2000){
			dept1000.push_back(allEmployees[i]);
		}
		else if(dept >= 2000 && dept < 3000){
			dept2000.push_back(allEmployees[i]);
		}
		else if(dept >= 3000 && dept < 4000){
			dept3000.push_back(allEmployees[i]);
		}
		else{
			dept0.push_back(allEmployees[i]);
		}
	} // End For loop - set department vectors

	// Header
	std::cout << "Employee Management Application -> Reporting: Department Report" << std::endl;
	std::cout << line << std::endl;
	std::cout << deptHeader << 1000 << std::endl;
	std::cout << line << std::endl;

	// Print first department
	for(int i = 0; i < dept1000.size(); i++){
		std::cout << dept1000[i].getName() << '\t';
		std::cout << '$' << dept1000[i].getWages() << std::endl;
		totalGross += dept1000[i].getWages();
	}

	// Subtotal
	std::cout << line << std::endl;
	std::cout << subtotal << totalGross << std::endl << std::endl;
	totalGrossAllDept += totalGross;
	totalGross = 0; // Reset totalGross subtotal

	// Print second department
	std::cout << deptHeader << 2000 << std::endl;
	std::cout << line << std::endl;
	for(int i = 0; i < dept2000.size(); i++){
		std::cout << dept2000[i].getName() << '\t';
		std::cout << '$' << dept2000[i].getWages() << std::endl;
		totalGross += dept2000[i].getWages();
	}
	
	// Subtotal
	std::cout << line << std::endl;
	std::cout << subtotal << totalGross << std::endl << std::endl;
	totalGrossAllDept += totalGross;
	totalGross = 0;

	// Print third department
	std::cout << deptHeader << 3000 << std::endl;
	std::cout << line << std::endl;
	for(int i = 0; i < dept3000.size(); i++){
		std::cout << dept3000[i].getName() << '\t';
		std::cout << '$' << dept3000[i].getWages() << std::endl;
		totalGross += dept3000[i].getWages();
	}
	
	// Subtotal
	std::cout << line << std::endl;
	std::cout << subtotal << totalGross << std::endl << std::endl;
	totalGrossAllDept += totalGross;
	totalGross = 0;

	// If there are unknown department employees...
	if(!dept0.empty()){
		std::cout << line << std::endl;
		std::cout << deptHeader << "N/A" << std::endl;
		std::cout << line << std::endl;
		for(int i = 0; i < dept0.size(); i++){
			std::cout << dept0[i].getName() << '\t';
			std::cout << '$' << dept0[i].getWages() << std::endl;
			totalGross += dept0[i].getWages();
		}
		
		// Subtotal
		std::cout << line << std::endl;
		std::cout << subtotal << totalGross << std::endl << std::endl;
		totalGrossAllDept += totalGross;
		totalGross = 0;
	}

	// Footer
	std::cout << line << std::endl;
	std::cout << "Total:\t\t$" << totalGrossAllDept << std::endl << std::endl;

	std::system("pause");
} // End departmentReport


// Sub menu for printing a previously viewed report.
// Runs after the main report output screen.
void Reports::printReport(int r){

	char print; // Holds switch for print or not print
	bool done = false; // Ends menu if true

	std::string reportPath; // Path to write report to
	std::ofstream write;

	do{// Menu loop

		std::system("cls");

		// Prompt for print
		std::cout << "Would you like to print this report? y/n" << std::endl;
		std::cin >> print;
		print = toupper(print);

		if(print == 'Y'){ // Print report

			// Get path
			std::cout << "Please enter a file path for this report." << std::endl;
			std::cin >> reportPath;

			// Attempt to open path
			write.open(reportPath);

			if(write.is_open()){ // If path is valid...

				// Use method input to determine which report to print
				switch(r){
					case 1:
						plainReport(write);
						break;
					case 2:
						grossReport(write);
						break;
					case 3:
						departmentReport(write);
						break;
					default:
						break;
				} // End switch

				write.close();
				done = true;

				// Success message
				std::cout << "File printed successfully to " << reportPath << std::endl;
				std::system("pause");

			}
			else{ // On file path fail...
				std::cout << "Invalid file path." << std::endl;
				write.close();
				std::system("pause");
			}
		}

		// If no is selected (n)...
		else if(print == 'N')
			done = true;

	}while(!done); // End menu loop

} // End printReport





/* ------------------------------------------------- //
// From here down are the print methods.
// They mirror the previously listed methods for
// output to console but accept an ofstream as
// input and print to file.
// ------------------------------------------------- */



void Reports::plainReport(std::ofstream& write){

	std::string line = "----------------------------------------------------------";

	write << "Employee Management Application -> Reporting: Basic Report" << std::endl;
	write << line << std::endl;
	write << "Name\t\tID\tType\t\tRate\tValue" << std::endl;
	write << line << std::endl;
	for(int i = 0; i < allEmployees.size(); i++){
		write << allEmployees[i].getName() << '\t';
		write << allEmployees[i].getId() << '\t';
		write << allEmployees[i].getType() << '\t';
		if(allEmployees[i].getType() == "Hourly")
			write << '\t';
		if(allEmployees[i].getRate() < 1)
			write << allEmployees[i].getRate() * 100 << '%' << '\t';
		else
			write << '$' << allEmployees[i].getRate() << '\t';
		write << '$' << allEmployees[i].getValue() << std::endl;
	}
}

void Reports::grossReport(std::ofstream& write){

	double totalGross = 0;
	double totalOt = 0;

	std::string line = "---------------------------------------------------------------";

	write << "Employee Management Application -> Reporting: Basic Report" << std::endl;
	write << line << std::endl;
	write << "Name\t\tID\tType\t\tTotal Gross\tOverage" << std::endl;
	write << line << std::endl;
	for(int i = 0; i < allEmployees.size(); i++){
		write << allEmployees[i].getName() << '\t';
		write << allEmployees[i].getId() << '\t';
		write << allEmployees[i].getType() << '\t';
		if(allEmployees[i].getType() == "Hourly")
			write << '\t';
		write << '$' << allEmployees[i].getWages() << "\t\t";
		write << '$' << allEmployees[i].getOvertimePay() << std::endl;
		totalGross += allEmployees[i].getWages();
		totalOt += allEmployees[i].getOvertimePay();
	}
	write << line << std::endl;
	write << "\t\t\t\tTotal:  $" << totalGross << "\t$" << totalOt << std::endl;
}

void Reports::departmentReport(std::ofstream& write){
	std::vector<Employee> dept1000;
	std::vector<Employee> dept2000;
	std::vector<Employee> dept3000;
	std::vector<Employee> dept0;

	double totalGross = 0;
	double totalGrossAllDept = 0;

	std::string line = "---------------------------------------------------------------";
	std::string subtotal = "Subtotal:\t$";
	std::string deptHeader = "Name\t\tTotal Gross\t\t\t   | Dept. ";

	for(int i = 0; i < allEmployees.size(); i++){
		int dept;
		dept = allEmployees[i].getId();
		if(dept >= 1000 && dept < 2000){
			dept1000.push_back(allEmployees[i]);
		}
		else if(dept >= 2000 && dept < 3000){
			dept2000.push_back(allEmployees[i]);
		}
		else if(dept >= 3000 && dept < 4000){
			dept3000.push_back(allEmployees[i]);
		}
		else{
			dept0.push_back(allEmployees[i]);
		}
	}

	write << "Employee Management Application -> Reporting: Department Report" << std::endl;
	write << line << std::endl;
	write << deptHeader << 1000 << std::endl;
	write << line << std::endl;
	for(int i = 0; i < dept1000.size(); i++){
		write << dept1000[i].getName() << '\t';
		write << '$' << dept1000[i].getWages() << std::endl;
		totalGross += dept1000[i].getWages();
	}

	write << line << std::endl;
	write << subtotal << totalGross << std::endl << std::endl;
	totalGrossAllDept += totalGross;
	totalGross = 0;

	write << deptHeader << 2000 << std::endl;
	write << line << std::endl;
	for(int i = 0; i < dept2000.size(); i++){
		write << dept2000[i].getName() << '\t';
		write << '$' << dept2000[i].getWages() << std::endl;
		totalGross += dept2000[i].getWages();
	}
	
	write << line << std::endl;
	write << subtotal << totalGross << std::endl << std::endl;
	totalGrossAllDept += totalGross;
	totalGross = 0;

	write << deptHeader << 3000 << std::endl;
	write << line << std::endl;
	for(int i = 0; i < dept3000.size(); i++){
		write << dept3000[i].getName() << '\t';
		write << '$' << dept3000[i].getWages() << std::endl;
		totalGross += dept3000[i].getWages();
	}
	
	write << line << std::endl;
	write << subtotal << totalGross << std::endl << std::endl;
	totalGrossAllDept += totalGross;
	totalGross = 0;

	if(!dept0.empty()){
		write << line << std::endl;
		write << deptHeader << "N/A" << std::endl;
		write << line << std::endl;
		for(int i = 0; i < dept0.size(); i++){
			write << dept0[i].getName() << '\t';
			write << '$' << dept0[i].getWages() << std::endl;
			totalGross += dept0[i].getWages();
		}
		
		write << line << std::endl;
		write << subtotal << totalGross << std::endl << std::endl;
		totalGrossAllDept += totalGross;
		totalGross = 0;
	}

	write << line << std::endl;
	write << "Total:\t\t$" << totalGrossAllDept << std::endl << std::endl;
}