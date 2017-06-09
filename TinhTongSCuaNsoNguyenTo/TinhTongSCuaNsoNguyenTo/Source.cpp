#include <stdio.h>
#include <conio.h>

int Ktsnt()
{
	/*if (n <= 1) 
		return 1;*/
	int s = 0;
	int dem = 0;


		for (int i = 2; i <= 100; i++){
			for (int j = 1; j <= i; j++)
			{


				if (i%j != 0)
				{
					break;

				}

			}
			break;
			printf("%d ",i);
			
		}
	return 1;
}

void main()
{
	//int n;
	
		/*printf("\n\nNhap vao so n= ");
		scanf_s("%d", &n);*/
		Ktsnt();
	_getch();
}