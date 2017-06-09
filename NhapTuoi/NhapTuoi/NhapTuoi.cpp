#include <stdio.h>
#include <conio.h>

void main()
{
	int n;
	printf("nhap vao tuoi n= ");
	scanf_s("%d",&n);
	if (n<0 || n>110){
		printf("Nhap sai");

	}
	else
	{
		for (int i = 1; i <= 13; i++)
		{
			if (i == n){
				printf("Tre Con");
				break;
			}
			
		}
		for (int i = 14; i < 18; i++)
		{
			if (i == n)
				printf("Thieu nien");
			break;
		}
		for (int i = 19; i <= 39; i++)
		{
			if (i == n){
				printf("Truong Thanh");
				break;
			}
			
		}
		for (int i = 40; i <= 55; i++)
		{
			if (i == n){
				printf("Trung Nien");
				break;
			}
			
		}
		for (int i = 56; i <= 80; i++)
		{
			if (i == n){
				printf("Co tuoi");
				break;
			}
			
		}
		for (int i = 81; i <= 120; i++)
		{
			if (i == n){
				printf("Thuong tho");
				break;
			}
			
		}

	}

	_getch();


}