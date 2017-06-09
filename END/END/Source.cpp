#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <windows.h>
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}

void gotoxy(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x - 1, y - 1 };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

void Input()
{
	FILE *F;
	F = fopen("input.hihi", "r");
	if ((F) == NULL)
	{
		printf("\n\nFile Not exists");
		_getch();

		return;
	}
	else{

		while (!feof(F))
		{
			int temp;
			fscanf(F, "%c", &temp);
			if (!feof(F)){
				//Sleep(1);
				printf("%c", temp);

			}
		}
	}
	fclose(F);

}
void main()
{/*
 for (int i = 0; i < 1000; i++)
 {
 printf("%d\n", i);
 textcolor(i);

 }*/


	//textcolor(764);
	gotoxy(1, 5);
	Input();
	_getch();
}