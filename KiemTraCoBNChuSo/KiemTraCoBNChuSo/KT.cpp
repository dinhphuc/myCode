#include <stdio.h>
#include <conio.h>

bool KT(int tg)
{
	int n = tg;
	int Tong1 = 0, Tong2 = 0;
	int i;
	int A[20];

	for (i = 0; n >= 1; i++)
	{
		A[i] = n % 10;
		n = n / 10;
		//printf("%d", A[i]);
	}

	/*int count = 0;
	while (n!=0)
	{
	A[count] = n % 10;
	n /= 10;
	count++;
	}*/

	printf("So %d co %d chu so\n\n", tg, i);
	if (i % 2 != 0)
	{
		A[i] = 0;
		i++;
	}
		

	for (int j = 0; j < i / 2; j++)
	{
		Tong1 = Tong1 + A[j];
	}
	for (int j = i / 2; j < i; j++)
	{

		Tong2 = Tong2 + A[j];
	}

	return (Tong1 == Tong2) ? true : false;


}




void main()
{
	int n;
	while (true)
	{

		printf("\n\n\nNhap Vao So Can Kiem Tra N= ");
		scanf_s("%d", &n);
		KT(n) ? printf("C") : printf("K");
	}
	_getch();

}