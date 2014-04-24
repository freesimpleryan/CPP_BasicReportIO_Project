#pragma once
#include <string>
class Employee
{
public:
	// Constructors
	Employee(void);
	~Employee(void);

	// Get Methods
	std::string getName(void);
	int getId(void);
	std::string getType(void);
	double getWages(void);
	double getRate(void);
	double getValue(void);
	double getOvertimeHours(void);
	double getOvertimePay(void);

	// Set Methods
	void setName(std::string);
	void setId(int);
	void setType(int);
	void setRate(double);
	void setValue(double);

private:

	// Variables
	std::string name;
	int id;
	int type;
	double wages;
	double rate;
	double value;
	double overtimePay; // Holds commission overage for commission employees
	double overtimeHours;

	// "Constants" for class
	double COMMISSION_BASE;
	double OVERTIME_RATE;
	double OVERTIME_HOURS;
	double COMMISSION_RATE_MAX;
	double HOURLY_RATE_MAX;

	// Private methods
	double calcHourly(void);
	double calcCommission(void);
};

