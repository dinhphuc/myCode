#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<ctype.h>
#include <stdio.h>
#include <cstring>
#include <conio.h>
#include <stdlib.h>
#include "console.h"
#include "menu.h"
#include "struct.h"
#include "FixErr.h"
#include <datetimeapi.h>


void KhungExit()
{ 
	char c = 205;  //ống Ngang
	char d = 186;  // ống dọc
	char c1 = 201; // góc trái trên
	char c2 = 200; // góc trái dưới
	char c3 = 187; // góc phải trên 
	char c4 = 188; // góc phải dưới
	char c5 = 202; // Ống căm lên
	char c6 = 203; // ống cắm xuống

	gotoxy(0, 0);
	int i;
	textcolor(8);
	//Ống Bên Chiều Dài Trên t
	for (i = 55; i < 90; i++)
	{
		gotoxy(i, 15);
		printf("%c", c);

	}
	gotoxy(55, 15); printf("%c", c1);
	gotoxy(90, 15); printf("%c", c3);
	//Ống Bên Chiều Dài Dưới 
	for (i = 55; i < 90; i++)
	{
		gotoxy(i, 21);
		printf("%c", c);

	}
	gotoxy(55, 15); printf("%c", c1);
	gotoxy(90, 15); printf("%c", c3);
	/// Ống Bên Chiều rộng
	for (i = 16; i < 21; i++)
	{
		gotoxy(55, i);
		printf("%c", d);

	}
	for (i = 16; i < 21; i++)
	{
		gotoxy(90, i);
		printf("%c", d);
	}
	gotoxy(55, 21); printf("%c", c2);
	gotoxy(90, 21); printf("%c", c4);
}
void ChangeColor(int x)
{
	switch (x)
	{
	case 69:
		textcolor(14);
		gotoxy(69, 19);
		printf("yes");
		textcolor(7);
		gotoxy(75, 19);
		printf("No");
		break;
	case 75:
		textcolor(14);
		gotoxy(75, 19);
		printf("No");
		textcolor(7);
		gotoxy(69, 19);
		printf("yes");
		break;
	}
}
void checkExit(int *Err1)
{
	KhungExit();
	textcolor(15);
	HidePointer();
	gotoxy(64, 17); 
	printf("Do you want Exit ?");
	gotoxy(69, 19);
	printf("yes");
	gotoxy(73, 19); printf("|");
	textcolor(14);
	gotoxy(75, 19);
	printf("No");


	int x = 75;
	int Nhap=0;

	while (1)
	{
		fflush(stdin);
		Nhap = _getch();
		switch (Nhap)
		{
		case 77:
			x -= 6;
			break;
		case 75:
			x += 6;
			break;
		}
		if (Nhap == 13)
		{
			switch (x)
			{
			case 75:
				*Err1 = 1;
				break;
			case 69:
				*Err1 = -1;
				break;
			}
		}
		if ((x > 75)) x = 69;
		if ((x < 69)) x = 75;
		// Chuyển màu
		ChangeColor(x);
		if (Nhap == 13) break;
	}

}

void XoaCheckExit()
{
	
	HidePointer();
	for (int i = 15; i < 23; i++)
	{
		gotoxy(40, i);
		textcolor(256);
		printf("                                                     ");
		textcolor(7);
	}
	ShowPointer();

}
void NhapChuoi(char *s, int cot, int dong, int *Err)
{
	int Err1;
	gotoxy(cot, dong);
	do{
		if (_getch() == 27)
		{
			checkExit(&Err1);
			if (Err1 == -1)
			{
				*Err = -1;
				return;
			}
			else
			{
				XoaCheckExit();
			}
		}
		ShowPointer();
		gets(s);
		HidePointer();
	} while (strlen(s) == 0);

}
void ScanfChuoi(char *xau, int cot, int dong, int *Err)
{
	ShowPointer();
	gotoxy(cot, dong);
	char c; int i = 0,Err1;
	do
	{
		c = _getch();
		if (c == 27)
		{
			checkExit(&Err1);
			if (Err1 == -1)
			{
				*Err = -1;
				return;
			}
			else
			{
				XoaCheckExit();
				ShowPointer();
				gotoxy(cot + i, dong);
				textcolor(249);
			}
		}
		if (i  > 0 && c == 8)
		{
			printf("\b \b");
			i--;
			continue;
		}
		if (i >=0&&c != 27&&c!=8)
		{
			c = toupper(c);
			xau[i++] = c;
			printf("%c", c);
		}
	} while (c != 13);
	if (xau[i - 1] == ' ' || c == 13)
		i--;
	xau[i] = NULL;
	HidePointer();

}
void ScanfHoTen(char *xau, int cot, int dong, int *Err)
{
	ShowPointer();
	gotoxy(cot, dong);
	char c; int i = 0, Err1;
	do
	{
		c = _getch();
		if (c == 27)
		{
			checkExit(&Err1);
			if (Err1 == -1)
			{
				*Err = -1;
				return;
			}
			else
			{
				XoaCheckExit();	
				ShowPointer();
				gotoxy(cot + i, dong);
				textcolor(249);
			}
		}

		if (c == 8 && i > 0)
		{
			printf("\b \b");
			i--;
			continue;
		}
		if (c<=0)
			continue;
		if (i>0&&c == 32 && xau[i - 1] != ' ' && i != 0)
		{
			printf(" ");
			xau[i++] = c;
		}
		if (!isalpha(c))
			continue;
		if (i == 0 || xau[i - 1] == ' ')
			c = toupper(c);
		if (i != 0 && xau[i - 1] != ' ')
			c = tolower(c);
		xau[i++] = c;
		printf("%c", c);
	} while (c != 13);

	if (xau[i - 1] == ' ')
		i--;
	xau[i] = NULL;
	HidePointer();
}
void ScanfNgaySinh(char *xau, int cot, int dong, int *Err)
{
	ShowPointer();
	gotoxy(cot, dong);
	char c; int i = 0, Err1;
	do
	{
		fflush(stdin);
		c = _getch();
		if (c == 27)
		{
			checkExit(&Err1);
			if (Err1 == -1)
			{
				*Err = -1;
				return;
			}
			else
			{
				XoaCheckExit();
				ShowPointer();
				gotoxy(cot + i, dong);
				textcolor(249);
			}
		}

		if (c == 8 && i > 0)
		{

			printf("\b \b");
			i--;
			continue;
		}
		if (i>=0&&c >= '0'&&c <= '9')
		{
			/* Chuẩn Hóa Ngày */
			if (i == 0)
			{
				if (c >= '0'&&c <= '3')
				{
					xau[i++] = c;
					printf("%c", c);
					continue;
				}
				// Ngày 4-9 cho thêm số 0 phía trước
				if (c >= '4'&&c <= '9')
				{
					char a = '0';
					xau[i++] = a;
					printf("0");
					xau[i++] = c;
					printf("%c", c);
				}
			}
			if (i == 1)
			{
				//Nếu là ngày 3 thì cho nhập 0 và 1 ;
				if (xau[i - 1] == '3' && c >= '0'&&c <= '1')
				{
					xau[i++] = c;
					printf("%c", c);
					continue;
				}
				//Nếu là ngày 1 hoặc 2 thì cho nhập 0 - 9 ;
				if (((xau[i - 1] == '1') || (xau[i - 1] == '2')) && (c >= '0') && (c <= '9'))
				{
					xau[i++] = c;
					printf("%c", c);
				}
				//Nếu là ngày = 0  thì chỉ cho nhập 1 - 9 ;
				if ((xau[i - 1] == '0') && (c > '0') && (c <= '9'))
				{
					xau[i++] = c;
					printf("%c", c);
				}
			}

			// cho nhập năm
			if (i != 4 && i != 3 && i != 2 && i != 1)
			{
				if (i >= 0 && i < 10)
				{
					xau[i++] = c;
					printf("%c", c);
				}
				continue;
			}
			/* Chuẩn Hóa Tháng */
			if (i == 3)
			{
				if (c >= '0'&&c <= '1')
				{
					xau[i++] = c;
					printf("%c", c);
					continue;
				}
				//Thêm số 0 vào tháng 2-9
				if (c >= '2'&&c <= '9')
				{
					char a = '0';
					xau[i++] = a;
					printf("0");
					xau[i++] = c;
					printf("%c", c);
				}
			}
			if (i == 4)
			{
				// Nếu tháng 1 hoặc nhập 0 thì cho nhập 0 và 2
				if (xau[i - 1] == '1' && c >= '0'&&c <= '2')
				{
					xau[i++] = c;
					printf("%c", c);
				}
				// Nếu c 0 thì cho nhập 1 - 9
				if (xau[i - 1] == '0' && c > '0'&&c <= '9')
				{
					xau[i++] = c;
					printf("%c", c);
				}
			}
			// In ra dấu "/"
			if (i == 2 || i == 5)
			{
				char a = '/';
				xau[i++] = a;
				printf("/");
			}
		}
	} while (c != 13);
	if (xau[i - 1] == ' ')
		i--;
	xau[i] = NULL;
}


void TachNgay(char *xau, int *day, int *mount, int *year)
{
	Date Nhap;
	int x=0, j = 0, z = 0;
	for (int i = 0; i < strlen(xau); i++)
	{
		if (i == 0 || i == 1)
		{
			Nhap.day[x] = xau[i];
			x++;
			if (x == 2)*day = atoi(Nhap.day);
		}
		if (i == 3 || i == 4)
		{
			Nhap.month[j] = xau[i];
			j++;
			if (j == 2)*mount = atoi(Nhap.month);
		}
		if (i >= 6 && i <= 9)
		{
			Nhap.year[z] = xau[i];
			z++;
			if (z == 4) *year = atoi(Nhap.year);
		}
	}

}
int KT_Date(int &day, int &month, int &year)
{
	if (year < 0 || year >2017)
	{
		return 0;
	}
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	{
		switch (month)
		{
		case 1: case 3:	case 5: case 7:case 8: case 10: case 12:
		{
					break;
		}

		case 4: case 6: case 9: case 11:
		{
					if (day > 30)
					{
						return 0;
					}
					break;
		}
		case 2:
		{
				  if (day > 29)
				  {
					  return 0;
				  }
				  break;
		}		
		}
		return 1;

	}
	// Năm Không nhuận
	switch (month)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
	{break; }
	case 4: case 6: case 9: case 11:
	{
				if (day > 30)
				{
					return 0;
				}
				break;
	}
	case 2:
	{
			  if (day > 28)
			  {
				  return 0;
			  }
			  break;
	}
	}
	return 1;
}
