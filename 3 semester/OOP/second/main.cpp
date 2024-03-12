//Вариант 5 Создать программу с классом Firm, порождающий объекты– данные о 
// конкретном сотруднике фирмы.Класс включает в себя следующие поля :
// -Ф И О сотрудника;
// -табельный номер;
// -количество проработанных часов за месяц;
// -почасовой тариф;
// и следующие методы :
// -конструктор с параметрами;
// -метод просмотра текущего состояния объектов.
// - функция - друг, выводящая данные о сотрудниках с отработанным
// временем свыше 144 часов.Оно считается сверхурочным и оплачивается в
// двойном размере.

#include <iostream>
#include "Firm.h"

double checkDouble();
int checkInt();
void interface(Firm**, int);

int main()
{
	int N{};
	std::cout << "Type the size of the array of objects\n>";
	std::cin >> N;
	Firm** employees = new Firm* [N];
	for(int i = 0; i < N; ++i)
		*(employees+i) = nullptr;
	interface(employees, N);
}

Firm* create_empl()
{
	char name[64];
	int id{};
	double hours{}, rate{};
	std::cout << "Type employee name:\n>";
	std::cin.getline(name, sizeof(name));
	std::cout << "Type employeeId:\n>";
	id = checkInt();
	std::cout << "Type hoursWorked:\n>";
	hours = checkDouble();
	std::cout << "Type hourlyRate:\n>";
	rate = checkDouble();
	return new Firm(name, id, hours, rate);
}

void interface(Firm** employees, int size) 
{
	enum {DISPLAY=1,CREATE,OVERTIME,DEL,EXIT};
	int j = 0;
	bool exit = 0, full = 0;
	while(!exit) {
		system("cls");
		std::cout << "1.Display\n2.Create object\n3.Over time Employees\n4.Delete\n5.Exit\n>";
		switch(checkInt()) {
		case DISPLAY:
			for(int i = 0; i < size && employees[i]; i++) {
				employees[i]->viewInfo();
				std::cout << "\n";
			}
			system("pause");
			break;
		case CREATE:
			if(employees[size-1] != nullptr) {
				std::cout << "All objects are occupied!\n";
				system("pause");
				break;
			}
			for(j = 0; employees[j]; j++) {}
			employees[j] = create_empl();
			std::cout << "Employee created!\n";
			system("pause");
			break;
		case OVERTIME:
			std::cout << "The OverTime employee is:\n";
			printOvertimeEmployees(employees, size);
			system("pause");
			break;
		case DEL:
			for(int i = 0; employees[i]; i++) {
				delete employees[i];
				employees[i] = nullptr;
			}
			break;
		case EXIT:
			exit = 1;
		}
	}
}

double checkDouble()
{
	double a = 0;
	while(true) {
		while((std::cin >> a, getchar()) != '\n') {
			std::cout << "Incorrect input!\n>";
			rewind(stdin);
		}
		if(a <= 0) {
			std::cout << "Incorrect number!\n>";
		}
		else {
			break;
		}
	}
	return a;
}

int checkInt()
{
	int a = 0;
	while(true) {
		while((std::cin >> a, getchar()) != '\n') {
			std::cout << "Incorrect input!\n>";
			rewind(stdin);
		}
		if(a <= 0) {
			std::cout << "Incorrect number!\n>";
		}else {
			break;
		}
	}
	return a;
}