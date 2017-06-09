#include <stdio.h>
#include <conio.h>


void SelectionSort(int A[])
{
	int min;
	int temp;
	for (int i = 0; i < 10; i++)
	{
		for (int j = i+1; j<10; j++)
		{
			min = i;
			if (A[min] > A[j])
			{
				
				min = j;
			}
			temp = A[min];
			A[min] = A[i];
			A[i] = temp;
		}
		
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d", A[i]);
	}
}


void InserttSort(int A[])
{
	int temp, j;

	for (int i = 1; i < 10; i++)
	{
		j = i - 1;
		temp = A[i];

		while ((j >= 0) && (A[j]>temp)){
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = temp;

	}


	for (int i = 0; i < 10; i++)
	{
		printf("%d", A[i]);
	}
}

void BubbleSort(int A[])
{
	for (int i = 0; i < 9; i++)
	{
		
		for (int j = 9; j>i; j--)
		{
			int temp;
			if (A[j] < A[j-1])
			{
				temp = A[j - 1];
				A[j - 1] =  A[j];
				A[j] = temp;			
			}
			

		}
		
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d", A[i]);
	}
}
void main()
{
	int A[10] = { 5, 2, 5, 7, 9, 1, 6, 7, 9, 3 };
	/*printf("chon\n");
	SelectionSort(A);
	printf("\nchen\n");
	InserttSort(A);
	printf("\nBot\n");*/
	BubbleSort(A);

	_getch();
}
