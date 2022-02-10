#include<stdio.h>
#include<locale.h>
#pragma warning(disable:4996)
int main()
{
	setlocale(LC_ALL, "rus");
	char string[100], mas[100];
	FILE* file1, * file2;
	int i, n;
	file1 = fopen("file1.txt.", "a+");
	if (!(file1 = fopen("file1.txt.", "a+"))) printf("Не удается открыть файл");
	printf("Введите кол-во строк,которые вы хотите ввести\n");
	scanf_s("%d", &n);
	getchar();
	for (i = 0; i < n; i++)
	{
		gets_s(string);
		fprintf(file1, "%s\n", string);
	}
	rewind(file1);
	if (!(file2 = fopen("file2.txt.", "w"))) printf("Не удается открыть файл для записи");
	for (i = 0; i < n; i++)
	{
		if (i % 2 == 0)
		{
			fgets(mas, 100, file1);
			fputs(mas, file2);
		}
		else fgets(mas, 100, file1);
	}
	fclose(file1);
	fclose(file2);
	return 0;

}