#include <stdio.h>
#include <conio.h>

char A[100];
int B[20];
char C[20];
void KTFibonaci(){
	int n1=1, n2=2, n3, s=0;
	

	for (int i = 2; i < 20; i++)
	{
		n3 = n1 + n2;
		B[i] = n3;
		printf("%d ", n3);
		s++;
		n1 = n2;
		n2 = n3;
	}
	//for (int i = 0; i < s; i++){
	//	B[0] = { 1 }, B[1] = { 2 };
	//	if (C[i] == B[i])
	//	{
	//		fflush(stdin);
	//		printf("day La FIbo %c \n",C[i]);
	//	}
	//	//printf("%d ", B[i]);
	//}
}
void KTso(char A[], int n)
{
	int dem = 0;

	for (int i = 0; i < n; i++)
	{  
		// Kiem Tra so hay chu
		//(A[i] >= '0' && A[i] <= '9') ? printf("Ki Tu %c La So\n", A[i]) : printf("Ki tu %c la Chu\n", A[i]);
		if (A[i] >= '0' && A[i] <= '9')
		{
			dem++;
			//C[i] = A[i];
		}
		
	}
	printf("so co %d\n\n", dem);
}
void KTinThuong(char A[], int n)
{
	int Dem=0;
	for (int i = 0; i < n; i++)
	{
	
		if (A[i] >= 'a' && A[i] <= 'z')
		{
			Dem++;
		}
		
	}
	printf("In thuong co %d\n\n", Dem);
}

void Change(char A[], int n)
{
	for (int i = 0; i < n; i++)
	{

		A[i] = (A[i] >= 'a' && A[i] <= 'z') ? A[i] -= 32 : A[i];
		if (A[i] >= 'a' && A[i] <= 'z')
		{
			A[i] -= 32;

			printf("Ki Tu In Hoa %c\n", A[i]);
		}
	}
}

void main()
{

	int n;
	/*printf("Nhap Vao so phan tu cua mang n= ");
	scanf_s("%d", &n);
	fflush(stdin);
	for (int i = 0; i < n; i++)
	{
		printf("nhap Vao Phan Tu thu %d la: ", i + 1);
		scanf_s("%c", &A[i]);
		fflush(stdin);
	}*/


	///printf("Ban Vua Nhap %d so", KTso(A, n));
//	KTso(A, n);
	
//	KTinThuong(A, n);
	printf("\n                     -------- Fibonacci Sequence ----------\n\n");
	printf("    1 2 ");
	KTFibonaci();
	printf("...");
//	Change(A, n);
	_getch();

}