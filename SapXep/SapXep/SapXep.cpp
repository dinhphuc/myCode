#include <stdio.h>
#include <conio.h>




void sapxepchen(int A[], int n)
{
	int temp, j;

	for (int i = 1; i < n; i++)
	{
		j = i - 1;
		temp = A[i];
	
		while ((j >= 0) && (A[j]>temp)){
			A[j + 1] = A[j];
			j -- ;
		}
		A[j + 1] = temp;
	
	}


	for (int i = 0; i < n; i++)
	{
		printf(" %d", A[i]);
	}
}
void sapxepchon(int A[], int n)
{ 
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{  
			int min = i;
			if (A[min] > A[j])
			{
				min =j;
			}
			if (i != min)
			{

				int t = A[min];
				A[min] = A[i];
				A[i] = t;
			}

		}
	}
	for (int i = 0; i < n; i++)
	{
		printf(" %d", A[i]);
	}
}

void main()
{ 
	int A[20] = { 7, 3, 1, 2, 9, 6, 8, 7, 4, 0, 0, 1, 2, 3, 4, 19 };
	printf("\n---Sap Xep Chen---\n");
	sapxepchen(A, 9);	
	printf("\n---Sap Xep Chon---\n");
	sapxepchon(A, 9);
	_getch();
}