#include <iostream>
class A {
public: 
	int* x;
};

int main()
{
	A* obj = new A;
	obj->x = new int;
	*(*obj).x = 5;
	std::cout << *obj->x;
}