#include <iostream>

struct Branch
{
	char FIO[30];
	int numOfPass;
	Branch* LeftBranch; 
	Branch* RightBranch;
	int height;
};

int check();
void View_Tree(Branch*, int level = 1);
void fixheight(Branch*);
Branch* rotateleft(Branch*);
Branch* rotateright(Branch*);
int bfactor(Branch*);
Branch* balance(Branch*);
Branch* find_balance(Branch* p);
Branch* Add(char* aFIO, int aNumOfPass, Branch* aBranch);
void pr_obh(Branch*);
void Find(int, Branch*);
void obr_obh(Branch*);
void Indiv(Branch* aBranch, char a, int& kol);
void vozrast_obh(Branch*);
void afterDelFix(Branch*);
Branch* delElem(Branch*, int);
Branch* delTree(Branch*);

int main()
{
	system("chcp 1251>nul");
	Branch* Root = 0;
	bool exitDisplay = false;
	int vremPass;
	char a;
	char vremFIO[30];

	int kol;
	while (true)
	{
		system("cls");
		printf("на данный момент дерево выглядит так :\n");
		enum {Exit, AddElem, SearchKey, Display, Balance, Individ, Del};
		View_Tree(Root);
		printf("\n");
		printf("1.Добавить элемент\n2.Найти по номеру паспорта\n3.Вывести ифнормацию\n4.Балансировка\n5.Индивидуальное задание\n6.Удалить\n0.Выйти\n");
		switch (check())
		{
		case AddElem:
			system("cls");
			printf("Фио: ");
			rewind(stdin);
			gets_s(vremFIO);
			printf("Номер паспорта: ");
			vremPass=check();
			Root=Add(vremFIO,vremPass, Root);
			break;
		case SearchKey:
			system("cls");
			int KeyPass;
			printf("Введите искомый номер паспорта: ");
			scanf_s("%d", &KeyPass);
			Find(KeyPass, Root);
			system("pause");
			break;
		case Display:
			system("cls");
			printf("Как вывести информацию?\n1.Прямым образом\n2.Обратным образом\n3.По возрастанию Номера паспорта\n");
			while(!exitDisplay) {
				exitDisplay = true;
				switch (check())
				{
				case 1:
					pr_obh(Root);
					system("pause");
					break;
				case 2:
					obr_obh(Root);
					system("pause");
					break;
				case 3:
					vozrast_obh(Root);
					system("pause");
					break;
				default:
					printf("Такого варинта нет!!1!!!");
					exitDisplay = false;
					break;
				}
			}
			break;
		case 4:
			Root = find_balance(Root);
			fixheight(Root);
			break;
		case 5:
			system("cls");
			kol = 0;
			printf("Введите с какого символа должна начинаться запись: ");
			scanf_s("%c", &a);
			Indiv(Root, a, kol);
			printf("Количество: %d\n",  kol);
			system("pause");
			break;
		case 6:
			system("cls");
			printf("Введите что хотите удалить:\n1.Всё дерево\n2.Элемент по паспорту\n");
			switch (check())
			{
			case 1:
				Root = delTree(Root);
				break;
			case 2:
				printf("Введите номер паспорта, кого хотите удалить: ");
				vremPass = check();
				Root = delElem(Root, vremPass);
			default:
				break;
			}
			break;
		case 0:
			return 0;
		}
	}
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

void View_Tree(Branch* aBranch, int level) {
	if (!aBranch)return;
	level += 2;
	View_Tree(aBranch->RightBranch, level);
	for (int i = 2; i < level; ++i) printf(" ");
	printf("%d\n", aBranch->numOfPass);
	View_Tree(aBranch->LeftBranch, level);
}

int height(Branch* aBranch) {
	if (aBranch) return aBranch->height;
	else return 0;
}

int bfactor(Branch* aBranch)
{
	return height(aBranch->RightBranch) - height(aBranch->LeftBranch);
}

void fixheight(Branch* aBranch)
{
	int hl = height(aBranch->LeftBranch);
	int hr = height(aBranch->RightBranch);
	if (hl > hr) {
		aBranch->height = hl + 1;
	}
	else {
		aBranch->height = hr + 1;
	}
}

Branch* rotateleft(Branch* aBranch)
{
	Branch* q = aBranch->RightBranch;
	aBranch->RightBranch = q->LeftBranch;
	q->LeftBranch = aBranch;
	fixheight(aBranch);
	fixheight(q);
	return q;
}

Branch* rotateright(Branch* aBranch)
{
	Branch* q = aBranch->LeftBranch;
	aBranch->LeftBranch = q->RightBranch;
	q->RightBranch = aBranch;
	fixheight(aBranch);
	fixheight(q);
	return q;
}


Branch* balance(Branch* aBranch)
{
	if (!aBranch) {
		return aBranch;
	}
	int bf = height(aBranch->RightBranch) - height(aBranch->LeftBranch);
	if (bf >= 2)
	{
		if (height(aBranch->RightBranch->RightBranch) - height(aBranch->RightBranch->LeftBranch) < 0)
			aBranch->RightBranch = rotateright(aBranch->RightBranch);
		return rotateleft(aBranch);
	}
	if (bf <= -2)
	{
		if (height(aBranch->LeftBranch->RightBranch) - height(aBranch->LeftBranch->LeftBranch) > 0)
			aBranch->LeftBranch = rotateleft(aBranch->LeftBranch);
		return rotateright(aBranch);
	}
	return aBranch;
}

Branch* find_balance(Branch* aBranch) 
{
	if (aBranch == nullptr)    return nullptr;
	int bf = height(aBranch->RightBranch) - height(aBranch->LeftBranch);
	while (bf >= 2 || bf <= -2) {
		aBranch = balance(aBranch);
		bf = height(aBranch->RightBranch) - height(aBranch->LeftBranch);
	}
	return aBranch;
}

Branch* Add(char* aFIO, int aNumOfPass, Branch* aBranch)
{
	if (!aBranch)
	{
		aBranch = new Branch;
		int i;
		for(i=0;aFIO[i];i++)
		{
			aBranch->FIO[i] = aFIO[i];
		}
		aBranch->FIO[i] = '\0';
		aBranch->numOfPass = aNumOfPass;
		aBranch->height = 1;
		aBranch->LeftBranch = NULL;
		aBranch->RightBranch = NULL;
		return aBranch;
	}
	if (aBranch->numOfPass == aNumOfPass) return aBranch;
	if (aBranch->numOfPass > aNumOfPass)
	{
		aBranch->LeftBranch = Add(aFIO, aNumOfPass, aBranch->LeftBranch);
	}
	else
	{ 
		aBranch->RightBranch = Add(aFIO, aNumOfPass, aBranch->RightBranch);
	}
	fixheight(aBranch);
	return aBranch;
}


void pr_obh(Branch* aBranch)
{
	if (aBranch == NULL)    return;   

	printf("ФИО: %s | Номер паспорта: %d\n", aBranch->FIO, aBranch->numOfPass);
	pr_obh(aBranch->LeftBranch); 
	pr_obh(aBranch->RightBranch);
}

void obr_obh(Branch* aBranch)
{
	if(aBranch != NULL)
	{
		obr_obh(aBranch->LeftBranch);  
		obr_obh(aBranch->RightBranch);
		printf("Фио: %s | Номер паспорта: %d\n", aBranch->FIO, aBranch->numOfPass);
	}
}

void vozrast_obh(Branch* aBranch)
{
	if (aBranch != NULL)
	{
		vozrast_obh(aBranch->LeftBranch);
		printf("Фио: %s | Номер паспорта: %d\n", aBranch->FIO, aBranch->numOfPass);
		vozrast_obh(aBranch->RightBranch);
	}
}

void Find(int Key, Branch* aBranch)
{
	if (!aBranch)
	{
		return;
	}
	if(aBranch->numOfPass==Key)
	{ 
		printf("ФИО: %s | Номер паспорта: %d\n", aBranch->FIO, aBranch->numOfPass);
		return;
	}
	if (Key < aBranch->numOfPass)
		Find(Key, aBranch->LeftBranch);
	else
		Find(Key, aBranch->RightBranch);
}

void Indiv(Branch* aBranch, char a, int& kol)
{
	if (!aBranch)
	{
		return;
	}
	if (aBranch->FIO[0] == a)
	{
		kol++;
		if(aBranch->LeftBranch!=NULL)
		{
			Indiv(aBranch->LeftBranch, a, kol);
		}
		if(aBranch->RightBranch!=NULL)
		{
			Indiv(aBranch->RightBranch, a, kol);
		}
		return;
	}
	Indiv(aBranch->LeftBranch, a, kol);
	Indiv(aBranch->RightBranch, a, kol);
}

void afterDelFix(Branch* aBranch) {
	if (aBranch->RightBranch == nullptr) {
		fixheight(aBranch);
		return;
	}
	afterDelFix(aBranch->RightBranch);
	fixheight(aBranch);
}

Branch* delElem(Branch* aBranch, int key) 
{
	Branch* del = aBranch, * prev = nullptr, * swap = nullptr, * preSwap = nullptr, * save = nullptr;
	bool left_need = false, first = false, fixneed = false;

	if (aBranch->numOfPass == key) first = true;

	if (aBranch->LeftBranch == nullptr && aBranch->RightBranch == nullptr) 
	{
		aBranch = nullptr;
		return aBranch;
	}

	
	while (del != nullptr && del->numOfPass != key) 
	{
		if (del->numOfPass > key) { prev = del; left_need = true; del = del->LeftBranch; }
		else { prev = del; left_need = false; del = del->RightBranch; }
	}

	if (del == NULL) {
		printf("Такого элемента нет в дереве!!!\n");
		system("pause");
		return aBranch;
	}

	if (del->LeftBranch == nullptr) swap = del->RightBranch;
	else if (del->RightBranch == nullptr) swap = del->LeftBranch;
	
	else {
		fixneed = true;
		swap = del->LeftBranch;
		while (swap->RightBranch)
		{
			preSwap = swap;
			swap = swap->RightBranch;
		}
		
		if (preSwap) preSwap->RightBranch = swap->LeftBranch;

		if (del->LeftBranch != swap) swap->LeftBranch = del->LeftBranch;

		swap->RightBranch = del->RightBranch;
	}
	if (first){
		aBranch = swap;
	}
	else {
		if (left_need) prev->LeftBranch = swap;
		
		else prev->RightBranch = swap;
	}
	delete del;
	if(fixneed) afterDelFix(aBranch->LeftBranch);
	fixheight(aBranch);
	return aBranch;
}

Branch* delTree(Branch* aBranch)
{
	if (aBranch)
	{
		delTree(aBranch->LeftBranch);
		delTree(aBranch->RightBranch);
		delete aBranch;
	}
	return nullptr;
}