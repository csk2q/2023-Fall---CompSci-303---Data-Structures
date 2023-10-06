//Author csk2q

#include "Professional.h"

Professional::Professional(string fullName) : Employee(fullName, 28)
{
    Title = "The Professional";
}

double Professional::GetWeeklySalary(double _unused_ = 0)
{
    //Pay is 'fixed' because hours worked is 'fixed'
    // for the professionals at this company.
    return hourlyRate * HOURS_IN_WORK_WEEK;
}

double Professional::GetHealthCareContributions(double _unused_ = 0)
{
    // 5% (aka 1/20) of income is contributed to healthcare
    return GetWeeklySalary() / 20;
}

double Professional::GetVacationDays(double hoursWorked)
{
    //A vacation day every 50 work hours and a cap of 30 days
    return std::min(hoursWorked / 50, (double)30);
}

