#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)
static struct person
{
	char surname[40];
	char name[30];
	char otch[30];
	char adress[100];
	long int phone_num;
	int age;
};
typedef person data;
data* people;
static FILE* file;
static int initial_quantity;
//первоначальное количество людей в базе
int menu()
{
	setlocale(LC_ALL, "rus");
	printf("MЕНЮ\n");
	printf("1-сформировать файл\n2-распечатать данные\n3-добавить данные\n4-найти запись\n5-выйти из программы\n");
	int operation;
	scanf_s("%d", &operation);
	return operation;
}
void form()
{
	setlocale(LC_ALL, "rus");
	puts("Введите первоначальное количество людей в базе");
	scanf_s("%d", &initial_quantity);
	people = (data*)malloc(initial_quantity * sizeof(data));
	if (!(file = fopen("file3.txt", "wb")))
	{
		puts("Не удается сформировать файл для записи\n");
		exit(1);
	}
	else
	{
		for (int i = 0; i < initial_quantity; i++)
		{
			printf("Введите фамилию %d-го человека\n", i + 1);
			getchar();
			fgets(people[i].surname, 40, stdin);
			printf("Введите имя %d-го человека\n", i + 1);
			fgets(people[i].name, 30, stdin);
			printf("Введите отчество %d-го человека\n", i + 1);
			fgets(people[i].otch, 30, stdin);
			printf("Введите адрес %d-го человека\n", i + 1);
			fgets(people[i].adress, 100, stdin);
			printf("Введите номер телефона %d-го человека\n", i + 1);
			scanf_s("%d", &people[i].phone_num);
			printf("Введите возраст %d-го человека\n", i + 1);
			scanf_s("%d", &people[i].age);
			fwrite(&people[i], sizeof(people[i]), 1, file);
			printf("\n\n");
		}
	}
	fclose(file);
}
void print_data()
{
	setlocale(LC_ALL, "rus");
	if (!(file = fopen("file3.txt", "rb")))
	{
		puts("Не удалось открыть файл для чтения");
		exit(1);
	}
	data temp;
	// структурная переменная для чтения из файла 1 записи(структуры)
	int i = 0;
	while (i!=initial_quantity)
	{
		i++;
		fread(&temp, sizeof(data), 1, file);
		printf("Фамилия %d-го человека - %s", i, temp.surname);
		printf("Имя %d-го человека - %s", i, temp.name);
		printf("Отчество %d-го человека - %s", i, temp.otch);
		printf("Адрес %d-го человека - %s", i, temp.adress);
		printf("Номер телефона %d-го человека - %d\n", i, temp.phone_num);
		printf("Возраст %d-го человека - %d\n", i, temp.age);
		printf("\n\n");
	}
	fclose(file);
}
void add_data()
{
	setlocale(LC_ALL, "rus");
	printf("Введите количество записей, которые нужно добавить\n");
	int optional_quantity;
	// количество дополнительных записей
	scanf_s("%d", &optional_quantity);
	int temp = initial_quantity;
	initial_quantity += optional_quantity;
	// количество записей с уже добавленными
	people = (data*)realloc(people, initial_quantity * sizeof(data));
	if (!(file = fopen("file3.txt", "ab")))
	{
		puts("Не удается открыть файл для добавления записей\n");
		exit(1);
	}
	for (int i = temp; i < initial_quantity; i++)
	{
		printf("Введите фамилию %d-го человека\n", i + 1);
		getchar();
		fgets(people[i].surname, 40, stdin);
		printf("Введите имя %d-го человека\n", i + 1);
		fgets(people[i].name, 30, stdin);
		printf("Введите отчество %d-го человека\n", i + 1);
		fgets(people[i].otch, 30, stdin);
		printf("Введите адрес %d-го человека\n", i + 1);
		fgets(people[i].adress, 100, stdin);
		printf("Введите номер телефона %d-го человека\n", i + 1);
		scanf_s("%d", &people[i].phone_num);
		printf("Введите возраст %d-го человека\n", i + 1);
		scanf_s("%d", &people[i].age);
		fwrite(&people[i], sizeof(people[i]), 1, file);
		printf("\n\n");
	}
	fclose(file);
}
void find_data()
{
	setlocale(LC_ALL, "rus");
	puts("Введите фамилию для поиска записи");
	puts("Примечание: при присутствии в базе нескольких человек с одинаковой фамилией на экран выведутся данные первого человека");
	char get_surname[40];
	// переменная для получения фамилии, по которой необходимо найти запись
	getchar();
	fgets(get_surname, 40, stdin);
	if (!(file = fopen("file3.txt", "a+b")))
	{
		puts("Невозможно открыть файл для добавления");
		exit(1);
	}
	bool flag = false;
	data temp;
	while (!feof(file))
	{
		fread(&temp, sizeof(data), 1, file);
		if (strcmp(temp.surname, get_surname) == 0)
		{
			getchar();
			printf("Фамилия- %s", temp.surname);
			printf("Имя - %s", temp.name);
			printf("Отчество - %s", temp.otch);
			printf("Адрес - %s", temp.adress);
			printf("Номер телефона - %d\n", temp.phone_num);
			printf("Возраст - %d\n", temp.age);
			printf("\n\n");
			flag = true;
			break;
		}
	}
	if (!flag) printf("В списках нет людей с такой фамилией\n");
	fclose(file);
}