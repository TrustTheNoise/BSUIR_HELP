//#include<iostream>
#include "DynamicArray.h"
#include <iostream>
int check();
template <class T>
void interface(DynamicArray<T> arr);
enum {OK, };

int main()
{
    int N = 0;
    std::cout << "Type the size of the array:\n>";
    N = check();
    DynamicArray<int> intArray;
	interface(intArray);
	return OK;
}

template <class T>
void interface(DynamicArray<T> arr){
	enum {VIEW=1,CREATE,TASK, DELETE, EXIT};
	int value=0;
	int exit = 0;
	while (!exit) {
		std::cout << "1.View objects\n2.Create object\n3.Task\n4.Delete\n5.Exit\n>";
		switch(check()) {
		case VIEW:
			arr.viewArray();
			break;
		case CREATE:
			std::cout << "Type the element of array:\n>";
			std::cin >> value;
			arr.initializeArray(value);
			break;
		case TASK:
			arr.performOperation();
			break;
		case DELETE:
			arr.delElem();
			break;
		case EXIT:
			exit = 1;
		}
	}
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