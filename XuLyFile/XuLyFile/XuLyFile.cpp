#include <stdio.h>
#include <conio.h>

FILE *teptin;
int A[100];
void NhapFile()
{
	int n;
	teptin = fopen("Vidu.txt", "wb");
	for (int i =0 ; i < n; i++)
	fprintf(teptin, "%d", A[i]);
	fclose(teptin);
}

int main()
{
	int i;
	int n;
	printf("Nhap Vao So Phan tu ");
	scanf_s("%d", &n);

	for (i = 0; i < n; i++)
	{
		printf("Nhap Vao So thu %d ", (i + 1));
		scanf_s("%d", &A[i]);
	}
	NhapFile();

	_getch();
}