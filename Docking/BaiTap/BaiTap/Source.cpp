#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <string.h>
void ChangeMoney(int m)
{
	int A[50];
	int n;
	int Dem=0;
	n = m;

	for (int i = 0; n!=0; i++)
	{
		A[i] = n % 10;
		n = n / 10;
		Dem++;
		//printf("dem %d", A[i]);
	}
	
	
	char B[][11] = { "Khong", "Mot", "Hai", "Ba", "Bon", "Nam", "Sau", "Bay", "Tam", "chin", "Muoi" };
	//printf("dem %s", B[1]);
	switch (Dem)
	{
	case 1 :
		printf("Menh Gia: %s Dong", B[A[Dem-1]]);
		break;
	case 2 :
		printf("Menh Gia: ");
		if (A[(Dem - 2)] == 0)
		{
			printf("%s ", B[A[Dem - 1]]);
		}
		 printf("%s ", B[10]);
		if (A[(Dem - 2)] != 0)
		{
			printf("%s ", B[10]);
			printf("%s", B[A[Dem - 2]]);
		}
		
		printf("Dong");
		break;
	case 3:
		printf("Menh Gia: ");
		
		printf("Dong");
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	case 8:
		break;
	case 9:
		break;
	case 10:
		break;
}
	
}
void Change()
{
	char so[][12] = { "khong", "mot", "hai", "ba", "bon", "nam", "sau", "bay", "tam", "chin", "muoi", "muoi mot", "muoi hai" };
	char money[100] = "";
	int n, t, i;
	printf("Nhap vao so tien: ");
	scanf_s("%d", &t);
	if (t > 999999999) i = 10;
	else if (t > 99999999) i = 9;
	else if (t > 9999999) i = 8;
	else if (t > 999999) i = 7;
	else if (t > 99999) i = 6;
	else if (t > 9999) i = 5;
	else if (t > 999) i = 4; 
	else if (t > 99) i = 3; 
	else if (t > 9) i = 2;
	else i = 1;

	switch (i)
	{
	case 5:n = t / 10000;
		t = t - n * 10000;
		strcat(money, so[n]);
		strcat(money, " trieu ");
		if (t % 1000 == 0) break;
	case 4: n = t / 1000;
		t = t - n * 1000;
		strcat(money, so[n]);
		strcat(money, " nghin ");
		if (t % 1000 == 0) break;
	case 3: n = t / 100;
		if (t>99) t = t - n * 100;
		strcat(money, so[n]);
		strcat(money, " tram ");
		if (t % 100 == 0) break;
	case 2: if (t<10) strcat(money, " ninh "); else if (t<20) strcat(money, " muoi "); else { strcat(money, so[t / 10]); strcat(money, " muoi "); }
			if (t % 10 == 0) break;
	case 1:
		strcat(money, so[t % 10]);
	}
	strcat(money, " dong");
	puts(money);
}


void main()
{
	//ChangeMoney(40);
	Change();
	_getch();
}