#define _CRT_SECURE_NO_WARNINGS
#include "console.h"
#include <Windows.h>
#include <stdio.h>
#include <conio.h>


#define Console_Dai 120
#define Console_Rong 28
#define SetConsoleTitle
// ẩn  con trỏ


//void setConsoleStatus() {
//	HWND hConsole;
//	LPCWSTR zz;
//	MENUITEMINFO mii;
//	SMALL_RECT windowSize = { 50, 50, 100, 100 };
//
//	SetConsoleWindowInfo(hConsole, TRUE, &windowSize);
//	char s[] = "QUAN LY SINH VIEN";
//	SetConsoleTitle(zz);
//
//	Sleep(10);
//
//	hConsole = FindWindow(NULL, zz);
//
//	HMENU hMenu = GetSystemMenu((HWND)hConsole, FALSE);
//
//
//
//	mii.fState = MFS_GRAYED;
//
//	EnableMenuItem(hMenu, 4, MF_DISABLED);
//
//	SetMenuItemInfo(hMenu, 4, MF_BYPOSITION, &mii);
//
//
//
//	DeleteMenu(hMenu, 1, MF_BYPOSITION); // disable 'Move'
//
//	DeleteMenu(hMenu, 1, MF_BYPOSITION); // disable 'Size'
//
//
//	DeleteMenu(hMenu, 2, MF_BYPOSITION); // disable 'Maximize'
//
//	DeleteMenu( hMenu, 3, MF_BYPOSITION); // disable 'Close or X'
//
//
//}

void HidePointer()
{
	HANDLE hOut;
	CONSOLE_CURSOR_INFO ConCurInf;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = FALSE;
	SetConsoleCursorInfo(hOut, &ConCurInf);
}
// Hiện Con Trỏ
void ShowPointer()
{
	HANDLE hOut;
	CONSOLE_CURSOR_INFO ConCurInf;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = TRUE;
	SetConsoleCursorInfo(hOut, &ConCurInf);
}

// Hàm thay đổi kích cỡ của khung cmd.
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
void textbackground(WORD color) // màu nền
{

	HANDLE hconsolerOutput;
	hconsolerOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hconsolerOutput, &screen_buffer_info);
	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	color <<= 4;
	wAttributes &= 0xff0f;
	wAttributes |= color;
	SetConsoleTextAttribute(hconsolerOutput, wAttributes);

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

void pain()  // tạo khung chương trình
{
	textcolor(7);
	char c = 205;  //ống Ngang
	char d = 186;  // ống dọc
	char c1 = 201; // góc trái trên
	char c2 = 200; // góc trái dưới
	char c3 = 187; // góc phải trên 
	char c4 = 188; // góc phải dưới
	char c5 = 202; // Ống căm lên
	char c6 = 203; // ống cắm xuống
	char c7 = 206; // ống Dấu cộng

	gotoxy(0, 0);
	int i;

	//Ống Bên Chiều Dài Trên 
	for (i = 2; i < Console_Dai; i++)
	{
		gotoxy(i, 2);
		printf("%c", c);

	}
	gotoxy(1, 2); printf("%c", c1);
	gotoxy(120, 2); printf("%c", c3);
	gotoxy(35, 2); printf("%c", c6);

	textcolor(14);
	gotoxy(50, 1);
	printf("CHUONG TRINH QUAN LY HOC VIEN");
	textcolor(7);
	//Ống bên Chiều dài dưới
	for (i = 2; i <= Console_Dai; i++)
	{
		gotoxy(i, 30);
		printf("%c", c);

		if (i == 35)
		{
			gotoxy(i, 30);
			printf("%c", c5);

		}
		else if (i == 120)
		{
			gotoxy(1, 30);
			printf("%c", c2);
			//break;
		}
		if (i == 120)
		{
			gotoxy(i, 30);
			printf("%c", c4);
			break;

		}

	}
	// Ống Bên Chiều rộng
	for (i = 3; i < Console_Rong + 2; i++)
	{
		gotoxy(1, i);
		printf("%c", 178);

	}

	for (i = 3; i < Console_Rong + 2; i++)
	{
		gotoxy(120, i);
		printf("%c", 178);
	}


	// Ống Giữa
	for (i = 3; i < Console_Rong + 2; i++)
	{
		gotoxy(35, i);
		printf("%c", d);
	}
	gotoxy(1, 1);
}

void GioiThieu()
{
	// Ve Khung Gioi Thieu

	char c = 205;  //ống Ngang
	char d = 186;  // ống dọc
	char c1 = 201; // góc trái trên
	char c2 = 200; // góc trái dưới
	char c3 = 187; // góc phải trên 
	char c4 = 188; // góc phải dưới
	char c5 = 202; // Ống căm lên
	char c6 = 203; // ống cắm xuống
	char c7 = 206; // ống Dấu cộng

	gotoxy(0, 0);
	int i;
	int slep = 20;


	//	slep = 0;

	textbackground(0);
	//dài trên
	for (i = 0; i < Console_Dai - 2; i++)
	{

		if (i == 0)
		{
			gotoxy(i, 0);
			printf("%c", c1);

		}

		gotoxy(i, 0);
		printf("%c", c);
		if (i == 117)
		{
			gotoxy(i, 0);
			printf("%c", c3);
			break;

		}


	}

	// dài dưới
	for (i = 0; i <= Console_Dai; i++)
	{
		gotoxy(i, 30);
		printf("%c", c);


		if (i == 120)
		{
			gotoxy(1, 30);
			printf("%c", c2);
			//break;
		}
		if (i == 120)
		{
			gotoxy(i, 30);
			printf("%c", c4);
			break;

		}

	}
	// RONG
	for (i = 2; i < Console_Rong + 2; i++)
	{
		gotoxy(1, i);
		printf("%c", d);

	}

	for (i = 2; i < Console_Rong + 2; i++)
	{
		gotoxy(120, i);
		printf("%c", d);
	}


	gotoxy(1, 1);
	//// IN LOGO 
	//{
	//	FILE* F;
	//	F = fopen("LOGO.txt", "r");
	//	while (!feof(F))
	//	{

	//		char a;
	//		fscanf(F, "%c", &a);
	//		if (!feof(F))
	//			printf("%c", a);
	//	}
	//	fclose(F);
	//}



	//
	////////////
	char s1[] = "THUC TAP KI THUAT LAP TRINH";

	int a = (Console_Dai - 2 - strlen(s1)) / 2;

	textcolor(14);

	gotoxy(a, 4);
	for (int i = 0; i < strlen(s1); i++)
	{

		printf("%c", s1[i]);
		Sleep(slep);

	}

	textcolor(7);
	gotoxy(a - 10, 6);
	printf("**************************************************");
	char s2[] = "Full Name :	  NGO DINH PHUC";
	char s3[] = "Class:	  KTPM-K14";
	char s4[] = "Student code:  15150178";
	textcolor(7);

	/*if (_kbhit())
	{
	slep = 0;
	}*/
	//Khung Giới Thiệu
	//dài trên
	//
	//gotoxy(50, 13);
	
	//
	for (i = 39; i < 80; i++)
	{
		gotoxy(i, 12);
		printf("%c", 178);
		Sleep(slep);

	}
	for (i = 13; i < 21; i++)
	{
		gotoxy(39, i);
		printf("%c", 178);
		
		gotoxy(40, i);
		printf("%c", 178);
		Sleep(slep);

	}

	// dài dưới
	for (i = 39; i < 80; i++)
	{
		gotoxy(i, 20);
		printf("%c", 178);

		Sleep(slep);
	}
	
	// //RONG
	for (i = 12; i < 21; i++)
	{
		gotoxy(79, i);
		printf("%c", 178);
		
		gotoxy(80, i);
		printf("%c", 178);
		Sleep(slep);
	}
	
	

	//
	//int z = (120 - strlen(s2)) / 2;
	textcolor(12);
	gotoxy(44, 15);
	for (int i = 0; i < strlen(s2); i++)
	{
		printf("%c", s2[i]);
		Sleep(100);
	}


	gotoxy(44, 16);
	for (int i = 0; (i < strlen(s3)); i++)
	{

		printf("%c", s3[i]);
		Sleep(slep);
	}

	gotoxy(44, 17);
	for (int i = 0; i < strlen(s4); i++)
	{
		printf("%c", s4[i]);
		Sleep(slep);
	}

	textcolor(7);

	gotoxy(43, 25);
	printf(">> Press any key to continue ........ >>");
	gotoxy(80, 25);
	textcolor(7);

}
void clrscr()
{
	for (int i = 3; i < 30; i++)
	{ 
		gotoxy(36, i);
		textcolor(256);
		printf("                                                                                    ");
		textcolor(7);
	}

}
void HuongDan()
{



}
void Save()
{
	char c = 205;  //ống Ngang
	char d = 186;  // ống dọc
	char c1 = 201; // góc trái trên
	char c2 = 200; // góc trái dưới
	char c3 = 187; // góc phải trên 
	char c4 = 188; // góc phải dưới
	char c5 = 202; // Ống căm lên
	char c6 = 203; // ống cắm xuống
	char c7 = 206; // ống Dấu cộng

	gotoxy(0, 0);
	int i;
	textcolor(244);
	//Ống Bên Chiều Dài Trên t
	for (i = 50; i < 100; i++)
	{
		gotoxy(i, 9);
		printf("%c", c);

	}
	gotoxy(1, 2); printf("%c", c1);
	gotoxy(120, 2); printf("%c", c3);
	//Ống Bên Chiều Dài Dưới 
	for (i = 51; i < 100; i++)
	{
		gotoxy(i, 15);
		printf("%c", c);

	}
	gotoxy(50, 9); printf("%c", c1);
	gotoxy(100, 9); printf("%c", c3);
	/// Ống Bên Chiều rộng
	for (i = 10; i < 15; i++)
	{
		gotoxy(50, i);
		printf("%c", d);

	}
	for (i = 10; i < 15; i++)
	{
		gotoxy(100, i);
		printf("%c", d);
	}
	gotoxy(50, 15); printf("%c", c2);
	gotoxy(100, 15); printf("%c", c4);

	/*********** Bên Trong*************/

	gotoxy(66, 10); printf("Them Vao Danh Sach");
	/********YES*******/
	for (i = 54; i < 62; i++)
	{
		gotoxy(i, 12);
		printf("%c", c);
	}
	gotoxy(54, 12); printf("%c", c1);
	gotoxy(62, 12); printf("%c", c3);

	gotoxy(54, 13);
	printf("%c  YES  %c", d, d);

	for (i = 54; i < 62; i++)
	{
		gotoxy(i, 14);
		printf("%c", c);
	}
	gotoxy(54, 14); printf("%c", c2);
	gotoxy(62, 14); printf("%c", c4);


	/********NO*******/
	gotoxy(88, 12);
	for (i = 88; i < 96; i++)
	{
		gotoxy(i, 12);
		printf("%c", c);
	}
	gotoxy(88, 12); printf("%c", c1);
	gotoxy(96, 12); printf("%c", c3);

	gotoxy(88, 13); printf("%c  NO   %c", d, d);

	for (i = 88; i < 96; i++)
	{
		gotoxy(i, 14);
		printf("%c", c);
	}
	gotoxy(88, 14); printf("%c", c2);
	gotoxy(96, 14); printf("%c", c4);
	/*       màu nền   */
	gotoxy(51, 10); printf("               "); gotoxy(84, 10); printf("                ");
	gotoxy(51, 11); printf("                                                 ");
	gotoxy(51, 12); printf("   ");	gotoxy(63, 12); printf("                         ");	gotoxy(97, 12); printf("   ");
	gotoxy(51, 13); printf("   ");  gotoxy(63, 13); printf("                         ");	gotoxy(97, 13); printf("   ");
	gotoxy(51, 14); printf("   "); gotoxy(63, 14); printf("                         "); gotoxy(97, 14); printf("   ");



	textcolor(7);

}
void END()
{ 
	system("cls");
	gotoxy(60, 13);
	char s1[] = "END";
	for (int i = 0; i < 3; i++)
	{ 
		Sleep ( 200);
		printf("%c", s1[i]);
	}
	
}
