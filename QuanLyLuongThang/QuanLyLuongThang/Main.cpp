#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
struct person
{
	int lever;
	char ht[25];
	int TimeWork;
};

long size = sizeof(person);

void Menu();
void TaoMoi()
{
	person cb;
	FILE *fp;
	int n = 0;
	fp = fopen("dscb.txt", "wb");
	while (true)
	{

		system("cls");
		printf("\nNguoi Thu %d\n\n", n + 1);
		printf("\nHo Ten: ");
		gets(cb.ht);
		fflush(stdin);
		if (cb.ht[0] == 0)
			break;
		printf("\nBac Luong: ");
		scanf_s("%d", &cb.lever);
		printf("\nNgay Cong: ");
		scanf_s("%d", &cb.TimeWork);
		++n;
		fwrite(&cb, size, 1, fp);
	}

	  fclose(fp);
	  Menu();
	
}

void INSERT()
{
	person cb;
	FILE *fp;
	long n;
	fp = fopen("dscb.txt", "ab");

	fseek(fp, 0, SEEK_END);


}
void EDIT(){}

void ViewData()
{
	person cb;
	FILE *fp;
	int i=0;
	if ((fp = fopen("dscb.txt", "r")) == NULL)
	{
		printf("\n\nEmpty Data");
	}
	else
	{ 
		system("cls");
		while (fread(&cb, size, 1, fp) > 0)
		{
			i++;
			printf("\n\nNguoi %d", i);
			printf("\nHo Ten: %s ", cb.ht);
			printf("\nBac Luong: %d ", cb.lever);
			printf("\nNgay Cong: %d ", cb.TimeWork);
		
		}
		fclose(fp);
		
		_getch();
	}

	Menu();
}
void END(){}
void Menu()
{

	int k;


	system("cls");
	printf("\n1.Creat New");
	printf("\n2.INSERT");
	printf("\n3.EDIT");
	printf("\n4.View Data");
	printf("\n5.END");

	k = _getch();
	switch (k)
	{
	case '1':
		TaoMoi();
		break;
	case '2':
		INSERT();
		break;
	case '3':
		EDIT();
		break;
	case '4':
		ViewData();
		break;
	case '5':
		END();
		break;

	}

}


void main()
{
	Menu();

	_getch();

}