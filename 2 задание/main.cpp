#include<stdio.h>
#include<locale.h>
#include"Header.h"
#pragma warning(disable:4996)

int main()
{
	setlocale(LC_ALL, "rus");
	while (true)
	{
		switch (menu())
		{
		case 1: form(); break;
		case 2: print_data(); break;
		case 3: add_data(); break;
		case 4: find_data(); break;
		case 5: return 0; break;
		default: puts("Неверноое значение\n");
		}
	}
	return 0;
}
