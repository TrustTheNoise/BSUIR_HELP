#include<iostream>
#include <conio.h>

template<class T>
struct Stack
{
	T elem;
	Stack* next;
};


int Prior(char);

template<class T>
Stack<T>* InStack(Stack<T>*, T);
template<class T>
void Del_All(Stack<T>**);
template<class T>
T OutStack(Stack<T>**);

double Result(char*, bool);
void zapis(char*, int);
double checkDouble();
int checkInt();

void main()
{
	system("chcp 1251>0");
	Stack<char>* elems = nullptr;
	char In[81] = "a-(b/c*(d+e))", Out[81] = " ";
	bool pattern = true;
	printf_s("Какие данные записать:\n1.Свои\n2.Шаблон\n");
	switch (checkInt())
	{
	case 1:
		zapis(In, 81);
		pattern = false;
		break;
	case 2:
		break;
	}
	int out_len = 0;
	for (int i = 0; In[i]; i++)
	{
		switch (In[i])
		{
		case '(':
			elems = InStack(elems, In[i]);
			break;
		case ')':
			while (elems->elem != '(')
			{
				Out[out_len++] = OutStack(&elems);
			}
			OutStack(&elems);
			break;
		case '+': case '-': case '*': case '/':
			while (elems != nullptr && Prior(elems->elem) >= Prior(In[i]))
			{
				Out[out_len++] = OutStack(&elems);
			}
			elems = InStack(elems, In[i]);
			break;
		}
		if ((In[i] >= 'a' && In[i] <= 'z') || (In[i] >= '0' && In[i] <= '9'))
		{
			Out[out_len++] = In[i];
		}
	}
	while (elems != nullptr)
	{
		Out[out_len++] = OutStack(&elems);
	}
	delete elems;
	Out[out_len] = '\0';
	printf("Polish = %s\n", Out);
	printf("Result = %.2lf", Result(Out, pattern));
}

template<class T>
void Del_All(Stack<T>** p)
{
	Stack<T>* t;
	while(*p != nullptr) {
		t = *p;
		*p = (*p)->next;
		delete t;
	}
}

template<class T>
Stack<T>* InStack(Stack<T>* st, T ch)
{
	Stack<T>* temp = new Stack<T>;
	temp->elem = ch;
	temp->next = st;
	return temp;
}

template<class T>
T OutStack(Stack<T>** st)
{
	T ch = (*st)->elem;
	Stack<T>* to_del = *st;
	*st = (*st)->next;
	delete to_del;
	return ch;
}

int  Prior(char ch)
{
	switch (ch)
	{
	case '(': return 0;

	case '+': case '-': return 2;

	case '*': case '/': return 3;
	}
	return 0;
}

double Result(char* str, bool pattern)
{
	Stack<double>* rezults = nullptr;
	char ssR = 'z' + 1;
	double op1, op2, res{}, values[26]{};
	bool valueState[26]{};
	if(pattern) {
		values[int('a' - 'a')] = 5.6;
		printf("a = %.1lf\n", 5.6);
		values[int('b' - 'a')] = 3.2;
		printf("b = %.1lf\n", 3.2);
		values[int('c' - 'a')] = 0.9;
		printf("c = %.1lf\n", 0.9);
		values[int('d' - 'a')] = 1.7;
		printf("d = %.1lf\n", 1.7);
		values[int('e' - 'a')] = 4.8;
		printf("e = %.1lf\n", 4.8);
	}else {
		for (int i = 0, j = 0; str[i]; ++i) {
			if (str[i] >= 'a' && str[i] <= 'z') {
				if(!valueState[int(str[i] - 'a')]) {
					printf("%c = ", str[i]);
					values[int(str[i] - 'a')] = checkDouble();
					valueState[int(str[i] - 'a')] = true;
				}
			}
		}
	}


	for (int i = 0, j = 0; str[i] != '\0'; ++i) {

		if (str[i] >= 'a' && str[i] <= 'z') 
			rezults = InStack(rezults, values[int(str[i] - 'a')]);
		else if (str[i] >= '0' && str[i] <= '9') rezults = InStack(rezults, double(str[i] - '0'));
		else {
			op2 = OutStack(&rezults);
			op1 = OutStack(&rezults);
			switch (str[i])
			{
			case '+':
				res = op1 + op2;
				break;
			case '-':
				res = op1 - op2;
				break;
			case '*':
				res = op1 * op2;
				break;
			case '/':
				if(op2 == 0) {
					printf("Деление на 0!111!1\n");
					return 0;
				}
				res = op1 / op2;
			}
			rezults = InStack(rezults, res);
			ssR++;
		}
	}
	Del_All(&rezults);
	return res;
}

void zapis(char* s, int size)
{
	int i{};
	char x{};
	bool brace=false;
	while (i < size - 1)
	{
		printf_s("Введите математическую формулу которую нужно решить: ");
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
		if ((x >= 'a' && x <= 'z') || x == '+' || x == '/' || x == '*' || x == '-' || (x>='0' && x<='9'))
		{
			s[i] = x;
			i++;
		}
		if(x == '(') {
			brace = true;
			s[i] = x;
			i++;
		}
		if(x == ')' && brace) {
			s[i] = x;
			i++;
		}
		if (x == '\r')
		{
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
		rewind(stdin);
		return;
	}
	s[i] = '\0';
}

double checkDouble() {
	double a{};
	while (!scanf_s("%lf", &a)) {
		printf("Неправильный ввод\nВведите число:");
		rewind(stdin);
	}
	char temp;
	while ((temp = getchar()) != '\n') {
		if (temp > 57 || temp < 48) {
			printf("Неправильный ввод\nВведите число:");
			rewind(stdin);
			scanf_s("%lf", &a);
		}
	}
	return a;
}

int checkInt() {
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