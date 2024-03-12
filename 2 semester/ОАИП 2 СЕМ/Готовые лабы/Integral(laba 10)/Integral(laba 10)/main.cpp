#include <iostream>
#include <cmath>

typedef double (*TFun)(double);

double F(double x)
{
	return pow(x,3) + 6 * pow(x, 2) - 0.02 * exp(x);
}

double gaus_with_n(double a, double b, int n)
{
	const double PI = 3.141592653589793;
	double* nuls = new double[n];
    double* w = new double[n];
    double h = (b - a) / 2;
    double x = (a + b) / 2;
    double q, S = 0;

	switch (n) {
	case 1:
		nuls[0] = 0.0;
		w[0] = 2.0;
		break;
	case 2:
		nuls[0] = -0.5773502691896257;
		nuls[1] = 0.5773502691896257;
		w[0] = 1.0;
		w[1] = 1.0;
		break;
	case 3:
		nuls[0] = -0.7745966692414834;
		nuls[1] = 0.0;
		nuls[2] = 0.7745966692414834;
		w[0] = 0.5555555555555556;
		w[1] = 0.8888888888888888;
		w[2] = 0.5555555555555556;
		break;
	}

    for (int i = 0; i < n; i++) {
        q = x + h * nuls[i];
        S += w[i] * F(q);
    }

	delete[] w;
	delete[] nuls;
    return h * S;
}

int check() {
	int a{};
	while (!scanf_s("%d", &a)) {
		printf("Неправильный ввод\nВведите число:");
		rewind(stdin);
	}
	char temp;
	while ((temp = getchar()) != '\n') {
		if (temp > 57 || temp < 48) {
			printf("Неправильный ввод\nВведите число:");
			rewind(stdin);
			scanf_s("%d", &a);
		}
	}
	return a;
}

int main()
{
	system("chcp 1251>nul");
	double s = 0, h, x;
	printf("1.Шаблон\n2.Свои\n");
	int a{}, b{};
	switch (check()) {
	case 1:
		a = -5;
		b = 3;
		break;
	case 2:
		printf("a = ");
		a = check();
		printf("b = ");
		b = check();
		break;
	}
	printf("Метод Гаусса какого порядка?\n");
	int n = check();
	printf("Вотъ: %lf", gaus_with_n(a, b, n));
}