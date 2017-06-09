#include <iostream>
#include <conio.h>
#include <time.h>
using namespace std;

//int Tong(int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		int a = rand() % n;
//	}
//}
bool KT(char a[], char b[])
{
	for (int i = 0; i < 30; i++)
	{
		if ('a[i]' != 'b[i]')
		{
			return false;
		}
		return true;
	}
}
void main()
{
		char a[30];
		char b[30];
		cout << "Nhap Vao Chuoi A   ";
		cin >> a;
		cout << "Nhap Vao Chuoi B   ";
		cin >> b;
		if (KT(a, b));
		{
			printf("Khac");
		}

	_getch();
}