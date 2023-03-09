//
// ���� 1
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
//	printf("������� n: ");
//	n = check();
//	printf("����������� �������: %lf \n������� �������: %lf", RecY(n), Y(n));
//	std::cout << "����������� �������: " << RecY(n) << std::endl << "������� �������: " << Y(n);
//}
//
//int check() {
//	int a{};
//	while (!scanf_s("%d", &a)) {
//		printf("������������ ����\n������� �����:");
//		rewind(stdin);
//	}
//	char temp;
//	while ((temp = getchar()) != '\n') {
//		if (temp > 57 || temp < 48) {
//			printf("������������ ����\n������� �����:");
//			rewind(stdin);
//			scanf_s("%d", &a);
//		}
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
// ���� 2
//

//#include <iostream>
//#include <ctime>
//
//struct Stack
//{
//	int num;
//	Stack* next;
//} *begin;
//
//Stack* InStack(Stack* p) {
//	Stack* t = new Stack;
//	t->num = rand()-16000;
//	t->next = p;
//	return t;
//}
//
//void View(Stack* p) {
//	Stack* t = p;
//	while (t != NULL) 
//	{
//		printf("%d\n", t->num);
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
//void Del_All(Stack** p) {
//	Stack* t;
//	while(*p!=nullptr)
//	{
//		t = *p;
//		*p = (*p)->next;
//		delete t;
//	}
//}
//
//void Sort(Stack *p)
//{
//	Stack* t=nullptr, *t1;
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
//void Invdiv(Stack *p)
//{
//	int sredArifm{}, kolOfNum{};
//	Stack* t=p;
//	while(p!=nullptr)
//	{
//		sredArifm += p->num;
//		kolOfNum++;
//		p = p->next;
//	}
//	sredArifm = sredArifm / kolOfNum;
//	t->num = sredArifm;
//}
//
//int main()
//{
//	system("chcp 1251>nul");
//	srand(time(NULL));
//	int choise{};
//	bool proverka = true;
//	while (proverka)
//	{
//		system("cls");
//		printf("1.�������\t2.��������\t3.����������\t4.�������������� �������\t5.������� ����\t6.�����\n���������:");
//		scanf_s("%d", &choise);
//		switch (choise)
//		{
//		case 1:
//			begin = InStack(begin);
//			break;
//		case 2:
//			View(begin);
//			system("pause");
//			break;
//		case 3:
//			Sort(begin);
//			break;
//		case 4:
//			Invdiv(begin);
//			View(begin);
//			system("pause");
//			break;
//		case 5:
//			Del_All(&begin);
//			break;
//		case 6:
//			proverka = false;
//			break;
//		default:
//			printf("������ �������� ���!!!1!!!");
//		}
//	}
//}


//
// ���� 3
//

//#include <iostream>
//
//struct Spis
//{
//	int num;
//	Spis* prev, * next;
//} *begin, *end;
//
//int check();
//void CreateSpis();
//void InSpisBegin();
//void InSpisEnd();
//void View(bool);
//void Del_All(Spis**);
//
//int main()
//{
//	system("chcp 1251>nul");
//	bool proverka = true;
//	while (proverka)
//	{
//		printf("1.�������\t2.��������\t3.�����������\t4.�������\t0.�����\n���������: ");
//		switch (check())
//		{
//		case 1:
//			CreateSpis();
//			printf("������ ������!\n");
//			break;
//		case 2:
//			printf("���� ��������?\t1.� ������\t2.� �����\n���������:");
//			switch (check())
//			{
//			case 1:
//				InSpisBegin();
//				break;
//			case 2:
//				InSpisEnd();
//				break;
//			}
//			break;
//		case 3:
//			printf("������ ��������?\t1.� ������\t2.� �����\n���������:");
//			switch (check())
//			{
//			case 1:
//				View(true);
//				break;
//			case 2:
//				View(false);
//				break;
//			}
//			break;
//		case 4:
//			Del_All(&begin);
//			break;
//		case 0:
//			proverka = false;
//			break;
//		}
//	}
//}
//
//int check() {
//	int a{};
//	while (!scanf_s("%d", &a)) {
//		printf("������������ ����\n������� �����:");
//		rewind(stdin);
//	}
//	char temp;
//	while ((temp = getchar()) != '\n') {
//		if (temp > 57 || temp < 48) {
//			printf("������������ ����\n������� �����:");
//			rewind(stdin);
//			scanf_s("%d", &a);
//		}
//	}
//	return a;
//}
//
//void CreateSpis()
//{
//	Spis* t = new Spis;
//	printf("������� �������: ");
//	t->num = check();
//	t->next = t->prev = NULL;
//	begin = end = t;
//}
//
//void InSpisBegin()
//{
//	Spis* t = new Spis;
//	printf("������� �������: ");
//	t->num = check();
//	t->prev = NULL;
//	t->next = begin;
//	begin->prev = t;
//	begin = t;
//}
//
//void InSpisEnd()
//{
//	Spis* t = new Spis;
//	printf("������� �������: ");
//	t->num = check();
//	t->next = NULL;
//	t->prev = end;
//	end->next = t;
//	end = t; 
//}
//
//void View(bool vperde)
//{
//	if (vperde)
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
// ���� 6
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
//		printf("\n1.������� ��� ������������� ������� ����  2.������� ����  3.�����\n���������: ");
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
//					printf("��� ����: %s", File_Zap);
//					printf("\n1 - �������\n2 - ��������\n3 - ��������\n4 - ����������\n5 - ����� � �����\n6 - �������������� �������\n0 - �����\n");
//					printf("���������: ");
//					choise1 = check();
//					switch (choise1)
//					{
//					case 1:
//						system("cls");
//						if (_access(File_Zap, 0) == 0) {
//							printf("���� ��� ������");
//							system("pause");
//							break;
//						}
//						create();
//						if (!Fz)
//						{
//							printf("������!");
//							return 0;
//						}
//						proverka = false;
//						system("pause");
//						break;
//					case 2:
//						if (!view())
//						{
//							printf("\n\n���� ����������...\n");
//						}
//						proverka = false;
//						system("pause");
//						break;
//					case 3:
//						system("cls");
//						if (_access(File_Zap, 0) == -1) {
//							printf("���� �� ������");
//							system("pause");
//							break;
//						}
//						proverkaForCase3 = true;
//						while (proverkaForCase3)
//						{
//							printf("\n1.��������\n2.��������\n��� ������ ��������?  ");
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
//									printf("\n��������� ������� ����� �������� ���!!1!1\n");
//									proverkaForCase3 = false;
//									system("pause");
//									break;
//								}
//
//								printf("\n\n������� ����� ������, ������� ������ ��������:\t");
//								proverkaForCase3 = false;
//								choiseNum = check();
//								rewind(stdin);
//
//								if (choiseNum > kol || choiseNum < 1)
//								{
//									printf("������ �������� ���...");
//									system("pause");
//									break;
//								}
//
//								edit(choiseNum);
//								system("pause");
//								break;
//							default:
//								printf("\n������ �������� ���!!!1!1");
//							}
//						}
//						proverka = false;
//						break;
//					case 4:
//						system("cls");
//						printf("�������� ����������: 1.����� ������� ������  2.QuickSort\n���������:");
//						switch (check())
//						{
//						case 1:
//							SortLin();
//							printf("���� ������������!!!!1!!1\n");
//							system("pause");
//							break;
//						case 2:
//							QuickSort();
//							printf("���� ������������!!!!1!!1\n");
//							system("pause");
//							break;
//						}
//						break;
//					case 5:
//						if (_access(File_Zap, 0) == -1) {
//							printf("���� �� ������");
//							system("pause");
//							break;
//						}
//						char key[40];
//						printf("������� ������� ���� ������ �����: ");
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
//					case 0:
//						proverka = false;
//						flag = true;
//						break;
//					default:
//						printf("������ �������� ���!!\n");
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
//				printf_s("\n���� ������� �����!\n");
//			}
//			else
//			{
//				printf_s("\n������ �������� �����...\n");
//			}
//			system("pause");
//			break;
//		case 3:
//			return 0;
//		default:
//			printf_s("������ �������� ���...");
//		}
//	}
//}
//
//int check() {
//	int a{};
//	while (!scanf_s("%d", &a)) {
//		printf("������������ ����\n������� �����:");
//		rewind(stdin);
//	}
//	char temp;
//	while ((temp = getchar()) != '\n') {
//		if (temp > 57 || temp < 48) {
//			printf("������������ ����\n������� �����:");
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
//		printf_s("�� ������ ������ ������������ �����:\n");
//		system("dir *.dat /b");
//		printf_s("������� ��� ����� ������� ������ �������: ");
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
//		printf("\n���������� �������� ����������!");
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
//			printf("���: ");
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
//					printf("\n����� ������ ���� 3 �����!!!\n\n");
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
//			printf("\n���� ������ ���� 3!!!\n");
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
//			printf("���: ");
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
//		printf("\n���������� �������� ����������!");
//		s[i] = '\0';
//		printf_s("\n���� ���: ");
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
//			printf("\n%d. %s - %s, ������: %d; ������: %d, ����������: %d, �����������: %d, �����: %d, ������� ����: %1.2lf", i, s.FIO, s.address, s.num_group, s.marks[0], s.marks[1], s.marks[2], s.marks[3], s.s_mark);
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
//				if (stud[i].FIO[m] > stud[j].FIO[m])
//				{
//					m = j;
//				}
//				if (stud[i].FIO[m] == stud[j].FIO[m])
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
//		//while (a[i].FIO[0] < x[0]) i++;
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
//		//while (a[j].FIO[0] > x[0]) j--;
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
//	printf("\n���� ������!\n");
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
//	printf("\n\t--------------- ���������� ---------------\n");
//	fprintf(Ft, "\n\n\n\t---------------  ���������� ---------------\n");
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
//	printf("\n%d. %s - %s, ������: %d; ������: %d, ����������: %d, �����������: %d, �����: %d, ������� ����: %1.2lf", i, s.FIO, s.address, s.num_group, s.marks[0], s.marks[1], s.marks[2], s.marks[3], s.s_mark);
//	fprintf(Potochek, "\n%s - %s, ������: %d; ������: %d, ����������: %d, �����������: %d, �����: %d, ������� ����: %1.2lf", s.FIO, s.address, s.num_group, s.marks[0], s.marks[1], s.marks[2], s.marks[3], s.s_mark);
//}
//
//void add()
//{
//	system("cls");
//	Students student;
//	zapisName(student.FIO, sizeof(student.FIO));
//
//	rewind(stdin);
//	printf("\n������: ");
//	gets_s(student.address);
//
//	printf("����� ������: ");
//	student.num_group = check();
//	printf("������� ������ �� ���������:");
//	while (1)
//	{
//		printf("\n������: ");
//		student.marks[0] = check();
//		if (student.marks[0] >= 0 && student.marks[0] <= 10) break;
//		printf("������������ ����...");
//	}
//	while (1)
//	{
//		printf("����������: ");
//		student.marks[1] = check();
//		if (student.marks[1] >= 0 && student.marks[1] <= 10) break;
//		printf("������������ ����...\n");
//	}
//	while (1)
//	{
//		printf("�����������: ");
//		student.marks[2] = check();
//		if (student.marks[2] >= 0 && student.marks[2] <= 10) break;
//		printf("������������ ����...\n");
//	}
//	while (1)
//	{
//		printf("�����: ");
//		student.marks[3] = check();
//		if (student.marks[3] >= 0 && student.marks[3] <= 10) break;
//		printf("������������ ����...\n");
//	}
//	student.s_mark = (double)(student.marks[0] + student.marks[1] + student.marks[2] + student.marks[3]) / 4;
//	printf("������� ����: %.2lf", student.s_mark);
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
//	printf("\n������: ");
//	gets_s(newStudent.address);
//	rewind(stdin);
//
//	printf("����� ������: ");
//	newStudent.num_group = check();
//	printf("������� ������ �� ���������:");
//	while (1)
//	{
//		printf("\n������: ");
//		newStudent.marks[0] = check();
//		if (newStudent.marks[0] >= 0 && newStudent.marks[0] <= 10) break;
//		printf("������������ ����...");
//	}
//	while (1)
//	{
//		printf("����������: ");
//		newStudent.marks[1] = check();
//		if (newStudent.marks[1] >= 0 && newStudent.marks[1] <= 10) break;
//		printf("������������ ����...\n");
//	}
//	while (1)
//	{
//		printf("�����������: ");
//		newStudent.marks[2] = check();
//		if (newStudent.marks[2] >= 0 && newStudent.marks[2] <= 10) break;
//		printf("������������ ����...\n");
//	}
//	while (1)
//	{
//		printf("�����: ");
//		newStudent.marks[3] = check();
//		if (newStudent.marks[3] >= 0 && newStudent.marks[3] <= 10) break;
//		printf("������������ ����...\n");
//	}
//	newStudent.s_mark = (newStudent.marks[0] + newStudent.marks[1] + newStudent.marks[2] + newStudent.marks[3]) / 4;
//	printf("������� ����: %lf", newStudent.s_mark);
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
//	char key[] = "�. �����";
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
//		printf("\n%d. %s - %s, ������: %d; ������: %d, ����������: %d, �����������: %d, �����: %d, ������� ����: %1.2lf", i, studWithGoodInfo[i].FIO, studWithGoodInfo[i].address, studWithGoodInfo[i].num_group, studWithGoodInfo[i].marks[0], studWithGoodInfo[i].marks[1], studWithGoodInfo[i].marks[2], studWithGoodInfo[i].marks[3], studWithGoodInfo[i].s_mark);
//	}
//	delete[] studWithGoodInfo;
//}

//
//	���� 7
//

//#include <iostream>
//#include <cmath>
//
//double Fx(double x)
//{
//	return x * x * x + 6 * x * x - 0.02 * exp(x) - 14;
//}
//
//int check() {
//	double a{};
//	while (!scanf_s("%lf", &a)) {
//		printf("������������ ����\n������� �����:");
//		rewind(stdin);
//	}
//	char temp;
//	while ((temp = getchar()) != '\n') {
//		if (temp > 57 || temp < 48) {
//			printf("������������ ����\n������� �����:");
//			rewind(stdin);
//			scanf_s("%lf", &a);
//		}
//	}
//	return a;
//}
//double MP(int a, int b)
//{
//	double x0{ 100 }, h = (double)(a - b) / 3,  e{0.0001}, it{};
//	double
//		x1 = x0 - h,
//		x2 = x0,
//		x3 = x0 + h,
//		y1 = Fx(x1),
//		y2 = Fx(x2),
//		y3 = Fx(x3);
//	double zm{}, z1, z2, r, d, p, q, zm1, zm2;
//	do
//	{
//		it++;
//		z1 = x1 - x3;
//		z2 = x2 - x3;
//		r = y3;
//		p = ((y1 - y3) * z2 - (y2 - y3) * z1) / (z1 * z2 * (z1 - z2));
//		q = ((y1 - y3) * z2*z2 - (y2 - y3) * z1*z1) / (z1 * z2 * (z2 - z1));
//		double D = sqrt(fabs(q * q - 4 * p * r));
//		zm1 = (-1 * q + D) / (2*p);
//		zm2 = (-1 * q - D) / (2 * p);
//		zm = zm1 < zm2 ? zm1 : zm2;
//		x1 = x2; x2 = x3;
//		y1 = y2; y2 = y3;
//		x3 = x3 + zm;
//		y3 = Fx(x3);
//	} while (fabs(zm)>e && it<100);
//	return x3;
//}
//
//int main()
//{
//	system("chcp 1251>nul");
//	double a, b, m{ 3 };
//	printf("a = ");
//	a = check();
//	printf("b = ");
//	b = check();
//	double x = a, y;
//
//	printf("������ = %lf", MP(a, b));
//}

//
//	���� 8
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
//		printf("������������ ����\n������� �����:");
//		rewind(stdin);
//	}
//	char temp;
//	while ((temp = getchar()) != '\n') {
//		if (temp > 57 || temp < 48) {
//			printf("������������ ����\n������� �����:");
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
//	printf("����: %lf", gaus2_with_n(F, a, b));
//}



//
// ���� � �������� �������
//

//#include <iostream>
//
//struct Branch
//{
//	char FIO[30];
//	int numOfPass;
//	Branch* LeftBranch; 
//	Branch* RightBranch;
//};
//
//
//using namespace std;
//
//int check();
//void Add(char*, int, Branch*&);
//void pr_obh(Branch*&);
////Branch* del_elem(int, Branch*&);
//void Find(int, Branch*&);
//void obr_obh(Branch*&);
//void Indiv(Branch*& aBranch, char a, int& kol);
//void Add_Norm(Branch*&, int, char*);
//void vozrast_obh(Branch*&);
//
//int main()
//{
//	system("chcp 1251>nul");
//	Branch* Root = 0;
//	bool proverka=true;
//	int vremPass;
//
//	char vremFIO[30];
//
//	int kol;
//	while (proverka)
//	{
//		system("cls");
//		printf("1.�������� ������� �������\n2.����� �� ������ ��������\n3.������� ����������\n4.�������������� �������\n5.������� �� �����\n6.�����\n");
//		switch (check())
//		{
//		case 1:
//			system("cls");
//			printf("���: ");
//			rewind(stdin);
//			gets_s(vremFIO);
//			printf("����� ��������: ");
//			vremPass=check();
//			Add(vremFIO,vremPass, Root);
//
//			
//			break;
//		case 2:
//			system("cls");
//			int KeyPass;
//			printf("������� ������� ����� ��������: ");
//			scanf_s("%d", &KeyPass);
//			Find(KeyPass, Root);
//			system("pause");
//			break;
//		case 3:
//			system("cls");
//			printf("��� ������� ����������?\n1.������ �������\n2.�������� �������\n3.�� ����������� ������ ��������\n");
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
//			system("cls");
//			char a;
//			kol = 0;
//			printf("������� � ������ ������� ������ ���������� ������: ");
//			scanf_s("%c", &a);
//			Indiv(Root, a, kol);
//			printf("����������: %d\n",  kol);
//			system("pause");
//			break;
//		case 5:
//			/*system("cls");
//			printf("������� ����� ��������, ���� ������ �������: ");
//			vremPass = check();
//			Root = del_elem(vremPass, Root);
//			system("pause");
//			break;*/
//		case 6:
//			return 0;
//		}
//	}
//}
//
//int check() {
//	int a{};
//	while (!scanf_s("%d", &a)) {
//		printf("������������ ����\n������� �����:");
//		rewind(stdin);
//	}
//	char temp;
//	while ((temp = getchar()) != '\n') {
//		if (temp > 57 || temp < 48) {
//			printf("������������ ����\n������� �����:");
//			rewind(stdin);
//			scanf_s("%d", &a);
//		}
//	}
//	return a;
//}
//
//
//
//void Add(char* aFIO, int aNumOfPass, Branch*& aBranch)
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
//		aBranch->LeftBranch = NULL;
//		aBranch->RightBranch = NULL;
//		return;
//	}
//	if (aBranch->numOfPass == aNumOfPass) return;
//	if (aBranch->numOfPass > aNumOfPass)
//	{
//		Add(aFIO, aNumOfPass, aBranch->LeftBranch);
//	}
//	else
//	{ 
//		Add(aFIO, aNumOfPass, aBranch->RightBranch);
//	}
//}
//
//
//void pr_obh(Branch*& aBranch)
//{
//	if (aBranch == NULL)    return;   
//
//	cout << "���: " << aBranch->FIO << " | ����� ��������: " << aBranch->numOfPass << endl; 
//	pr_obh(aBranch->LeftBranch); 
//	pr_obh(aBranch->RightBranch);
//}
//
//void obr_obh(Branch*& aBranch)
//{
//	if(aBranch != NULL)
//	{
//		obr_obh(aBranch->LeftBranch);  
//		obr_obh(aBranch->RightBranch);
//		printf("���: %s | ����� ��������: %d\n", aBranch->FIO, aBranch->numOfPass);
//	}
//}
//
//void vozrast_obh(Branch*& aBranch)
//{
//	if (aBranch != NULL)
//	{
//		vozrast_obh(aBranch->LeftBranch);
//		printf("���: %s | ����� ��������: %d\n", aBranch->FIO, aBranch->numOfPass);
//		vozrast_obh(aBranch->RightBranch);
//	}
//}
//
//void Find(int Key, Branch*& aBranch)
//{
//	if (!aBranch)
//	{
//		return;
//	}
//	if(aBranch->numOfPass==Key)
//	{
//		printf("���: %s | ����� ��������: %d\n", aBranch->FIO, aBranch->numOfPass);
//		return;
//	}
//	if (Key < aBranch->numOfPass)
//		Find(Key, aBranch->LeftBranch);
//	else
//		Find(Key, aBranch->RightBranch);
//}
//
//void Indiv(Branch*& aBranch, char a, int& kol)
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
// ���� �������� �������� ������
//