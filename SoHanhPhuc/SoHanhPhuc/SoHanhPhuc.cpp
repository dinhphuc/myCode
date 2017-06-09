#include <stdio.h>
#include <conio.h>

void TimSoHP(int n){
	int s=0;
	for (int i = 1; i <=( n / 2); i++){
		if (n%i == 0){
			s = s + i;
		}
	}
	if (n == s){
		printf("Day la so hanh phuc");
	}
	else
	{
		printf("day khong la so hanh phuc");
	}
}
void main(){
	while (true){
		int n;
		printf("\n nhap Vao So Can Kiem Tra n= ");
		scanf_s("%d", &n);
		TimSoHP(n);
		_getch();
	}
}