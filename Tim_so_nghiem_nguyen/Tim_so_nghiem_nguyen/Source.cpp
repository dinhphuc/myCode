#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

long long tohop(int n, int k)
{
	long long c = 1;
	for (int i = 1; i <= k; i++, n--)
		c = c*n / i;
	return c;
}
int main()
{
	do
	{
		system("cls");

		int n, k, n1, k1;
		printf("Tim so nghiem nguyen cua pt: x1+x2+..+xk=n\n");
		printf("Nhap k: "); scanf("%d", &k);
		printf("Nhap n: "); scanf("%d", &n);
		n1 = n + k - 1;
		k1 = k - 1;
		printf("So ngiem cua pt la: %d", tohop(n1, k1));
		printf("\n");
	} while (_getch()!= 27);
	
}

