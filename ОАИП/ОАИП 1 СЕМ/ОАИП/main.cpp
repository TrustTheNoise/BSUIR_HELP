//
// лаба номер 1
//

//#include <iostream>
//#include <cmath>
//
//using namespace std;
//
//double check() {
//	double a{};
//	while (!scanf_s("%lf", &a)) {
//		printf("Неправильный ввод\nВведите число:");
//		rewind(stdin);
//	}
//	char temp;
//	while ((temp = getchar()) != '\n') {
//		if ((temp > 57) || (temp < 48)) {
//			printf("Неправильный ввод\nВведите число:");
//			rewind(stdin);
//			scanf_s("%lf", &a);
//		}
//	}
//	return a;
//}
//
//int main()
//{
//	setlocale(LC_ALL, "RUS");
//	double x{}, y{}, z{}, b{};
//	
//	printf_s("Введи x: ");
//	x = check();
//	
//	printf("Введи y: ");
//	y=check();
//	
//	printf("Введи z: ");
//	z=check();
//
//	if ((x + y > 0) && ((exp(abs(x - y)) + (x / 2)) != 0))
//	{
//
//		b = pow(y, pow(abs(x), 1.0 / 3)) + pow(cos(y), 3) * (abs(x - y) * (1 + (pow(sin(z), 2)) / sqrt(x + y))) / (exp(abs(x - y)) + (x / 2));
//
//		printf("b = %.4lf", b);
//	}else 
//	{
//		printf("Некорректные данные(данные не входят в одз)");
//	}
//	return 0;
//}

// 
// лаба номер 2
//

//#include <iostream>
//#include <cmath>
//
//template<typename T> T check();
//
//template<> double check();
//template<> int check();
//
//using namespace std;
//int main()
//{
//	setlocale(LC_ALL, "Rus");
//	double x, y, z, func{};
//	int preFunc;
//	bool proverka{true};
//	printf("Введите z: ");
//	z=check<double>();
//	if (z > 0) 
//	{
//		x = 1/(z*z+2*z);
//	}else
//	{
//		x = 1-z*z*z;
//	}
//
//	
//	double a, b;
//	printf("Введите a: ");
//	a = check<double>();
//	printf("Введите c: ");
//	b=check<double>();
//
//	while (proverka)
//	{
//		printf("Выберите функцию f(x):\n1.f(x)=2x\n2.f(x)=x^2\n3.f(x)=x/3\n");
//
//		preFunc = check<int>();
//
//		switch (preFunc)
//		{
//		case 1:
//			func = 2 * x;
//			proverka = false;
//			break;
//		case 2:
//			func = pow(x, 2);
//			proverka = false;
//			break;
//		case 3:
//			func = x / 3;
//			proverka = false;
//			break;
//		default:
//			printf("Такого варианта нет!");
//		}
//	}
//
//	printf("Переменная y расчитывалась с учётом того, что функция f(x) = ");
//
//	switch (preFunc)
//	{
//	case 1:
//		printf("2 * x, ");
//		break;
//	case 2:
//		printf("x^2, ");
//		break;
//	case 3:
//		printf("x / 3, ");
//		break;
//	}
//
//	printf("а x = %lf \n", x);
//
//	y = (2.5*a*exp(pow(sin(x),3))-4*b*x*x)/(log(fabs(x))+func);
//
//	printf("Тогда y = %lf", y);
//	
//	return 0;
//}
//
//template<> double check() {
//	double a{};
//	while (!scanf_s("%lf", &a)) {
//		printf("Неправильный ввод\nВведите число:");
//		rewind(stdin);
//	}
//	char temp;
//	while ((temp = getchar()) != '\n') {
//		if ((temp > 57) || (temp < 48)) {
//			printf("Неправильный ввод\nВведите число:");
//			rewind(stdin);
//			scanf_s("%lf", &a);
//		}
//	}
//	return a;
//}
//
//template<> int check() {
//	int a{};
//	while (!scanf_s("%d", &a)) {
//		printf("Неправильный ввод\nВведите число:");
//		rewind(stdin);
//	}
//	char temp;
//	while ((temp = getchar()) != '\n') {
//		if ((temp > 57) || (temp < 48)) {
//			printf("Неправильный ввод\nВведите число:");
//			rewind(stdin);
//			scanf_s("%d", &a);
//		}
//	}
//	return a;
//}


//
// лаба 3
//

//#include <iostream>
//#include <cmath>
//#include <cstdio>
//
//using namespace std;
//
//template <typename T> T check();
//
//template <> double check();
//template <> int check();
//
//int main()
//{
//	system("chcp 1251>nul");
//	double x, a=0.1, b=1.0, h=0.1, Y;
//	int n=10, choise;
//	bool proverka = true, BigProverka=true, proverkaChoise=true;
//	while (proverkaChoise)
//	{
//		printf("Выберите как вводить переменные: 1)проверочные значения 2)свои значения\n");
//		choise = check<int>();
//		switch (choise)
//		{
//		case 1:
//			proverkaChoise = false;
//			break;
//		case 2:
//			while (BigProverka)
//			{
//				while (proverka)
//				{
//					printf_s("Введите a: ");
//					a = check<double>();
//					if (a <= 0)
//					{
//						printf_s("a не может быть меньше или равен 0\n");
//					}
//					else
//					{
//						proverka = false;
//					}
//				}
//				proverka = true;
//				while (proverka)
//				{
//					printf_s("Введите b: ");
//					b = check<double>();
//					if (b <= 0)
//					{
//						printf_s("b не может быть меньше либо равно 0\n");
//					}
//					else
//					{
//						proverka = false;
//					}
//					if (a > b)
//					{
//						printf("a не может быть больше b\n");
//					}
//					else
//					{
//						BigProverka = false;
//					}
//				}
//			}
//			while (true)
//			{
//				printf("Введите h: ");
//				h = check<double>();
//				if (h <= 0)
//				{
//					printf("h не может быть меньше либо равно 0\n");
//				}
//				else
//				{
//					break;
//				}
//			}
//			while (true)
//			{
//				printf("Введите n: ");
//				n = check<int>();
//				if (n <= 0)
//				{
//					printf("n не может быть меньше либо равно 0");
//				}
//				else
//				{
//					break;
//				}
//			}
//			proverkaChoise = false;
//			break;
//		default:
//			printf("Такого варианта нет!\n");
//			break;
//		}
//	}
//	double S;
//	for(x=a; x<=b; x+=h)
//	{
//		double r = S = 1;
//		Y = (x * x / 4 + x / 2 + 1) * exp(x / 2);
//		for(int k=1;k<=n;k++)
//		{
//			r = r * x / (2 * k);
//			S += (k * k + 1) * r;
//		}
//		printf_s("Y = %lf", Y);
//		printf_s("\tS = %lf\t", S);
//		printf_s("|Y(x)-S(x)| = %g\n", fabs(Y-S));
//	}
//}
//
//template<> double check() {
//	double a{};
//	while (!scanf_s("%lf", &a)) {
//		printf("Неправильный ввод\nВведите число:");
//		rewind(stdin);
//	}
//	char temp;
//	while ((temp = getchar()) != '\n') {
//		if ((temp > 57) || (temp < 48)) {
//			printf("Неправильный ввод\nВведите число:");
//			rewind(stdin);
//			scanf_s("%lf", &a);
//		}
//	}
//	return a;
//}
//
//template<> int check() {
//	int a{};
//	while (!scanf_s("%d", &a)) {
//		printf("Неправильный ввод\nВведите число:");
//		rewind(stdin);
//	}
//	char temp;
//	while ((temp = getchar()) != '\n') {
//		if ((temp > 57) || (temp < 48)) {
//			printf("Неправильный ввод\nВведите число:");
//			rewind(stdin);
//			scanf_s("%d", &a);
//		}
//	}
//	return a;
//}

//
// лаба 4
//

//#include <iostream>
//#include <cmath>
//#include <cstdio>
//
//using namespace std;
//
//typedef double (*TFun)(double, int);
//
//int Fact(int N)
//{
//	int F = 1;
//	if (N < 0)
//		return 0;
//	if (N == 0)
//		return 1;
//	for (int i = 1; i <= N; ++i)
//		F *= i;
//	return F;
//}
//
// double checkDouble() {
//	double a{};
//	while (!scanf_s("%lf", &a)) {
//		printf("Неправильный ввод\nВведите число:");
//		rewind(stdin);
//	}
//	char temp;
//	while ((temp = getchar()) != '\n') {
//		if ((temp > 57) || (temp < 48)) {
//			printf("Неправильный ввод\nВведите число:");
//			rewind(stdin);
//			scanf_s("%lf", &a);
//		}
//	}
//	return a;
//}
//
// int checkInt() {
//	int a{};
//	while (!scanf_s("%d", &a)) {
//		printf("Неправильный ввод\nВведите число:");
//		rewind(stdin);
//	}
//	char temp;
//	while ((temp = getchar()) != '\n') {
//		if ((temp > 57) || (temp < 48)) {
//			printf("Неправильный ввод\nВведите число:");
//			rewind(stdin);
//			scanf_s("%d", &a);
//		}
//	}
//	return a;
//}
//
//void outrez(TFun f, double a, double b, double h, int n) {
//	for (a; a <= b; a += h) {
//		printf("| %.12lf |", f(a, n));
//		printf("\n");
//	}
//}
//
//double Sx(double x, int n)
//{
//	double S;
//	double r=S = 1;
//	for(int k=1;k<=n;k++)
//	{
//		r = r * (x * x / (2 * k * (2 * k - 1)));
//		S = S + r;
//	}
//	return S;
//}
//
//double Yx(double x, int n)
//{
//	double Y;
//	Y = (exp(x)+exp(-x))/2;
//	return Y;
//}
//
//double modul(double x, int n)
//{
//	double modul, Y;
//	double S;
//	double r = S = 1;
//	for (int k = 1; k <= n; k++)
//	{
//		r = r * (x * x / (2 * k * (2 * k - 1)));
//		S = S + r;
//	}
//	Y = (exp(x) + exp(-x)) / 2;
//	return fabs(Y - S);
//}
//
//int main()
//{
//	system("chcp 1251>0");
//	double a=0.1,b=1.0,h=0.1;
//	int n=10, choise;
//	bool BigProverka = true, proverka=true, proverkaChoise=true;
//	while (proverkaChoise)
//	{
//		printf("Выберите как вводить переменные: 1)проверочные значения 2)свои значения\n");
//		choise = checkInt();
//		switch (choise)
//		{
//		case 1:
//			proverkaChoise = false;
//			break;
//		case 2:
//			while (BigProverka)
//			{
//				while (proverka)
//				{
//					printf_s("Введите a: ");
//					a = checkDouble();
//					if (a <= 0)
//					{
//						printf_s("a не может быть меньше или равен 0\n");
//					}
//					else
//					{
//						proverka = false;
//					}
//				}
//				proverka = true;
//				while (proverka)
//				{
//					printf_s("Введите b: ");
//					b = checkDouble();
//					if (b <= 0)
//					{
//						printf_s("b не может быть меньше либо равно 0\n");
//					}
//					else
//					{
//						proverka = false;
//					}
//					if (a > b)
//					{
//						printf("a не может быть больше b\n");
//					}
//					else
//					{
//						BigProverka = false;
//					}
//				}
//			}
//			while (true)
//			{
//				printf("Введите h: ");
//				h = checkDouble();
//				if (h <= 0)
//				{
//					printf("h не может быть меньше либо равно 0\n");
//				}
//				else
//				{
//					break;
//				}
//			}
//			while (true)
//			{
//				printf("Введите n: ");
//				n = checkInt();
//				if (n <= 0)
//				{
//					printf("n не может быть меньше либо равно 0");
//				}
//				else
//				{
//					break;
//				}
//			}
//			proverkaChoise = false;
//			break;
//		default:
//			printf("Такого варианта нет!\n");
//			break;
//		}
//	}
//	printf("Выберите функцию: 1)sx 2)yx 3)|yx-sx|\n");
//	bool flag=true;
//	while (true)
//	{
//		choise = checkInt();
//		switch (choise)
//		{
//		case 1:
//			outrez(Sx, a, b, h, n);
//			break;
//		case 2:
//			outrez(Yx, a, b, h, n);
//			break;
//		case 3:
//			outrez(modul, a, b, h, n);
//			break;
//		default:
//			printf_s("Такого варианта нет!1!!\n");
//			flag = false;
//			break;
//		}
//		if(flag)
//		{
//			break;
//		}
//	}
//}

//
// лаба 5
//

//#include <iostream>
//#include <ctime>
//
//using namespace std;
//
//int check() {
//	int a{};
//	while (!scanf_s("%d", &a)) 
//		{
//		printf("Неправильный ввод\nВведите число:");
//			rewind(stdin);
//		}
//	char temp;
//	while ((temp = getchar()) != '\n') 
//		{
//			if ((temp > 57) || (temp < 48)) {
//				printf("Неправильный ввод\nВведите число:");
//				rewind(stdin);
//				scanf_s("%d", &a);
//			}
//		}
//	return a;
//	}
//
//int main()
//{
//	setlocale(LC_ALL, "RUS");
//	srand(time(NULL));
//	int n;
//	bool proverka = true;
//	int arr[100] = {}, sum{}, choise;
//	do
//	{
//		printf("Введи размер массива(в пределах 1-99): ");
//		n = check();
//		if (n > 0 && n < 100)
//		{
//			proverka = false;
//		}else
//		{
//			printf("Размер должен быть в пределах 1 - 99\n");
//		}
//	} while (proverka);
//	proverka = true;
//	while (proverka)
//	{
//		printf_s("Как хотите заполнить массив? 1.с клавиатуры 2.случайные числа\n");
//		choise = check();
//
//		switch (choise)
//		{
//		case 1:
//			proverka = false;
//			for (int i = 0; i < n; i++)
//			{
//				printf_s("Введите %d элемент массива: ", i);
//				arr[i] = check();
//			}
//			break;
//		case 2:
//			proverka = false;
//			for (int i = 0; i < n; i++)
//			{
//				arr[i] = -4 + rand() % 10;
//			}
//			break;
//		default:
//			printf("Такого варианта нет...\n");
//		}
//	}
//
//	for (int i = 0; i < n; i++)
//	{
//		printf_s("%d | ", arr[i]);
//	}
//
//	int min = arr[0], numMin{};
//	
//	for (int i = 1; i < n; i++)
//	{
//		if (arr[i] <= min)
//		{
//			min = arr[i];
//			numMin = i;
//		}
//	}
//
//	for (int i = 0; i < numMin; i++)
//	{
//		if (arr[i] == min)
//		{
//			printf("\nВ массиве два или более одинаковых минимальных элемента");
//			return 0;
//		}
//	}
//
//	printf_s("\nМинимальным элементом массива является: %d", min);
//
//	if(numMin==n-1)
//	{
//		printf("\nМинимальный элемент является последним элементом массива");
//		return 0;
//	}
//
//	for(int i = numMin+1; i < n; i++ )
//	{
//		sum += arr[i];
//	}
//
//	printf_s("\nСумма элементов массива после минимального элемента равна: %d", sum);
//}

//
// лаба 6
//

//#include <iostream>
//
//int checkForArr(int i, int j)
//{
//	int a{};
//	while (!scanf_s("%d", &a))
//	{
//		printf("Неправильный ввод\nВведите элемент arr[%d][%d]:",i,j);
//		rewind(stdin);
//	}
//	char temp;
//	while ((temp = getchar()) != '\n')
//	{
//		if ((temp > 57) || (temp < 48)) {
//			printf("Неправильный ввод\nВведите элемент arr[%d][%d]:", i, j);
//			rewind(stdin);
//			scanf_s("%d", &a);
//		}
//	}
//	return a;
//}
//
//int check()
//{
//	int a{};
//	while (!scanf_s("%d", &a)) 
//		{
//		printf("Неправильный ввод\nВведите число:");
//			rewind(stdin);
//		}
//	char temp;
//	while ((temp = getchar()) != '\n') 
//		{
//			if ((temp > 57) || (temp < 48)) {
//				printf("Неправильный ввод\nВведите число:");
//				rewind(stdin);
//				scanf_s("%d", &a);
//			}
//		}
//	return a;
//}
//
//int main()
//{
//	setlocale(LC_ALL, "RUS");
//	int N{}, M{}, num{};
//	bool proverka = true;
//	printf_s("Введите размеры N, M\n");
//	while (proverka)
//	{
//		printf_s("N: ");
//		N = check();
//		if(N<=0)
//		{
//			printf("N не может быть меньше или равен 0...\n");
//		}else
//		{
//			proverka = false;
//		}
//	}
//	proverka = true;
//
//
//	while (proverka)
//	{
//		printf_s("M: ");
//		M = check();
//		if (M <= 0)
//		{
//			printf("M не может быть меньше или равен 0...\n");
//		}
//		else
//		{
//			proverka = false;
//		}
//	}
//	if (M <= 2)
//	{
//		printf("Элементов удовлетворяющих условию не может существовать при N меньше либо равно 0...");
//		return 0;
//	}
//
//	proverka = true;
//	int** arr = new int*[N];
//	for(int i=0; i<N; i++)
//	{
//		arr[i] = new int[M];
//	}
//
//	int ch;
//	while (proverka)
//	{
//		printf("Как заполнить массив: 1.С клавиатуры 2.Рандомно\n");
//		ch = check();
//		switch(ch)
//		{
//		case 1:
//			for (int i = 0; i < N; i++)
//			{
//				for (int j = 0; j < M; j++)
//				{
//					printf_s("Введите элемент arr[%d][%d]: ", i, j);
//					arr[i][j] = checkForArr(i,j);
//				}
//			}
//			proverka = false;
//			break;
//		case 2:
//			for (int i = 0; i < N; i++)
//			{
//				for (int j = 0; j < M; j++)
//				{
//					arr[i][j] = rand() % 10;
//				}
//			}
//			proverka = false;
//			break;
//		default:
//			printf("Такого варианта нет...\n");
//			break;
//		}
//	}
//
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < M; j++)
//		{
//			printf_s("%d | ", arr[i][j]);
//		}
//		printf_s("\n");
//	}
//
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 1; j < M-1; j++)
//		{
//			if (arr[i][j] > arr[i][j - 1] && arr[i][j] < arr[i][j + 1])
//			{
//				num++;
//			}
//		}
//	}
//
//	printf_s("Количество элементов матрицы, у которых слева находится элемент меньше его, а справа – больше: %d", num);
//
//	for (int i = 0; i < N; i++)
//	{
//		delete[] arr[i];
//	}
//	delete[] arr;
//	return 0;
//}


// лаба 7 


//#include <iostream>
//#include <conio.h>
//
//using namespace std;
//
//void zapis(char* s, int size)
//{
//	int i{};
//	char x{};
//	bool flag = true;
//	while(i<size-1 && x !='\r')
//	{
//		printf("Введите строку(прописными символами на английском языке): ");
//		for (int j = 0; j < i; j++)
//		{
//			printf("%c", s[j]);
//		}
//		x = _getch();
//		system("cls");
//		if(x == '\b' && i>0)
//		{
//			i--;
//			s[i] = '\0';
//		}
//		if (s[i - 1] == ' ' && x == ' ')
//		{
//			flag = false;
//			continue;
//		}
//		if ((x >= 97 && x <= 122) || (x == ' '))
//		{
//			s[i] = x;
//			i++;
//		}
//		flag = true;
//	}
//	if (i == size-1)
//	{
//		while(s[i-1]==' ')
//		{
//			i--;
//		}
//		printf("\nКоличество символов ограничено!");
//		s[i] = '\0';
//		rewind(stdin);
//		return;
//	}
//	s[i] = '\0';
//}
//
//int main()
//{
//	setlocale(LC_ALL, "RUS");
//	char arr[100];
//	int numOfSpace{}, sizeOfWord{}, maxSize{};
//	while (1)
//	{
//		numOfSpace = 0;
//		zapis(arr, sizeof(arr));
//			for (int i = 0; arr[i]; i++)
//			{
//				if (arr[i] == ' ')
//				{
//					numOfSpace++;
//				}
//			}
//		if(numOfSpace!=0)
//		{
//			break;
//		}
//		printf("\nВ вашей строке только 1 слово!!!11!\n");
//	}
//	printf("Введите строку(прописными символами на английском языке): %s", arr);
//	printf("\n");
//	int lastNumOfSpace=-1;
//	for(int i=0;; i++)
//	{
//		if(arr[i] == ' ')
//		{
//			sizeOfWord = i-lastNumOfSpace-1;
//			if(sizeOfWord>maxSize)
//			{
//				maxSize = sizeOfWord;
//			}
//			lastNumOfSpace = i;
//		}
//		if(!arr[i])
//		{
//			sizeOfWord = i - lastNumOfSpace - 1;
//			if (sizeOfWord > maxSize)
//			{
//				maxSize = sizeOfWord;
//			}
//			lastNumOfSpace = i;
//			break;
//		}
//	}
//	char** ch = new char* [++numOfSpace];
//
//	for (int i = 0; i < numOfSpace; i++)
//	{
//		ch[i] = new char[maxSize+1];
//	}
//	int k = 0;
//	for(int i=0;i<numOfSpace;i++)
//	{
//		for(int j=0;j<=maxSize;j++, k++)
//		{
//			if(arr[k]==' ' || !arr[k])
//			{
//				k++;
//				ch[i][j] = '\0';
//				break;
//			}
//			ch[i][j] = arr[k];
//		}
//	}
//
//	for (int i = 0; i < numOfSpace; i++)
//	{
//		for (k = i + 1; k < numOfSpace; k++)
//		{
//			for (int m = 0; ch[i][m] && ch[k][m]; m++)
//			{
//				if (ch[i][m] > ch[k][m])
//				{
//					char* temp = ch[i];
//					ch[i] = ch[k];
//					ch[k] = temp;
//					break;
//				}
//				if (ch[i][m] == ch[k][m])
//				{
//					continue;
//				}
//				break;
//			}
//		}
//	}
//	printf("Отсортированный вариант(в алфавитном порядке):\n");
//	for(int i=0;i<numOfSpace;i++)
//	{
//		printf_s("%s ", ch[i]);
//	}
//	for(int i=0; i<numOfSpace; i++)
//	{
//		delete[] ch[i];
//	}
//	delete[] ch;
//}

//
//	лаба 8
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <io.h>
#include <conio.h>
#include <iostream>


struct Students {
  char FIO[40];
	int year_birthday;
	int num_group;
	int marks[4];
	double s_mark;
};
FILE* Fz, * Ft, * It;
char File_Zap[256];
char File_Rez[] = "rezult.txt";
int sizeOfStruct = sizeof(Students);


int check();
void create();
void out(Students&, FILE*, int);
void add();
bool view();
void save(Students*, int);
void edit(int);
void zadanie();
void zapisName(char*, int);
void zapisFile(char*, int);


using namespace std;
int main()
{
	system("chcp 1251>0");
	char* a;
	while(true)
	{
		int choise1, razm;
		system("cls");
		printf("\n1.Создать или редактировать текущий файл  2.Удалить файл  3.Выйти\nВыбирайте: ");
		choise1 = check();
		switch(choise1)
		{
		case 1:
			system("cls");
			razm = 0;
			zapisFile(File_Zap, sizeof(File_Zap));
			while (File_Zap[razm])
			{
				razm++;
			}
			File_Zap[razm] = '.';
			File_Zap[++razm] = 'd';
			File_Zap[++razm] = 'a';
			File_Zap[++razm] = 't';
			File_Zap[razm + 1] = '\0';
			while (true)
			{
				int choise2;
				bool proverka = true, proverkaForCase3 = true, flag=false;
				while (proverka)
				{
					system("cls");
					printf("Ваш файл: %s", File_Zap);
					printf("\n1 - Создать\t2 - Просмотр\t3 - Изменить\t4 - Индивидуальное задание\t0 - Выйти\n");
					printf("Выбирайте: ");
					choise1 = check();
					switch (choise1)
					{
					case 1:
						system("cls");
						if (_access(File_Zap, 0) == 0) {
							printf("Файл уже создан");
							break;
						}
						create();
						if (!Fz)
						{
							printf("Ошибка!");
							return 0;
						}
						proverka = false;
						system("pause");
						break;
					case 2:
						if (!view())
						{
							printf("\n\nФайл остуствует...\n");
						}
						proverka = false;
						system("pause");
						break;
					case 3:
						system("cls");
						if (!Fz)
						{
							printf("Файл не создан!\n");
							system("pause");
							break;
						}
						proverkaForCase3 = true;
						while (proverkaForCase3)
						{
							printf("\n1.Добавить\n2.Изменить\nКак именно изменить?  ");
							choise2 = check();
							switch (choise2)
							{
							case 1:
								add();
								proverkaForCase3 = false;
								system("pause");
								break;
							case 2:
								int choiseNum;
								view();

								int descriptor, kol;
								long len;
								Fz = fopen(File_Zap, "rb");
								descriptor = _fileno(Fz);
								len = _filelength(descriptor);
								kol = len / sizeOfStruct;
								fclose(Fz);

								if(kol==0)
								{
									printf("\nЭлементов которые можно изменить нет!!1!1\n");
									proverkaForCase3 = false;
									system("pause");
									break;
								}

								printf("\n\nВведите номер записи, которую хотите изменить:\t");
								proverkaForCase3 = false;
								choiseNum = check();
								rewind(stdin);

								if (choiseNum > kol || choiseNum<1)
								{
									printf("Такого элемента нет...");
									system("pause");
									break;
								}

								edit(choiseNum);
								system("pause");
								break;
							default:
								printf("\nТакого варианта нет!!!1!1");
							}
						}
						proverka = false;
						break;
					case 4:
						if (!Fz)
						{
							printf("Файл не создан!\n");
							system("pause");
							break;
						}
						zadanie();
						proverka = false;
						break;
					case 0:
						proverka = false;
						flag = true;
						break;
					default:
						printf("Такого варианта нет!!\n");
					}
				}
				if (flag)
				{
					break;
				}
			}
			break;
		case 2:
			system("cls");
			razm = 0;
			zapisFile(File_Zap, sizeof(File_Zap));
			rewind(stdin);

			while (File_Zap[razm])
			{
				razm++;
			}
			File_Zap[razm] = '.';
			File_Zap[++razm] = 'd';
			File_Zap[++razm] = 'a';
			File_Zap[++razm] = 't';
			File_Zap[razm + 1] = '\0';
			if(remove(File_Zap)==0)
			{
				printf_s("\nФайл успешно удалён!\n");
			}else
			{
				printf_s("\nОшибка удаления файла...\n");
			}
			system("pause");
			break;
		case 3:
			return 0;
		default:
			printf_s("Такого варианта нет...");
		}
	}
}

void zapisFile(char* s, int size)
{
	int i{};
	char x{};
	while (i < size - 1)
	{
		printf_s("На данный момент существующие файлы:\n");
		system("dir *.dat /b");
		printf_s("Введите имя файла который хотите удалить: ");
		for (int j = 0; j < i; j++)
		{
			printf("%c", s[j]);
		}
		x = _getch();
		system("cls");
		if (x == '\b' && i > 0)
		{
			i--;
			s[i] = '\0';
			continue;
		}
		if (x == '/' || x == '\\' || x == ':' || x == '*' || x == '?' || x == '>' || x == '<' || x == '|')
		{
			continue;
		}
		if(x=='\r')
		{
			break;
		}
		s[i] = x;
		i++;
	}
	if (i == size - 1)
	{
		while (s[i - 1] == ' ')
		{
			i--;
		}
		printf("\nКоличество символов ограничено!");
		s[i] = '\0';
		rewind(stdin);
		return;
	}
	s[i] = '\0';
}

void zapisName(char* s, int size)
{
	int i{};
	while (true)
	{
		setlocale(LC_ALL, "Rus");
		int numOfSpace{};
		unsigned char x{};
		while (i < size - 1)
		{
			printf("ФИО: ");
			for (int j = 0; j < i; j++)
			{
				printf("%c", s[j]);
			}
			x = _getch();
			system("cls");
			if (x == ' ')
			{
				if (s[i - 1] == ' ')
				{
					continue;
				}
				numOfSpace++;
				if (numOfSpace > 2)
				{
					printf("\nВсего должно быть 3 слова!!!\n\n");
					system("pause");
					system("cls");
					continue;
				}
				s[i] = x;
				i++;
			}
			if (x == '\b' && i > 0)
			{
				if(s[i-1]==' ')
				{
					s[--i] = '\0';
					numOfSpace--;
					continue;
				}
				s[--i] = '\0';
				continue;
			}
			if (x >= 192 && x <= 255)
			{
				s[i] = x;
				i++;
			}
			if (x == '\r')
			{
				break;
			}
		}
		if(numOfSpace<2)
		{
			printf("\nСлов должно быть 3!!!\n");
			for (int j = 0; j < i; j++)
			{
				s[j] = '\0';
			}
			i = 0;
			system("pause");
			system("cls");
		}else
		{
			printf("ФИО: ");
			for (int j = 0; j < i; j++)
			{
				printf("%c", s[j]);
			}
			break;
		}
	}
	if (i == size - 1)
	{
		while (s[i - 1] == ' ')
		{
			i--;
		}
		printf("\nКоличество символов ограничено!");
		s[i] = '\0';
		printf_s("\nВаше ФИО: ");
		for (int j = 0; j < i; j++)
		{
			printf("%c", s[j]);
		}
		rewind(stdin);
		return;
	}
	s[i] = '\0';
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

void create()
{
	Fz = fopen(File_Zap, "wb");
	printf("\nФайл создан!\n");
	fclose(Fz);
}

bool view() {
	Fz = fopen(File_Zap, "rb");
	Ft = fopen(File_Rez, "wb");
	if (!Fz)
		return false;
	Students student;

	printf("\n\t--------------- Информация ---------------\n");
	fprintf(Ft, "\n\n\n\t---------------  Информация ---------------\n");


	for (int i = 1; fread(&student, sizeOfStruct, 1, Fz);i++)
	{
		out(student, Ft, i);
	}
	printf("\n\n");
	fclose(Fz);
	fclose(Ft);
	return true;
}

void out(Students &s, FILE* Potochek, int i = 0)
{
	printf("\n%d. %s - %d, Группа: %d; Физика: %d, Математика: %d, Информатика: %d, Химия: %d, Средний балл: %1.2lf", i, s.FIO, s.year_birthday, s.num_group, s.marks[0], s.marks[1], s.marks[2], s.marks[3], s.s_mark);
	fprintf(Potochek, "\n%s - %d, Группа: %d; Физика: %d, Математика: %d, Информатика: %d, Химия: %d, Средний балл: %1.2lf", s.FIO, s.year_birthday, s.num_group, s.marks[0], s.marks[1], s.marks[2], s.marks[3], s.s_mark);
}

void add()
{
	system("cls");
	Students student;
	zapisName(student.FIO, sizeof(student.FIO));
	while (1)
	{
		printf("\nГод рождения: ");
		student.year_birthday = check();
		if (student.year_birthday <= 2005 && student.year_birthday >= 1999) break;
		printf("Некорректная дата...\n");
	}
	printf("Номер группы: ");
	student.num_group = check();
	printf("Введите оценки по предметам:");
	while (1)
	{
		printf("\nФизика: ");
		student.marks[0] = check();
		if (student.marks[0] >= 0 && student.marks[0] <= 10) break;
		printf("Некорректный ввод...");
	}
	while(1)
	{
		printf("Математика: ");
		student.marks[1] = check();
		if (student.marks[1] >= 0 && student.marks[1] <= 10) break;
		printf("Некорректный ввод...\n");
	}
	while (1)
	{
		printf("Информатика: ");
		student.marks[2] = check();
		if (student.marks[2] >= 0 && student.marks[2] <= 10) break;
		printf("Некорректный ввод...\n");
	}
	while (1)
	{
		printf("Химия: ");
		student.marks[3] = check();
		if (student.marks[3] >= 0 && student.marks[3] <= 10) break;
		printf("Некорректный ввод...\n");
	}
	student.s_mark = (double)(student.marks[0] + student.marks[1] + student.marks[2] + student.marks[3]) / 4;
	printf("Средний балл: %.2lf", student.s_mark);
	printf("\n");
	Fz = fopen(File_Zap, "ab");
	fwrite(&student, sizeOfStruct, 1, Fz);
	fclose(Fz);
}

void save(Students* st, int num) {
	Fz = fopen(File_Zap, "wb");
	fwrite(st, sizeOfStruct, num, Fz);
	fclose(Fz);
}

void edit(int edit_number) {
	Students* st, newStudent;
	int descriptor, i, kol;
	double len;
	zapisName(newStudent.FIO,sizeof(newStudent.FIO));
	while (1)
	{
		printf("Год рождения: ");
		newStudent.year_birthday = check();
		if (newStudent.year_birthday <= 2005 && newStudent.year_birthday >= 1999) break;
		printf("Некорректная дата...\n");
	}
	printf("Номер группы: ");
	newStudent.num_group = check();
	printf("Введите оценки по предметам:");
	while (1)
	{
		printf("\nФизика: ");
		newStudent.marks[0] = check();
		if (newStudent.marks[0] >= 0 && newStudent.marks[0] <= 10) break;
		printf("Некорректный ввод...");
	}
	while (1)
	{
		printf("Математика: ");
		newStudent.marks[1] = check();
		if (newStudent.marks[1] >= 0 && newStudent.marks[1] <= 10) break;
		printf("Некорректный ввод...\n");
	}
	while (1)
	{
		printf("Информатика: ");
		newStudent.marks[2] = check();
		if (newStudent.marks[2] >= 0 && newStudent.marks[2] <= 10) break;
		printf("Некорректный ввод...\n");
	}
	while (1)
	{
		printf("Химия: ");
		newStudent.marks[3] = check();
		if (newStudent.marks[3] >= 0 && newStudent.marks[3] <= 10) break;
		printf("Некорректный ввод...\n");
	}
	newStudent.s_mark = (newStudent.marks[0] + newStudent.marks[1] + newStudent.marks[2] + newStudent.marks[3]) / 4;
	printf("Средний балл: %lf", newStudent.s_mark);

	Fz = fopen(File_Zap, "rb");
	descriptor = _fileno(Fz);
	len = _filelength(descriptor);
	kol = len / sizeOfStruct;
	st = new Students[kol];
	for (i = 0; i < kol; i++) {
		fread((st + i), sizeOfStruct, 1, Fz);
	}
	fclose(Fz);

	st[edit_number - 1] = newStudent;
	Ft = fopen(File_Rez, "wb");
	for (i = 0; i < kol; i++)
		out(st[i], Ft, i + 1);
	save(st, kol);
	fclose(Ft);
	delete[]st;
	printf("\n\n");
}

void zadanie()
{
	Students* studentsWithGoodInfo;
	int value, i=1;

	int nuzhniGroup;

	printf("Введите интересуемую группу: ");
	scanf_s("%d",&nuzhniGroup);

	Fz = fopen(File_Zap, "rb");
	Ft = fopen(File_Rez, "ab");

	printf("\n ------- Студент из группы %d и отметкой по информатике 9 или 10 ------- ", nuzhniGroup);
	fprintf(Ft, "\n\n ------- Студент из группы %d и отметкой по информатике 9 или 10 ------- ", nuzhniGroup);


	value = _filelength(_fileno(Fz)) / sizeOfStruct;
	studentsWithGoodInfo = new Students[value];

	for (i = 0; i < value; i++) {
		fread((studentsWithGoodInfo+i), sizeOfStruct, 1, Fz);
	}

	for (i = 0; i < value; i++) {
		if (studentsWithGoodInfo[i].marks[2] >=9 && studentsWithGoodInfo[i].num_group==nuzhniGroup)
			out(studentsWithGoodInfo[i], Ft, i+1);
	}

	printf("\n\n");
	fclose(Fz);
	fclose(Ft);
	delete[] studentsWithGoodInfo;
	system("pause");
}