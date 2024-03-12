#include <iostream>

struct List
{
	double num;
	List* prev, * next;
};

int check();
void createList(List**, List**);
List* addList(List*, bool);
void printList(List*);
void sortList(List*);
void delKey(List**, List**);
void delList(List**);
void howDelList(List**, List**);
void indiv(List*);

int main()
{
	system("chcp 1251>nul");
	bool proverka = true;
	bool exitFromAdd = false, forward{};
	int kol = 0;
	enum {Exit, Create, Add, HowView, Sort, Individ, Del};
	List* begin = nullptr, * end = nullptr;
	List** pointView = &begin, **pointAdd = &begin;
	while(proverka) {
		system("cls");
		printf("На данный момент список выглядит так:\n");
		printList(*pointView);
		printf("\n");
		printf("1.Создать\n2.Добавить\n3.Изменить вид просмотра\n4.Сортировать\n5.Индивидуальное задание\n6.Удалить\n0.Выйти\nВыбирайте: ");
		switch(check()) {
		case Create:
			system("cls");
			if(begin) {
				printf("Список уже создан!!\n");
				system("pause");
				break;
			}
			createList(&begin, &end);
			printf("Список создан!\n");
			system("pause");
			break;
		case Add:
			system("cls");
			exitFromAdd = false;
			while(!exitFromAdd) {
				exitFromAdd = true;
				forward = false;
				printf("Куда добавить?\t1.В начало\t2.В конец\nВыбирайте:");
				switch(check()) {
				case 1:
					pointAdd = &begin;
					forward = true;
					break;
				case 2:
					pointAdd = &end;
					break;
				default:
					printf("Такого варианта нет!!!1!!1");
					exitFromAdd = false;
				}
			}
			printf("Сколько хотите добавить? ");
			kol = check();
			for(int i = 0; i < kol; i++) {
				*pointAdd = addList(*pointAdd, forward);
			}
			system("pause");
			break;
		case HowView:
			system("cls");
			printf("Откуда смотреть?\t1.С начала\t2.С конца\nВыбирайте:");
			switch(check()) {
			case 1:
				pointView = &begin;
				break;
			case 2:
				pointView = &end;
				break;
			}
			system("pause");
			break;
		case Sort:
			sortList(begin);
			break;
		case Individ:
			indiv(begin);
			break;
		case Del:
			howDelList(&begin, &end);
			break;
		case Exit:
			proverka = false;
			break;
		}
	}
}

int check()
{
	int a = 0;
	while((scanf_s("%d", &a), getchar()) != '\n') {
		printf("Неправильный ввод!\nВведите число:");
		rewind(stdin);
	}
	return a;
}


void createList(List** begin, List** end)
{
	List* t = new List;
	printf("Введите элемент: ");
	t->num = check();
	t->next = t->prev = NULL;
	(*begin) = (*end) = t;
}

List* addList(List* point, bool forward)
{
	List* t = new List;
	printf("Введите элемент: ");
	t->num = check();
	if(forward) {
		t->prev = NULL;
		t->next = point;
		point->prev = t;
		point = t;
	}else {
		t->next = NULL;
		t->prev = point;
		point->next = t;
		point = t; 
	}
	point = t;
	return point;
}

void printList(List* point)
{
	if(point == nullptr)
		return;
	List* t = point;
	if(point->prev == nullptr) {
		while(t != nullptr) {
			printf("%.1lf\n", t->num);
			t = t->next;
		}
	}
	else {
		while(t != NULL) {
			printf("%.1lf\n", t->num);
			t = t->prev;
		}
	}
}

void delList(List** p)
{
	List* t;
	while(*p != nullptr) {
		t = *p;
		*p = (*p)->next;
		delete t;
	}
}

void delKey(List** begin, List** end)
{
	system("cls");
	printf("Введите элемент который хотите удалить: ");
	int elem = check();
	bool least_one = false;
	List* temp;

	while(*begin) {
		if((*begin)->num == elem) {
			temp = (*begin);
			if((*begin)->next == nullptr) {
				begin = &(*begin)->prev;
				(*begin)->next = nullptr;
				*end = *begin;
				least_one = true;
				delete temp;
				break;
			}
			*begin = (*begin)->next;
			(*begin)->prev = (*begin)->prev->prev;
			least_one = true;
			delete temp;
			continue;
		}
		else begin = &(*begin)->next;
	}

	if(!least_one) {
		printf("Такого элемента нет в списке!!1!!1");
	}
}

void delNum(List** begin, List** end)
{
	system("cls");
	printf("Введите номер элемент под которым хотите удалить: ");
	int num = check(), i = 1;
	for(i; i < num && *begin != nullptr; i++) begin = &(*begin)->next;

	if(i != num) {
		printf("Элемента с таким номером нет в списке!!1!!!");
		system("pause");
		return;
	}

	List* temp = *begin;

	if((*begin)->next == nullptr) {
		begin = &(*begin)->prev;
		(*begin)->next = nullptr;
		*end = *begin;
		delete temp;
		return;
	}
	*begin = (*begin)->next;
	(*begin)->prev = (*begin)->prev->prev;
	delete temp;
}

void howDelList(List** begin, List** end)
{
	system("cls");
	printf("Введите что хотите удалить:\n1.Весь список\n2.Элемент по ключу\n3.Элемент по номеру\n");
	switch(check()) {
	case 1:
		delList(begin);
		break;
	case 2:
		delKey(begin, end);
		break;
	case 3:
		delNum(begin, end);
	default:
		printf("Нет такого варианта!!!");
	}
}

void indiv(List* p)
{
	if(!p) {
		printf("Стек не создан!!!1!1");
		system("pause");
		return;
	}
	double sredArifm{};
	int kolOfNum{};
	List* t = p;
	while(p != nullptr) {
		sredArifm += p->num;
		kolOfNum++;
		p = p->next;
	}
	sredArifm = sredArifm / kolOfNum;
	t->num = sredArifm;
}

void sortList(List* p)
{
	if(!p->next) {
		printf("Список не создан!!1!!1");
		return;
	}
	List* t = nullptr, * t1;
	do {
		for(t1 = p; t1->next != t; t1 = t1->next) {
			if(t1->num > t1->next->num) {
				int q;
				q = t1->next->num;
				t1->next->num = t1->num;
				t1->num = q;
			}
		}
		t = t1;
	} while(p->next != t);
}