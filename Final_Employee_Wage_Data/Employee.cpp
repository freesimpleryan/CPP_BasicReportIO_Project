#include "Employee.h"
#include <string>

// Constructors
Employee::Employee(void)
{
	COMMISSION_BASE = 400;
	OVERTIME_RATE = 1.5;
	OVERTIME_HOURS = 40;
	COMMISSION_RATE_MAX = 0.4;
	HOURLY_RATE_MAX = 25;
	wages = 0;
	rate = 0;
	value = 0;
	id = 0;
	type = 0;
	overtimePay = 0;
	overtimeHours = 0;
	name = "";
}


Employee::~Employee(void)
{
}

// Get Methods
std::string Employee::getName(void){return name;}
int Employee::getId(void){return id;}
double Employee::getValue(void){return value;}
double Employee::getRate(void){return rate;}
double Employee::getOvertimeHours(void){return overtimeHours;}
double Employee::getOvertimePay(void){return overtimePay;}

std::string Employee::getType(void){
	if(type == 1)
		return "Hourly";
	else if(type == 2)
		return "Commission";
	else
		return "ERROR";
}


double Employee::getWages(void){
	if(type == 1){
		return calcHourly();
	}
	else if(type == 2){
		return calcCommission();
	}
	else
		return 0;
}

// Set Methods
void Employee::setName(std::string n){name = n;}
void Employee::setId(int i){
	if(i >= 1000 && i < 4000){
		id = i;
	}
	else{
		id = 0;
	}
}

void Employee::setType(int t){
	if(t == 1 || t == 2){
		type = t;
	}
	else{
		type = 0;
	}
}

void Employee::setRate(double r){
	if(r > 0 && type == 1 && r < HOURLY_RATE_MAX){
		rate = r;
	}
	else if(r > 0 && type == 2 && r < COMMISSION_RATE_MAX){
		rate = r;
	}
	else{
		rate = 0;
	}
}

void Employee::setValue(double h){
	if(h > 0){
		value = h;
	}
	else{
		value = 0;
	}
}

// Private Methods

// Calculates an Hourly Employee's pay
double Employee::calcHourly(void){
	double otRate = rate * OVERTIME_RATE;
	if(value >= OVERTIME_HOURS){
		wages = OVERTIME_HOURS * rate;
		overtimeHours = value - OVERTIME_HOURS;
		overtimePay = otRate * overtimeHours;
		wages += overtimePay;
	}
	else{
		wages = value * rate;
	}
	return wages;
}

// Calculates a Commission Employee's pay
double Employee::calcCommission(void){
	wages = rate * value;
	if(wages < COMMISSION_BASE)
		wages = COMMISSION_BASE;
	else
		overtimePay = wages - COMMISSION_BASE;
	return wages;
}
