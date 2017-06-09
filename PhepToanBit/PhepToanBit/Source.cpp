#include <stdio.h>
#include <conio.h>

/*
author by PhucBinz
*/


int Pow(int a, int b)
{
	int S = 1;
	for (int i = 0; i < b; i++)
	{
		S *= a;
	}
	return S;

}

void Change(int n)
{
	int A[100], dem = 0;
	int s = n;
	for (int i = 0; s != 0; i++)
	{
		A[i] = s % 2;
		s = s / 2;
		dem++;
	}
	for (int j = dem-1; j >= 0; j--)
		printf("%d", A[j]);

}

void getbit(int n,int i)
{
	int s = 0;
	{
		s = ((n / Pow(2, i - 1)) % 2);
	}
	printf("%d\n\n", s);
}


	void main()
{

		int n,i;
			printf("Nhap Vao So Can Chuyen: ");
			scanf_s("%d", &n);
			printf("Nhap Vao Bit Thu i: ");
			scanf_s("%d", &i);
			getbit(n,i);



			char k=13;
			int kt=0 ;
			do
			{
				printf("***************************************************\n");
				printf("\n\n\t  Ban Muon Nhap Tiep Khong ? \n\n");
				printf("\tNhan\t  ENTER\t\t ESC\n");
				printf("\t De \t Tiep Tuc\tThoat\n\n");
				printf("***************************************************\n");
				//k = _getch();
				if (k == 13 || k == 27)
				{

					switch (k = _getch())
					{

					case 13:
						
						do{
							printf("Nhap Vao So Can Chuyen: ");
							scanf_s("%d", &n);
							printf("Nhap Vao Bit Thu i: ");
							scanf_s("%d", &i);
								printf("\n\n***************************************************\n\n");
							
						} while (  kt == 13);
					    getbit(n, i);
						break;
					case 27:
						printf("Thoat");
						break;
					}
				}
				else
				{
					printf("\nBan Vua Nhap Phim %c La Phim Sai. Vui Long Nhap Lai\n", k);
				}
			} while (k != 27);
			_getch();
}