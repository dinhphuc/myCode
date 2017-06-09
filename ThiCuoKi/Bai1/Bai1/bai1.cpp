#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#define max 100000
void GhiFile(int A[], int n)
{
	FILE *F;
	
	F = fopen("output.txt", "w");
	if (F == NULL)
	{

		printf("\n\nFile Not exists");
		_getch();

		return;
	}
	for (int i = 0; i < n;i++)
	{
		fprintf(F, " %d", A[i]);
	}
	fclose(F);
}
void SelectSort(int A[], int n, double *t2)
{
	system("cls");
	printf("  Dang Sap Xep Chon....");
	clock_t f = clock();
	int temp;
	for (int i = 0; i < n; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (A[j] < A[min])
			{
				min = j;
			}

		}
		temp = A[min];
		A[min] = A[i];
		A[i] = temp;


	}
	clock_t s = clock();
	double t = (float)(s - f) / CLOCKS_PER_SEC;
	*t2 = t;
	system("cls");
	printf("\n  Done!   Sap Xep xong.\n");
	printf("Thoi Gian Vua Thuc Hien Sap Xep Chon la: %f s", t);
	printf("\n\nPress any key to continue...");
	_getch();
}
void insertSort(int A[] , int n,double *t1)
{
	
	system("cls");
	printf("  Dang Sap Xep Chen ....");
	clock_t f = clock();
	for (int i = 1; i < n; i++){
	int	j = i - 1;
	int temp = A[i];
	while ((temp<A[j])&&(j>=0))
	{
		A[j + 1] = A[j];
		j--;
	}
	A[j + 1] = temp;
	}
	clock_t s = clock();
	double t = (float)(s - f) / CLOCKS_PER_SEC;
	*t1 = t;
	system("cls");
	printf("\n  Done!   Sap Xep xong.\n");
	printf("Thoi Gian Vua Thuc Hien Sap Xep chen la: %f s", t);
	printf("\n\nPress any key to continue...");
	_getch();
}
void BubbleSort(int A[], int n, double *t3)
{
	system("cls");
	printf("  Dang Sap Xep Noi Bot....");
	clock_t f = clock();
	for (int i = 0; i < n-1; i++)
	{
		int temp;
		for (int j = n - 1; j > i; j--)
		{
			if (A[j] < A[j-1])
			{
				temp = A[j];
				A[j] = A[j-1];
					A[j-1] = temp;
			}
		}
	}
	clock_t s = clock();
	double t = (float)(s - f) / CLOCKS_PER_SEC;
	*t3 = t;
	system("cls");
	printf("\n  Done!   Sap Xep xong.\n");
	printf("Thoi Gian Vua Thuc Hien Sap Xep Noi Bot la: %f s", t);
	printf("\n\nPress any key to continue...");	
	_getch();
}
void Show(int A[], int n)
{
	system("cls");
	printf("Danh sach: \n");
	for (int i = 0; i < n; i++)
		printf("%d ", A[i]);

	printf("\n\nPress any key to continue...");
	_getch();
}
void CreatFIle()
{
	system("cls");
	int RD;
	printf("Nhap Vao so Luong Phan Tu cua FILE n: ");
	scanf("%d", &RD);
	FILE *F;
	
	F = fopen("input.txt", "w");
	if (F == NULL)
	{
		printf("\n\nFile Not exists");
		_getch();

		return;
	}
	else{
		for (int i = 0; i < RD; i++)
		{
			int temp;
			temp = rand() % RD;
			fprintf(F, "%d ", temp);

		}
		fclose(F);
		printf("\n\nDone! xong.\n");
		printf("\n\nPress any key to continue...");
		_getch();
	}
}
void Input(int A[],int *n)
{
	FILE *F;
	F = fopen("input.txt", "r");
	if((F)==NULL)
	{
		printf("\n\nFile Not exists");
		_getch();
		
		return;
	}
	else{
		int i = 0;
		while (!feof(F))
		{
			int temp;
			fscanf(F, "%d", &temp);
			if (!feof(F)){
				A[i] = temp;
				i++;
			}
			*n = i;
		}
	}
	fclose(F);
	
}
void calculateTime(double t1, double t2, double t3 )
{
	system("cls");
	double Max = t1;
	if (Max < t2)Max = t2;
	if (Max < t3)Max = t3;

	if (Max == t1)printf("\t\t\nThoi Gian Vua Thuc Hien Sx insertSort Cham Nhat voi t= %f s \n", Max);
	if (Max == t2) printf("\t\t\nThoi Gian Vua Thuc Hien Sx SelectSort cham Nhat voi t= %f s \n", Max);
	if (Max == t3) printf("\t\t\nThoi Gian Vua Thuc Hien Sx BubbleSort Cham Nhat voi t= %f s \n", Max);

	double Min = t1;
	if (Min > t2)Min = t2;
	if (Min > t3)Min = t3;
	if (Min == t1)printf("\t\t\nThoi Gian Vua Thuc Hien Sx insertSort Nhanh Nhat voi t= %f s \n", Min);
	if (Min == t2)printf("\t\t\nThoi Gian Vua Thuc Hien Sx SelectSort Nhanh Nhat voi t= %f s \n", Min);
	if (Min == t3)printf("\t\t\nThoi Gian Vua Thuc Hien Sx BubbleSort Nhanh Nhat voi t= %f s \n", Min);
	printf("\n\nPress any key to continue...");
	_getch();
}
void Menu()
{
	system("cls");
	printf("\n\t\t\t--------------KIEM TRA HK1---------------\n\n");
	printf("Bai Tap 1: insertSort,SelectSort,BubbleSort, calculate time. \n\n");
	printf("\t Chose (1-n) : \n");
	printf("\t 1. Tao File voi So luong phan tu \n");
	printf("\t 2. Sap Xep Chon (SelectSort) \n");
	printf("\t 3. Sap Xep Chen (insertSort) \n");
	printf("\t 4. Sap Xep Noi Bot (BubbleSort) \n");
	printf("\t 5. Xem Danh Sach da Sap Xep \n");
	printf("\t 6. So sanh Thoi Gian Thuc Hien Sap Xep \n");
	printf("\t 7. Exit \n\n\n\n\n");
}
void main()
{
	
	int A[max];
	int n;
	double t1=0, t2=0, t3=0;
	Menu();
	int c;
	do
	{
		printf("Nhap Vao Lua Chon: ");
		scanf("%d", &c);
		switch (c)
		{
		case 1:
			CreatFIle();
			Menu();
			break;
		case 2:
		{
				  Input(A, &n);
					SelectSort(A, n, &t1);	
					GhiFile(A, n);
					Menu();
					break;
		}

		case 3:
		{
				  Input(A, &n);
				  insertSort(A, n,&t2);
				  Menu();
				
		}
			break;
		case 4:
		{
				  Input(A, &n);
				  BubbleSort(A, n, &t3);
				  Menu();
		}
			break;
		case 5:
		{
				  Show(A, n);
				  Menu();
		}
			break;
		case 6:
		{
				  system("cls");
				 
				  printf("\n\n Press any key to Thuc Hien cac sap xep ...\n");
				 
				  _getch();
				  Input(A, &n);
				  SelectSort(A, n, &t1);
				  Input(A, &n);
				  insertSort(A, n, &t2);
				  Input(A, &n);
				  BubbleSort(A, n, &t3);
				  calculateTime(t1, t2, t3);
				  Menu();
		}
			break;
		case 7:
			break;
			return;
		}
	} while (c < 7);
	


	_getch();
}