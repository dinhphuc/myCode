#include <stdio.h>
#include <conio.h>
#include <math.h>

int TinhGiaThua(int n)
{
	int i;
	int s = 1;
	for ( i = 1; i <=n; i++)
		s *= i;
	return s;
}

int TinhToHop(int n , int k)
{
	int ToHop = TinhGiaThua(n) / ((TinhGiaThua(k))*TinhGiaThua(n - k));
	return ToHop;
}
void swap(int a, int b)
{
	a = a + b;
	b = a - b;
	a = a - b;
	printf("%d     %d", a, b);
}
void main()
{
	/*int k, n;
	printf("Nhap To Hop Chap K cua N ( n < k ) \n");
	do{
		printf("Nhap k= ");
		scanf_s("%d", &k);
		printf("Nhap n= ");
		scanf_s("%d", &n);
	} while (n < k);

	TinhToHop(n, k);*/
	swap(5, 12);

	_getch();
}
