#include "WriteEmployee.h"
#include <Windows.h>
#include <iostream>
#include <fstream>

WriteEmployee::WriteEmployee(void)
{
	filePath = "C:\\employees.dat";
}


WriteEmployee::~WriteEmployee(void)
{
}

void WriteEmployee::run(void){
	std::ofstream write;

	std::system("cls");
	std::cout << "Employee Management Application -> Employee Input" << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;
	std::cout << "Please make sure file is located at " << filePath << std::endl;
	std::system("pause");
	write.open(filePath, std::fstream::app);

	if(write.is_open()){
		writeLoop(write);
		write.close();
	}
	else{
		std::cout << "File not found. Please try again." << std::endl;
		std::system("pause");
	}
}

void WriteEmployee::writeLoop(std::ofstream& out){
	bool another = true;

	do{
		std::system("cls");
		std::cout << "Employee Management Application -> Employee Input" << std::endl;
		std::cout << "-------------------------------------------------" << std::endl;
		std::string fName;
		std::string lName;
		int id;
		int type;
		double rate;
		double value;
		char yn;
		bool flag = true;

		std::cout << "Enter Employee First Name:" << std::endl;
		std::cin >> fName;
		std::cout << "Enter Employee Last Name:" << std::endl;
		std::cin >> lName;
		out << fName << ' ' << lName << ' ';

		do{
			std::cout << "Enter Employee ID:" << std::endl;
			std::cin >> id;
			if(id < 1000 || id >= 4000){
				std::cout << "Please enter a valid 4 digit id between 1000 and 3999" << std::endl;
			}
			else{
				out << id << ' ';
			}
		}while(id < 1000 || id >= 4000);

		do{
			std::cout << "Enter Employee Type:" << std::endl;
			std::cout << "1 - Hourly, 2 - Commission" << std::endl;
			std::cin >> type;
			if(type == 1 || type == 2){
				out << type << ' ';
				flag = false;
			}
			else{
				std::cout << "Please enter a valid Employee Type" << std::endl;
			}
		}while(flag);
		flag = true;

		do{
			std::cout << "Enter Employee Rate:" << std::endl;
			std::cin >> rate;
			if(rate > 0 && rate < 1 && type == 2){
				out << rate << ' ';
			}
			else if(rate > 0 && type == 1){
				out << rate << ' ';
			}
			else{
				std::cout << "Please enter a valid Rate" << std::endl;
			}
		}while(rate <= 0);
		
		do{
			std::cout << "Enter Employee Sales/Hours Worked:" << std::endl;
			std::cin >> value;
			if(value > 0){
				out << value << '\n';
			}
			else{
				std::cout << "Please enter a valid Value" << std::endl;
			}
		}while(value <= 0);

		do{
			std::cout << "Enter another Employee? y/n" << std::endl;
			std::cin >> yn;
			if(toupper(yn) == 'N'){
				another = false;
				flag = false;
			}
			if(toupper(yn) == 'Y'){
				flag = false;
			}
		}while(flag);
		flag = true;

	}while(another);
}