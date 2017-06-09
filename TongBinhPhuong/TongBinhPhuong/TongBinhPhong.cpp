#include <stdio.h>
#include <conio.h>
#include <math.h>



void FindNumber(int k)
{
	int A[100];
	int j;

	for (int i = 1000; i <= 9999; i++)
	{
		int dem = 0;
		int tong = 0;
		int n = i;
		for (j = 0; n != 0; j++){
		
			A[j] = n % 10;
			n = n / 10;
			dem++;
		}
		
		for (int h = 0; h < dem; h++)
		{
			int pow = 0;
			pow = A[h] * A[h];
			tong += pow;

		}
		if (tong == k)
		{
			printf("\n%d", i);
		}
	}
}
void main()
{
	int k;
	printf("Nhap Vao So k: K= ");
	scanf_s("%d", &k);
	FindNumber(k);
	_getch();
}