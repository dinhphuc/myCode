#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <Windows.h>

void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

// Hàm tô màu.
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}

// Hàm dịch chuyển con trỏ đến tọa độ x, y.
void gotoxy(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x - 1, y - 1 };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

// Hàm xóa màn hình.
void XoaManHinh()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}

void VEKHUNG()
{
	resizeConsole(800, 600);
	for (int i = 0; i < 80; i++)
	{
		gotoxy(i, 1);
		printf("%c", 3);

	}
	for (int i = 1; i < 45; i++)
	{
		gotoxy(1, i);
		printf("%c", 4);
	}
	for (int i = 1; i < 80; i++)
	{
		gotoxy(i, 45);
		printf("%c",4);

	}

	for (int i = 1; i < 45; i++)
	{
		gotoxy(79, i);
		printf("%c", 4);
	}
}

int main()
{
	FILE* F;
	F = fopen("V.txt", "r");
	int i = 2;
	while (!feof(F))
	{
		
		char a;
		fscanf(F, "%c", &a);
		if (!feof(F))
			printf("%c", a);
	}
	fclose(F);

	_getch();
	return 0;
}