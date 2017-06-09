#include <stdio.h>
#include <conio.h>

void VeDauCach(int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("\n");
	}
}
void VeHinhChuNhat(int x, int y,int n)
{
	for (int i = 0; i < x; i++)
	{

		for (int j = 0; j < n; j++)
			printf(" ");
		for (int k = 0; k < y; k++)
			printf("*");
	
		    printf("\n");

	}
	

}
void VeTamGiac(int n)
{
	int kt = 20;

	for (int i = 0; i < (n-1); i++)
	{
		int dayTG = 2 * i + 1;
		for (int j = 0; j <kt ; j++)
			printf(" ");
		for (int j = 0; j < dayTG; j++)
		{
			if (j == 0 || j == dayTG - 1)
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
		}
		 


		kt--;
		printf("\n");


	}
	for (int j = 0; j <kt; j++)
		printf(" ");
	for (int i = 0; i < 2 * n - 1; i++)
	{
		printf("*");
	}



}
void main()
{

	
	/*//Hinh chu nhat thu nhat
	VeDauCach(4);
	VeHinhChuNhat(6, 9, 5);
	//ve Hinh chu Nhat thu hai
	VeDauCach(3);
	VeHinhChuNhat(6, 9, 20);
	//ve hinh chu nhat thu ba
	VeDauCach(3);
	VeHinhChuNhat(6, 9, 15);
	VeDauCach(5);
	*/
	VeTamGiac(20);
	
		_getch();

}