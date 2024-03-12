#include <iostream>

using namespace std;

double f(double x) {
    return x * x * x - 5 * x * x + 12;
}

double vetein(double a, double b, double eps) {
    double x0 = a, x1 = b;
    double y0 = f(x0), y1 = f(x1);
    double z{};
    double de;
    int it = 0;
    do {
        it = it + 1;
        double d = x1 - x0;
        z = x1 - (y1 * d) / (y1 - y0);
        de = fabs(x1 - z);
        x0 = x1;
        x1 = z;
        y0 = y1;
        y1 = f(z);
    } while (de < eps || it>100);
    return z;
}

double half_division(double a, double b, double eps) {
    double y1, y2, y3, x3;
    y1 = f(a);
    y2 = f(b);
    do {
        x3 = (a + b) / 2.;
        y3 = f(x3);
        if (y1 * y3 < 0) {
            b = x3;
        }
        else {
            a = x3;
            y1 = y3;
        }
    } while (b - a > eps);
    return ((a + b) / 2.);
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

int main() {
    system("chcp 1251>nul");
    double x0 = -2, x1 = 5;
    int num_intervals = 10;
    bool exit = false;
    double (*methode)(double, double, double) = vetein;

    printf("Какой метод:\n1.Вегстейна\n2.Метод деления отрезка пополам\n");
    while (!exit) {
        switch (check()) {
        case 1:
            exit = true;
            break;
        case 2:
            methode = half_division;
            exit = true;
            break;
        default:
            printf("Такого варианта нет!!1!!");
        }
    }

    system("cls");
    exit = false;
    while (!exit) {
        printf("1.Шаблон\n2. Свои значения\n");
        switch (check()) {
        case 1:
            exit = true;
            break;
        case 2:
            printf("Введите:\na=");
            x0 = check();
            printf("b=");
            x1 = check();
            printf("num of intervals=");
            num_intervals = check();
            exit = true;
            break;
        default:
            printf("Такого варианта нет!!1!!");
        }
    }

    double y0 = f(x0), y1 = f(x1);
    double dx = (x0 + x1) / num_intervals;
    double x_left = x0, x_right = x0 + dx;

    while (x_right <= x1) {
        if (f(x_left) * f(x_right) <= 0) {
            double root = methode(x_left, x_right, 1e-6);
            printf("Root: %f\n", root);
        }
        x_left = x_right;
        x_right += dx;
    }
}