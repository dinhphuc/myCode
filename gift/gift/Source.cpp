#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include <stdlib.h>
struct HoTen
{
	char Ten[5], *Ho, FullName[30];
};
void TachTen(char a[],HoTen &Ht, int *leng)
{ 
	if (a == NULL) return;
	int j = 0;
	for (int i = strlen(a)-1 ; i >= 0; i--)
	{
		Ht.Ten[j] = a[i];
		j++;
		if ((a[i] ==' ')) 
			break;
	}

	int n=0;
	for (int i = j-1; i >=0 ; i--)
	{
		Ht.FullName[n] = Ht.Ten[i];
		n++;
	}
	Ht.FullName[n] = ' ';
	n++;
	for (int i = 0; i < strlen(a) - j; i++)
	{
		Ht.FullName[n] = a[i];
		n++;
	}
	
}
int main()
{
	int j;
	int z=0;
	HoTen Ht;
	char a[50] = "8.5";
	float x=atof(a);
	printf("%f", x);
	_getch();
	return 0;
}