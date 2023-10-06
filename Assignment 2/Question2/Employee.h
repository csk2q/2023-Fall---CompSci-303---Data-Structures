//Author csk2q
#ifndef QUESTION2_EMPLOYEE_H
#define QUESTION2_EMPLOYEE_H

#include <string>

using std::string;

//Use an abstract class Employee to store information common to all employees and to
//declare member functions for calculating weekly salary (number of hours worked * hourly rate)
//and computing health care contributions and vacation days earned that week (come up with some rules for these 2) .
//You need 3 functions (calculating weekly salary, health care contributions, and Vacation days).

class Employee
{
protected:
	const double HOURS_IN_WORK_WEEK = 40.0;
	const double hourlyRate;

public:
	Employee(string fullName, double hourlyRate);

	//Variables
	string FullName;
	string Title = "Employee";


	//Methods
	virtual double GetWeeklySalary(double hoursWorked);
	virtual double GetHealthCareContributions(double hoursWorked) = 0;
	virtual double GetVacationDays(double hoursWorked) = 0;
};


#endif //QUESTION2_EMPLOYEE_H
