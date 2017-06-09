#include <stdio.h>
#include <conio.h>


void main()
{
	char k;
	//do{
	//	//your code here
	//	//printf("nhan esc de ket thuc");
	//	k = _getch();
	//	printf("dang nhap Vao %d \n", k);
	//} while (k != 27);
	switch (k = _getch())
	{
	case 13 :
		printf("dang nhap Vao %d \n", k);
		break;
	case 27 :
		printf("thoat");
		break;
	}
	_getch();
}