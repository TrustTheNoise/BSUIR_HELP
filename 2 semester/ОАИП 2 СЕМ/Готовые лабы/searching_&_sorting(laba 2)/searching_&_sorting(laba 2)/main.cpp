#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <io.h>
#include <conio.h>
#include <iostream>


struct Students {
	char FIO[40];
	char address[40];
	int num_group;
	int marks[4];
	double s_mark;
};
FILE* binF, * txtF;
char File_Rec[256];
char File_Rez[] = "output.txt";
int sizeOfStruct = sizeof(Students);


int check();
void createFile();
void out(Students&, FILE*, int);
void add();
bool view();
void save(Students*, int);
void edit(int);
void individual();
bool strLess(char*, char*);
bool strBig(char*, char*);
void zapisName(char*, int);
void fNameRec(char*, int);
void linSearch(char*);
void sortLin();
void quickSort(Students*, int, int);
void howSort();
void workWithFile();


using namespace std;
int main()
{
	system("chcp 1251>0");
	int fSize = 0;
	while (true)
	{
		int choise1;
		system("cls");
		printf("\n1.Создать или редактировать текущий файл  2.Удалить файл  3.Выйти\nВыбирайте: ");
		choise1 = check();
		switch (choise1)
		{
		case 1:
			fSize = 0;
			system("cls");
			fNameRec(File_Rec, sizeof(File_Rec));
			while (File_Rec[fSize])
			{
				fSize++;
			}
			File_Rec[fSize] = '.';
			File_Rec[++fSize] = 'd';
			File_Rec[++fSize] = 'a';
			File_Rec[++fSize] = 't';
			File_Rec[fSize + 1] = '\0';

			workWithFile();

			break;
		case 2:
			system("cls");
			fSize = 0;
			fNameRec(File_Rec, sizeof(File_Rec));
			rewind(stdin);

			while (File_Rec[fSize])
			{
				fSize++;
			}
			File_Rec[fSize] = '.';
			File_Rec[++fSize] = 'd';
			File_Rec[++fSize] = 'a';
			File_Rec[++fSize] = 't';
			File_Rec[fSize + 1] = '\0';
			if (remove(File_Rec) == 0) {
				printf_s("\nФайл успешно удалён!\n");
			}
			else {
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

void workWithFile()
{
	int choise2;
	bool exitFromRedactingFile = false;
	enum {Exit, Create, Display, Change, Sort, FindKey, Individ};
	while(true) {
		system("cls");
		printf("Ваш файл: %s", File_Rec);
		printf("\n1 - Создать\n2 - Просмотр\n3 - Изменить\n4 - Сортировка\n"
			"5 - Поиск в файле\n6 - Индивидуальное задание\n0 - Выйти\n");
		printf("Выбирайте: ");
		switch(check()) {
		case Create:
			system("cls");
			if(_access(File_Rec, 0) == 0) {
				printf("Файл уже создан");
				system("pause");
				break;
			}
			createFile();
			if(!binF) {
				printf("Ошибка!");
				return;
			}
			system("pause");
			break;
		case Display:
			if(!view()) {
				printf("\n\nФайл остуствует...\n");
			}
			system("pause");
			break;
		case Change:
			system("cls");
			exitFromRedactingFile = false;
			if(_access(File_Rec, 0) == -1) {
				printf("Файл не создан");
				system("pause");
				break;
			}
			while(!exitFromRedactingFile) {
				printf("\n1.Добавить\n2.Изменить\nКак именно изменить?  ");
				choise2 = check();
				switch(choise2) {
				case 1:
					add();
					exitFromRedactingFile = true;
					system("pause");
					break;
				case 2:
					int choiseNum;
					view();

					int descriptor, kol;
					long len;
					binF = fopen(File_Rec, "rb");
					descriptor = _fileno(binF);
					len = _filelength(descriptor);
					kol = len / sizeOfStruct;
					fclose(binF);

					if(kol == 0) {
						printf("\nЭлементов которые можно изменить нет!!1!1\n");
						exitFromRedactingFile = true;
						system("pause");
						break;
					}

					printf("\n\nВведите номер записи, которую хотите изменить:\t");
					exitFromRedactingFile = true;
					choiseNum = check();
					rewind(stdin);

					if(choiseNum > kol || choiseNum < 1) {
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
			break;
		case Sort:
			howSort();
			break;
		case FindKey:
			if(_access(File_Rec, 0) == -1) {
				printf("Файл не создан");
				system("pause");
				break;
			}
			char key[40];
			printf("Введите фамилию кого хотите найти: ");
			gets_s(key);
			rewind(stdin);
			printf("\n");
			linSearch(key);
			system("pause");
			break;
		case Individ:
			system("cls");
			individual();
			system("pause");
			break;
		case 0:
			return;
		default:
			printf("Такого варианта нет!!\n");
		}
	}
}

void fNameRec(char* s, int size)
{
	int i{};
	char x{};
	while (i < size - 1)
	{
		printf_s("На данный момент существующие файлы:\n");
		system("dir *.dat /b");
		printf_s("Введите имя файла который хотите создать, или изменить: ");
		for (int j = 0; j < i; j++) {
			printf("%c", s[j]);
		}
		x = _getch();
		system("cls");
		if (x == '\b' && i > 0) {
			i--;
			s[i] = '\0';
			continue;
		}
		if (x == '/' || x == '\\' || x == ':' || x == '*' || x == '?' || x == '>' || x == '<' || x == '|') {
			continue;
		}
		if (x == '\r') {
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
		int numOfWord{};
		unsigned char x{};
		while (i < size - 1)
		{
			printf("ФИО: ");
			for (int j = 0; j < i; j++) {
				printf("%c", s[j]);
			}
			x = _getch();
			system("cls");
			if (x == ' ') {
				if (s[i - 1] == ' ') {
					continue;
				}
				numOfWord++;
				if (numOfWord > 2) {
					printf("\nВсего должно быть 3 слова!!!\n\n");
					system("pause");
					system("cls");
					continue;
				}
				s[i] = x;
				i++;
			}
			if (x == '\b' && i > 0) {
				if (s[i - 1] == ' ') {
					s[--i] = '\0';
					numOfWord--;
					continue;
				}
				s[--i] = '\0';
				continue;
			}
			if (x >= 192 && x <= 255) {
				s[i] = x;
				i++;
			}
			if (x == '\r') {
				break;
			}
		}
		if (numOfWord < 2)
		{
			printf("\nСлов должно быть 3!!!\n");
			for (int j = 0; j < i; j++)
			{
				s[j] = '\0';
			}
			i = 0;
			system("pause");
			system("cls");
		}
		else
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

void linSearch(char* key)
{
	binF = fopen(File_Rec, "rb");
	Students s;
	bool identical = false;
	for(int i=1; fread(&s, sizeOfStruct, 1, binF); i++)
	{
		for(int i=0;key[i] && s.FIO[i];i++)
		{
			if(key[i] == s.FIO[i])
			{
				identical = true;
			}else
			{
				identical = false;
				break;
			}
		}
		if(identical)
		{
			printf("\n%d. %s - %s, Группа: %d; Физика: %d, Математика: "
				"% d, Информатика: % d, Химия : % d, Средний балл : % 1.2lf", i, s.FIO, s.address, s.num_group, 
				s.marks[0], s.marks[1], s.marks[2], s.marks[3], s.s_mark);
		}
	}
	fclose(binF);
}


void sortLin()
{
	binF = fopen(File_Rec, "rb");
	Students* stud;
	int kol = _filelength(_fileno(binF)) / sizeOfStruct;
	stud = new Students[kol];
	fread(stud, sizeOfStruct, kol, binF);
	fclose(binF);
	for (int i = 0; i < kol - 1; i++)
	{
		int m = i;
		for (int j = i + 1; j < kol; j++)
		{
			for (int l = 0; stud[i].FIO[l] && stud[j].FIO[l]; l++)
			{
				if (stud[i].FIO[l] > stud[j].FIO[l])
				{
					m = j;
				}
				if (stud[i].FIO[l] == stud[j].FIO[l])
				{
					continue;
				}
				break;
			}
		}
		Students r = stud[m];
		stud[m] = stud[i];
		stud[i] = r;
	}
	
	save(stud, kol);
	delete[] stud;
}

bool strBig(char* first, char* second)
{
	bool big = false;
	for(first, second; *first && *second; first += 1, second += 1) {
		if(*first > *second) {
			big = true;
		}else if(*first == *second) {
			continue;
		}
		else big = false;
		break;
	}
	if(*first && !(*second)) {
		big = true;
	}
	if((!*first) && *second) {
		big = false;
	}
	return big;
}

bool strLess(char* first, char* second)
{
	bool less = false;
	for (first, second; *first && *second; first += 1, second += 1) 
	{
		if (*first < *second) 
		{
			less = true;
		}else if(*first == *second) {
			continue;
		}else less = false;
		break;
	}
	if (*first && !(*second)) 
	{
		less = false;
	}
	if((!*first) && *second) {
		less = true;
	}
	return less;
}

void quickSort(Students* a,int left, int right)
{
	if(left >= right) {
		// Если в массиве меньше двух элементов или уже отсортирован, выходим из функции
		return;
	}
	int i = left;
	int j = right;
	char* x = a[(right+left) / 2].FIO;

	while(i <= j) {

		while(strLess(a[i].FIO, x)) {
			i++;
		}

		while(strBig(a[j].FIO, x)){
			j--;
		}

		if (i <= j) {
			Students r = a[i];
			a[i] = a[j];
			a[j] = r;
			i++;
			j--;
		}
	}
	quickSort(a, left, j);
	quickSort(a, i, right);
}

void howSort() 
{
	system("cls");
	printf("Выберите сортировку: 1.Метод прямого выбора  2.quickSort\nВыбирайте:");
	switch(check()) {
	case 1:
		sortLin();
		printf("Файл отсортирован!!!!1!!1\n");
		system("pause");
		break;
	case 2:
		binF = fopen(File_Rec, "rb");
		Students* a;
		int kol = _filelength(_fileno(binF)) / sizeOfStruct;
		a = new Students[kol];
		fread(a, sizeOfStruct, kol, binF);
		fclose(binF);
		quickSort(a, 0, kol - 1);
		save(a, kol);
		delete[] a;
		printf("Файл отсортирован!!!!1!!1\n");
		system("pause");
		break;
	}
}

void createFile()
{
	binF = fopen(File_Rec, "wb");
	printf("\nФайл создан!\n");
	fclose(binF);
}

bool view() {
	binF = fopen(File_Rec, "rb");
	txtF = fopen(File_Rez, "wb");
	if (!binF)
		return false;
	Students student;

	printf("\n\t--------------- Информация ---------------\n");
	fprintf(txtF, "\n\n\n\t---------------  Информация ---------------\n");


	for (int i = 1; fread(&student, sizeOfStruct, 1, binF); i++)
	{
		out(student, txtF, i);
	}
	printf("\n\n");
	fclose(binF);
	fclose(txtF);
	return true;
}

void out(Students& s, FILE* Potochek, int i = 0)
{
	printf("\n%d. %s - %s, Группа: %d; Физика: %d, Математика: %d, Информатика: %d, Химия: %d, Средний балл: %1.2lf", i, s.FIO, s.address, s.num_group, s.marks[0], s.marks[1], s.marks[2], s.marks[3], s.s_mark);
	fprintf(Potochek, "\n%s - %s, Группа: %d; Физика: %d, Математика: %d, Информатика: %d, Химия: %d, Средний балл: %1.2lf", s.FIO, s.address, s.num_group, s.marks[0], s.marks[1], s.marks[2], s.marks[3], s.s_mark);
}

Students createStud(Students student) {
	zapisName(student.FIO, sizeof(student.FIO));

	rewind(stdin);
	printf("\nАдресс: ");
	gets_s(student.address);

	printf("Номер группы: ");
	student.num_group = check();
	printf("Введите оценки по предметам:");
	while(1) {
		printf("\nФизика: ");
		student.marks[0] = check();
		if(student.marks[0] >= 0 && student.marks[0] <= 10) break;
		printf("Некорректный ввод...");
	}
	while(1) {
		printf("Математика: ");
		student.marks[1] = check();
		if(student.marks[1] >= 0 && student.marks[1] <= 10) break;
		printf("Некорректный ввод...\n");
	}
	while(1) {
		printf("Информатика: ");
		student.marks[2] = check();
		if(student.marks[2] >= 0 && student.marks[2] <= 10) break;
		printf("Некорректный ввод...\n");
	}
	while(1) {
		printf("Химия: ");
		student.marks[3] = check();
		if(student.marks[3] >= 0 && student.marks[3] <= 10) break;
		printf("Некорректный ввод...\n");
	}
	student.s_mark = (double)(student.marks[0] + student.marks[1] + student.marks[2] + student.marks[3]) / 4;
	return student;
}

void add()
{
	system("cls");
	Students student{};
	student = createStud(student);
	printf("Средний балл: %.2lf", student.s_mark);
	printf("\n");
	binF = fopen(File_Rec, "ab");
	fwrite(&student, sizeOfStruct, 1, binF);
	fclose(binF);
}

void save(Students* st, int num) {
	binF = fopen(File_Rec, "wb");
	fwrite(st, sizeOfStruct, num, binF);
	fclose(binF);
}

void edit(int edit_number) {
	Students* st, newStudent{};
	newStudent = createStud(newStudent);
	printf("Средний балл: %lf", newStudent.s_mark);

	binF = fopen(File_Rec, "rb");
	int descriptor, i, kol, len;
	descriptor = _fileno(binF);
	len = _filelength(descriptor);
	kol = len / sizeOfStruct;
	st = new Students[kol];
	for (i = 0; i < kol; i++) {
		fread((st + i), sizeOfStruct, 1, binF);
	}
	fclose(binF);

	st[edit_number - 1] = newStudent;
	txtF = fopen(File_Rez, "wb");
	for (i = 0; i < kol; i++)
		out(st[i], txtF, i + 1);
	save(st, kol);
	fclose(txtF);
	delete[]st;
	printf("\n\n");
}

bool containsSubstr(char* arr, int size, const char* substring)
{
	for(int i = 0; i < size; i++) {
		char* str = arr;
		int j = 0;
		int k = 0;

		while(str[j] != '\0' && substring[k] != '\0') {
			if(str[j] == substring[k]) {
				j++;
				k++;
			}
			else {
				j++;
				k = 0;
			}
		}

		if(substring[k] == '\0') {
			return true;
		}
	}

	return false;
}

void individual()
{
	Students* studFromFile;
	int value, i = 1, numOfStud{};

	binF = fopen(File_Rec, "rb");
	value = _filelength(_fileno(binF)) / sizeOfStruct;
	studFromFile = new Students[value];

	fread(studFromFile, sizeOfStruct, value, binF);
	fclose(binF);
	char key[] = "г. Минск";
	bool ident = false;

	for(int i = 0; i < value; i++)
	{
		if (containsSubstr(studFromFile[i].address, value, key))
		{
			numOfStud++;
		}
	}

	Students* studWithGoodInfo = new Students[numOfStud];

	int GoodNum{};

	for (int i = 0; i < value; i++)
	{
		if (containsSubstr(studFromFile[i].address, value, key)) {
			studWithGoodInfo[GoodNum++] = studFromFile[i];
		}
	}

	quickSort(studWithGoodInfo, 0, GoodNum-1);

	for (int i = 0; i < numOfStud; i++)
	{
		printf("\n%d. %s - %s, Группа: %d; Физика: %d, Математика: %d, Информатика: %d, Химия: %d, Средний балл: %1.2lf", i, studWithGoodInfo[i].FIO, studWithGoodInfo[i].address, studWithGoodInfo[i].num_group, studWithGoodInfo[i].marks[0], studWithGoodInfo[i].marks[1], studWithGoodInfo[i].marks[2], studWithGoodInfo[i].marks[3], studWithGoodInfo[i].s_mark);
	}
	delete[] studWithGoodInfo;
}