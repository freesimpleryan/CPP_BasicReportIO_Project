#include "MainMenu.h"
#include "WriteEmployee.h"
#include <iostream>
#include <Windows.h>


MainMenu::MainMenu(void)
{
	run();
}


MainMenu::~MainMenu(void)
{
}

// Main menu controls
void MainMenu::run(void){

	bool loopMenu = true; // Keeps menu active
	int menu; // Holds menu seleciton

	do{ // Menu loop

		// Menu output
		std::system("cls");
		std::cout << "Employee Management Application" << std::endl;
		std::cout << "-------------------------------" << std::endl;
		std::cout << "1. Enter employee information" << std::endl;
		std::cout << "2. Run reports" << std::endl;
		std::cout << "3. About" << std::endl;
		std::cout << "4. Exit" << std::endl;
		std::cout << std::endl;
		std::cout << "Please select a menu item." << std::endl;
		std::cin >> menu;

		// Menu controls
		switch(menu){
			case 1: // Input Employees
				writer.run();
				break;
			case 2: // Run Reports
				reporting.run();
				break;
			case 3: // About
				about();
				break;
			case 4: // Exit
				loopMenu = false;
				break;
			default: // Invalid selection
				break;
		} // End menu controls

	}while(loopMenu); // End menu loop

} // End run

void MainMenu::about(void){
	std::system("cls");
	std::cout << "Employee Management Application" << std::endl;
	std::cout << "-------------------------------" << std::endl;
	std::cout << "Written by: Ryan Brown" << std::endl;
	std::cout << "For Class: Professor Carter's C++ I Class" << std::endl;
	std::cout << std::endl;
	std::cout << "Written per instructions given for the final" << std::endl;
	std::cout << std::endl;
	std::system("pause");
} // End about
