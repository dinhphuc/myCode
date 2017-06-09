#include <stdio.h>
#include <conio.h>

//// in ra phần tử vị trí chẵn
//void InPhanTuChan(int n)
//{
//	for (int i=0; i < n; i++)
//	{ 
//		if ((i+1) % 2 == 0)
//		{
//			printf("\nPhan tu o vi tri chan thu %d la : %d ",(i + 1),A[i]);
//		}
//	}
//}
//// in ra các phần tử chẵn và phần tử lẻ
//void InChanLe(int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		if (A[i] % 2 == 0)
//		{
//			printf("\nPhan tu chan la : %d ", A[i]);		
//		}
//	}
//
//	for (int i = 0; i < n; i++)
//	{
//	if (A[i] % 2 != 0)
//		{
//			printf("\nPhan tu le la : %d ", A[i]);
//		}
//	}
//}
//
////Tính tổng các phần tử chẵn phần tử lẻ
//
//void TongChanLe(int n)
//{
//	int TongChan=0;
//	int TongLe=0;
//	for (int i = 0; i < n; i++)
//		{
//			if (A[i] % 2 == 0)
//			{
//				TongChan += A[i];
//			}
//			else
//			{
//				TongLe += A[i];
//			}
//		}
//
//		/*for (int i = 0; i < n; i++)
//		{
//			if (A[i] % 2 != 0)
//			{
//				TongLe += A[i];
//			}
//		}
//		*/
//	
//	printf("\nTong Chan La : %d", TongChan);
//	printf("\nTong Le La : %d", TongLe);
//}
//// Tìm số lớn nhất bé nhất và tính mảng hai số này
//int TongMinMax(int *A)
//{ 
//
//	int Max = A[0];
//	int Min = A[0];
//	int Tong = 0;
//	{
//		for (int i = 0; i < n; i++)
//		{
//			if (Max < A[i])
//			{
//				Max = A[i];
//
//			}
//		}
//		printf("\nPhan Tu lon nhat la %d", Max);
//	}
//	for (int i = 0; i < n; i++)
//	{
//		if (Min > A[i])
//		{
//			Min = A[i];
//
//		}
//	}
//	printf("\nPhan Tu Nho nhat la %d", Min);
//
//
//	//tính tổng 
//	
//		Tong = Min + Max;
//		printf("\n\nTong so lon nhat va so be nhat la: %d", Tong);
//	return 0;
//}
////Tim Các Giá trị Lớn hơn m 
//
//void TimGiaTriLonHon(int n){
//}
//
//// Tinh tổng Hai mảng
//
//void TongHaiMang(int n)
//{
//}

// Main Program

int Min(int *a, int n)
{
	int min = (n > 0) ? a[0] : 0;
	for (int i = 0; i < n; i++)
	{
		min = (min > a[i]) ? a[i] : min;
	}
	return min;
}

int Max(int *a, int n)
{
	int max = (n > 0) ? a[0] : 0;
	for (int i = 0; i < n; i++)
	{
		max = (max < a[i]) ? a[i] : max;
	}
	return max;
}

int Tong(int *a, int n)
{
	return Min(a, n) + Max(a, n);
}

int TongHaiMang(int *a, int *b,int n)
{
	int Tong = 0;
	for (int i = 0; i < n; i++)
	{
		Tong += a[i] + b[i];
	}
	
	return Tong;
}

void main()
{

	//int n;
	////Mảng 1
	//printf("Nhap Vao so Phan tu cua mang n= ");
	//scanf_s("%d",&n);
	//for (int i = 0; i < n; i++)
	//{
	//	printf("Nhap Vao phan tu thu %d cua mang 1 : ", (i + 1));
	//	scanf_s("%d", &A[i]);
	//}
	////Mảng 2
	//int B[15];
	//for (int i = 0; i < n; i++)
	//{
	//	printf("Nhap Vao phan tu thu %d cua mang 2 : ", (i + 1));
	//	scanf_s("%d", &B[i]);
	//}
	////InPhanTuChan(n);
	////InChanLe(n);
	////TongChanLe(n);
	////TongMinMax(n);
	//TimGiaTriLonHon(n);
	int a[100];
	int	b[100];
	int n;
	printf("Nhap vao so phan tu cua mang n= ");
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		printf("Nhap Vao Phan tu thu %d cua Mang 1 la : ", (i + 1));
		scanf_s("%d", &a[i]);
	}
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		printf("Nhap Vao Phan tu thu %d cua Mang 2 la : ", (i + 1));
		scanf_s("%d", &b[i]);
	}
	printf("tong cau hai mang la %d ", TongHaiMang(a, b, n));
	_getch();
}