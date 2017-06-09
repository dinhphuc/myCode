#include "menu.h"
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include "console.h"
#include "struct.h"
#include "menu.h"


void Swap_change(HoSo &Hs1, HoSo &Hs2)
{
	HoSo HsTemp;
	HsTemp = Hs1;
	Hs1 = Hs2;
	Hs2 = HsTemp;

}
int SoSanhChuoi(char *s1, char *s2)
{
	int x, y, size;
	x = strlen(s1);
	y = strlen(s2);

	(x >= y) ? (size = x) : (size = y);

	for (int i = 0; i < size; i++)
	{
		if (s1[i]>s2[i])
		{
			return 1;
		}
		if (s1[i] < s2[i])
		{
			return -1;
		}
	}
	if (x > y)
	{
		return 1;
	}
	if (x < y)
	{
		return -1;
	}
	return 0;
}
// SX Mã Lớp 
void SX_Chon_MaLop(HoSo *Array, int n)
{
	if (TongSoSV() == 0)
	{
		return;
	}
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (SoSanhChuoi(Array[i].MaLop, Array[j].MaLop) == 1)
			{
				Swap_change(Array[i], Array[j]);
			}
		}
	}
	return;
}
void SX_Chen_MaLop(HoSo  *Array, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = i; j >0; j--)
		{
			if (SoSanhChuoi(Array[j].MaLop, Array[j - 1].MaLop) == -1)
			{
				Swap_change(Array[j], Array[j - 1]);
			}
		}

	}
	return;
}
void SX_NoiBot_MaLop(HoSo  *Array, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (SoSanhChuoi(Array[j].MaLop, Array[j + 1].MaLop) == 1)
			{
				Swap_change(Array[j], Array[j + 1]);
			}
		}

	}
	return;

}
void SX_QuickSort_MaLop(HoSo  *Array, int left, int right)
{
	HoSo hoso_tg;
	int i = left;
	int j = right;
	int tg = int(left + right) / 2;
	hoso_tg = Array[tg];

	while (i <= j)
	{
		while (SoSanhChuoi(Array[i].MaLop, hoso_tg.MaLop) == -1 && i <= right)
		{
			i++;
		}
		while (SoSanhChuoi(Array[j].MaLop, hoso_tg.MaLop) == 1 && j >= left)
		{
			j--;
		}

		if (i <= j)
		{
			Swap_change(Array[i], Array[j]);
			i++;
			j--;
		}
	}

	if (left < j)
	{
		SX_QuickSort_MaLop(Array, left, j);
	}
	if (i < right)
	{
		SX_QuickSort_MaLop(Array, i, right);
	}

	return;

}


// Sắp Xếp Mã SV
void SX_Chon_MaSV(HoSo  *Array, int n)
{
	if (TongSoSV == 0)
	{
		return;
	}
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (SoSanhChuoi(Array[i].MaSV, Array[j].MaSV) == 1)
			{
				Swap_change(Array[i], Array[j]);
			}
		}
	}
	return;
}
void SX_Chen_MaSV(HoSo  *Array, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = i; j >0; j--)
		{
			if (SoSanhChuoi(Array[j].MaSV, Array[j - 1].MaSV) == -1)
			{
				Swap_change(Array[j], Array[j - 1]);
			}
		}

	}
	return;
}
void SX_NoiBot_MaSV(HoSo  *Array, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (SoSanhChuoi(Array[j].MaSV, Array[j + 1].MaSV) == 1)
			{
				Swap_change(Array[j], Array[j + 1]);
			}
		}

	}
	return;

}
void SX_QuickSort_MaSV(HoSo  *Array, int left, int right)
{
	HoSo hoso_tg;
	int i = left;
	int j = right;
	int tg = int(left + right) / 2;
	hoso_tg = Array[tg];

	while (i <= j)
	{
		while (SoSanhChuoi(Array[i].MaSV, hoso_tg.MaSV) == -1 && i <= right)
		{
			i++;
		}
		while (SoSanhChuoi(Array[j].MaSV, hoso_tg.MaSV) == 1 && j >= left)
		{
			j--;
		}

		if (i <= j)
		{
			Swap_change(Array[i], Array[j]);
			i++;
			j--;
		}
	}

	if (left < j)
	{
		SX_QuickSort_MaSV(Array, left, j);
	}
	if (i < right)
	{
		SX_QuickSort_MaSV(Array, i, right);
	}

	return;

}



/*---------------------------------------------------------------------------*/
void Menu_sx_DoiMau1(int ToaDo)
{


	int a = 50;

	gotoxy(a, 7);
	printf("Sap Xep Chon");
	gotoxy(a, 9);
	printf("Sap Xep Chen");
	gotoxy(a, 11);
	printf("Sap Xep Noi Bot");
	gotoxy(a, 13);
	printf("Sap Xep Nhanh");
	gotoxy(a + 5, 15);
	printf("-Thoat-");
	//////////////////////////
	int i;
	for (i = 42; i < 73; i++)
	{
		gotoxy(i, 5);
		printf("%c", 178);

	}
	for (i = 6; i < 20; i++)
	{
		gotoxy(42, i);
		printf("%c", 178);

	}

	// dài dưới
	for (i = 42; i < 73; i++)
	{
		gotoxy(i, 19);
		printf("%c", 178);
	}

	// //RONG
	for (i = 6; i < 20; i++)
	{
		gotoxy(72, i);
		printf("%c", 178);
	}
	////////////////////////
	switch (ToaDo)
	{
	case 7:
		textcolor(14);
		gotoxy(a, 7);
		printf("Sap Xep Chon");
		textcolor(7);
		break;
	case 9:
		textcolor(14);
		gotoxy(a, 9);
		printf("Sap Xep Chen");;
		textcolor(7);
		break;
	case 11:
		textcolor(14);
		gotoxy(a, 11);
		printf("Sap Xep Noi Bot");
		textcolor(7);
		break;
	case 13:
		textcolor(14);
		gotoxy(a, 13);
		printf("Sap Xep Nhanh");
		textcolor(7);
		break;
	case 15:
		textcolor(12);
		gotoxy(a + 5, 15);
		printf("-Thoat-");
		textcolor(7);
		break;
	}
}
void Menu_sx_DoiMau2(char *s, int ToaDo)
{
	int a = 85;

	gotoxy(a, 7);
	printf("Sap Xep %s Theo Ma Lop", s);
	gotoxy(a, 9);
	printf("Sap Xep %s Theo Ma SV", s);
	gotoxy(a, 11);
	printf("Sap Xep %s Theo Ho Ten", s);
	gotoxy(a, 13);
	printf("Sap Xep %s Theo Ngay Sinh", s);
	gotoxy(a, 15);
	printf("Sap Xep %s Theo Diem TB", s);
	gotoxy(a + 5, 17);
	printf("-Thoat-");

	////////////////////////////////////////////////////////////////
	int slep = 10;
	int i;
	for (i = 80; i < 117; i++)
	{
		gotoxy(i, 5);
		printf("%c", 178);

	}
	for (i = 6; i < 20; i++)
	{
		gotoxy(80, i);
		printf("%c", 178);

	}

	// dài dưới
	for (i = 80; i < 117; i++)
	{
		gotoxy(i, 19);
		printf("%c", 178);
	}

	// //RONG
	for (i = 6; i < 20; i++)
	{
		gotoxy(116, i);
		printf("%c", 178);
	}
	///////////////////////////////////////////////////////////////

	switch (ToaDo)
	{
	case 7:
		textcolor(14);
		gotoxy(a, 7);
		printf("Sap Xep %s Theo Ma Lop", s);
		textcolor(7);
		break;
	case 9:
		textcolor(14);
		gotoxy(a, 9);
		printf("Sap Xep %s Theo Ma SV", s);
		textcolor(7);
		break;
	case 11:
		textcolor(14);
		gotoxy(a, 11);
		printf("Sap Xep %s Theo Ho Ten", s);
		textcolor(7);
		break;
	case 13:
		textcolor(14);
		gotoxy(a, 13);
		printf("Sap Xep %s Theo Ngay Sinh", s);
		textcolor(7);
		break;
	case 15:
		textcolor(14);
		gotoxy(a, 15);
		printf("Sap Xep %s Theo Diem TB", s);
		textcolor(7);
		break;
	case 17:
		textcolor(12);
		gotoxy(a + 5, 17);
		printf("-Thoat-");
		textcolor(7);
		break;
	}

}
void MenuConSX1(HoSo *Array, char *s, int z)
{

	{
		int n = TongSoSV();
		int x = 0, y = 0, c;
		x = 40, y = 7;
		Menu_batPhim(7);
		Menu_sx_DoiMau2(s, 7);
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
				case 7:
					/*Người Dùng Đang ấn vào Sắp xếp Ma Lop*/
					switch (z)
					{
					case 7:
						SX_Chon_MaLop(Array, n);
						break;
					case 9:
						SX_Chen_MaLop(Array, n);
						break;
					case 11:
						SX_NoiBot_MaLop(Array, n);
						break;
					case 13:
						///SX_QuickSort_MaLop(Array, n);
						break;
					}
					/*In ra sau khi sắp xếp*/
					clrscr();
					OutPut(Array, n);
					clrscr();
					Menu_sx_DoiMau1(z);
					break;
				case 9:
					/*Người Dùng Đang ấn vào Sắp xếp Ma SV*/
					switch (z)
					{
					case 7:
						SX_Chon_MaSV(Array, n);
						break;
					case 9:
						SX_Chen_MaSV(Array, n);
						break;
					case 11:
						SX_NoiBot_MaSV(Array, n);
						break;
					case 13:
						//						SX_QuickSort_MaSV(Array, n);
						break;
					}
					/*In ra sau khi sắp xếp*/
					clrscr();
					OutPut(Array, n);
					clrscr();
					Menu_sx_DoiMau1(z);
					break;
				case 11:
					/*Người Dùng Đang ấn vào Sắp xếp Hoten*/
					break;
				case 13:
					/*Người Dùng Đang ấn vào Sắp xếp Ngay Sinh*/
					break;
				case 15:
					/*Người Dùng Đang ấn vào Sắp xếp Diem TB*/
					break;
				case 17:
					clrscr();
					return;
					break;
				}
			}
			if (y > 17)	y = 7;
			if (y < 7) y = 17;
			Menu_sx_DoiMau2(s, y);
			gotoxy(x, y);
		}
	}
}

void MainSapxep()
{
	int n;
	HoSo Array[1000];
	input("DSSV.kBz", Array, &n);
	if (n==0)
	{
		return;
	}
		{
			int x = 0, y = 0, c;
			x = 40, y = 7;
			Menu_batPhim(7);
			Menu_sx_DoiMau1(7);
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
					case 7:
						MenuConSX1(Array, "Chon", y);
						break;
					case 9:
						MenuConSX1(Array, "Chen", y);
						break;
					case 11:
						MenuConSX1(Array, "Noi Bot", y);
						break;
					case 13:
						MenuConSX1(Array, "Nhanh", y);
						break;
					case 15:
						clrscr();
						pain();
						return;
						break;
					}
				}
				if (y > 15)	y = 7;
				if (y < 7) y = 15;
				Menu_sx_DoiMau1(y);
				gotoxy(x, y);
			}
		}

}
