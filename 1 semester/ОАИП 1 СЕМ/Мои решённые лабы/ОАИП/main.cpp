//
// ���� ����� 1
//

//#include <iostream>
//#include <cmath>
//
//using namespace std;
//
//double check() {
//	double a{};
//	while (!scanf_s("%lf", &a)) {
//		printf("������������ ����\n������� �����:");
//		rewind(stdin);
//	}
//	char temp;
//	while ((temp = getchar()) != '\n') {
//		if ((temp > 57) || (temp < 48)) {
//			printf("������������ ����\n������� �����:");
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
//	printf_s("����� x: ");
//	x = check();
//	
//	printf("����� y: ");
//	y=check();
//	
//	printf("����� z: ");
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
//		printf("������������ ������(������ �� ������ � ���)");
//	}
//	return 0;
//}

// 
// ���� ����� 2
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
//	printf("������� z: ");
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
//	printf("������� a: ");
//	a = check<double>();
//	printf("������� c: ");
//	b=check<double>();
//
//	while (proverka)
//	{
//		printf("�������� ������� f(x):\n1.f(x)=2x\n2.f(x)=x^2\n3.f(x)=x/3\n");
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
//			printf("������ �������� ���!");
//		}
//	}
//
//	printf("���������� y ������������� � ������ ����, ��� ������� f(x) = ");
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
//	printf("� x = %lf \n", x);
//
//	y = (2.5*a*exp(pow(sin(x),3))-4*b*x*x)/(log(fabs(x))+func);
//
//	printf("����� y = %lf", y);
//	
//	return 0;
//}
//
//template<> double check() {
//	double a{};
//	while (!scanf_s("%lf", &a)) {
//		printf("������������ ����\n������� �����:");
//		rewind(stdin);
//	}
//	char temp;
//	while ((temp = getchar()) != '\n') {
//		if ((temp > 57) || (temp < 48)) {
//			printf("������������ ����\n������� �����:");
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
//		printf("������������ ����\n������� �����:");
//		rewind(stdin);
//	}
//	char temp;
//	while ((temp = getchar()) != '\n') {
//		if ((temp > 57) || (temp < 48)) {
//			printf("������������ ����\n������� �����:");
//			rewind(stdin);
//			scanf_s("%d", &a);
//		}
//	}
//	return a;
//}


//
// ���� 3
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
//		printf("�������� ��� ������� ����������: 1)����������� �������� 2)���� ��������\n");
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
//					printf_s("������� a: ");
//					a = check<double>();
//					if (a <= 0)
//					{
//						printf_s("a �� ����� ���� ������ ��� ����� 0\n");
//					}
//					else
//					{
//						proverka = false;
//					}
//				}
//				proverka = true;
//				while (proverka)
//				{
//					printf_s("������� b: ");
//					b = check<double>();
//					if (b <= 0)
//					{
//						printf_s("b �� ����� ���� ������ ���� ����� 0\n");
//					}
//					else
//					{
//						proverka = false;
//					}
//					if (a > b)
//					{
//						printf("a �� ����� ���� ������ b\n");
//					}
//					else
//					{
//						BigProverka = false;
//					}
//				}
//			}
//			while (true)
//			{
//				printf("������� h: ");
//				h = check<double>();
//				if (h <= 0)
//				{
//					printf("h �� ����� ���� ������ ���� ����� 0\n");
//				}
//				else
//				{
//					break;
//				}
//			}
//			while (true)
//			{
//				printf("������� n: ");
//				n = check<int>();
//				if (n <= 0)
//				{
//					printf("n �� ����� ���� ������ ���� ����� 0");
//				}
//				else
//				{
//					break;
//				}
//			}
//			proverkaChoise = false;
//			break;
//		default:
//			printf("������ �������� ���!\n");
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
//		printf("������������ ����\n������� �����:");
//		rewind(stdin);
//	}
//	char temp;
//	while ((temp = getchar()) != '\n') {
//		if ((temp > 57) || (temp < 48)) {
//			printf("������������ ����\n������� �����:");
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
//		printf("������������ ����\n������� �����:");
//		rewind(stdin);
//	}
//	char temp;
//	while ((temp = getchar()) != '\n') {
//		if ((temp > 57) || (temp < 48)) {
//			printf("������������ ����\n������� �����:");
//			rewind(stdin);
//			scanf_s("%d", &a);
//		}
//	}
//	return a;
//}

//
// ���� 4
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
//		printf("������������ ����\n������� �����:");
//		rewind(stdin);
//	}
//	char temp;
//	while ((temp = getchar()) != '\n') {
//		if ((temp > 57) || (temp < 48)) {
//			printf("������������ ����\n������� �����:");
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
//		printf("������������ ����\n������� �����:");
//		rewind(stdin);
//	}
//	char temp;
//	while ((temp = getchar()) != '\n') {
//		if ((temp > 57) || (temp < 48)) {
//			printf("������������ ����\n������� �����:");
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
//		printf("�������� ��� ������� ����������: 1)����������� �������� 2)���� ��������\n");
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
//					printf_s("������� a: ");
//					a = checkDouble();
//					if (a <= 0)
//					{
//						printf_s("a �� ����� ���� ������ ��� ����� 0\n");
//					}
//					else
//					{
//						proverka = false;
//					}
//				}
//				proverka = true;
//				while (proverka)
//				{
//					printf_s("������� b: ");
//					b = checkDouble();
//					if (b <= 0)
//					{
//						printf_s("b �� ����� ���� ������ ���� ����� 0\n");
//					}
//					else
//					{
//						proverka = false;
//					}
//					if (a > b)
//					{
//						printf("a �� ����� ���� ������ b\n");
//					}
//					else
//					{
//						BigProverka = false;
//					}
//				}
//			}
//			while (true)
//			{
//				printf("������� h: ");
//				h = checkDouble();
//				if (h <= 0)
//				{
//					printf("h �� ����� ���� ������ ���� ����� 0\n");
//				}
//				else
//				{
//					break;
//				}
//			}
//			while (true)
//			{
//				printf("������� n: ");
//				n = checkInt();
//				if (n <= 0)
//				{
//					printf("n �� ����� ���� ������ ���� ����� 0");
//				}
//				else
//				{
//					break;
//				}
//			}
//			proverkaChoise = false;
//			break;
//		default:
//			printf("������ �������� ���!\n");
//			break;
//		}
//	}
//	printf("�������� �������: 1)sx 2)yx 3)|yx-sx|\n");
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
//			printf_s("������ �������� ���!1!!\n");
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
// ���� 5
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
//		printf("������������ ����\n������� �����:");
//			rewind(stdin);
//		}
//	char temp;
//	while ((temp = getchar()) != '\n') 
//		{
//			if ((temp > 57) || (temp < 48)) {
//				printf("������������ ����\n������� �����:");
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
//		printf("����� ������ �������(� �������� 1-99): ");
//		n = check();
//		if (n > 0 && n < 100)
//		{
//			proverka = false;
//		}else
//		{
//			printf("������ ������ ���� � �������� 1 - 99\n");
//		}
//	} while (proverka);
//	proverka = true;
//	while (proverka)
//	{
//		printf_s("��� ������ ��������� ������? 1.� ���������� 2.��������� �����\n");
//		choise = check();
//
//		switch (choise)
//		{
//		case 1:
//			proverka = false;
//			for (int i = 0; i < n; i++)
//			{
//				printf_s("������� %d ������� �������: ", i);
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
//			printf("������ �������� ���...\n");
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
//			printf("\n� ������� ��� ��� ����� ���������� ����������� ��������");
//			return 0;
//		}
//	}
//
//	printf_s("\n����������� ��������� ������� ��������: %d", min);
//
//	if(numMin==n-1)
//	{
//		printf("\n����������� ������� �������� ��������� ��������� �������");
//		return 0;
//	}
//
//	for(int i = numMin+1; i < n; i++ )
//	{
//		sum += arr[i];
//	}
//
//	printf_s("\n����� ��������� ������� ����� ������������ �������� �����: %d", sum);
//}

//
// ���� 6
//

//#include <iostream>
//
//int checkForArr(int i, int j)
//{
//	int a{};
//	while (!scanf_s("%d", &a))
//	{
//		printf("������������ ����\n������� ������� arr[%d][%d]:",i,j);
//		rewind(stdin);
//	}
//	char temp;
//	while ((temp = getchar()) != '\n')
//	{
//		if ((temp > 57) || (temp < 48)) {
//			printf("������������ ����\n������� ������� arr[%d][%d]:", i, j);
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
//		printf("������������ ����\n������� �����:");
//			rewind(stdin);
//		}
//	char temp;
//	while ((temp = getchar()) != '\n') 
//		{
//			if ((temp > 57) || (temp < 48)) {
//				printf("������������ ����\n������� �����:");
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
//	printf_s("������� ������� N, M\n");
//	while (proverka)
//	{
//		printf_s("N: ");
//		N = check();
//		if(N<=0)
//		{
//			printf("N �� ����� ���� ������ ��� ����� 0...\n");
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
//			printf("M �� ����� ���� ������ ��� ����� 0...\n");
//		}
//		else
//		{
//			proverka = false;
//		}
//	}
//	if (M <= 2)
//	{
//		printf("��������� ��������������� ������� �� ����� ������������ ��� N ������ ���� ����� 0...");
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
//		printf("��� ��������� ������: 1.� ���������� 2.��������\n");
//		ch = check();
//		switch(ch)
//		{
//		case 1:
//			for (int i = 0; i < N; i++)
//			{
//				for (int j = 0; j < M; j++)
//				{
//					printf_s("������� ������� arr[%d][%d]: ", i, j);
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
//			printf("������ �������� ���...\n");
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
//	printf_s("���������� ��������� �������, � ������� ����� ��������� ������� ������ ���, � ������ � ������: %d", num);
//
//	for (int i = 0; i < N; i++)
//	{
//		delete[] arr[i];
//	}
//	delete[] arr;
//	return 0;
//}


// ���� 7 


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
//		printf("������� ������(���������� ��������� �� ���������� �����): ");
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
//		printf("\n���������� �������� ����������!");
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
//		printf("\n� ����� ������ ������ 1 �����!!!11!\n");
//	}
//	printf("������� ������(���������� ��������� �� ���������� �����): %s", arr);
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
//	printf("��������������� �������(� ���������� �������):\n");
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
//	���� 8
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
		printf("\n1.������� ��� ������������� ������� ����  2.������� ����  3.�����\n���������: ");
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
					printf("��� ����: %s", File_Zap);
					printf("\n1 - �������\t2 - ��������\t3 - ��������\t4 - �������������� �������\t0 - �����\n");
					printf("���������: ");
					choise1 = check();
					switch (choise1)
					{
					case 1:
						system("cls");
						if (_access(File_Zap, 0) == 0) {
							printf("���� ��� ������");
							break;
						}
						create();
						if (!Fz)
						{
							printf("������!");
							return 0;
						}
						proverka = false;
						system("pause");
						break;
					case 2:
						if (!view())
						{
							printf("\n\n���� ����������...\n");
						}
						proverka = false;
						system("pause");
						break;
					case 3:
						system("cls");
						if (!Fz)
						{
							printf("���� �� ������!\n");
							system("pause");
							break;
						}
						proverkaForCase3 = true;
						while (proverkaForCase3)
						{
							printf("\n1.��������\n2.��������\n��� ������ ��������?  ");
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
									printf("\n��������� ������� ����� �������� ���!!1!1\n");
									proverkaForCase3 = false;
									system("pause");
									break;
								}

								printf("\n\n������� ����� ������, ������� ������ ��������:\t");
								proverkaForCase3 = false;
								choiseNum = check();
								rewind(stdin);

								if (choiseNum > kol || choiseNum<1)
								{
									printf("������ �������� ���...");
									system("pause");
									break;
								}

								edit(choiseNum);
								system("pause");
								break;
							default:
								printf("\n������ �������� ���!!!1!1");
							}
						}
						proverka = false;
						break;
					case 4:
						if (!Fz)
						{
							printf("���� �� ������!\n");
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
						printf("������ �������� ���!!\n");
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
				printf_s("\n���� ������� �����!\n");
			}else
			{
				printf_s("\n������ �������� �����...\n");
			}
			system("pause");
			break;
		case 3:
			return 0;
		default:
			printf_s("������ �������� ���...");
		}
	}
}

void zapisFile(char* s, int size)
{
	int i{};
	char x{};
	while (i < size - 1)
	{
		printf_s("�� ������ ������ ������������ �����:\n");
		system("dir *.dat /b");
		printf_s("������� ��� ����� ������� ������ �������: ");
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
		printf("\n���������� �������� ����������!");
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
			printf("���: ");
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
					printf("\n����� ������ ���� 3 �����!!!\n\n");
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
			printf("\n���� ������ ���� 3!!!\n");
			for (int j = 0; j < i; j++)
			{
				s[j] = '\0';
			}
			i = 0;
			system("pause");
			system("cls");
		}else
		{
			printf("���: ");
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
		printf("\n���������� �������� ����������!");
		s[i] = '\0';
		printf_s("\n���� ���: ");
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
		printf("������������ ����\n������� �����:");
		rewind(stdin);
	}
	char temp;
	while ((temp = getchar()) != '\n') {
		if (temp > 57 || temp < 48) {
			printf("������������ ����\n������� �����:");
			rewind(stdin);
			scanf_s("%d", &a);
		}
	}
	return a;
}

void create()
{
	Fz = fopen(File_Zap, "wb");
	printf("\n���� ������!\n");
	fclose(Fz);
}

bool view() {
	Fz = fopen(File_Zap, "rb");
	Ft = fopen(File_Rez, "wb");
	if (!Fz)
		return false;
	Students student;

	printf("\n\t--------------- ���������� ---------------\n");
	fprintf(Ft, "\n\n\n\t---------------  ���������� ---------------\n");


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
	printf("\n%d. %s - %d, ������: %d; ������: %d, ����������: %d, �����������: %d, �����: %d, ������� ����: %1.2lf", i, s.FIO, s.year_birthday, s.num_group, s.marks[0], s.marks[1], s.marks[2], s.marks[3], s.s_mark);
	fprintf(Potochek, "\n%s - %d, ������: %d; ������: %d, ����������: %d, �����������: %d, �����: %d, ������� ����: %1.2lf", s.FIO, s.year_birthday, s.num_group, s.marks[0], s.marks[1], s.marks[2], s.marks[3], s.s_mark);
}

void add()
{
	system("cls");
	Students student;
	zapisName(student.FIO, sizeof(student.FIO));
	while (1)
	{
		printf("\n��� ��������: ");
		student.year_birthday = check();
		if (student.year_birthday <= 2005 && student.year_birthday >= 1999) break;
		printf("������������ ����...\n");
	}
	printf("����� ������: ");
	student.num_group = check();
	printf("������� ������ �� ���������:");
	while (1)
	{
		printf("\n������: ");
		student.marks[0] = check();
		if (student.marks[0] >= 0 && student.marks[0] <= 10) break;
		printf("������������ ����...");
	}
	while(1)
	{
		printf("����������: ");
		student.marks[1] = check();
		if (student.marks[1] >= 0 && student.marks[1] <= 10) break;
		printf("������������ ����...\n");
	}
	while (1)
	{
		printf("�����������: ");
		student.marks[2] = check();
		if (student.marks[2] >= 0 && student.marks[2] <= 10) break;
		printf("������������ ����...\n");
	}
	while (1)
	{
		printf("�����: ");
		student.marks[3] = check();
		if (student.marks[3] >= 0 && student.marks[3] <= 10) break;
		printf("������������ ����...\n");
	}
	student.s_mark = (double)(student.marks[0] + student.marks[1] + student.marks[2] + student.marks[3]) / 4;
	printf("������� ����: %.2lf", student.s_mark);
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
		printf("��� ��������: ");
		newStudent.year_birthday = check();
		if (newStudent.year_birthday <= 2005 && newStudent.year_birthday >= 1999) break;
		printf("������������ ����...\n");
	}
	printf("����� ������: ");
	newStudent.num_group = check();
	printf("������� ������ �� ���������:");
	while (1)
	{
		printf("\n������: ");
		newStudent.marks[0] = check();
		if (newStudent.marks[0] >= 0 && newStudent.marks[0] <= 10) break;
		printf("������������ ����...");
	}
	while (1)
	{
		printf("����������: ");
		newStudent.marks[1] = check();
		if (newStudent.marks[1] >= 0 && newStudent.marks[1] <= 10) break;
		printf("������������ ����...\n");
	}
	while (1)
	{
		printf("�����������: ");
		newStudent.marks[2] = check();
		if (newStudent.marks[2] >= 0 && newStudent.marks[2] <= 10) break;
		printf("������������ ����...\n");
	}
	while (1)
	{
		printf("�����: ");
		newStudent.marks[3] = check();
		if (newStudent.marks[3] >= 0 && newStudent.marks[3] <= 10) break;
		printf("������������ ����...\n");
	}
	newStudent.s_mark = (newStudent.marks[0] + newStudent.marks[1] + newStudent.marks[2] + newStudent.marks[3]) / 4;
	printf("������� ����: %lf", newStudent.s_mark);

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

	printf("������� ������������ ������: ");
	scanf_s("%d",&nuzhniGroup);

	Fz = fopen(File_Zap, "rb");
	Ft = fopen(File_Rez, "ab");

	printf("\n ------- ������� �� ������ %d � �������� �� ����������� 9 ��� 10 ------- ", nuzhniGroup);
	fprintf(Ft, "\n\n ------- ������� �� ������ %d � �������� �� ����������� 9 ��� 10 ------- ", nuzhniGroup);


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