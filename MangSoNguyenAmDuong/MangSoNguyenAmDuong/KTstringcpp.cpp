#include <stdio.h>
#include <conio.h>
#include <string.h>
int Input()
{
	char s[100];
	bool ok;
	int n = 0;
	do
	{
		n = 0;
		ok = true;
		fflush(stdin);
		gets_s(s);
		for (int i = 0; i < strlen(s); i++)
		{
			if (s[i] >='0' && s[i] <='9')
			{
				n = n * 10 + s[i] - 48;
			}
			else
			{
				ok = false;
				printf("Nhap sai dl!\n");
				break;
			}
		}

	} while (!ok);

	return n;
}

int* NhapMang()
{
	int A[10] = { -8, 8, 3, 4, 5, 6, 7, 8, 9 };
	return A;
}

void Kiem(int *a, int n)
{
	//printf("%3d", a[1]);
	for (int i = 0; i < n; i++)
	{
		if (a[i]%2==0)
			printf("%3d", a[i]);
	}
}

void main()
{
	

	int *p;
	p = NhapMang();
	/*	printf("%3d", p[0]);
	printf("%3d", p[1]);
	printf("%3d", p[2]);
	printf("%3d", p[3]);
	printf("%3d", p[4]);
	printf("%3d", p[5]);
	printf("%3d", p[6]);*/
	printf("%3d", p[7]);
	printf("%3d", p[8]);
	//printf("%3d", p[9]);*/
	/*int A[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	Kiem(A, 9);*/
	//printf("%3d", p[1]);

	/*for (int i = 0; i < 9; i++)
	{
		if (p[i] % 2 == 0)
			printf("%3d", p[i]);
			
	}*/
	//Kiem(p, 9);

	_getch();
}