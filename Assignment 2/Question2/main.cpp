//Author csk2q

#include <iostream>
#include <iomanip>

#include "Employee.h"
#include "Professional.h"
#include "NonProfessional.h"

using namespace std;

//Displays all attributes shared by employees
void displaySummary(Employee* employee, double hours)
{
	cout << "Weekly summary of employee: " << employee->FullName << " \"" << employee->Title << "\"\n"
		<< "Worked for " << hours << " hours this week.\n"
		<< "Pay out for the week: $" << employee->GetWeeklySalary(hours) << "\n"
		<< "Health care contribution: $" << employee->GetHealthCareContributions(hours) << "\n"
		<< "Added " << employee->GetVacationDays(hours) << " days to their stored vacation days.\n"
		<< "\n";
}

int main()
{
	// Fix number of decimal places shown to two places
	cout << fixed << setprecision(2);

	//Create employees
	Employee* professional = new Professional("Brandon Smith");
	Employee* nonProfessional = new NonProfessional("Terry Fowler");

	//Display employee summaries
	displaySummary(professional, (double)39.8);
	displaySummary(nonProfessional, (double)46.33);

	return 0;
}

