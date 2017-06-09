#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <Windows.h>
#include "console.h"
#include "menu.h"
#include "struct.h"
#include "SapXep.h"

void Menu()
{

	int a = 5;
	system("cls");
	pain();
	gotoxy(a + 6, 3);
	textcolor(252);
	printf("***MENU***");
	textcolor(7);
	//	textcolor(14);
	gotoxy(a, 5);
	printf("1. Them Moi Ho So");
	//
	gotoxy(a, 6);
	printf("2. In Danh Sach");
	gotoxy(a, 7);
	printf("3. Sap Xep");
	gotoxy(a, 8);
	printf("4. Tim Kiem");
	gotoxy(a, 9);
	printf("5. Thong Ke");
	gotoxy(a, 10);
	printf("6. Thoat");
	gotoxy(a, 5);
}
void Menu_batPhim(int Toado)
{
	int a = 5;
	//	XoaManHinh();
	//	pain();
	gotoxy(a + 6, 3);
	textcolor(415);
	printf("***MENU***");
	textcolor(7);
	gotoxy(a, 5);
	printf("1. Them Moi Ho So");
	gotoxy(a, 6);
	printf("2. In Danh Sach");
	gotoxy(a, 7);
	printf("3. Sap Xep");
	gotoxy(a, 8);
	printf("4. Tim Kiem");
	gotoxy(a, 9);
	printf("5. Thong Ke");
	gotoxy(a, 10);
	printf("6. Thoat");
	gotoxy(a, 5);

	switch (Toado)
	{
	case 5:
		textcolor(14);
		gotoxy(a, 5);
		printf("1. Them Moi Ho So");
		textcolor(7);
		break;
	case 6:
		textcolor(14);
		gotoxy(a, 6);
		printf("2. In Danh Sach");
		textcolor(7);
		break;
	case 7:

		textcolor(14);
		gotoxy(a, 7);
		printf("3. Sap Xep");
		textcolor(7);
		break;
	case 8:
		textcolor(14);
		gotoxy(a, 8);
		printf("4. Tim Kiem");
		textcolor(7);
		break;
	case 9:
		textcolor(14);
		gotoxy(a, 9);
		printf("5. Thong Ke");
		textcolor(7);
		break;
	case 10:
		textcolor(12);
		gotoxy(a, 10);
		printf("6. Thoat");
		textcolor(7);
		break;
	}

}
void main()
{
	
	int n;
	HoSo Array[1000];
	input("DSSV.kBz", Array, &n);
	HidePointer();
	Menu();
	// Bắt Phím
	{
		int x = 0, y = 0, c;
		x = 5, y = 5;
		Menu_batPhim(5);
		while (1)
		{

			c = _getch();
			switch (c)
			{
			case 80:
				y++;
				break;
			case 72:
				y--;
				break;
			}
			if (c == 13)
			{
				switch (y)
				{

				case 5:
					ThemMoi_Hs(Array);
					clrscr();
					Menu();
					break;
				case 6:
					clrscr();
					input("DSSV.kBz", Array, &n);
					OutPut(Array, n);
					InFile(Array);
					Menu();
					break;
				case 7:
					MainSapxep();
					break;
				case 8:
					MainTimKiem(Array, n);
					break;
				case 9:
					input("DSSV.kBz", Array, &n);
					Main_ThongKe(Array, "DSSV.kBz", n);
					break;
				case 10:
					int Err;
					checkExit(&Err);
					if (Err == -1)
					{

						END();
						_getch();
						return;
					}
					else
					{
						XoaCheckExit();
						HidePointer();
						break;
					}

				}
			}
			if (y > 10)	y = 5;
			if (y < 5) y = 10;
			Menu_batPhim(y);
			gotoxy(x, y);
		}
	}
}
/////////////////////////////////////////
void ChuyenContro(HoSo *Array, int *ToaDo, int Trang)
{
	int trangcuoi = TongSoSV() / 10 + 1;
	int x, y, c;
	x = 36, y = 7;
	gotoxy(x, y);
	printf("=>");
	int i = 0;
	while (1)
	{

		fflush(stdin);
		c = _getch();
		switch (c)
		{
		case 80:
			if (y == 25)
			{
				y += 3;
				gotoxy(x, y - 3);
				printf("  ");
				textcolor(12);
				gotoxy(43, 28);
				printf("Cancel");
			}
			else
			{
				y += 2;
				gotoxy(x, y - 2);
				printf("  ");
				textcolor(7);
				gotoxy(43, 28);
				printf("Cancel");
			}

			break;
		case 72:
			if (y == 28)
			{
				y -= 3;
				gotoxy(x, y + 3);
				printf("  ");
				textcolor(7);
				gotoxy(43, 28);
				printf("Cancel");
			}
			else
			{
				if (y == 7)
				{
					textcolor(12);
					gotoxy(43, 28);
					printf("Cancel");
				}
				y -= 2;
				gotoxy(x, y + 2);
				printf("  ");
			}
		}
		if (c == 13)
		{
			switch (y)
			{
			case 7:
				*ToaDo = (10 * Trang + 1);
				break;
			case 9:
				*ToaDo = (10 * Trang + 2);
				break;
			case 11:
				*ToaDo = (10 * Trang + 3);
				break;
			case 13:
				*ToaDo = (10 * Trang + 4);
				break;
			case 15:
				*ToaDo = (10 * Trang + 5);
				break;
			case 17:
				*ToaDo = (10 * Trang + 6);
				break;
			case 19:
				*ToaDo = (10 * Trang + 7);
				break;
			case 21:
				*ToaDo = (10 * Trang + 8);
				break;
			case 23:
				*ToaDo = (10 * Trang + 9);
				break;
			case 25:
				*ToaDo = (10 * Trang + 10);
				break;
			case 28:
				*ToaDo = -1;
				break;
			}
		}
		//// trang cuối n/10+1
		if (y > 28)	y = 7;
		if (y < 7) y = 28;
		gotoxy(x, y);
		printf("=>");
		if (c == 13) break;

	}
}