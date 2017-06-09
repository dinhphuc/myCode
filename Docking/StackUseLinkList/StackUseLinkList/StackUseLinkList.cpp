#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#define MaxSize 100
void gotoxy(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x - 1, y - 1 };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

int stack[MaxSize];
struct Node
{
	int v;
	Node* Next;
};



void main()
{


	FILE *F;
	/*F = fopen("PhucBinz.txt", "w");
	fprintf(F, "Ngo Dinh Phuc 123");
	fclose(F);*/

	F = fopen("PhucBinz.txt", "r");
	gotoxy(20, 20);
	while (!feof(F))
	{
		char a;
		fscanf(F, "%c", &a);
		Sleep(100);
		if (!feof(F))
		printf("%c", a);

	}
	fclose(F);
	_getch();
}