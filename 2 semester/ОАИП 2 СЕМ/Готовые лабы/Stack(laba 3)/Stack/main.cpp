#include <iostream>
#include <ctime>

struct Stack
{
	double num;
	Stack* next;
};

int check();
bool existStack(Stack*);
Stack* addStack(Stack*, bool);
bool howToAdd();
void view(Stack*);
double outStack(Stack**);
void delKey(Stack**);
void delStack(Stack**);
void delNum(Stack**);
void howDel(Stack**);
void sort(Stack*);
void indiv(Stack*);

int main()
{
	Stack* begin = nullptr;
	system("chcp 1251>nul");
	srand(time(NULL));
	int choise{};
	bool exitFromInterface = false, rand{};
	int kol{};
	enum {Exit, CreateStack, Add, Pop, Sort, Individ, Del};
	while (!exitFromInterface)
	{
		system("cls");
		printf("На данный момент очередь: \n");
		view(begin);
		printf("\n1.Создать\n2.Добавить\n3.Вывести из стека эелемент\n"
			"4.Сортировка\n5.Индивидуальное задание\n6.Удаление\n0.Выйти\nВыбирайте: ");
		switch (check())
		{
		case CreateStack:
			system("cls");
			if (begin != nullptr) {
				printf("Стек уже создан!!!\n");
				system("pause");
				continue;
			}
			begin = addStack(begin, howToAdd());
			break;
		case Add:
			if(!existStack(begin)) 
				continue;
			system("cls");
			
			printf_s("Выберите сколько элементов хотите добавить: ");
			kol = check();
			
			rand = howToAdd();

			for (int i = 0; i < kol; i++) {
				begin = addStack(begin, rand);
			}
			break;
		case Pop:
			if(!existStack(begin)) 
				continue;
			
			printf("Элемент: %lf\n", outStack(&begin));
			system("pause");
			break;
		case Sort:
			if(!existStack(begin))
				continue;
			
			sort(begin);
			break;
		case Individ:
			if(!existStack(begin)) 
				continue;
			
			indiv(begin);
			break;
		case Del:
			if(!existStack(begin)) 
				continue;
			
			howDel(&begin);
			break;
		case Exit:
			exitFromInterface = true;
			break;
		default:
			printf("Такого варианта нет!!!1!!!");
		}
	}
}

int check() {
	int a = 0;
	while ((scanf_s("%d", &a), getchar()) != '\n') {
		printf("Неправильный ввод!\nВведите число:");
		rewind(stdin);
	}
	return a;
}

bool existStack(Stack* p) {
	if(p == nullptr) {
		printf("Стек не создан!!!\n");
		system("pause");
		return false;
	}
	return true;
}

Stack* addStack(Stack* p, bool random) {
	Stack* t = new Stack;
	if (random) {
		t->num = rand()%19-9;
	}else {
		printf("Введите элемент: ");
		t->num = check();
	}
	t->next = p;
	return t;
}

bool howToAdd() {
	while(true) {
		printf("Выберите как создать элемент в очереди:\n1.Рандомно\n2.Ввод с клавиатуры\n");
		switch(check()) {
		case 1:
			return true;
		case 2:
			return false;
		default:
			printf("Нет такого варианта");
		}
	}

}

void view(Stack* p) {
	Stack* t = p;
	while (t != NULL)
	{
		printf("%.1lf\n", t->num);
		t = t->next;
	}
}

double outStack(Stack** p) {
	Stack* t = *p;
	double num = (*p)->num;
	(*p) = (*p)->next;
	delete t;
	return num;
}

void delKey(Stack** p) {
	system("cls");
	printf("Введите какой элемент хотите удалить: ");
	int elem = check();
	bool least_one = false;
	Stack** pcur = p;
	Stack* temp;
	while (*pcur) {
		if ((*pcur)->num == elem) {
			temp = (*pcur);
			(*pcur) = (*pcur)->next;
			least_one = true;
			delete temp;
		}
		else pcur = &(*pcur)->next;
	}
	if (!least_one) {
		printf("Такого элемента нет в списке!!!");
	}
}

void delStack(Stack** p) {
	Stack* t;
	while (*p != nullptr)
	{
		t = *p;
		*p = (*p)->next;
		delete t;
	}
}

void delNum(Stack** p) {
	system("cls");
	printf("Введите номер элемент хотите удалить: ");
	int num = check();
	Stack** pcur = p;
	int i = 1;
	for (i; (i < num) && (*pcur != nullptr); i++) {
		pcur = &(*pcur)->next;
	}
	if (i != num) {
		printf("Нет такого номера!!!((\n");
		return;
	}else {
		Stack* temp = (*pcur);
		(*pcur) = (*pcur)->next;
		delete temp;
	}
}

void howDel(Stack** p) {
	system("cls");
	printf("Введите что хотите удалить:\n1.Весь список\n2.Элемент по ключу\n3.Элемент по номеру\n");
	switch (check()) {
	case 1:
		delStack(p);
		break;
	case 2:
		delKey(p);
		break;
	case 3:
		delNum(p);
		break;
	default:
		printf("Нет такого варианта!!!");
	}
}

void sort(Stack* p)
{
	if (!p->next) {
		return;
	}
	Stack* t = nullptr, * t1;
	do {
		for (t1 = p; t1->next != t; t1 = t1->next)
		{
			if (t1->num > t1->next->num)
			{
				int q;
				q = t1->next->num;
				t1->next->num = t1->num;
				t1->num = q;
			}
		}
		t = t1;
	} while (p->next != t);
}

void indiv(Stack* p)
{
	if (!p) {
		printf("Стек не создан!!!1!1");
		system("pause");
		return;
	}
	double sredArifm{};
	int kolOfNum{};
	Stack* t = p;
	while (p != nullptr)
	{
		sredArifm += p->num;
		kolOfNum++;
		p = p->next;
	}
	sredArifm = sredArifm / kolOfNum;
	t->num = sredArifm;
}
