#include "Employee.h"

Employee::Employee(string fullName, double hourlyRate) :
	FullName(fullName), hourlyRate(hourlyRate)
{
}

double Employee::GetWeeklySalary(double hoursWorked)
{
	return hoursWorked * hourlyRate;
}
