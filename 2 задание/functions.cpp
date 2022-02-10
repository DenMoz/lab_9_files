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
//�������������� ���������� ����� � ����
int menu()
{
	setlocale(LC_ALL, "rus");
	printf("M���\n");
	printf("1-������������ ����\n2-����������� ������\n3-�������� ������\n4-����� ������\n5-����� �� ���������\n");
	int operation;
	scanf_s("%d", &operation);
	return operation;
}
void form()
{
	setlocale(LC_ALL, "rus");
	puts("������� �������������� ���������� ����� � ����");
	scanf_s("%d", &initial_quantity);
	people = (data*)malloc(initial_quantity * sizeof(data));
	if (!(file = fopen("file3.txt", "wb")))
	{
		puts("�� ������� ������������ ���� ��� ������\n");
		exit(1);
	}
	else
	{
		for (int i = 0; i < initial_quantity; i++)
		{
			printf("������� ������� %d-�� ��������\n", i + 1);
			getchar();
			fgets(people[i].surname, 40, stdin);
			printf("������� ��� %d-�� ��������\n", i + 1);
			fgets(people[i].name, 30, stdin);
			printf("������� �������� %d-�� ��������\n", i + 1);
			fgets(people[i].otch, 30, stdin);
			printf("������� ����� %d-�� ��������\n", i + 1);
			fgets(people[i].adress, 100, stdin);
			printf("������� ����� �������� %d-�� ��������\n", i + 1);
			scanf_s("%d", &people[i].phone_num);
			printf("������� ������� %d-�� ��������\n", i + 1);
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
		puts("�� ������� ������� ���� ��� ������");
		exit(1);
	}
	data temp;
	// ����������� ���������� ��� ������ �� ����� 1 ������(���������)
	int i = 0;
	while (i!=initial_quantity)
	{
		i++;
		fread(&temp, sizeof(data), 1, file);
		printf("������� %d-�� �������� - %s", i, temp.surname);
		printf("��� %d-�� �������� - %s", i, temp.name);
		printf("�������� %d-�� �������� - %s", i, temp.otch);
		printf("����� %d-�� �������� - %s", i, temp.adress);
		printf("����� �������� %d-�� �������� - %d\n", i, temp.phone_num);
		printf("������� %d-�� �������� - %d\n", i, temp.age);
		printf("\n\n");
	}
	fclose(file);
}
void add_data()
{
	setlocale(LC_ALL, "rus");
	printf("������� ���������� �������, ������� ����� ��������\n");
	int optional_quantity;
	// ���������� �������������� �������
	scanf_s("%d", &optional_quantity);
	int temp = initial_quantity;
	initial_quantity += optional_quantity;
	// ���������� ������� � ��� ������������
	people = (data*)realloc(people, initial_quantity * sizeof(data));
	if (!(file = fopen("file3.txt", "ab")))
	{
		puts("�� ������� ������� ���� ��� ���������� �������\n");
		exit(1);
	}
	for (int i = temp; i < initial_quantity; i++)
	{
		printf("������� ������� %d-�� ��������\n", i + 1);
		getchar();
		fgets(people[i].surname, 40, stdin);
		printf("������� ��� %d-�� ��������\n", i + 1);
		fgets(people[i].name, 30, stdin);
		printf("������� �������� %d-�� ��������\n", i + 1);
		fgets(people[i].otch, 30, stdin);
		printf("������� ����� %d-�� ��������\n", i + 1);
		fgets(people[i].adress, 100, stdin);
		printf("������� ����� �������� %d-�� ��������\n", i + 1);
		scanf_s("%d", &people[i].phone_num);
		printf("������� ������� %d-�� ��������\n", i + 1);
		scanf_s("%d", &people[i].age);
		fwrite(&people[i], sizeof(people[i]), 1, file);
		printf("\n\n");
	}
	fclose(file);
}
void find_data()
{
	setlocale(LC_ALL, "rus");
	puts("������� ������� ��� ������ ������");
	puts("����������: ��� ����������� � ���� ���������� ������� � ���������� �������� �� ����� ��������� ������ ������� ��������");
	char get_surname[40];
	// ���������� ��� ��������� �������, �� ������� ���������� ����� ������
	getchar();
	fgets(get_surname, 40, stdin);
	if (!(file = fopen("file3.txt", "a+b")))
	{
		puts("���������� ������� ���� ��� ����������");
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
			printf("�������- %s", temp.surname);
			printf("��� - %s", temp.name);
			printf("�������� - %s", temp.otch);
			printf("����� - %s", temp.adress);
			printf("����� �������� - %d\n", temp.phone_num);
			printf("������� - %d\n", temp.age);
			printf("\n\n");
			flag = true;
			break;
		}
	}
	if (!flag) printf("� ������� ��� ����� � ����� ��������\n");
	fclose(file);
}