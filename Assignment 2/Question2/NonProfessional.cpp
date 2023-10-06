//Author csk2q

#include <iostream>
#include <algorithm>
#include "NonProfessional.h"

using namespace std;

NonProfessional::NonProfessional(string fullName) : Employee(fullName, 19)
{
    Title = "The Worker";
}

double NonProfessional::GetHealthCareContributions(double hoursWorked)
{
    // 1/30 (roughly 3.33%) of income is contributed to healthcare
    return GetWeeklySalary(hoursWorked) / 30;
}

double NonProfessional::GetVacationDays(double hoursWorked)
{
    //A vacation day every 65 work hours and a cap of 14 days
    return std::min(hoursWorked / 66, (double)14);

}
