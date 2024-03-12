#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <conio.h>
#include <cstring>

#define MAX_STR_SIZE 100
#define TIME_STR_SIZE 6

struct TInf {
	int numOfFlight;
	char typeOfPlane[MAX_STR_SIZE];
	char key[MAX_STR_SIZE];
	char timeOfArrive[TIME_STR_SIZE];
};

struct Stack 
{
	TInf Inf;
	Stack* next;
};

void setTime(char* s, int size);
bool charcmp(char*, char*);
void setNameFile(char*, int);
int check();



class THash {
private:
	Stack** H;
	int sizeHash;
public:

	int hashFunction(char* key) {
		int sum = 0;
		for (key; *key != '\0' ; key++) {
			sum += *key;
		}
		return sum % sizeHash;
	}

	THash(int k)
	{
		sizeHash = k;
		H = new Stack * [sizeHash];
		for (int i = 0; i < sizeHash; i++) H[i] = NULL;
	}

	void add(TInf Inf)
	{
		Stack* p = new Stack;
		int i = hashFunction(Inf.key);
		p->next = H[i];
		p->Inf = Inf;
		H[i] = p;
	}
	
	void delKey(char* key)
	{
		int i = hashFunction(key);
		Stack* p = H[i], *prev = nullptr;
		if (p == nullptr) return;
		while (p) 
		{
			if (charcmp(p->Inf.key, key)) 
			{
				if (!prev) 
				{
					H[i] = p->next;
					delete p;
					return;
				}
				prev->next = p->next;
				delete p;
				return;
			}
			prev = p;
			p = p->next;
		}
		printf("С таким ключом нет элемента в Хеш-таблице");
	}

	void Read(char* key)
	{
		int i = hashFunction(key);
		Stack* p = H[i], * p1{};
		bool bl = false;
		if (p != NULL)
		{
			do {
				if (charcmp(p->Inf.key, key)) 
				{
					bl = true;
					printf("%d || %s || %s || %s\n", p->Inf.numOfFlight, p->Inf.typeOfPlane, p->Inf.key, p->Inf.timeOfArrive);
				}
				p1 = p;
				p = p->next;
			} while (p != NULL);
		}
		if (!bl) 
		{
			printf("С таким ключом нет элемента в Хеш-таблице");
		}
	}

	void Individual()
	{
		char* key = new char[MAX_STR_SIZE];
		int i;
		printf("Введите Пункт назначения информацио о рейсах которой хотите увидеть: ");
		char temp[MAX_STR_SIZE];
		scanf_s("%s", &temp, (unsigned int)sizeof(temp));
		strcpy(key, temp);
		int sum = 0;
		for (key; *key != '\0'; key++) {
			sum += *key;
		}
		i = hashFunction(temp);
		TInf tempSt[20]{};

		Stack* p = H[i], * p1{};
		int numInf = 0;
		bool bl = false;
		if (p != NULL) {
			do {
				if (charcmp(p->Inf.key, temp)) {
					bl = true;
					TInf tempInf{};
					strcpy(tempInf.key, p->Inf.key);
					tempInf.numOfFlight = p->Inf.numOfFlight;
					strcpy(tempInf.timeOfArrive, p->Inf.timeOfArrive);
					strcpy(tempInf.typeOfPlane, p->Inf.typeOfPlane);
					tempSt[numInf] = tempInf;
					numInf++;

				}
				p1 = p;
				p = p->next;
			} while (p != NULL);
		}
		if (!bl) {
			printf("С таким ключом нет элементов в Хеш-таблице");
			return;
		}
		int size=0;
		for (size; tempSt[size].numOfFlight!=0; size++);

		i = 0;
		int j = size - 1;
		char* x = tempSt[size / 2].timeOfArrive;
		int minutesOfX = ((x[0] - 48) * 10 + (x[1] - 48)) * 60 + (x[3] - 48) * 10 + (x[4] - 48);
		while (i <= j) {
			for(int l=0;tempSt[i].timeOfArrive[l] && x[l];l++) {
				int minutesOfI = ((tempSt[i].timeOfArrive[0] - 48) * 10 + (tempSt[i].timeOfArrive[1] - 48)) * 60 + (tempSt[i].timeOfArrive[3] - 48) * 10 + (tempSt[i].timeOfArrive[4] - 48);
				if (minutesOfI < minutesOfX)
				{
					i++;
				}
				if (minutesOfI == minutesOfX)
				{
					continue;
				}
				break;
			}
		
			for (int l = 0; tempSt[j].timeOfArrive[l] && x[l]; l++)
			{
				int minutesOfJ = ((tempSt[j].timeOfArrive[0] - 48) * 10 + (tempSt[j].timeOfArrive[1] - 48)) * 60 + (tempSt[j].timeOfArrive[3] - 48) * 10 + (tempSt[j].timeOfArrive[4] - 48);
				if (minutesOfJ > minutesOfX)
				{
					j--;
				}
				if (minutesOfJ == minutesOfX)
				{
					continue;
				}
				break;
			}
		
			if (i <= j) {
				TInf r = tempSt[i];
				tempSt[i] = tempSt[j];
				tempSt[j] = r;
				i++;
				j--;
			}
		}

		for (int i = 0; i < size; i++) 
		{
			printf("%d || %s || %s || %s\n", tempSt[i].numOfFlight, tempSt[i].typeOfPlane, tempSt[i].key, tempSt[i].timeOfArrive);
		}
	}

	~THash()
	{
		char File_Name[100];
		int razm = 0;
		
		setNameFile(File_Name, sizeof(File_Name));
		while (File_Name[razm])
		{
			razm++;
		}
		File_Name[razm] = '.';
		File_Name[++razm] = 'd';
		File_Name[++razm] = 'a';
		File_Name[++razm] = 't';
		File_Name[razm + 1] = '\0';

		FILE* Fl;
		if ((Fl = fopen(File_Name, "wb")) == NULL) {
			printf("File no created");
			return;
		}
		fclose(Fl);
		Fl = fopen(File_Name, "wb");
		for (int i = 0; i < sizeHash; i++) {
			while (H[i] != NULL) {
				fwrite(&H[i]->Inf, sizeof(TInf), 1, Fl);
				/*fprintf(Fl, "\n\n\n\t---------------  Информация ---------------\n");
				fprintf(Fl, "%d || %s || %s || %s\n", p->Inf.numOfFlight, p->Inf.typeOfPlane, p->Inf.key, p->Inf.timeOfArrive);*/
				H[i] = H[i]->next;
			}
		}
		fclose(Fl);
		delete H;
	}
};


void workHash(THash*);

int main() {
	system("chcp 1251>nul");
	THash* hash{};
	TInf* Inf = new TInf;
	char File_Name[MAX_STR_SIZE];
	FILE* binFile;
	int sizeHash{}, razm{};
	enum {NewHash=1,FromFileHash, Exit};
	while(true) {
		system("cls");
		printf("1.Новая хеш таблица\n2.Из файла\n3.Выйти\n");
		switch(check()) {
		case NewHash:
			workHash(hash);
			break;
		case FromFileHash:
			system("cls");
			razm = 0;
			system("dir *.dat /b");
			printf("\nВыберите файл: ");
			setNameFile(File_Name, sizeof(File_Name));
			while(File_Name[razm]) {
				razm++;
			}
			File_Name[razm] = '.';
			File_Name[++razm] = 'd';
			File_Name[++razm] = 'a';
			File_Name[++razm] = 't';
			File_Name[razm + 1] = '\0';
			binFile = fopen(File_Name, "rb");
			if(binFile == nullptr) {
				printf("Неверне имя файла!!1!!1");
				return 0;
			}
			printf("Введите размер Хеш-таблицы: ");
			hash = new THash(check());

			while(fread(Inf, sizeof(TInf), 1, binFile)) 
				hash->add(*Inf);
			workHash(hash);
			break;
		case Exit:
			return 0;
		}
	}
}

void workHash(THash* hash)
{
	system("cls");
	bool end = false;
	char key[MAX_STR_SIZE];

	enum { ExitHash, CreateHash, AddHash, DelKey, SearchKey, Indiv, DelHash };

	while(!end) {
		printf("\n1 - Создать\n2 - Добавить\n3 - Удалить элемент по ключу"
			"\n4 - Поиск в хеш - таблице по ключу\n5 - Индивидуальное задание\n6 - Удалить Хеш - таблицу\n0 - Выйти\n");
		printf("Выбирайте: ");
		switch(check()) {
		case CreateHash:
			system("cls");
			if(hash) {
				printf("Хеш-таблица уже создана!!");
				system("pause");
				break;
			}
			printf("Введите кол-во записей в таблице: ");
			hash = new THash(check());
			system("pause");
			break;
		case AddHash:
			system("cls");
			if(!hash) {
				printf("Хеш - таблица не создана");
				system("pause");
				break;
			}
			TInf Inf1;

			printf("Введите\nНомер рейса: ");
			Inf1.numOfFlight = check();
			printf("Тип самолёта: ");
			scanf_s("%s", &(Inf1.typeOfPlane), (unsigned int)sizeof(Inf1.typeOfPlane));
			printf("Пункт назначения: ");
			scanf_s("%s", &(Inf1.key), (unsigned int)sizeof(Inf1.key));
			printf("Время прибытия: ");
			setTime(Inf1.timeOfArrive, sizeof(Inf1.timeOfArrive));

			printf("Введите\nНомер рейса: %d\n", Inf1.numOfFlight);
			printf("Тип самолёта: %s\n", Inf1.typeOfPlane);
			printf("Пункт назначения: %s\n", Inf1.key);
			printf("Время прибытия: %s\n", Inf1.timeOfArrive);
			hash->add(Inf1);
			system("pause");
			break;
		case DelKey:
			system("cls");
			if(!hash) {
				printf("Хеш - таблица не создана");
				system("pause");
				break;
			}
			printf("Запишите Пункт назначения, элемент с которым вы хотите удалить: ");
			scanf_s("%s", &key, (unsigned int)sizeof(key));
			hash->delKey(key);
			system("pause");
			break;
		case SearchKey:
			system("cls");
			if(!hash) {
				printf("Хеш - таблица не создана");
				system("pause");
				break;
			}
			printf("Запишите Пункт назначения элемент с которым вы хотите просмотреть: ");
			scanf_s("%s", &key, (unsigned int)sizeof(key));
			hash->Read(key);
			system("pause");
			break;
		case Indiv:
			system("cls");
			hash->Individual();
			system("pause");
			break;
		case DelHash:
			system("cls");
			if(!hash) {
				printf("Хеш - таблица не создана");
				system("pause");
				break;
			}
			delete hash;
			hash = nullptr;
			printf("Хеш таблица удалена\n");
			system("pause");
			break;
		case ExitHash:
			end = true;
			break;
		default:
			system("cls");
			printf("Такова варианта нет!!1!1");
			system("pause");
		}
	}
}

void setNameFile(char* s, int size)
{
	int i{};
	char x{};
	while (i < size - 1) {
		printf_s("Введите имя файла куда хотите создать Хеш-таблицу: ");
		for (int j = 0; j < i; j++) {
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
		if (x == '\r')
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

void setTime(char* s, int size)
{
	system("cls");
	int i{};
	char x{};
	while (true) {
		i = 0;
		while (i < size - 1)
		{
			printf_s("Время прибытия: ");
			for (int j = 0; j < i; j++)
			{
				printf("%c", s[j]);
			}
			if (i == 2) {
				x = ':';
				s[i] = x;
				i++;
				system("cls");
				continue;
			}
			x = _getch();
			system("cls");
			if (x == '\b' && i > 0)
			{
				i--;
				s[i] = '\0';
				continue;
			}
			if (x< '0' || x > '9' && x != ':')
			{
				continue;
			}
			s[i] = x;
			i++;
		}

		if (((s[0] - 48) * 10 + (s[1] - 48)) > 23) {
			printf("Некорректно введено время\n");
			system("pause");
			continue;
		}

		if (((s[3] - 48) * 10 + (s[4] - 48)) > 59) {
			printf("Некорректно введено время\n");
			system("pause");
			continue;
		}
		break;
	}

	if (i == size - 1)
	{
		while (s[i - 1] == ' ')
		{
			i--;
		}
		s[i] = '\0';
		rewind(stdin);
		return;
	}
	s[i] = '\0';
}

bool charcmp(char* first, char* second) {
	bool same = false;
	for (first, second; *first && *second; first += 1, second += 1) 
	{
		if (*first == *second) 
		{
			same = true;
		}
		else {
			same = false;
		}
	}
	if (*first || *second) 
	{
		same = false;
	}
	return same;
}

int check() {
	int a = 0;
	while ((scanf_s("%d", &a), getchar()) != '\n') {
		printf("Неправильный ввод!\nВведите число:");
		rewind(stdin);
	}
	return a;
}