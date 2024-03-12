#include <iostream>

int check();
double RecY(int);
double Y(int);

int main()
{
	system("chcp 1251>nul");
	int n;
	printf("Введите n: ");
	n = check();
	printf("Рекурсивная функция: %lf \nОбычная функция: %lf", RecY(n), Y(n));
}

int check() {
	int a = 0;
	while ((scanf_s("%d", &a), getchar()) != '\n') {
		printf("Неправильный ввод!\nВведите число:");
		rewind(stdin);
	}
	return a;
}

double RecY(int n)
{
	if(n==0)
	{
		return 1.0/2;
	}
	return 1 / (n + RecY(n - 1));
}

double Y(int n)
{
	double Y{1.0/2};
	int n1{1};
	while (n1 != n+1)
	{
		Y = 1 / (n1++ + Y);
	}
	return Y;
}