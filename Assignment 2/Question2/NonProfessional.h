//Author csk2q

#ifndef QUESTION2_NONPROFESSIONAL_H
#define QUESTION2_NONPROFESSIONAL_H

#include "Employee.h"

class NonProfessional : public Employee
{
public:
    
    NonProfessional(string fullName);
    
    double GetHealthCareContributions(double hoursWorked) override;
    
    double GetVacationDays(double hoursWorked) override;
};


#endif //QUESTION2_NONPROFESSIONAL_H
