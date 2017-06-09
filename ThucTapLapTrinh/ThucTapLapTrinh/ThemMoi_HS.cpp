#define _CRT_SECURE_NO_WARNINGS

#include "menu.h"
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include "console.h"
#include "struct.h"
#include "FixErr.h"

long size = sizeof(HoSo);
void Menu_ThemHS()
{
	int a = 50;
	/***************************************/
	/*Nhập Mã  Lớp*/
	textcolor(192);
	gotoxy(a, 5);
	printf("    Ma Lop:     ");

	gotoxy(a + 17, 5);
	textcolor(255);
	printf("                       ");

	/*Nhập Mã  SV*/
	gotoxy(a, 7);
	textcolor(192);
	printf("     MaSV:      ");

	gotoxy(a + 17, 7);
	textcolor(255);
	printf("                       ");

	/*Nhập Họ  Tên*/
	gotoxy(a, 9);
	textcolor(192);
	printf("  Ho va Ten:    ");

	gotoxy(a + 17, 9);
	textcolor(255);
	printf("                       ");

	/*Nhập Ngày Sinh*/
	gotoxy(a, 11);
	textcolor(192);
	printf("   Ngay Sinh:   ");

	gotoxy(a + 17, 11);
	textcolor(255);
	printf("                       ");

	/*Nhập Điểm TB*/
	gotoxy(a, 13);
	textcolor(192);
	printf("Diem Trung Binh:");
	gotoxy(a + 17, 13);
	textcolor(255);
	printf("                       ");
	textcolor(7);
	/**************************************/
}
void  ThemMoi_Hs(HoSo *Array)
{

	int Err, day=0, month=0, year=0, c, a = 50;;
	Date Nhap;
	HoSo SV;
	
	int Dem = 1;
	do{
		gotoxy(a + 30, 3);
		printf("(Ban Dang Nhap Thong Tin HoSo: %d)", Dem);
		Menu_ThemHS();
		gotoxy(a, 5);
		fflush(stdin);

		/*Nhập Mã  Lớp*/
		textcolor(192);
		printf("    Ma Lop:     ");
		do{
			textcolor(249);
			ScanfChuoi(SV.MaLop, a + 18, 5, &Err);
			if (Err == -1)
			{
				return;
			}
			if ((strlen(SV.MaLop) <= 0) || (strlen(SV.MaLop) > 15))
			{
				textcolor(14);
				gotoxy(a + 43, 5);
				printf("ERRO ! Empty ");
				gotoxy(a + 17, 5);
				textcolor(255);
				printf("                       ");
			}
		} while ((strlen(SV.MaLop) <= 0) || (strlen(SV.MaLop) > 15));

		textcolor(7);
		gotoxy(90, 5);
		printf("                             ");

		fflush(stdin);
		/*Nhập Mã  SV*/
		gotoxy(a, 7);
		textcolor(192);
		printf("     MaSV:     ");
		do
		{
			textcolor(249);
			ScanfChuoi(SV.MaSV, a + 18, 7, &Err);
			if (Err == -1)
			{
				return;
			}
			if (strlen(SV.MaSV) != 8)
			{
				gotoxy(93, 7);
				textcolor(14);
				printf("ERRO ! Enter 8 number ");
				gotoxy(a + 17, 7);
				textcolor(255);
				printf("                       ");
			}
		} while (strlen(SV.MaSV) != 8);
		textcolor(7);
		gotoxy(90, 7);
		printf("                             ");

		/*Nhập Họ Và Tên*/
		gotoxy(a, 9);
		textcolor(192);
		printf("  Ho va Ten:    ");
		do
		{
			textcolor(249);
			ScanfHoTen(SV.Hoten, a + 18, 9, &Err);
			if (Err == -1)
			{
				return;
			}
			if (strlen(SV.Hoten)<=0)
			{
				gotoxy(93, 9);
				textcolor(14);
				printf("ERRO ! Empty ");
				gotoxy(a + 17, 9);
				textcolor(255);
				printf("                       ");
			}
		} while (strlen(SV.Hoten) <= 0 );
		textcolor(7);
		gotoxy(90, 9);
		printf("                             ");
		textcolor(249);
		fflush(stdin);

		/*Nhập Ngày Sinh*/
		gotoxy(a, 11);
		textcolor(192);
		printf("   Ngay Sinh:   ");
		do{
			textcolor(249);
			gotoxy(a + 18, 11);
			ScanfNgaySinh(SV.NgaySinh, a + 18, 11, &Err);
			if (Err == -1)
			{
				return;
			}
			TachNgay(SV.NgaySinh, &day, &month, &year);
			if (KT_Date(day, month, year) == 0 || (strlen(SV.NgaySinh) != 10))
			{
				textcolor(14);
				gotoxy(a + 45, 11);
				printf("ERRO !");
				gotoxy(a + 17, 11);
				textcolor(255);
				printf("                       ");
			}
		} while ((KT_Date(day, month, year) == 0) || (strlen(SV.NgaySinh) != 10));
		textcolor(7);
		gotoxy(90, 11);
		printf("                             ");
		/*Nhập Điểm  TB*/
		gotoxy(a, 13);
		textcolor(192);
		printf("Diem Trung Binh:");
		gotoxy(a + 18, 13);
		do
		{
			textcolor(249);
			gotoxy(a + 18, 13);
			scanf("%f", &SV.DiemTB);
			if (SV.DiemTB > 10.0 || SV.DiemTB <0.0)
			{
				textcolor(14);
				gotoxy(a + 45, 13);
				printf("ERRO !");
				gotoxy(a + 17, 13);
				textcolor(255);
				printf("                       ");
			}
		} while (SV.DiemTB >10.0 || SV.DiemTB < 0.0);
		HidePointer();
		textcolor(7);
		gotoxy(a + 45, 13);
		printf("                  ");
		////////////////////////////////////////////////////////////////////
		FILE *fp;
		fp = fopen("DSSV.kBz", "a+b");
		fwrite(&SV, size, 1, fp);
		fclose(fp);
		///////////////////////////////////////////////////////////////////
		gotoxy(a, 15);
		HidePointer();
		printf("1.Nhap Tiep (Enter)\t2.Cancel(ESC)");
		c = _getch();
		clrscr();
		ShowPointer();
		textcolor(7);
		Dem++;
	} while (c == 13);
	HidePointer();
	//free(Array);
	int n;
	input("DSSV.kBz", Array, &n);
}