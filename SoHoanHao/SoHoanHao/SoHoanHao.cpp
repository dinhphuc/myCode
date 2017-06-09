#include <stdio.h>
#include <conio.h>


bool KTSDX(int n)
{
	int temp = n;
	int s = 0;
	while (temp!=0)
	{
		s = s * 10 + temp % 10;
		temp /= 10;
	}

	return (s == n) ? true : false;
}

void main()
{
	(KTSDX(9988)) ? printf("la so doi xung") : printf("Khong la so doi xung");
	_getch();
}