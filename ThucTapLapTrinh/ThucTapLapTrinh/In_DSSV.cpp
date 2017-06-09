#define _CRT_SECURE_NO_WARNINGS

#include "menu.h"
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "console.h"
#include "struct.h"
#include "menu.h"


#define  NULL 0
#define Console_Dai 120
#define Console_Rong 28

char c = 205;  //ống Ngang
char d = 186;  // ống dọc
char c1 = 201; // góc trái trên
char c2 = 200; // góc trái dưới
char c3 = 187; // góc phải trên 
char c4 = 188; // góc phải dưới
char c5 = 202; // Ống căm lên
char c6 = 203; // ống cắm xuống
char c7 = 206; // ống Dấu cộng

double size = sizeof(HoSo);
/*IN KHUNG Thống KÊ */
void Khung_PrintfTK_class()
{

	
	for (int i = 50; i < 100; i++)
	{
		gotoxy(i, 26);
		printf("%c", c);
	}
	for (int i = 5; i < 26; i++)
	{
		gotoxy(50, i);
		printf("%c", d);
	}
	for (int i = 5; i < 26; i++)
	{
		gotoxy(100, i);
		printf("%c", d);
	}

	for (int i = 5; i < 26; i++)
	{
		gotoxy(80, i);
		printf("%c", d);
	}
	for (int i = 50; i < 100; i++)
	{
		for (int j = 4; j < 26; j = j + 2)
		{
			gotoxy(i, j);
			printf("%c", c);
			gotoxy(80, j); printf("%c", c7);
			gotoxy(50, j); printf("%c", 204);
			gotoxy(100, j); printf("%c", 185);
		}
	}
	gotoxy(80, 4); printf("%c", c6);
	gotoxy(80, 26); printf("%c", c5);
   /// Các Góc
	gotoxy(100, 4); printf("%c", c3);
	gotoxy(100, 26); printf("%c", c4);
	gotoxy(50, 4); printf("%c", c1);
	gotoxy(50, 26); printf("%c", c2);
	// Menu
	gotoxy(85, 5); printf("So Luong");
	gotoxy(63, 5); printf("Ma Lop");

}
/*IN KHUNG */
void Ong_NganCach(int OY)
{

	// Ống Ngăn Cách {
	int i;
	for (i = 38; i < Console_Dai - 3; i++)
	{

		gotoxy(i, OY);
		printf("%c", c);
		if (i == 38)
		{
			gotoxy(i, OY);
			printf("%c", 204);

		}
		// Các ống cắm xuống
		else if (i == 44)
		{
			gotoxy(i, OY);
			printf("%c", c7);

		}
		else if (i == 57)
		{
			gotoxy(i, OY);
			printf("%c", c7);

		}
		else if (i == 68)
		{
			gotoxy(i, OY);
			printf("%c", c7);

		}

		else if (i == 90)
		{
			gotoxy(i, OY);
			printf("%c", c7);

		}
		else if (i == 107)
		{
			gotoxy(i, OY);
			printf("%c", c7);

		}
		else if (i == 116)
		{

			gotoxy(i, 0);
			printf("%c", 185);
			break;

		}
	}

}
void Ong_DaiDuoi(int ChieuDai_duoi_min)
{

	// Ống Chiều dài dưới
	int i;
	//ChieuDai_duoi_min ;
	for (i = 38; i <= Console_Dai - 3; i++)
	{
		gotoxy(i, ChieuDai_duoi_min);
		printf("%c", c);

		if (i == 38)
		{
			gotoxy(i, ChieuDai_duoi_min);
			printf("%c", c2);

		}
		else if (i == 44)
		{

			gotoxy(i, ChieuDai_duoi_min);
			printf("%c", c5);
		}
		if (i == 117)
		{
			gotoxy(i, ChieuDai_duoi_min);
			printf("%c", c4);
			break;
		}

		// Các ống cắm Lên
		if (i == 44)
		{
			gotoxy(i, ChieuDai_duoi_min);
			printf("%c", c5);

		}
		else if (i == 57)
		{
			gotoxy(i, ChieuDai_duoi_min);
			printf("%c", c5);

		}
		else if (i == 68)
		{
			gotoxy(i, ChieuDai_duoi_min);
			printf("%c", c5);

		}

		else if (i == 90)
		{
			gotoxy(i, ChieuDai_duoi_min);
			printf("%c", c5);

		}
		else if (i == 107)
		{
			gotoxy(i, ChieuDai_duoi_min);
			printf("%c", c5);

		}
	}



}
void Ong_ChieuRong(int Ong_RongMin)
{
	int i;
	Ong_RongMin += 7;
	for (i = 5; i < Ong_RongMin; i += 2)
	{
		gotoxy(117, i);
		printf("%c", d);

		gotoxy(38, i);
		printf("%c", d);

		gotoxy(44, i);
		printf("%c", d);

		gotoxy(57, i);
		printf("%c", d);

		gotoxy(68, i);
		printf("%c", d);

		gotoxy(90, i);
		printf("%c", d);

		gotoxy(107, i);
		printf("%c", d);
	}

}
void Khung_IN()
{
	// khung bên trong (khung con)

	gotoxy(0, 0);
	int i;
	//Ống Chiều dài trên
	for (i = 38; i < Console_Dai - 3; i++)
	{
		gotoxy(i, 4);
		printf("%c", c);

		if (i == 38)
		{
			gotoxy(i, 4);
			printf("%c", c1);

		}
		// Các ống cắm xuống
		else if (i == 44)
		{
			gotoxy(i, 4);
			printf("%c", c6);

		}
		else if (i == 57)
		{
			gotoxy(i, 4);
			printf("%c", c6);

		}
		else if (i == 68)
		{
			gotoxy(i, 4);
			printf("%c", c6);

		}

		else if (i == 90)
		{
			gotoxy(i, 4);
			printf("%c", c6);

		}
		else if (i == 107)
		{
			gotoxy(i, 4);
			printf("%c", c6);

		}
		else if (i == 116)
		{

			gotoxy(i, 0);
			printf("%c", c3);
			break;

		}
	}


	Ong_NganCach(6);

	gotoxy(69, 3);
	printf("Danh Sach Sinh Vien");

	gotoxy(40, 5);
	printf("STT");

	gotoxy(48, 5);
	printf("Ma Lop");

	gotoxy(61, 5);
	printf("Ma SV");

	gotoxy(75, 5);
	printf("Ho Va Ten");

	gotoxy(95, 5);
	printf("Ngay Sinh");

	gotoxy(109, 5);
	printf("Diem TB");



}
int TongSoSV()
{
	int TongSoSV = 0;
	HoSo SV;
	FILE *fp;
	fp = fopen("DSSV.kBz", "rb");
	if ((fp == NULL) || (fread(&SV, size, 1, fp) <= 0))
	{
		Khung_IN();
		gotoxy(40, 3);
		printf("Empty Data !!!!!!!!");
		Ong_ChieuRong(1);
		Ong_DaiDuoi(8);
		_getch();
		clrscr();
		return 0;
	}
	else
	{
		do{
			TongSoSV++;
		} while (fread(&SV, size, 1, fp) > 0);
	}
	return TongSoSV;
}
void input(char *NameFile, HoSo *Array,int  *j)
{
	FILE *fp;
	int a = 0;
	fp = fopen(NameFile, "rb");
	if ((fp == NULL) || (feof(fp)))
	{
		return;
	}
	else
	{
		int i = 0;
		do{
			fread(&Array[i], sizeof(HoSo), 1, fp);
			i++;
		} while (!feof(fp));
		*j = i-1;
	}
}
void UpdateFile(char *FileName, HoSo *Array, int n)
{
	FILE *fp;
	fp = fopen(FileName, "wb");
	for (int i = 0; i < n; i++){	
		fwrite(&Array[i], size, 1, fp);
	}
	fclose(fp);
}
void ChuyenMau(int x)
{
	// Đổi Màu Chữ
	switch (x)
	{
	case 70:
		textcolor(14);
		gotoxy(108, 28);
		printf("Next >>");
		textcolor(7);
		gotoxy(92, 28);
		printf(" << Preview");
		gotoxy(80, 28);
		printf("Delete");
		textcolor(7);
		gotoxy(43, 28);
		printf("Cancel");
		textcolor(7);
		gotoxy(57, 28);
		printf("Add");
		textcolor(7);
		gotoxy(68, 28);
		printf("Edit");
		break;
	case 85:
		textcolor(14);
		gotoxy(92, 28);
		printf(" << Preview");
		textcolor(7);
		gotoxy(108, 28);
		printf("Next >>");
		gotoxy(80, 28);
		printf("Delete");
		textcolor(7);
		gotoxy(43, 28);
		printf("Cancel");
		textcolor(7);
		gotoxy(57, 28);
		printf("Add");
		textcolor(7);
		gotoxy(68, 28);
		printf("Edit");
		break;
	case 100:
		textcolor(9);
		gotoxy(80, 28);
		printf("Delete");
		textcolor(7);
		gotoxy(108, 28);
		printf("Next >>");
		gotoxy(92, 28);
		printf(" << Preview");
		textcolor(7);
		gotoxy(43, 28);
		printf("Cancel");
		textcolor(7);
		gotoxy(57, 28);
		printf("Add");
		textcolor(7);
		gotoxy(68, 28);
		printf("Edit");
		break;
	case 115:
		textcolor(9);
		gotoxy(68, 28);
		printf("Edit");
		textcolor(7);
		gotoxy(108, 28);
		printf("Next >>");
		gotoxy(92, 28);
		printf(" << Preview");
		gotoxy(80, 28);
		printf("Delete");
		textcolor(7);
		gotoxy(43, 28);
		printf("Cancel");
		textcolor(7);
		gotoxy(57, 28);
		printf("Add");
		break;
	case 130:

		textcolor(9);
		gotoxy(57, 28);
		printf("Add");

		textcolor(7);
		gotoxy(108, 28);
		printf("Next >>");
		gotoxy(92, 28);
		printf(" << Preview");
		textcolor(7);
		gotoxy(43, 28);
		printf("Cancel");
		textcolor(7);
		gotoxy(80, 28);
		printf("Delete");
		textcolor(7);
		gotoxy(68, 28);
		printf("Edit");
		break;
	case 145:
		textcolor(12);
		gotoxy(43, 28);
		printf("Cancel");
		textcolor(7);
		gotoxy(108, 28);
		printf("Next >>");
		gotoxy(92, 28);
		printf(" << Preview");
		gotoxy(80, 28);
		printf("Delete");
		textcolor(7);
		gotoxy(57, 28);
		printf("Add");
		textcolor(7);
		gotoxy(68, 28);
		printf("Edit");

		break;
	}

}
void Menu_In_Down()
{
	gotoxy(80, 28);
	printf("Delete");
	gotoxy(43, 28);
	printf("Cancel");
	gotoxy(57, 28);
	printf("Add");
	gotoxy(68, 28);
	printf("Edit");
	textcolor(14);
	gotoxy(108, 28);
	printf("Next >>");
	textcolor(7);
	gotoxy(105, 28);
	printf("|");
	textcolor(7);
	gotoxy(92, 28);
	printf(" << Preview");
}

void OutPut(HoSo *Array, int n)
{
	HidePointer();

	if (TongSoSV() == 0)
	{
		return;
	}
	int SV_dlt, ToaDo, Err;;
	int Trang = 1;
	int Next = 0; // Qua Trang
	int TongSo_SV = n;
	int b = 7;
	int stt = 0;
	HoSo *SV = new (HoSo);
	int Ong_Rong = 0;
	int i;
	for (i = 0; i < TongSo_SV; i++)
	{

		gotoxy(39, 3);
		printf("Trang - %d >>", Trang);
		Khung_IN();
		Ong_NganCach(b - 1);
		textcolor(9);
		gotoxy(41, b);
		printf("%d", stt + 1);

		gotoxy(46, b);
		printf("%s", Array[i].MaLop);


		gotoxy(59, b);
		printf("%s", Array[i].MaSV);

		gotoxy(71, b);
		printf("%s", Array[i].Hoten);

		gotoxy(94, b);
		printf("%s", Array[i].NgaySinh);

		gotoxy(111, b);
		printf("%0.2f", Array[i].DiemTB);
		textcolor(7);
		b += 2;
		stt++;
		Ong_Rong += 2;


		Ong_ChieuRong(Ong_Rong);
		Ong_DaiDuoi(b - 1);

		gotoxy(100, 3);
		printf("Tong So (%d/%d)", stt, TongSo_SV);

		if (stt == (10 + Next))
		{
			Next += 10;
			// Menu In ở dưới
			Menu_In_Down();
			// Phần Bắt Phím //
			/* Phải là 77 Trái là  75*/
			int x = 70;
			int Nhap;

			while (1)
			{
				//_getch();
				Nhap = _getch();
				switch (Nhap)
				{
				case 77:
					x -= 15;
					break;
				case 75:

					x += 15;
					break;
				}
				if (Nhap == 13)
				{
					switch (x)
					{
					case 70: //next 
						clrscr();
						x += 10;
						Ong_Rong = 0;
						b = 7;
						gotoxy(39, 3);
						printf("Trang - %d >>", Trang);
						Menu_batPhim(6);
						Trang++;
						break;
					case 85: // Prevew
						if (Trang >= 2){
							clrscr();
							Next = (Trang - 2) * 10;
							Ong_Rong = 0;
							stt = (Trang - 2) * 10;
							b = 7;
							i = ((Trang - 2) * 10) - 1;
							Trang--;
							break;
						}
						else
						{
							clrscr();
							
							checkExit(&Err);
							{
								if (Err == -1)
								{
									return;
								}
								clrscr();
								OutPut(Array, n);
								return;
							}
						}
					case 100: // Delete
						ChuyenContro(Array, &ToaDo, Trang - 1);
						if (ToaDo == -1)
						{
							clrscr();
							OutPut(Array, n);
							return;
						}
						DeleteSV(Array, ToaDo, &SV_dlt);
						clrscr();
						UpdateFile("DSSV.kBz", Array, SV_dlt);
						OutPut(Array, SV_dlt);

						clrscr();
						return;
						break;
					case 115:// edit
						printf("hihi");
						break;
					case 130: // Thêm	
						clrscr();
						ThemMoi_Hs(Array);
						input("DSSV.kBz", Array, &n);
						clrscr();
						OutPut(Array, n);
						return;
						break;
					case 145: // Thoát 
						return;
						break;
					}
				}
				if ((x > 145)) x = 70;
				if ((x < 70)) x = 145;
				ChuyenMau(x);
				if (Nhap == 13) break;
			}
		}
		if ((stt == TongSo_SV))
		{
			gotoxy(100, 3);
			printf("Tong So (%d/%d)", stt, TongSo_SV);
			gotoxy(52, 3);
			textcolor(201);
			printf("[Het]");
			textcolor(15);
			Menu_In_Down();
			// Phần Bắt Phím //
			/* Phải là 77 Trái là  75*/
			int x = 70;
			int Nhap;
			while (1)
			{
				//_getch();
				Nhap = _getch();
				switch (Nhap)
				{
				case 77:
					x -= 15;
					break;
				case 75:
					x += 15;
					break;
				}
				if (Nhap == 13)
				{
					switch (x)
					{
					case 70:	//next 
						if (TongSo_SV == stt)
						{
							clrscr();
							
							checkExit(&Err);
							{
								if (Err == -1)
								{
									return;
								}
								clrscr();
								OutPut(Array, n);
								return;
							}
						}
					case 85: //lùi
						if (Trang >= 2)
						{
							clrscr();
							Next = (Trang - 2) * 10;
							Ong_Rong = 0;
							stt = (Trang - 2) * 10;
							b = 7;
							i = ((Trang - 2) * 10);
							Trang--;
							break;
						}
						return;
					case 100: // Delete
						ChuyenContro(Array, &ToaDo, Trang - 1);
						if (ToaDo == -1)
						{
							clrscr();
							OutPut(Array, n);
							return;
						}
						if (ToaDo > TongSo_SV)
						{
							gotoxy(70, 26);
							textcolor(192);
							printf("Do not exist");
							textcolor(15);
							_getch();
							clrscr();
							OutPut(Array, n);
							return;
						}
						DeleteSV(Array, ToaDo, &SV_dlt); 
						clrscr();
						UpdateFile("DSSV.kBz", Array, SV_dlt);
						OutPut(Array, SV_dlt);
						return;
						break;
					case 115:// edit
						printf("hihi");
						break;
					case 130: // Thêm	
						clrscr();
						ThemMoi_Hs(Array);
//						input(, Array);
						clrscr();
						OutPut(Array, n);
						return;
						break;
					case 145: // Thoát 
						return;
						break;
					}
				}
				if ((x > 145)) x = 70;
				if ((x < 70)) x = 145;
				ChuyenMau(x);
				if (Nhap == 13) break;
			}
		}
	}
}

void InFile(HoSo *Array)
{
	FILE *p;
	p = fopen("fileIn.txt", "w");
	fprintf(p, "%s", "\n");
	fprintf(p, "%-22s%-24s%-24s%-24s%-24s%-24s", "STT", "   MaLop", "  MaSV", "  HoVaTen", " NgaySinh", "DiemTB");
	fprintf(p, "%s", "\n\n");
	for (int i = 0; i < TongSoSV(); i++)
	{
		fprintf(p, "%-22d%-24s%-24s%-24s%-24s%-24.2f", i + 1, Array[i].MaLop, Array[i].MaSV, Array[i].Hoten, Array[i].NgaySinh, Array[i].DiemTB);
		fprintf(p, "%s", "\n");
	}
	fclose(p);
}
void DeleteSV(HoSo *Array, int ToaDo, int *n)
{
	for (int i = ToaDo - 1; i < TongSoSV(); i++)
	{
		Array[i] = Array[i + 1];
	}
	*n = TongSoSV() - 1;
}

