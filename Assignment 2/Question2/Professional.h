//Author csk2q

#ifndef QUESTION2_PROFESSIONAL_H
#define QUESTION2_PROFESSIONAL_H

#include "Employee.h"

class Professional : public Employee
{
public:
    Professional(string fullName);

    double GetWeeklySalary(double _) override;

    double GetHealthCareContributions(double hoursWorked) override;
    
    double GetVacationDays(double hoursWorked) override;

};


#endif //QUESTION2_PROFESSIONAL_H
