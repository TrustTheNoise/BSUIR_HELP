#pragma once
#include <iostream>
#include <string>

class Firm {
private:
  char fullName[254];
  int employeeId;
  double hoursWorked;
  double hourlyRate;

public:
  Firm(char* n, int id, double hours, double rate);
  void viewInfo() const;
  friend void printOvertimeEmployees(Firm**, int size);
};