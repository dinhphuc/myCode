#include <stdio.h>
#include <conio.h>

bool Ktsnt(int n)
{
	if (n <= 1) return false;
	for (int i = 2; i <= n / 2; i++){

		if (n%i == 0)
		{
			return false;
		}
	}
	return true;
}

void main()
{
	int n;
	while (true)
	{
		printf("\n\nNhap vao so n= ");
		scanf_s("%d", &n);
		if (Ktsnt(n))
			printf("La so nguyen to");
		else printf("Khong la so nguyen to");
	}
	_getch();
}