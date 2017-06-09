

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char* p;
	int i, n;
	printf("\n Nhap xau ki tu :");
	gets(p);
	n = strlen(p);
	printf("\n xau dao: \n");
	for (i = n - 1; i >= 0; i--)
		putchar(p[i]);
	printf("\n");
	free(p);
	getch();
	return 0;
}


/*nhap
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
void main()
{
	//for (int i = 0; i<10; i++)
	//{
	printf("\n\n\n");
		printf("             Ngo ");
		Sleep (1500);
		printf(" Dinh ");
		Sleep(1500);
		printf(" Phuc ");
		Sleep(1500);

	//}
		_getch ();

}
*/