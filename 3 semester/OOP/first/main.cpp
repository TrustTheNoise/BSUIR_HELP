// Вариант 30. Заданы два массива А(m) и В(n). В каждом из массивов найти 
// наибольшее значение и умножить на него все элементы массивов.На печать
// вывести исходные и преобразованные массивы.

#include<iostream>

int check_elem();
int find_max(int*, int);
void multiply_arr(int*, int, int);
int fill_array(int*, int);
int print_array(int*, int);
int check_size();

enum {ALL_GOOD, EMPTY_ARRAY, FILL_ARRAY, INCORRECT_SIZE};

int main()
{
	int m{}, n{};
	int* A{}, * B{};
	std::cout << "Type size of A array:\n>";
	m = check_size();
	std::cout << "Type size of B array:\n>";
	n = check_size();
	A = new int[m];
	B = new int[n];
	std::cout << "Fill the A array:\n";
	if(fill_array(A, m) == -1) {
		std::cerr << "Error in filling array A!\n";
		return FILL_ARRAY;
	}
	if(fill_array(B, n) == -1) {
		std::cerr << "Error in filling array B!\n";
		return FILL_ARRAY;
	}
	print_array(A,m);
	print_array(B, n);
	multiply_arr(A, m, find_max(A, m));
	multiply_arr(B, n, find_max(B, n));
	print_array(A, m);
	print_array(B, n);
	delete[] A;
	delete[] B;
	return ALL_GOOD;
}

int fill_array(int* arr, int size)
{
	int i{};
	if(!arr)
		return -1;
	if(size <= 0) {
		std::cout << "Incorrect size\n";
		return -1;
	}
	for(i=0; i<size; i++){
		std::cout << "Type the " << i << "th element of Array\n>";
		*(arr+i) = check_elem();
	}
	return i;
}

int print_array(int* arr, int size)
{
	int i{};
	if(!arr)
		return -1;
	if(size <= 0) {
		std::cout << "Incorrect size\n";
		return -1;
	}
	for(int i = 0; i < size; i++) {
		std::cout << *(arr+i) << " | ";
	}
	std::cout << "\n";
}

int check_size(){
	int a = 0;
	while(true) {
		while((std::cin >> a, getchar()) != '\n') {
			std::cout << "Incorrect input!\n>";
			rewind(stdin);
		}
		if(a <= 0) {
			std::cout << "Incorrect size of array!\n>";
		}
		else {
			break;
		}
	}
	return a;
}

int check_elem() {
	int a = 0;
	while((std::cin >> a, getchar()) != '\n') {
		std::cout << "Incorrect input!\n>";
		rewind(stdin);
	}
	return a;
}

int find_max(int* arr, int size)
{
	int max = *arr;
	for(int i = 1; i < size; i++) {
		if(max < *(arr + i)) {
			max = *(arr + i);
		}
	}
	return max;
}

void multiply_arr(int* arr, int size, int x)
{
	for(int i = 0; i < size; i++) {
		*(arr + i) *= x;
	}
}