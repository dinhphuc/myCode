#include <stdio.h>
#include <conio.h>
#define MaxSize 100
int stack[MaxSize];



int pust(int stack[], int V)
{
	if (stack[0] < MaxSize - 1)
	{
		stack[0] = stack[0] + 1;
		stack[stack[0]] = V;
		return 1;
	}
	else
	return 0;
}


void main()
{


	_getch();
}