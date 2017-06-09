#include <stdio.h>
#include <conio.h>
#include <string.h>
#define N 100 
typedef struct SV
{
	char Hoten[30];
	char QueQuan[20];
	char GT[5];
	float Toan, ly, Hoa, DTB;

};
// 

void NhapTTSV(SV a[], int n)
{
	
	// Nhap Vao Ho ten, Diem , Tinh Diem Trung Binh
	for (int i = 0; i < n; i++)
	{
		printf("nhap vao ho ten sinh vien %d la : ", i+1);
		gets_s(a[i].Hoten);
		fflush(stdin);
		printf("nhap vao Que Quan sinh vien %d la : ", i + 1);
		gets_s(a[i].QueQuan);
		fflush(stdin);
		printf("nhap vao Gioi Tinh sinh vien %d la : ", i + 1);
		gets_s(a[i].GT);
		fflush(stdin);

		printf("nhap vao diem toan cua SV %d la : ", i+1);
		scanf_s("%f", &a[i].Toan);
		fflush(stdin);

		printf("Nhap Vao diem Ly cua SV %d la: ", i+1);
		scanf_s("%f", &a[i].ly);
		fflush(stdin);

		printf("Nhap vao diem hoa cua SV %d la : ", i+1);
		scanf_s("%f", &a[i].Hoa);
		fflush(stdin);
		a[i].DTB = (a[i].Toan + a[i].ly + a[i].Hoa) / 3;
	}

}
// xuat Sinh Vien ra Man Hinh
void XuatSV(SV a[], int n)
{
	
		printf("\n        ---------DANH SACH SINH VIEN----------\n");
		printf("\n%-20s %-15s %-10s %-5s %-5s %-5s %-5s", "Ho Ten", "Que Quan","Gioi Tinh", "Toan", "ly", "Hoa", "DiemTB\n");
		for (int i = 0; i < n; i++)
		{
			printf("\n%-20s %-15s %-10s %-5.1f %-5.1f %-5.1f %-5.1f\n", a[i].Hoten, a[i].QueQuan,a[i].GT, a[i].Toan, a[i].ly, a[i].Hoa, a[i].DTB);
		}
		
	


}
// Xuat Sinh Vien Vao File

void GhiFile(SV a[], int n){

	FILE  *fize;
	fize = fopen("SinhVien.txt", "w");
	fprintf(fize,"\n        ---------DANH SACH SINH VIEN----------\n");
	fprintf(fize,"\n%-30s %-20s %-20s %-10s %-10s %-10s %-10s", "Ho Ten", "Que Quan", "Gioi Tinh", "Toan", "ly", "Hoa", "DiemTB\n");
	for (int i = 0; i < n; i++)
	{
		fprintf(fize,"\n%-30s %-20s %-10s %-10.1f %-10.1f %-10.1f %-10.1f\n", a[i].Hoten, a[i].QueQuan, a[i].GT, a[i].Toan, a[i].ly, a[i].Hoa, a[i].DTB);
	}
}
int main()
{
	int n;
	SV SinhVien[N];
	{
		// Kiem tra Nhap So luong Sinh Vien
		do
		{
			printf("Nhap Vao So Luong Sinh Vien n= ");
			scanf_s("%d", &n);
			fflush(stdin);

			if (n < 0 || n>100)
			{
				printf("Khong Hop Le. Vui Long Nhap Lai\n\n");
			}
		} while (n  < 0 || n>100);


	}

	
	NhapTTSV(SinhVien, n);
	XuatSV(SinhVien, n);
	GhiFile(SinhVien, n);
	_getch();
	return 0;
}