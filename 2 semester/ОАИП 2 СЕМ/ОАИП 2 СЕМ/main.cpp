//
// лаба 1
//

//#include <iostream>
//
//int check();
//double RecY(int);
//double Y(int);
//
//int main()
//{
//	system("chcp 1251>nul");
//	int n;
//	printf("Введите n: ");
//	n = check();
//	printf("Рекурсивная функция: %lf \nОбычная функция: %lf", RecY(n), Y(n));
//}
//
//int check() {
//	int a = 0;
//	while ((scanf_s("%d", &a), getchar()) != '\n') {
//		printf("Неправильный ввод!\nВведите число:");
//		rewind(stdin);
//	}
//	return a;
//}
//
//double RecY(int n)
//{
//	if(n==0)
//	{
//		return 1.0/2;
//	}
//	return 1 / (n + RecY(n - 1));
//}
//
//double Y(int n)
//{
//	double Y{1.0/2};
//	int n1{1};
//	while (n1 != n+1)
//	{
//		Y = 1 / (n1++ + Y);
//	}
//	return Y;
//}

//
// лаба 3
//

//#include <iostream>
//#include <ctime>
//
//struct Stack
//{
//	double num;
//	Stack* next;
//} *begin;
//
//int check();
//Stack* InStack(Stack*, bool);
//void View(Stack*);
//Stack* OutStack(Stack*, int*);
//void Del_Elem(Stack**);
//void Del_All(Stack**);
//void Del_Num(Stack**);
//void Del(Stack**);
//void Sort(Stack*);
//void Invdiv(Stack*);
//
//int main()
//{
//	system("chcp 1251>nul");
//	srand(time(NULL));
//	int choise{};
//	bool proverka = true;
//	int kol{};
//	while (proverka)
//	{
//		system("cls");
//		printf("На данный момент очередь: \n");
//		View(begin);
//		printf("\n1.Создать\n2.Добавить\n3.Сортировка\n4.Индивидуальное задание\n5.Удаление\n0.Выйти\nВыбирайте: ");
//		switch (check())
//		{
//		case 1:
//			system("cls");
//			if (begin != nullptr) {
//				printf("Очередь уже создана!!!\n");
//				system("pause");
//				continue;
//			}
//
//			printf("Выберите как создать элемент в очереди:\n1.Рандомно\n2.Ввод с клавиатуры\n");
//
//			switch (check()) {
//			case 1:
//				begin = InStack(begin, true);
//				break;
//			case 2:
//				begin = InStack(begin, false);
//				break;
//			default:
//				continue;
//			}
//			break;
//		case 2:
//			system("cls");
//			kol = 0;
//			printf_s("Выберите сколько элементов хотите добавить: ");
//			kol = check();
//			printf("Выберите как создать элемент в очереди:\n1.Рандомно\n2.Ввод с клавиатуры\n");
//			bool rand;
//			switch (check()) {
//			case 1:
//				rand = true;
//				break;
//			case 2:
//				rand = false;
//				break;
//			default:
//				continue;
//			}
//
//			for (int i = 0; i < kol; i++) {
//				begin = InStack(begin, rand);
//			}
//			break;
//		case 3:
//			if (begin == nullptr) {
//				printf("Очередь не создана!!!\n");
//				system("pause");
//				continue;
//			}
//			Sort(begin);
//			break;
//		case 4:
//			if (begin == nullptr) {
//				printf("Очередь не создана!!!\n");
//				system("pause");
//				continue;
//			}
//			Invdiv(begin);
//			break;
//		case 5:
//			if (begin == nullptr) {
//				printf("Очередь не создана!!!\n");
//				system("pause");
//				continue;
//			}
//			Del(&begin);
//			break;
//		case 0:
//			proverka = false;
//			break;
//		default:
//			printf("Такого варианта нет!!!1!!!");
//		}
//	}
//}
//
//int check() {
//	int a = 0;
//	while ((scanf_s("%d", &a), getchar()) != '\n') {
//		printf("Неправильный ввод!\nВведите число:");
//		rewind(stdin);
//	}
//	return a;
//}
//
//Stack* InStack(Stack* p, bool random) {
//	Stack* t = new Stack;
//	if (random) {
//		t->num = rand()%10;
//	}else {
//		printf("Введите элемент: ");
//		t->num = check();
//	}
//	t->next = p;
//	return t;
//}
//
//void View(Stack* p) {
//	Stack* t = p;
//	while (t != NULL)
//	{
//		printf("%.1lf\n", t->num);
//		t = t->next;
//	}
//}
//
//Stack* OutStack(Stack* p, int* out) {
//	Stack* t = p;
//	*out = p->num;
//	p = p->next;
//	delete t;
//	return p;
//}
//
//void Del_Elem(Stack** p) {
//	system("cls");
//	printf("Введите какой элемент хотите удалить: ");
//	int elem = check();
//	bool least_one = false;
//	Stack** pcur = p;
//	Stack* temp;
//	while (*pcur) {
//		if ((*pcur)->num == elem) {
//			temp = (*pcur);
//			(*pcur) = (*pcur)->next;
//			least_one = true;
//			delete temp;
//		}
//		else pcur = &(*pcur)->next;
//	}
//	if (!least_one) {
//		printf("Такого элемента нет в списке!!!");
//	}
//}
//
//void Del_All(Stack** p) {
//	Stack* t;
//	while (*p != nullptr)
//	{
//		t = *p;
//		*p = (*p)->next;
//		delete t;
//	}
//}
//
//void Del_Num(Stack** p) {
//	system("cls");
//	printf("Введите номер элемент хотите удалить: ");
//	int num = check();
//	Stack** pcur = p;
//	Stack* temp;
//	int i = 1;
//	for (i; (i < num) && ((*pcur) = nullptr); i++) {
//		pcur = &(*pcur)->next;
//	}
//	if (i != num) {
//		printf("Нет такого номера!!!((\n");
//		return;
//	}else {
//		temp = (*pcur);
//		(*pcur) = (*pcur)->next;
//		delete temp;
//	}
//}
//
//void Del(Stack** p) {
//	system("cls");
//	printf("Введите что хотите удалить:\n1.Весь список\n2.Элемент\n3.Элемент по номеру\n");
//	switch (check()) {
//	case 1:
//		Del_All(p);
//		break;
//	case 2:
//		Del_Elem(p);
//		break;
//	case 3:
//		Del_Num(p);
//		break;
//	default:
//		printf("Нет такого варианта!!!");
//	}
//}
//
//void Sort(Stack* p)
//{
//	if (!p->next) {
//		return;
//	}
//	Stack* t = nullptr, * t1;
//	do {
//		for (t1 = p; t1->next != t; t1 = t1->next)
//		{
//			if (t1->num > t1->next->num)
//			{
//				int q;
//				q = t1->next->num;
//				t1->next->num = t1->num;
//				t1->num = q;
//			}
//		}
//		t = t1;
//	} while (p->next != t);
//}
//
//void Invdiv(Stack* p)
//{
//	double sredArifm{};
//	int kolOfNum{};
//	Stack* t = p;
//	while (p != nullptr)
//	{
//		sredArifm += p->num;
//		kolOfNum++;
//		p = p->next;
//	}
//	sredArifm = sredArifm / kolOfNum;
//	t->num = sredArifm;
//}


//
// лаба 4
//

//#include <iostream>
//
//struct Spis
//{
//	int num;
//	Spis* prev, * next;
//};
//
//int check();
//void CreateSpis(Spis**, Spis**);
//Spis* InSpisBegin(Spis*);
//Spis* InSpisEnd(Spis*);
//void View(Spis*, Spis*, bool);
//void Sort(Spis*);
//void Del_All(Spis**);
//void Del_Elem(Spis**);
//void Del(Spis**);
//
//int main()
//{
//	system("chcp 1251>nul");
//	bool proverka = true;
//	bool is_end = false;
//	int kol=0;
//	Spis *begin=nullptr, * end=nullptr;
//	while (proverka)
//	{
//		system("cls");
//		printf("1.Создать\n2.Добавить\n3.Просмотреть\n4.Удалить\n0.Выйти\nВыбирайте: ");
//		switch (check())
//		{
//		case 1:
//			system("cls");
//			if (begin) {
//				printf("Список уже создан!!\n");
//				system("pause");
//			}
//			CreateSpis(&begin, &end);
//			printf("Список создан!\n");
//			system("pause");
//			break;
//		case 2:
//			system("cls");
//			printf("Куда добавить?\t1.В начало\t2.В конец\nВыбирайте:");
//			switch (check())
//			{
//			case 1:
//				is_end = false;
//				break;
//			case 2:
//				is_end = true;
//				break;
//			default:
//				continue;
//			}
//			printf("Сколько хотите добавить? ");
//			kol = check();
//			if (is_end){
//				for (int i = 0; i < kol; i++) {
//					end = InSpisEnd(end);
//				}
//			}else {
//				for (int i = 0; i < kol; i++) {
//					begin = InSpisBegin(begin);
//				}
//			}
//			system("pause");
//			break;
//		case 3:
//			system("cls");
//			printf("Откуда смотреть?\t1.С начала\t2.С конца\nВыбирайте:");
//			switch (check())
//			{
//			case 1:
//				View(begin,end,true);
//				break;
//			case 2:
//				View(begin,end,false);
//				break;
//			}
//			system("pause");
//			break;
//		case 4:
//			Del(&begin);
//			break;
//		case 0:
//			proverka = false;
//			break;
//		}
//	}
//}
//
//int check() {
//	int a = 0;
//	while ((scanf_s("%d", &a), getchar()) != '\n') {
//		printf("Неправильный ввод!\nВведите число:");
//		rewind(stdin);
//	}
//	return a;
//}
//
//void CreateSpis(Spis** begin, Spis** end)
//{
//	Spis* t = new Spis;
//	printf("Введите элемент: ");
//	t->num = check();
//	t->next = t->prev = NULL;
//	(*begin) = (*end) = t;
//}
//
//Spis* InSpisBegin(Spis* begin)
//{
//	Spis* t = new Spis;
//	printf("Введите элемент: ");
//	t->num = check();
//	t->prev = NULL;
//	t->next = begin;
//	begin->prev = t;
//	begin = t;
//	return begin;
//}
//
//Spis* InSpisEnd(Spis* end)
//{
//	Spis* t = new Spis;
//	printf("Введите элемент: ");
//	t->num = check();
//	t->next = NULL;
//	t->prev = end;
//	end->next = t;
//	end = t; 
//	return end;
//}
//
//void Sort(Spis* p)
//{
//	if (!p->next) {
//		return;
//	}
//	Spis* t = nullptr, * t1;
//	do {
//		for (t1 = p; t1->next != t; t1 = t1->next)
//		{
//			if (t1->num > t1->next->num)
//			{
//				int q;
//				q = t1->next->num;
//				t1->next->num = t1->num;
//				t1->num = q;
//			}
//		}
//		t = t1;
//	} while (p->next != t);
//}
//
//void View(Spis* begin, Spis* end, bool is_end)
//{
//	if (is_end)
//	{
//		Spis* t = begin;
//		while (t != nullptr)
//		{
//			printf("%d\n", t->num);
//			t = t->next;
//		}
//	}
//	else
//	{
//		Spis* t = end;
//		while (t != NULL)
//		{
//			printf("%d\n", t->num);
//			t = t->prev;
//		}
//	}
//}
//
//void Del_All(Spis** p) {
//	Spis* t;
//	while(*p!=nullptr)
//	{
//		t = *p;
//		*p = (*p)->next;
//		delete t;
//	}
//}
//
//void Del_Elem(Spis** begin) {
//	system("cls");
//	printf("Введите какой элемент хотите удалить: ");
//	int elem = check();
//	bool least_one = false;
//	Spis** pcur = begin;
//	Spis* temp; 
//
//	if ((*pcur)->num == elem) {
//		temp = (*pcur);
//		(*pcur) = (*pcur)->next;
//		(*pcur)->prev = nullptr;
//		least_one = true;
//		delete temp;
//	}
//
//	while ((*pcur)->next) {
//		if ((*pcur)->num == elem) {
//			temp = (*pcur);
//			(*pcur)->prev->next = (*pcur)->next;
//			(*pcur)->prev = (*pcur)->prev->prev;
//			least_one = true;
//			delete temp;
//		}
//		else pcur = &(*pcur)->next;
//	}
//
//	if ((*pcur)->num == elem) {
//		temp = (*pcur);
//		(*pcur) = (*pcur)->prev;
//		(*pcur)->next = nullptr;
//		least_one = true;
//		delete temp;
//	}
//
//	if (!least_one) {
//		printf("Такого элемента нет в списке!!!");
//	}
//}
//
//void Del(Spis** begin) {
//	system("cls");
//	printf("Введите что хотите удалить:\n1.Весь список\n2.Элемент\n");
//	switch (check()) {
//	case 1:
//		Del_All(begin);
//		break;
//	case 2:
//		Del_Elem(begin);
//		break;
//	default:
//		printf("Нет такого варианта!!!");
//	}
//}

//
// лаба 2
//

//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <Windows.h>
//#include <io.h>
//#include <conio.h>
//#include <iostream>
//
//
//struct Students {
//	char FIO[40];
//	char address[40];
//	int num_group;
//	int marks[4];
//	double s_mark;
//};
//FILE* Fz, * Ft, * It;
//char File_Zap[256];
//char File_Rez[] = "rezult.txt";
//int sizeOfStruct = sizeof(Students);
//
//
//int check();
//void create();
//void out(Students&, FILE*, int);
//void add();
//bool view();
//void save(Students*, int);
//void edit(int);
//void zadanie();
//void zapisName(char*, int);
//void zapisFile(char*, int);
//void LinSearch(char*);
//void SortLin();
//void QuickSort();
//
//
//using namespace std;
//int main()
//{
//	system("chcp 1251>0");
//	char* a;
//	while (true)
//	{
//		int choise1, razm;
//		system("cls");
//		printf("\n1.Создать или редактировать текущий файл  2.Удалить файл  3.Выйти\nВыбирайте: ");
//		choise1 = check();
//		switch (choise1)
//		{
//		case 1:
//			system("cls");
//			razm = 0;
//			zapisFile(File_Zap, sizeof(File_Zap));
//			while (File_Zap[razm])
//			{
//				razm++;
//			}
//			File_Zap[razm] = '.';
//			File_Zap[++razm] = 'd';
//			File_Zap[++razm] = 'a';
//			File_Zap[++razm] = 't';
//			File_Zap[razm + 1] = '\0';
//			while (true)
//			{
//				int choise2;
//				bool proverka = true, proverkaForCase3 = true, flag = false;
//				while (proverka)
//				{
//					system("cls");
//					printf("Ваш файл: %s", File_Zap);
//					printf("\n1 - Создать\n2 - Просмотр\n3 - Изменить\n4 - Сортировка\n5 - Поиск в файле\n6 - Индивидуальное задание\n0 - Выйти\n");
//					printf("Выбирайте: ");
//					switch (check())
//					{
//					case 1:
//						system("cls");
//						if (_access(File_Zap, 0) == 0) {
//							printf("Файл уже создан");
//							system("pause");
//							break;
//						}
//						create();
//						if (!Fz)
//						{
//							printf("Ошибка!");
//							return 0;
//						}
//						proverka = false;
//						system("pause");
//						break;
//					case 2:
//						if (!view())
//						{
//							printf("\n\nФайл остуствует...\n");
//						}
//						proverka = false;
//						system("pause");
//						break;
//					case 3:
//						system("cls");
//						if (_access(File_Zap, 0) == -1) {
//							printf("Файл не создан");
//							system("pause");
//							break;
//						}
//						proverkaForCase3 = true;
//						while (proverkaForCase3)
//						{
//							printf("\n1.Добавить\n2.Изменить\nКак именно изменить?  ");
//							choise2 = check();
//							switch (choise2)
//							{
//							case 1:
//								add();
//								proverkaForCase3 = false;
//								system("pause");
//								break;
//							case 2:
//								int choiseNum;
//								view();
//
//								int descriptor, kol;
//								long len;
//								Fz = fopen(File_Zap, "rb");
//								descriptor = _fileno(Fz);
//								len = _filelength(descriptor);
//								kol = len / sizeOfStruct;
//								fclose(Fz);
//
//								if (kol == 0)
//								{
//									printf("\nЭлементов которые можно изменить нет!!1!1\n");
//									proverkaForCase3 = false;
//									system("pause");
//									break;
//								}
//
//								printf("\n\nВведите номер записи, которую хотите изменить:\t");
//								proverkaForCase3 = false;
//								choiseNum = check();
//								rewind(stdin);
//
//								if (choiseNum > kol || choiseNum < 1)
//								{
//									printf("Такого элемента нет...");
//									system("pause");
//									break;
//								}
//
//								edit(choiseNum);
//								system("pause");
//								break;
//							default:
//								printf("\nТакого варианта нет!!!1!1");
//							}
//						}
//						proverka = false;
//						break;
//					case 4:
//						system("cls");
//						printf("Выберите сортировку: 1.Метод прямого выбора  2.QuickSort\nВыбирайте:");
//						switch (check())
//						{
//						case 1:
//							SortLin();
//							printf("Файл отсортирован!!!!1!!1\n");
//							system("pause");
//							break;
//						case 2:
//							QuickSort();
//							printf("Файл отсортирован!!!!1!!1\n");
//							system("pause");
//							break;
//						}
//						break;
//					case 5:
//						if (_access(File_Zap, 0) == -1) {
//							printf("Файл не создан");
//							system("pause");
//							break;
//						}
//						char key[40];
//						printf("Введите фамилию кого хотите найти: ");
//						gets_s(key);
//						rewind(stdin);
//						printf("\n");
//						LinSearch(key);
//						system("pause");
//						break;
//					case 6:
//						system("cls");
//						zadanie();
//						system("pause");
//						break;
//					case 0:
//						proverka = false;
//						flag = true;
//						break;
//					default:
//						printf("Такого варианта нет!!\n");
//					}
//				}
//				if (flag)
//				{
//					break;
//				}
//			}
//			break;
//		case 2:
//			system("cls");
//			razm = 0;
//			zapisFile(File_Zap, sizeof(File_Zap));
//			rewind(stdin);
//
//			while (File_Zap[razm])
//			{
//				razm++;
//			}
//			File_Zap[razm] = '.';
//			File_Zap[++razm] = 'd';
//			File_Zap[++razm] = 'a';
//			File_Zap[++razm] = 't';
//			File_Zap[razm + 1] = '\0';
//			if (remove(File_Zap) == 0)
//			{
//				printf_s("\nФайл успешно удалён!\n");
//			}
//			else
//			{
//				printf_s("\nОшибка удаления файла...\n");
//			}
//			system("pause");
//			break;
//		case 3:
//			return 0;
//		default:
//			printf_s("Такого варианта нет...");
//		}
//	}
//}
//
//int check() {
//	int a{};
//	while (!scanf_s("%d", &a)) {
//		printf("Неправильный ввод\nВведите число:");
//		rewind(stdin);
//	}
//	char temp;
//	while ((temp = getchar()) != '\n') {
//		if (temp > 57 || temp < 48) {
//			printf("Неправильный ввод\nВведите число:");
//			rewind(stdin);
//			scanf_s("%d", &a);
//		}
//	}
//	return a;
//}
//
//void zapisFile(char* s, int size)
//{
//	int i{};
//	char x{};
//	while (i < size - 1)
//	{
//		printf_s("На данный момент существующие файлы:\n");
//		system("dir *.dat /b");
//		printf_s("Введите имя файла который хотите создать, или изменить: ");
//		for (int j = 0; j < i; j++)
//		{
//			printf("%c", s[j]);
//		}
//		x = _getch();
//		system("cls");
//		if (x == '\b' && i > 0)
//		{
//			i--;
//			s[i] = '\0';
//			continue;
//		}
//		if (x == '/' || x == '\\' || x == ':' || x == '*' || x == '?' || x == '>' || x == '<' || x == '|')
//		{
//			continue;
//		}
//		if (x == '\r')
//		{
//			break;
//		}
//		s[i] = x;
//		i++;
//	}
//	if (i == size - 1)
//	{
//		while (s[i - 1] == ' ')
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
//void zapisName(char* s, int size)
//{
//	int i{};
//	while (true)
//	{
//		setlocale(LC_ALL, "Rus");
//		int numOfSpace{};
//		unsigned char x{};
//		while (i < size - 1)
//		{
//			printf("ФИО: ");
//			for (int j = 0; j < i; j++)
//			{
//				printf("%c", s[j]);
//			}
//			x = _getch();
//			system("cls");
//			if (x == ' ')
//			{
//				if (s[i - 1] == ' ')
//				{
//					continue;
//				}
//				numOfSpace++;
//				if (numOfSpace > 2)
//				{
//					printf("\nВсего должно быть 3 слова!!!\n\n");
//					system("pause");
//					system("cls");
//					continue;
//				}
//				s[i] = x;
//				i++;
//			}
//			if (x == '\b' && i > 0)
//			{
//				if (s[i - 1] == ' ')
//				{
//					s[--i] = '\0';
//					numOfSpace--;
//					continue;
//				}
//				s[--i] = '\0';
//				continue;
//			}
//			if (x >= 192 && x <= 255)
//			{
//				s[i] = x;
//				i++;
//			}
//			if (x == '\r')
//			{
//				break;
//			}
//		}
//		if (numOfSpace < 2)
//		{
//			printf("\nСлов должно быть 3!!!\n");
//			for (int j = 0; j < i; j++)
//			{
//				s[j] = '\0';
//			}
//			i = 0;
//			system("pause");
//			system("cls");
//		}
//		else
//		{
//			printf("ФИО: ");
//			for (int j = 0; j < i; j++)
//			{
//				printf("%c", s[j]);
//			}
//			break;
//		}
//	}
//	if (i == size - 1)
//	{
//		while (s[i - 1] == ' ')
//		{
//			i--;
//		}
//		printf("\nКоличество символов ограничено!");
//		s[i] = '\0';
//		printf_s("\nВаше ФИО: ");
//		for (int j = 0; j < i; j++)
//		{
//			printf("%c", s[j]);
//		}
//		rewind(stdin);
//		return;
//	}
//	s[i] = '\0';
//}
//
//void LinSearch(char* key)
//{
//	Fz = fopen(File_Zap, "rb");
//	Students s;
//	bool identical = false;
//	for(int i=1; fread(&s, sizeOfStruct, 1, Fz); i++)
//	{
//		for(int i=0;key[i] && s.FIO[i];i++)
//		{
//			if(key[i] == s.FIO[i])
//			{
//				identical = true;
//			}else
//			{
//				identical = false;
//				break;
//			}
//		}
//		if(identical)
//		{
//			printf("\n%d. %s - %s, Группа: %d; Физика: %d, Математика: %d, Информатика: %d, Химия: %d, Средний балл: %1.2lf", i, s.FIO, s.address, s.num_group, s.marks[0], s.marks[1], s.marks[2], s.marks[3], s.s_mark);
//		}
//	}
//	fclose(Fz);
//}
//
//
//void SortLin()
//{
//	Fz = fopen(File_Zap, "rb");
//	Students* stud;
//	int kol = _filelength(_fileno(Fz)) / sizeOfStruct;
//	stud = new Students[kol];
//	fread(stud, sizeOfStruct, kol, Fz);
//	fclose(Fz);
//	for (int i = 0; i < kol - 1; i++)
//	{
//		int m = i;
//		for (int j = i + 1; j < kol; j++)
//		{
//			for (int l = 0; stud[i].FIO[l] && stud[j].FIO[l]; l++)
//			{
//				if (stud[i].FIO[l] > stud[j].FIO[l])
//				{
//					m = j;
//				}
//				if (stud[i].FIO[l] == stud[j].FIO[l])
//				{
//					continue;
//				}
//				break;
//			}
//		}
//		Students r = stud[m];
//		stud[m] = stud[i];
//		stud[i] = r;
//	}
//	
//	save(stud, kol);
//	delete[] stud;
//}
//
//void QuickSort()
//{
//	Fz = fopen(File_Zap, "rb");
//	Students* a;
//	int kol = _filelength(_fileno(Fz)) / sizeOfStruct;
//	a = new Students[kol];
//	fread(a, sizeOfStruct, kol, Fz);
//	fclose(Fz);
//	int i = 0;
//	int j = kol - 1;
//	char* x = a[(kol) / 2].FIO;
//	while (i <= j) {
//		for(int l=0;a[i].FIO[l] && x[l];l++)
//		{
//			if (a[i].FIO[l] < x[l])
//			{
//				i++;
//			}
//			if (a[i].FIO[l] == x[l])
//			{
//				continue;
//			}
//			break;
//		}
//
//
//
//		for (int l = 0; a[j].FIO[l] && x[l]; l++)
//		{
//			if (a[j].FIO[l] > x[l])
//			{
//				j--;
//			}
//			if (a[j].FIO[l] == x[l])
//			{
//				continue;
//			}
//			break;
//		}
//
//
//		if (i <= j) {
//			Students r = a[i];
//			a[i] = a[j];
//			a[j] = r;
//			i++;
//			j--;
//		}
//	}
//	save(a, kol);
//	delete[] a;
//}
//
//
//void create()
//{
//	Fz = fopen(File_Zap, "wb");
//	printf("\nФайл создан!\n");
//	fclose(Fz);
//}
//
//bool view() {
//	Fz = fopen(File_Zap, "rb");
//	Ft = fopen(File_Rez, "wb");
//	if (!Fz)
//		return false;
//	Students student;
//
//	printf("\n\t--------------- Информация ---------------\n");
//	fprintf(Ft, "\n\n\n\t---------------  Информация ---------------\n");
//
//
//	for (int i = 1; fread(&student, sizeOfStruct, 1, Fz); i++)
//	{
//		out(student, Ft, i);
//	}
//	printf("\n\n");
//	fclose(Fz);
//	fclose(Ft);
//	return true;
//}
//
//void out(Students& s, FILE* Potochek, int i = 0)
//{
//	printf("\n%d. %s - %s, Группа: %d; Физика: %d, Математика: %d, Информатика: %d, Химия: %d, Средний балл: %1.2lf", i, s.FIO, s.address, s.num_group, s.marks[0], s.marks[1], s.marks[2], s.marks[3], s.s_mark);
//	fprintf(Potochek, "\n%s - %s, Группа: %d; Физика: %d, Математика: %d, Информатика: %d, Химия: %d, Средний балл: %1.2lf", s.FIO, s.address, s.num_group, s.marks[0], s.marks[1], s.marks[2], s.marks[3], s.s_mark);
//}
//
//void add()
//{
//	system("cls");
//	Students student;
//	zapisName(student.FIO, sizeof(student.FIO));
//
//	rewind(stdin);
//	printf("\nАдресс: ");
//	gets_s(student.address);
//
//	printf("Номер группы: ");
//	student.num_group = check();
//	printf("Введите оценки по предметам:");
//	while (1)
//	{
//		printf("\nФизика: ");
//		student.marks[0] = check();
//		if (student.marks[0] >= 0 && student.marks[0] <= 10) break;
//		printf("Некорректный ввод...");
//	}
//	while (1)
//	{
//		printf("Математика: ");
//		student.marks[1] = check();
//		if (student.marks[1] >= 0 && student.marks[1] <= 10) break;
//		printf("Некорректный ввод...\n");
//	}
//	while (1)
//	{
//		printf("Информатика: ");
//		student.marks[2] = check();
//		if (student.marks[2] >= 0 && student.marks[2] <= 10) break;
//		printf("Некорректный ввод...\n");
//	}
//	while (1)
//	{
//		printf("Химия: ");
//		student.marks[3] = check();
//		if (student.marks[3] >= 0 && student.marks[3] <= 10) break;
//		printf("Некорректный ввод...\n");
//	}
//	student.s_mark = (double)(student.marks[0] + student.marks[1] + student.marks[2] + student.marks[3]) / 4;
//	printf("Средний балл: %.2lf", student.s_mark);
//	printf("\n");
//	Fz = fopen(File_Zap, "ab");
//	fwrite(&student, sizeOfStruct, 1, Fz);
//	fclose(Fz);
//}
//
//void save(Students* st, int num) {
//	Fz = fopen(File_Zap, "wb");
//	fwrite(st, sizeOfStruct, num, Fz);
//	fclose(Fz);
//}
//
//void edit(int edit_number) {
//	Students* st, newStudent;
//	zapisName(newStudent.FIO, sizeof(newStudent.FIO));
//
//	printf("\nАдресс: ");
//	gets_s(newStudent.address);
//	rewind(stdin);
//
//	printf("Номер группы: ");
//	newStudent.num_group = check();
//	printf("Введите оценки по предметам:");
//	while (1)
//	{
//		printf("\nФизика: ");
//		newStudent.marks[0] = check();
//		if (newStudent.marks[0] >= 0 && newStudent.marks[0] <= 10) break;
//		printf("Некорректный ввод...");
//	}
//	while (1)
//	{
//		printf("Математика: ");
//		newStudent.marks[1] = check();
//		if (newStudent.marks[1] >= 0 && newStudent.marks[1] <= 10) break;
//		printf("Некорректный ввод...\n");
//	}
//	while (1)
//	{
//		printf("Информатика: ");
//		newStudent.marks[2] = check();
//		if (newStudent.marks[2] >= 0 && newStudent.marks[2] <= 10) break;
//		printf("Некорректный ввод...\n");
//	}
//	while (1)
//	{
//		printf("Химия: ");
//		newStudent.marks[3] = check();
//		if (newStudent.marks[3] >= 0 && newStudent.marks[3] <= 10) break;
//		printf("Некорректный ввод...\n");
//	}
//	newStudent.s_mark = (newStudent.marks[0] + newStudent.marks[1] + newStudent.marks[2] + newStudent.marks[3]) / 4;
//	printf("Средний балл: %lf", newStudent.s_mark);
//
//	Fz = fopen(File_Zap, "rb");
//	int descriptor, i, kol;
//	double len;
//	descriptor = _fileno(Fz);
//	len = _filelength(descriptor);
//	kol = len / sizeOfStruct;
//	st = new Students[kol];
//	for (i = 0; i < kol; i++) {
//		fread((st + i), sizeOfStruct, 1, Fz);
//	}
//	fclose(Fz);
//
//	st[edit_number - 1] = newStudent;
//	Ft = fopen(File_Rez, "wb");
//	for (i = 0; i < kol; i++)
//		out(st[i], Ft, i + 1);
//	save(st, kol);
//	fclose(Ft);
//	delete[]st;
//	printf("\n\n");
//}
//
//void zadanie()
//{
//	Students* studFromFile;
//	int value, i = 1, numOfStud{};
//
//	Fz = fopen(File_Zap, "rb");
//	value = _filelength(_fileno(Fz)) / sizeOfStruct;
//	studFromFile = new Students[value];
//
//	fread(studFromFile, sizeOfStruct, value, Fz);
//	fclose(Fz);
//	char key[] = "г. Минск";
//	bool ident = false;
//
//	for (int i = 0; i < value; i++)
//	{
//		for (int j = 0; studFromFile[i].address[j]; j++)
//		{
//			for (int l = 0; l < sizeof(key) - 1; l++, j++)
//			{
//				if (studFromFile[i].address[j] == key[l])
//				{
//					ident = true;
//				}
//				else
//				{
//					ident = false;
//					break;
//				}
//			}
//			if (ident)
//			{
//				numOfStud++;
//			}
//		}
//	}
//
//	Students* studWithGoodInfo = new Students[numOfStud];
//
//	int GoodNum{};
//
//	for (int i = 0; i < value; i++)
//	{
//		for (int j = 0; studFromFile[i].address[j]; j++)
//		{
//			for (int l = 0; l < sizeof(key) - 1; l++, j++)
//			{
//				if (studFromFile[i].address[j] == key[l])
//				{
//					ident = true;
//				}
//				else
//				{
//					ident = false;
//					break;
//				}
//			}
//			if (ident)
//			{
//				studWithGoodInfo[GoodNum++] = studFromFile[i];
//			}
//		}
//	}
//
//	for (int i = 0; i < numOfStud - 1; i++)
//	{
//		int m = i;
//		for (int j = i + 1; j < numOfStud; j++)
//		{
//			for (int l = 0; studWithGoodInfo[i].FIO[l] && studWithGoodInfo[j].FIO[l]; l++)
//			{
//				if (studWithGoodInfo[i].FIO[m] > studWithGoodInfo[j].FIO[m])
//				{
//					m = j;
//				}
//				if (studWithGoodInfo[i].FIO[m] == studWithGoodInfo[j].FIO[m])
//				{
//					continue;
//				}
//				break;
//			}
//		}
//		Students r = studWithGoodInfo[m];
//		studWithGoodInfo[m] = studWithGoodInfo[i];
//		studWithGoodInfo[i] = r;
//	}
//
//	for (int i = 0; i < numOfStud; i++)
//	{
//		printf("\n%d. %s - %s, Группа: %d; Физика: %d, Математика: %d, Информатика: %d, Химия: %d, Средний балл: %1.2lf", i, studWithGoodInfo[i].FIO, studWithGoodInfo[i].address, studWithGoodInfo[i].num_group, studWithGoodInfo[i].marks[0], studWithGoodInfo[i].marks[1], studWithGoodInfo[i].marks[2], studWithGoodInfo[i].marks[3], studWithGoodInfo[i].s_mark);
//	}
//	delete[] studWithGoodInfo;
//}

//
//	лаба 9
//

//#include <iostream>
//#include <cmath>
//
//using namespace std;
//
//double f(double x) {
//    return x * x * x - 5 * x * x + 12;
//}
//
//double vetein(double a, double b, double eps) {
//    double x0 = a, x1 = b;
//    double y0 = f(x0), y1 = f(x1);
//    double z{};
//    double de;
//    int it = 0;
//    do {
//        it = it + 1;
//        double d = x1 - x0;
//        z = x1 - (y1 * d) / (y1 - y0);
//        de = fabs(x1 - z);
//        x0 = x1;
//        x1 = z;
//        y0 = y1;
//        y1 = f(z);
//    } while (de < eps || it>100);
//    return z;
//}
//
//int main() {
//    double x0 = -2, x1 = 5;
//    double y0 = f(x0), y1 = f(x1);
//    int num_intervals = 10; 
//    double dx = (5.0 + 2.0) / num_intervals;
//    double x_left = x0, x_right = x0 + dx;
//    while (x_right <= 5) {
//        if (f(x_left) * f(x_right) <= 0) {
//            double root = vetein(x_left, x_right, 1e-6);
//            printf("Root: %f\n", root);
//        }
//        x_left = x_right;
//        x_right += dx;
//    }
//}

//
//	лаба 8
//

//#include <iostream>
//#include <cmath>
//
//typedef double (*TFun)(double);
//
//double F(double x)
//{
//	return pow(x,3) + 6 * pow(x, 2) - 0.02 * exp(x);
//}
//
//double gaus2_with_n(TFun f, double a, double b)
//{
//    const double nuls[2] = { -0.5773503, 0.5773503 };
//    const double pol = 1;
//    double ra = (b - a) / 2;
//    double su = (a + b) / 2;
//    double q, S = 0;
//    for (int i = 0; i < 2; i++) {
//        q = su + ra * nuls[i];
//        S += pol * f(q);
//    }
//    return ra * S;
//}
//
//int check() {
//	int a{};
//	while (!scanf_s("%d", &a)) {
//		printf("Неправильный ввод\nВведите число:");
//		rewind(stdin);
//	}
//	char temp;
//	while ((temp = getchar()) != '\n') {
//		if (temp > 57 || temp < 48) {
//			printf("Неправильный ввод\nВведите число:");
//			rewind(stdin);
//			scanf_s("%d", &a);
//		}
//	}
//	return a;
//}
//
//int main()
//{
//	system("chcp 1251>nul");
//	double s = 0, h, x;
//    int a, b;
//    printf("a = ");
//    a = check();
//	printf("b = ");
//	b = check();
//	printf("Вотъ: %lf", gaus2_with_n(F, a, b));
//}



//
// лаба с бинарным деревом
//

//#include <iostream>
//
//struct Branch
//{
//	char FIO[30];
//	int numOfPass;
//	Branch* LeftBranch; 
//	Branch* RightBranch;
//	int height;
//};
//
//
//
//int check();
//void View_Tree(Branch*, int level = 1);
//void fixheight(Branch*);
//Branch* rotateleft(Branch*);
//Branch* rotateright(Branch*);
//int bfactor(Branch*);
//Branch* balance(Branch*);
//Branch* find_balance(Branch* p);
//Branch* Add(char* aFIO, int aNumOfPass, Branch* aBranch, int height);
//void pr_obh(Branch*);
//void Find(int, Branch*);
//void obr_obh(Branch*);
//void Indiv(Branch* aBranch, char a, int& kol);
//void vozrast_obh(Branch*);
//Branch* del_elem(Branch*, int);
//Branch* delTree(Branch*);
//
//int main()
//{
//	system("chcp 1251>nul");
//	Branch* Root = 0;
//	bool proverka=true;
//	int vremPass;
//	char a;
//	char vremFIO[30];
//
//	int kol;
//	while (proverka)
//	{
//		system("cls");
//		printf("на данный момент дерево выглядит так :\n");
//		View_Tree(Root);
//		printf("\n");
//		printf("1.Добавить элемент массива\n2.Найти по номеру паспорта\n3.Вывести ифнормацию\n4.Балансировка\n5.Индивидуальное задание\n6.Удалить\n0.Выйти\n");
//		switch (check())
//		{
//		case 1:
//			system("cls");
//			printf("Фио: ");
//			rewind(stdin);
//			gets_s(vremFIO);
//			printf("Номер паспорта: ");
//			vremPass=check();
//			Root=Add(vremFIO,vremPass, Root, 1);
//			break;
//		case 2:
//			system("cls");
//			int KeyPass;
//			printf("Введите искомый номер паспорта: ");
//			scanf_s("%d", &KeyPass);
//			Find(KeyPass, Root);
//			system("pause");
//			break;
//		case 3:
//			system("cls");
//			printf("Как вывести информацию?\n1.Прямым образом\n2.Обратным образом\n3.По возрастанию Номера паспорта\n");
//			switch (check())
//			{
//			case 1:
//				pr_obh(Root);
//				system("pause");
//				break;
//			case 2:
//				obr_obh(Root);
//				system("pause");
//				break;
//			case 3:
//				vozrast_obh(Root);
//				system("pause");
//				break;
//			}
//			break;
//		case 4:
//			Root = find_balance(Root);
//			break;
//		case 5:
//			system("cls");
//			kol = 0;
//			printf("Введите с какого символа должна начинаться запись: ");
//			scanf_s("%c", &a);
//			Indiv(Root, a, kol);
//			printf("Количество: %d\n",  kol);
//			system("pause");
//			break;
//		case 6:
//			system("cls");
//			printf("Введите что хотите удалить:\n1.Всё дерево\n2.Элемент по паспорту\n");
//			switch (check())
//			{
//			case 1:
//				Root = delTree(Root);
//				break;
//			case 2:
//				printf("Введите номер паспорта, кого хотите удалить: ");
//				vremPass = check();
//				Root = del_elem(Root, vremPass);
//			default:
//				break;
//			}
//			break;
//		case 0:
//			return 0;
//		}
//	}
//}
//
//int check() {
//	int a{};
//	while (!scanf_s("%d", &a)) {
//		printf("Неправильный ввод\nВведите число:");
//		rewind(stdin);
//	}
//	char temp;
//	while ((temp = getchar()) != '\n') {
//		if (temp > 57 || temp < 48) {
//			printf("Неправильный ввод\nВведите число:");
//			rewind(stdin);
//			scanf_s("%d", &a);
//		}
//	}
//	return a;
//}
//
//void View_Tree(Branch* aBranch, int level) {
//	if (!aBranch)return;
//	level += 2;
//	View_Tree(aBranch->RightBranch, level);
//	for (int i = 2; i < level; ++i) printf(" ");
//	printf("%d\n", aBranch->numOfPass);
//	View_Tree(aBranch->LeftBranch, level);
//}
//
//int height(Branch* aBranch) {
//	if (aBranch) return aBranch->height;
//	else return 0;
//}
//
//void fixheight(Branch* aBranch)
//{
//	int hl = height(aBranch->LeftBranch);
//	int hr = height(aBranch->RightBranch);
//	if (hl > hr) {
//		aBranch->height = hl + 1;
//	}
//	else {
//		aBranch->height = hr + 1;
//	}
//}
//
//Branch* rotateleft(Branch* aBranch) // левый поворот вокруг q
//{
//	Branch* q = aBranch->RightBranch;
//	aBranch->RightBranch = q->LeftBranch;
//	q->LeftBranch = aBranch;
//	fixheight(aBranch);
//	fixheight(q);
//	return q;
//}
//
//Branch* rotateright(Branch* aBranch)
//{
//	Branch* q = aBranch->LeftBranch;
//	aBranch->LeftBranch = q->RightBranch;
//	q->RightBranch = aBranch;
//	fixheight(aBranch);
//	fixheight(q);
//	return q;
//}
//
//
//Branch* balance(Branch* aBranch)
//{
//	int bf = height(aBranch->RightBranch) - height(aBranch->LeftBranch);
//	if (bf == 2)
//	{
//		if (bfactor(aBranch->RightBranch) < 0)
//			aBranch->RightBranch = rotateright(aBranch->RightBranch);
//		return rotateleft(aBranch);
//	}
//	if (bf == -2)
//	{
//		if (bfactor(aBranch->LeftBranch) > 0)
//			aBranch->LeftBranch = rotateleft(aBranch->LeftBranch);
//		return rotateright(aBranch);
//	}
//	return aBranch;
//}
//
//Branch* find_balance(Branch* aBranch) 
//{
//	if (aBranch == nullptr)    return nullptr;
//	aBranch = balance(aBranch);
//	aBranch->LeftBranch = balance(aBranch->LeftBranch);
//	aBranch->RightBranch = balance(aBranch->RightBranch);
//	return aBranch;
//}
//
//Branch* Add(char* aFIO, int aNumOfPass, Branch* aBranch, int height=1)
//{
//	if (!aBranch)
//	{
//		aBranch = new Branch;
//		int i;
//		for(i=0;aFIO[i];i++)
//		{
//			aBranch->FIO[i] = aFIO[i];
//		}
//		aBranch->FIO[i] = '\0';
//		aBranch->numOfPass = aNumOfPass;
//		aBranch->height = height;
//		aBranch->LeftBranch = NULL;
//		aBranch->RightBranch = NULL;
//		return aBranch;
//	}
//	if (aBranch->numOfPass == aNumOfPass) return aBranch;
//	if (aBranch->numOfPass > aNumOfPass)
//	{
//		aBranch->LeftBranch = Add(aFIO, aNumOfPass, aBranch->LeftBranch, height++);
//	}
//	else
//	{ 
//		aBranch->RightBranch = Add(aFIO, aNumOfPass, aBranch->RightBranch, height++);
//	}
//	fixheight(aBranch);
//	return aBranch;
//}
//
//
//void pr_obh(Branch* aBranch)
//{
//	if (aBranch == NULL)    return;   
//
//	printf("ФИО: %s | Номер паспорта: %d\n", aBranch->FIO, aBranch->numOfPass);
//	pr_obh(aBranch->LeftBranch); 
//	pr_obh(aBranch->RightBranch);
//}
//
//void obr_obh(Branch* aBranch)
//{
//	if(aBranch != NULL)
//	{
//		obr_obh(aBranch->LeftBranch);  
//		obr_obh(aBranch->RightBranch);
//		printf("Фио: %s | Номер паспорта: %d\n", aBranch->FIO, aBranch->numOfPass);
//	}
//}
//
//void vozrast_obh(Branch* aBranch)
//{
//	if (aBranch != NULL)
//	{
//		vozrast_obh(aBranch->LeftBranch);
//		printf("Фио: %s | Номер паспорта: %d\n", aBranch->FIO, aBranch->numOfPass);
//		vozrast_obh(aBranch->RightBranch);
//	}
//}
//
//void Find(int Key, Branch* aBranch)
//{
//	if (!aBranch)
//	{
//		return;
//	}
//	if(aBranch->numOfPass==Key)
//	{ 
//		printf("ФИО: %s | Номер паспорта: %d\n", aBranch->FIO, aBranch->numOfPass);
//		return;
//	}
//	if (Key < aBranch->numOfPass)
//		Find(Key, aBranch->LeftBranch);
//	else
//		Find(Key, aBranch->RightBranch);
//}
//
//void Indiv(Branch* aBranch, char a, int& kol)
//{
//	if (!aBranch)
//	{
//		return;
//	}
//	if (aBranch->FIO[0] == a)
//	{
//		kol++;
//		if(aBranch->LeftBranch!=NULL)
//		{
//			Indiv(aBranch->LeftBranch, a, kol);
//		}
//		if(aBranch->RightBranch!=NULL)
//		{
//			Indiv(aBranch->RightBranch, a, kol);
//		}
//		return;
//	}
//	Indiv(aBranch->LeftBranch, a, kol);
//	Indiv(aBranch->RightBranch, a, kol);
//}
//
//Branch* del_elem(Branch* aBranch, int key) 
//{
//	if (aBranch->LeftBranch == nullptr && aBranch->RightBranch == nullptr) 
//	{
//		aBranch = nullptr;
//		return aBranch;
//	}
//
//	Branch* del = aBranch, * prev = nullptr, * swap, * preSwap = nullptr, * save;
//	bool left_need = false;
//	
//	while (del != nullptr && del->numOfPass != key) 
//	{
//		if (del->numOfPass > key) { prev = del; left_need == true; del = del->LeftBranch; }
//		else { prev = del; left_need = false; del = del->RightBranch; }
//	}
//
//	if (del == NULL) {
//		printf("Такого элемента нет в дереве!!!");
//		return aBranch;
//	}
//
//	if (del->LeftBranch == nullptr) swap = del->RightBranch;
//	else if (del->RightBranch == nullptr) swap = del->LeftBranch;
//	
//	else {
//		swap = del->LeftBranch;
//		while (swap->RightBranch)
//		{
//			preSwap = swap;
//			swap = swap->RightBranch;
//		}
//		preSwap->RightBranch = swap->LeftBranch;
//		swap->LeftBranch = del->LeftBranch;
//		swap->RightBranch = del->RightBranch;
//	}
//	if (left_need)
//	{
//		prev->LeftBranch = swap;
//	}
//	else
//	{
//		prev->RightBranch = swap;
//	}
//	delete del;
//	return aBranch;
//}
//
//Branch* delTree(Branch* aBranch)
//{
//	if (aBranch)
//	{
//		delTree(aBranch->LeftBranch);
//		delTree(aBranch->RightBranch);
//		delete aBranch;
//	}
//	return nullptr;
//}

//
// лаба обратная польская запись
//

//#include<iostream>
//#include <conio.h>
//
//struct Stack
//{
//	char elem;
//	Stack* next;
//};
//
//int Prior(char);
//Stack* InStack(Stack*, char);
//char OutStack(Stack**);
//double Result(char*);
//void zapis(char*, int);
//double checkDouble();
//int checkInt();
//
//void main()
//{
//	system("chcp 1251>0");
//	Stack* elems = nullptr;
//	char In[81] = "a-(b/c*(d+e))", Out[81] = " ";
//	printf_s("Какие данные записать:\n1.Свои\n2.Шаблон\n");
//	switch (checkInt())
//	{
//	case 1:
//		zapis(In, 81);
//		break;
//	case 2:
//		break;
//	}
//	int out_len = 0;
//	for (int i = 0; In[i]; i++)
//	{
//		switch (In[i])
//		{
//		case '(':
//			elems = InStack(elems, In[i]);
//			break;
//		case ')':
//			while (elems->elem != '(')
//			{
//				Out[out_len++] = OutStack(&elems);
//			}
//			OutStack(&elems);
//			break;
//		case '+': case '-': case '*': case '/':
//			while (elems != nullptr && Prior(elems->elem) >= Prior(In[i]))
//			{
//				Out[out_len++] = OutStack(&elems);
//			}
//			elems = InStack(elems, In[i]);
//			break;
//		}
//		if (In[i] >= 'a' && In[i] <= 'z')
//		{
//			Out[out_len++] = In[i];
//		}
//	}
//	while (elems != nullptr)
//	{
//		Out[out_len++] = OutStack(&elems);
//	}
//	Out[out_len] = '\0';
//	printf("Polish = %s\n", Out);
//	printf("Result = %.2lf", Result(Out));
//}
//
//Stack* InStack(Stack* st, char ch)
//{
//	Stack* temp = new Stack;
//	temp->elem = ch;
//	temp->next = st;
//	return temp;
//}
//
//char OutStack(Stack** st)
//{
//	char ch = (*st)->elem;
//	Stack* to_del = *st;
//	*st = (*st)->next;
//	delete to_del;
//	return ch;
//}
//
//int  Prior(char ch)
//{
//	switch (ch)
//	{
//	case '(': return 0;
//
//	case '+': case '-': return 2;
//
//	case '*': case '/': return 3;
//	}
//	return 0;
//}
//
//double Result(char* str)
//{
//	Stack* begin = NULL;
//	char ss1, ss2, ssR = 'z' + 1;
//	double op1, op2, res, mas[50];
//	for (int i = 0, j = 0; str[i]; ++i) {
//		if (str[i] >= 'a' && str[i] <= 'z')
//		{
//			printf("%c = ", str[i]);
//			mas[int(str[i] - 'a')] = checkDouble();
//		}
//	}
//
//	for (int i = 0, j = 0; str[i] != '\0'; ++i) {
//		if (str[i] >= 'a' && str[i] <= 'z')
//			begin = InStack(begin, str[i]);
//		else {
//			op2 = mas[int(OutStack(&begin) - 'a')];
//			op1 = mas[int(OutStack(&begin) - 'a')];
//			switch (str[i])
//			{
//			case '+':
//				res = op1 + op2;
//				break;
//			case '-':
//				res = op1 - op2;
//				break;
//			case '*':
//				res = op1 * op2;
//				break;
//			case '/':
//				res = op1 / op2;
//			}
//			mas[int(ssR - 'a')] = res;
//			begin = InStack(begin, ssR);
//			ssR++;
//		}
//	}
//	return res;
//}
//
//void zapis(char* s, int size)
//{
//	int i{};
//	char x{};
//	while (i < size - 1)
//	{
//		printf_s("Введите математическую формулу которую нужно решить: ");
//		for (int j = 0; j < i; j++)
//		{
//			printf("%c", s[j]);
//		}
//		x = _getch();
//		system("cls");
//		if (x == '\b' && i > 0)
//		{
//			i--;
//			s[i] = '\0';
//			continue;
//		}
//		if ((x >= 'a' && x <= 'z') || x == '+' || x == '/' || x == '*' || x == '-' || x == '(' || x == ')')
//		{
//			s[i] = x;
//			i++;
//		}
//		if (x == '\r')
//		{
//			break;
//		}
//	}
//	if (i == size - 1)
//	{
//		while (s[i - 1] == ' ')
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
//double checkDouble() {
//	double a{};
//	while (!scanf_s("%lf", &a)) {
//		printf("Неправильный ввод\nВведите число:");
//		rewind(stdin);
//	}
//	char temp;
//	while ((temp = getchar()) != '\n') {
//		if (temp > 57 || temp < 48) {
//			printf("Неправильный ввод\nВведите число:");
//			rewind(stdin);
//			scanf_s("%lf", &a);
//		}
//	}
//	return a;
//}
//
//int checkInt() {
//	int a{};
//	while (!scanf_s("%d", &a)) {
//		printf("Неправильный ввод\nВведите число:");
//		rewind(stdin);
//	}
//	char temp;
//	while ((temp = getchar()) != '\n') {
//		if (temp > 57 || temp < 48) {
//			printf("Неправильный ввод\nВведите число:");
//			rewind(stdin);
//			scanf_s("%d", &a);
//		}
//	}
//	return a;
//}

//
//	лаба с хешированием
//

//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <fstream>
//#include <conio.h>
//#include <cstring>
//
//struct TInf {
//	int numOfFlight;
//	char typeOfPlane[100];
//	char key[100];
//	char timeOfArrive[6];
//};
//
//struct Stack 
//{
//	TInf Inf;
//	Stack* next;
//};
//
//void zapisCif(char* s, int size);
//bool charcmp(char*, char*);
//void zapisFile(char*, int);
//int check();
//
//
//
//class THash {
//private:
//	int M;
//	Stack** H;
//public:
//
//	int hashFunction(char* key) {
//		int sum = 0;
//		for (key; *key != '\0' ; key++) {
//			sum += *key;
//		}
//		return sum % M;
//	}
//
//	THash(int k)
//	{
//		M = k;
//		H = new Stack * [M];
//		for (int i = 0; i < M; i++) H[i] = NULL;
//	}
//
//	void Add(TInf Inf)
//	{
//		Stack* p = new Stack;
//		int i = hashFunction(Inf.key);
//		p->next = H[i];
//		p->Inf = Inf;
//		H[i] = p;
//	}
//	
//	void Del(char* key)
//	{
//		int i = hashFunction(key);
//		Stack* p = H[i], *prev = nullptr;
//		if (p == nullptr) return;
//		while (p) 
//		{
//			if (charcmp(p->Inf.key, key)) 
//			{
//				if (!prev) 
//				{
//					H[i] = p->next;
//					delete p;
//					return;
//				}
//				prev->next = p->next;
//				delete p;
//				return;
//			}
//			prev = p;
//			p = p->next;
//		}
//		printf("С таким ключом нет элемента в Хеш-таблице");
//	}
//
//	void Read(char* key)
//	{
//		int i = hashFunction(key);
//		Stack* p = H[i], * p1{};
//		bool bl = false;
//		if (p != NULL)
//		{
//			do {
//				if (charcmp(p->Inf.key, key)) 
//				{
//					bl = true;
//					printf("%d || %s || %s || %s\n", p->Inf.numOfFlight, p->Inf.typeOfPlane, p->Inf.key, p->Inf.timeOfArrive);
//				}
//				p1 = p;
//				p = p->next;
//			} while (p != NULL);
//		}
//		if (!bl) 
//		{
//			printf("С таким ключом нет элемента в Хеш-таблице");
//		}
//	}
//
//	void Individual()
//	{
//		char* key = new char[100];
//		int i;
//		printf("Введите Пункт назначения информацио о рейсах которой хотите увидеть: ");
//		char temp[100];
//		scanf_s("%s", &temp, (unsigned int)sizeof(temp));
//		strcpy(key, temp);
//		int sum = 0;
//		for (key; *key != '\0'; key++) {
//			sum += *key;
//		}
//		i = hashFunction(temp);
//		TInf tempSt[20]{};
//
//		Stack* p = H[i], * p1{};
//		int numInf = 0;
//		bool bl = false;
//		if (p != NULL)
//		{
//			do {
//				if (charcmp(p->Inf.key, temp))
//				{
//					bl = true;
//					TInf tempInf{};
//					strcpy(tempInf.key, p->Inf.key);
//					tempInf.numOfFlight = p->Inf.numOfFlight;
//					strcpy(tempInf.timeOfArrive, p->Inf.timeOfArrive);
//					strcpy(tempInf.typeOfPlane, p->Inf.typeOfPlane);
//					tempSt[numInf] = tempInf;
//					numInf++;
//
//				}
//				p1 = p;
//				p = p->next;
//			} while (p != NULL);
//		}
//		if (!bl)
//		{
//			printf("С таким ключом нет элементов в Хеш-таблице");
//			return;
//		}
//		int size=0;
//		for (size; tempSt[size].numOfFlight!=0; size++);
//
//		i = 0;
//		int j = size - 1;
//		char* x = tempSt[size / 2].timeOfArrive;
//		int minutesOfX = ((x[0] - 48) * 10 + (x[1] - 48)) * 60 + (x[3] - 48) * 10 + (x[4] - 48);
//		while (i <= j) {
//			for(int l=0;tempSt[i].timeOfArrive[l] && x[l];l++)
//			{
//				int minutesOfI = ((tempSt[i].timeOfArrive[0] - 48) * 10 + (tempSt[i].timeOfArrive[1] - 48)) * 60 + (tempSt[i].timeOfArrive[3] - 48) * 10 + (tempSt[i].timeOfArrive[4] - 48);
//				if (minutesOfI < minutesOfX)
//				{
//					i++;
//				}
//				if (minutesOfI == minutesOfX)
//				{
//					continue;
//				}
//				break;
//			}
//		
//			for (int l = 0; tempSt[j].timeOfArrive[l] && x[l]; l++)
//			{
//				int minutesOfJ = ((tempSt[j].timeOfArrive[0] - 48) * 10 + (tempSt[j].timeOfArrive[1] - 48)) * 60 + (tempSt[j].timeOfArrive[3] - 48) * 10 + (tempSt[j].timeOfArrive[4] - 48);
//				if (minutesOfJ > minutesOfX)
//				{
//					j--;
//				}
//				if (minutesOfJ == minutesOfX)
//				{
//					continue;
//				}
//				break;
//			}
//		
//			if (i <= j) {
//				TInf r = tempSt[i];
//				tempSt[i] = tempSt[j];
//				tempSt[j] = r;
//				i++;
//				j--;
//			}
//		}
//
//		for (int i = 0; i < size; i++) 
//		{
//			printf("%d || %s || %s || %s\n", tempSt[i].numOfFlight, tempSt[i].typeOfPlane, tempSt[i].key, tempSt[i].timeOfArrive);
//		}
//	}
//
//	~THash()
//	{
//		char File_Name[100];
//		int razm = 0;
//		
//		zapisFile(File_Name, sizeof(File_Name));
//		while (File_Name[razm])
//		{
//			razm++;
//		}
//		File_Name[razm] = '.';
//		File_Name[++razm] = 'd';
//		File_Name[++razm] = 'a';
//		File_Name[++razm] = 't';
//		File_Name[razm + 1] = '\0';
//
//		Stack* p;
//		FILE* Fl;
//		if ((Fl = fopen(File_Name, "wb")) == NULL) {
//			printf("File no created");
//			return;
//		}
//		for (int i = 0; i < M; i++) {
//			while (H[i] != NULL) {
//				p = H[i];
//				fwrite(&H[i], sizeof(Stack), 1, Fl);
//				H[i] = H[i]->next;
//				delete p;
//			}
//		}
//		fclose(Fl);
//		delete H;
//	}
//};
//
//int main() {
//	system("chcp 1251>nul");
//	THash* hash{};
//	bool end = false;
//	char key[100];
//	while (!end) {
//		system("cls");
//		printf("\n1 - Создать\n2 - Добавить\n3 - Удалить элемент по ключу\n4 - Поиск в хеш-таблице по ключу\n5 - Индивидуальное задание\n6 - Удалить Хеш-таблицу\n0 - Выйти\n");
//		printf("Выбирайте: ");
//		switch (check()) 
//		{
//		case 1:
//			system("cls");
//			if (hash) 
//			{
//				printf("Хеш-таблица уже создана!!");
//				system("pause");
//				break;
//			}
//			printf("Введите кол-во записей в таблице: ");
//			hash = new THash(check());
//			system("pause");
//			break;
//		case 2:
//			system("cls");
//			if (!hash) {
//				printf("Хеш - таблица не создана");
//				system("pause");
//				break;
//			}
//			TInf Inf1;
//			
//			printf("Введите\nНомер рейса: ");
//			Inf1.numOfFlight = check();
//			printf("Тип самолёта: ");
//			scanf_s("%s", &(Inf1.typeOfPlane), (unsigned int)sizeof(Inf1.typeOfPlane));
//			printf("Пункт назначения: ");
//			scanf_s("%s", &(Inf1.key), (unsigned int)sizeof(Inf1.key));
//			printf("Время прибытия: ");
//			zapisCif(Inf1.timeOfArrive, sizeof(Inf1.timeOfArrive));
//
//			printf("Введите\nНомер рейса: %d\n", Inf1.numOfFlight);
//			printf("Тип самолёта: %s\n", Inf1.typeOfPlane);
//			printf("Пункт назначения: %s\n", Inf1.key);
//			printf("Время прибытия: %s\n", Inf1.timeOfArrive);
//			hash->Add(Inf1);
//			system("pause");
//			break;
//		case 3:
//			system("cls");
//			if (!hash) {
//				printf("Хеш - таблица не создана");
//				system("pause");
//				break;
//			}
//			printf("Запишите Пункт назначения, элемент с которым вы хотите удалить: ");
//			scanf_s("%s", &key, (unsigned int)sizeof(key));
//			hash->Del(key);
//			system("pause");
//			break;
//		case 4:
//			system("cls");
//			if (!hash) {
//				printf("Хеш - таблица не создана");
//				system("pause");
//				break;
//			}
//			printf("Запишите Пункт назначения элемент с которым вы хотите просмотреть: ");
//			scanf_s("%s", &key, (unsigned int)sizeof(key));
//			hash->Read(key);
//			system("pause");
//			break;
//		case 5:
//			system("cls");
//			hash->Individual();
//			system("pause");
//			break;
//		case 6:
//			system("cls");
//			if (!hash) {
//				printf("Хеш - таблица не создана");
//				system("pause");
//				break;
//			}
//			delete hash;
//			hash = nullptr;
//			printf("Хеш таблица удалена");
//			system("pause");
//			break;
//		case 0:
//			end = true;
//			break;
//		default:
//			system("cls");
//			printf("Такова варианта нет!!1!1");
//			system("pause");
//		}
//	}
//
//	return 0;
//}
//
//void zapisFile(char* s, int size)
//{
//	int i{};
//	char x{};
//	while (i < size - 1)
//	{
//		printf_s("Введите имя файла куда хотите создать Хеш-таблицу: ");
//		for (int j = 0; j < i; j++)
//		{
//			printf("%c", s[j]);
//		}
//		x = _getch();
//		system("cls");
//		if (x == '\b' && i > 0)
//		{
//			i--;
//			s[i] = '\0';
//			continue;
//		}
//		if (x == '/' || x == '\\' || x == ':' || x == '*' || x == '?' || x == '>' || x == '<' || x == '|')
//		{
//			continue;
//		}
//		if (x == '\r')
//		{
//			break;
//		}
//		s[i] = x;
//		i++;
//	}
//	if (i == size - 1)
//	{
//		while (s[i - 1] == ' ')
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
//void zapisCif(char* s, int size)
//{
//	system("cls");
//	int i{};
//	char x{};
//	while (true) {
//		i = 0;
//		while (i < size - 1)
//		{
//			printf_s("Время прибытия: ");
//			for (int j = 0; j < i; j++)
//			{
//				printf("%c", s[j]);
//			}
//			if (i == 2) {
//				x = ':';
//				s[i] = x;
//				i++;
//				system("cls");
//				continue;
//			}
//			x = _getch();
//			system("cls");
//			if (x == '\b' && i > 0)
//			{
//				i--;
//				s[i] = '\0';
//				continue;
//			}
//			if (x< '0' || x > '9' && x != ':')
//			{
//				continue;
//			}
//			s[i] = x;
//			i++;
//		}
//
//		if (((s[0] - 48) * 10 + (s[1] - 48)) > 24) {
//			printf("Некорректно введено время\n");
//			system("pause");
//			continue;
//		}
//
//		if (((s[3] - 48) * 10 + (s[4] - 48)) > 60) {
//			printf("Некорректно введено время\n");
//			system("pause");
//			continue;
//		}
//		break;
//	}
//
//	if (i == size - 1)
//	{
//		while (s[i - 1] == ' ')
//		{
//			i--;
//		}
//		s[i] = '\0';
//		rewind(stdin);
//		return;
//	}
//	s[i] = '\0';
//}
//
//bool charcmp(char* first, char* second) {
//	bool same = false;
//	for (first, second; *first && *second; first += 1, second += 1) 
//	{
//		if (*first == *second) 
//		{
//			same = true;
//		}
//		else {
//			same = false;
//		}
//	}
//	if (*first || *second) 
//	{
//		same = false;
//	}
//	return same;
//}
//
//int check() {
//	int a = 0;
//	while ((scanf_s("%d", &a), getchar()) != '\n') {
//		printf("Неправильный ввод!\nВведите число:");
//		rewind(stdin);
//	}
//	return a;
//}