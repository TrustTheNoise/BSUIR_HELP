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
		printf("�� ������ ������ ������ �������� ���:\n");
		printList(*pointView);
		printf("\n");
		printf("1.�������\n2.��������\n3.�������� ��� ���������\n4.�����������\n5.�������������� �������\n6.�������\n0.�����\n���������: ");
		switch(check()) {
		case Create:
			system("cls");
			if(begin) {
				printf("������ ��� ������!!\n");
				system("pause");
				break;
			}
			createList(&begin, &end);
			printf("������ ������!\n");
			system("pause");
			break;
		case Add:
			system("cls");
			exitFromAdd = false;
			while(!exitFromAdd) {
				exitFromAdd = true;
				forward = false;
				printf("���� ��������?\t1.� ������\t2.� �����\n���������:");
				switch(check()) {
				case 1:
					pointAdd = &begin;
					forward = true;
					break;
				case 2:
					pointAdd = &end;
					break;
				default:
					printf("������ �������� ���!!!1!!1");
					exitFromAdd = false;
				}
			}
			printf("������� ������ ��������? ");
			kol = check();
			for(int i = 0; i < kol; i++) {
				*pointAdd = addList(*pointAdd, forward);
			}
			system("pause");
			break;
		case HowView:
			system("cls");
			printf("������ ��������?\t1.� ������\t2.� �����\n���������:");
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
		printf("������������ ����!\n������� �����:");
		rewind(stdin);
	}
	return a;
}


void createList(List** begin, List** end)
{
	List* t = new List;
	printf("������� �������: ");
	t->num = check();
	t->next = t->prev = NULL;
	(*begin) = (*end) = t;
}

List* addList(List* point, bool forward)
{
	List* t = new List;
	printf("������� �������: ");
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
	printf("������� ������� ������� ������ �������: ");
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
		printf("������ �������� ��� � ������!!1!!1");
	}
}

void delNum(List** begin, List** end)
{
	system("cls");
	printf("������� ����� ������� ��� ������� ������ �������: ");
	int num = check(), i = 1;
	for(i; i < num && *begin != nullptr; i++) begin = &(*begin)->next;

	if(i != num) {
		printf("�������� � ����� ������� ��� � ������!!1!!!");
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
	printf("������� ��� ������ �������:\n1.���� ������\n2.������� �� �����\n3.������� �� ������\n");
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
		printf("��� ������ ��������!!!");
	}
}

void indiv(List* p)
{
	if(!p) {
		printf("���� �� ������!!!1!1");
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
		printf("������ �� ������!!1!!1");
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