#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <Windows.h>
#include "console.h"
#include "menu.h"

void NhiPhan_Malop();
void NhiPhan_MaSV();
void NhiPhan_HoTen();
void NhiPhan_NgaySinh();


////////////////////////////////////////////////////////////
void Menu_TK_DoiMau1(int ToaDo)
{
	int a = 45;
	//
	for (int i = 3; i < 30; i++)
	{
		gotoxy(75, i);
		printf("%c", 186);
	}
	char c5 = 202; // Ống căm lên
	char c6 = 203; // ống cắm xuống
	gotoxy(75, 2);
	printf("%c", 203);

	gotoxy(75, 30);
	printf("%c", 202);

	//
	
	gotoxy(a, 8);
	printf("Tim Kiem Tuan Tu");;
	gotoxy(a, 10);
	printf("Tim Kiem Nhi Phan");
	gotoxy(a+5, 12);
	printf("-Thoat-");
	
	switch (ToaDo)
	{

	case 8:
		textcolor(14);
		gotoxy(a, 8);
		printf("Tim Kiem Tuan Tu");;
		textcolor(7);
		break;
	case 10:
		textcolor(14);
		gotoxy(a, 10);
		printf("Tim Kiem Nhi Phan");
		textcolor(7);
		break;
	case 12:
		textcolor(12);
		gotoxy(a+5, 12);
		printf("-Thoat-");
		textcolor(7);
		break;
	}
}
void Menu_TK_DoiMau2(char s[], int ToaDo)
{
	int a = 85;

	gotoxy(a, 8);
	printf("Tim Kiem %s Theo Ma Lop", s);
	gotoxy(a, 10);
	printf("Tim Kiem %s Theo Ma SV", s);
	gotoxy(a, 12);
	printf("Tim Kiem %s Theo Ho Ten", s);
	gotoxy(a, 14);
	printf("Tim Kiem %s Theo Ngay Sinh", s);
	gotoxy(a, 16);
	printf("Tim Kiem %s Theo Diem TB", s);
	gotoxy(a + 5, 18);
	printf("-Thoat-");


	switch (ToaDo)
	{
	case 8:
		textcolor(14);
		gotoxy(a, 8);
		printf("Tim Kiem %s Theo Ma Lop", s);
		textcolor(7);
		break;
	case 10:
		textcolor(14);
		gotoxy(a, 10);
		printf("Tim Kiem %s Theo Ma SV", s);
		textcolor(7);
		break;
	case 12:
		textcolor(14);
		gotoxy(a, 12);
		printf("Tim Kiem %s Theo Ho Ten", s);
		textcolor(7);
		break;
	case 14:
		textcolor(14);
		gotoxy(a, 14);
		printf("Tim Kiem %s Theo Ngay Sinh", s);
		textcolor(7);
		break;
	case 16:
		textcolor(14);
		gotoxy(a, 16);
		printf("Tim Kiem %s Theo Diem TB", s);
		textcolor(7);
		break;
	case 18:
		textcolor(12);
		gotoxy(a + 5, 18);
		printf("-Thoat-");
		textcolor(7);
		break;
	}

}
void MenuConTK1(HoSo *Array, char s[], int z)
{
	{
		int n = TongSoSV();
		int x = 0, y = 0, c;
		x = 40, y = 8;
		Menu_batPhim(8);
		Menu_TK_DoiMau2(s, 8);
		while (1)
		{

			c = _getch();
			switch (c)
			{
			case 80:
				y += 2;
				break;
			case 72:
				y -= 2;
				break;
			}
			if (c == 13)
			{
				switch (y)
				{
				case 8:
					/*Người Dùng Đang ấn vào Tìm Kiếm Ma Lớp*/
					switch (z)
					{
					case 8:
					
						break;
					case 10:
					
						break;
					case 12:

						break;
					case 14:
						
						break;
					}
					/*In ra sau khi Tìm Kiếm*/
					clrscr();
					OutPut(Array, n);
					clrscr();
					Menu_TK_DoiMau1(z);
					break;
				case 10:
					/*Người Dùng Đang ấn vào Tìm Kiếm Ma SV*/
					switch (z)
					{
					case 8:
						
						break;
					case 10:
						
						break;
					case 12:
						
						break;
					case 14:
											
						break;
					}
					/*In ra sau khi Tìm Kiếm*/
					clrscr();
					OutPut(Array, n);
					clrscr();
					Menu_TK_DoiMau1(z);
					break;
				case 12:
					/*Người Dùng Đang ấn vào Sắp xếp Hoten*/
					break;
				case 14:
					/*Người Dùng Đang ấn vào Tìm Kiếm Ngay Sinh*/
					break;
				case 16:
					/*Người Dùng Đang ấn vào Tìm Kiếm Diem TB*/
					break;
				case 18:
					
					clrscr();
					pain();
					return;
					break;
				}
			}
			if (y > 18)	y = 8;
			if (y < 8) y = 18;
			Menu_TK_DoiMau2(s, y);
			gotoxy(x, y);
		}
	}
}
void MainTimKiem(HoSo  *Array, int n)
{
	HidePointer();
	if (TongSoSV() == 0)
	{
		return;
	}
	{
		int x = 0, y = 0, c;
		x = 40, y = 8;
		Menu_batPhim(8);
		Menu_TK_DoiMau1(8);
		while (1)
		{

			c = _getch();
			switch (c)
			{
			case 80:
				y += 2;
				break;
			case 72:
				y -= 2;
				break;
			}
			if (c == 13)
			{
				switch (y)
				{
				case 8:
					MenuConTK1(Array, "Tuan Tu", y);
					break;
				case 10:
					MenuConTK1(Array, "Nhi Phan", y);
					break;
				case 12:
					clrscr();
					pain();
					return;
					break;
				}
			}
			if (y > 12)	y = 8;
			if (y < 8) y = 12;
			Menu_TK_DoiMau1(y);
			gotoxy(x, y);
		}
	}

}


