#include <iostream>
#include "Triangle.h"

// Вариант 30
// Создать класс треугольник, члены класса – длины трех сторон. 
// Предусмотреть в классе методы проверки существования треугольника,
// вычисления и вывода сведений о фигуре – длины сторон, углы, периметр,
// площадь.Создать производный класс – прямоугольный треугольник,
// предусмотреть в классе проверку, является ли треугольник прямоугольным.
// Написать программу, демонстрирующую работу с классом : дано N
// треугольников и M прямоугольных треугольников, найти треугольник с
// максимальной площадью и прямоугольный треугольник с наименьшей
// гипотенузой.

int check();
RightTriangle* create();
void interface(Triangle**, int, RightTriangle**, int);

int main()
{
	int N{}, M{};
	std::cout << "Type the size of the Triangle array:\n>";
	N = check();
	std::cout << "Type the size of the Right Triangle array:\n>";
	M = check();
	Triangle** trian = new Triangle *[N];
	for(int i = 0; i < N; i++) trian[i] = nullptr;
	RightTriangle** rtrian = new RightTriangle *[M];
	for(int i = 0; i < M; i++) rtrian[i] = nullptr;
	interface(trian, N, rtrian, M);
}

void creating(Triangle** trian, int size1,
	RightTriangle** rtrian, int size2)
{
	int j = 0;
	std::cout << "What do you want to create?\n"
		<< "1.Triangle\n2.Right Triangle\n>";
	switch(check()) {
	case 1:
		if(trian[size1-1] != nullptr) {
			std::cout << "All objects are occupied!\n";
			system("pause");
			break;
		}
		for(j = 0; trian[j]; j++) {}
		trian[j] = create();
		if(!trian[j]->isValid()) {
			delete trian[j];
			trian[j] = nullptr;
			std::cout << "This is not triangle!!!\n";
			system("pause");
			break;
		}
		std::cout << "Triangle created!\n";
		system("pause");
		break;
	case 2:
		if(rtrian[size2 - 1] != nullptr) {
			std::cout << "All objects are occupied!\n";
			system("pause");
			break;
		}
		for(j = 0; rtrian[j]; j++) {}
		rtrian[j] = create();
		if(!rtrian[j]->isValid() || !rtrian[j]->isRightTriangle()) {
			delete rtrian[j];
			rtrian[j] = nullptr;
			std::cout << "This is not right triangle!!!\n";
			system("pause");
			break;
		}
		std::cout << "Right triangle created!\n";
		system("pause");
		break;
	}
}

void task(Triangle** trian, int size1,
	RightTriangle** rtrian, int size2)
{
	Triangle* max_triangle = nullptr;
	if(trian[0]) {
		max_triangle = trian[0];
		double max_area_triangle = trian[0]->area();
		for(int i = 0; i < size1 && trian[i]; i++) {
			if(max_area_triangle < trian[i]->area()) {
				max_area_triangle = trian[i]->area();
				RightTriangle* rtr = rtrian[0];
				Triangle* tr = trian[0];
				tr->area();
				RightTriangle* derivedPtr = dynamic_cast<RightTriangle*>(tr);
				dynamic_cast<RightTriangle*>(tr)->area();
				max_triangle = trian[i];
			}
		}
	}
	RightTriangle* min_rtriangle = nullptr;
	if(rtrian[0]) {
		min_rtriangle = rtrian[0];
		rtrian[0]->Triangle::area();
		double min_hyb_rtriangle = rtrian[0]->findHypotenuse();
		for(int i = 0; i < size2 && rtrian[i]; i++) {
			if(min_hyb_rtriangle > rtrian[i]->findHypotenuse()) {
				min_hyb_rtriangle = rtrian[i]->findHypotenuse();
				rtrian[i]->Triangle::area();
				min_rtriangle = rtrian[i];
			}
		}
	}
	if(max_triangle) {
		std::cout << "Triangle with the max area: ";
		max_triangle->viewInfo();
	}
	if(min_rtriangle) {
		std::cout << "\nRight triangle with min hypotenuse: ";
		min_rtriangle->viewInfo();
	}
	std::cout << "\n";
}

void interface(Triangle** trian, int size1,
	RightTriangle** rtrian, int size2){
	bool exit = 0;
	enum {VIEW=1, CREATE, TASK, DEL, EXIT};
	while(!exit) {
		system("cls");
		std::cout << "1.View objects\n2.Create object\n3.Task\n4.Delete\n5.Exit\n>";
		switch(check()) {
		case VIEW:
			std::cout << "TRIANGLES:\n";
			for(int i = 0; i < size1 && trian[i]; i++) {
				trian[i]->viewInfo();
				std::cout << "\n";
			}
			std::cout << "RIGHT TRIANGLES:\n";
			for(int i = 0; i < size2 && rtrian[i]; i++) {
				rtrian[i]->viewInfo();
				std::cout << "\n";
			}
			system("pause");
			break;
		case CREATE:
			creating(trian, size1, rtrian, size2);
			break;
		case TASK:
			task(trian, size1, rtrian, size2);
			system("pause");
			break;
		case DEL:
			for(int i = 0; i<size1; i++) {
				delete trian[i];
				trian[i] = nullptr;
			}
			for(int i = 0; i<size2; i++) {
				delete rtrian[i];
				rtrian[i] = nullptr;
			}
			break;
		case EXIT:
			delete[] trian;
			delete[] rtrian;
			exit = 1;
			break;
		}
	}
}

RightTriangle* create()
{
	int size1{}, size2{}, size3{};
	std::cout << "Size1: ";
	size1 = check();
	std::cout << "Size2: ";
	size2 = check();
	std::cout << "Size3: ";
	size3 = check();
	return new RightTriangle(size1,size2,size3);
}

int check()
{
	int a = 0;
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