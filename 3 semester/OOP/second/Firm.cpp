#include "Firm.h"

char* str_cpy(char* destination, const char* source)
{
  char* result = destination;

  while(*source != '\0') {
    *destination = *source;
    destination++;
    source++;
  }
  *destination = '\0';
  return result;
}

Firm::Firm(char* n, int id, double hours, double rate){
	str_cpy(this->fullName, n);
	this->employeeId = id;
	this->hoursWorked = hours;
	this->hourlyRate = rate;
}

void Firm::viewInfo() const
{
  std::cout << "Full name: " << fullName << std::endl;
  std::cout << "Employee ID: " << employeeId << std::endl;
  std::cout << "Hours worked: " << hoursWorked << std::endl;
  std::cout << "Hourly rate: " << hourlyRate << std::endl;
}

void printOvertimeEmployees(Firm** employee, int size)
{
  for(int i = 0; i < size && employee[i]; i++) {
    if(employee[i]->hoursWorked > 144.0)
      employee[i]->viewInfo();
  }
}