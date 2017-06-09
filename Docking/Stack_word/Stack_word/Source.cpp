#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


char stack[100];

int main() {
	char n[50];
	printf("Nhap Vao Chuoi : ");
	gets_s(n);
	fflush(stdin);
	for (int i = 0; i < strlen(n); i++){
		stack[i] = n[i];
		
		
	}
	for (int j = strlen(n)-1; j>=0; j--)
	{
		printf("%c", stack[j]);
	}


	_getch();
	return 0;
}