#include <stdio.h>
#include <conio.h>

void main()
{
	for (int so = 1; so < 1000; so = so + 1)
	{
		int a = so;
		int song = 0;
		//Tim so nguoc cua so a
		for (int i = a; i != 0; i = i / 10)
		{
			int du = i % 10;
			song = song * 10 + du;
		}
		//Ket luan
		if (song == a)
			printf("%d ", a);
	}
	_getch();
	
}