#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void swap(int &a, int &b){
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void Quick_sort(int A[], int L, int R){
	int i = L, j = R;
	int key = A[(L + R) / 2];
	while (i <= j){
		while (A[i]<key){
			i++;
		}
		while (key<A[j]){
			j--;
		}
		if (i <= j){
			swap(A[i], A[j]);
			i++;
			j--;
		}
	}
	if (L<j){
		Quick_sort(A, L, j);
	}
	if (i<R){
		Quick_sort(A, i, R);
	}
}

int BinarySearch(int A[], int x, int L, int R){
	int key;
	if (L>R){
		return 0;
	}
	else{
		key = (L + R) / 2;
		if (x == A[key]) return (key+1);
		if (x<A[key]) return BinarySearch(A, x, L, key);
		if (x>A[key]) return BinarySearch(A, x, key, R);
	}
}


void readFile(char filename[50], int A[], int *n){
	FILE *f;
	
	if ((f = fopen(filename, "r")) == NULL){
		printf("Khong mo dk file!");
	}
	
	else{
		int i = 0;
		while (!feof(f))
		{ 
			int temp;
			fscanf(f,"%d", &temp);
			if (!feof(f)){
				A[i] = temp;
				i++;
			}
		}
		*n = i;
		fclose(f);
	}
}

void writeFile(char filename[50], int A[], int n){
	FILE *f;
	if ((f = fopen(filename, "w")) == NULL){
		printf("Khong the mo file!");
	}
	else{
		for (int i = 0; i < n; i++){
			fprintf(f, "%d ", A[i]);
		}
		fclose(f);
	}
}

void Output(int A[], int n){
	for (int i = 0; i <n; i++){
		printf("%d ", A[i]);
	}
	printf("\n");
}
void menu()
{ 
	system("cls");
	printf("1. Xem Du Lieu Doc Tu File \n2. Sap xep nhanh\n3. Tim kiem nhi phan");

}
void main(){
	int A[100000], n;
	menu();
	int temp;
	do{
		printf("\nChon: ");
		scanf("%d", &temp);

		switch (temp){
		case 1:
		{
				  system("cls");
				  readFile("input.txt", A, &n);
				  printf("\nDay so nhap tu file la: \n");
				  Output(A, n);
				  _getch();
				  menu();
				  break;
		}
		case 2:
		{
				   system("cls");				  
				   readFile("input.txt", A, &n);				  				  
				   Quick_sort(A, 0, n-1);
				   printf("\nDay sau khi sap xep nhanh la: ");				  
				   Output(A, n);
				   writeFile("output.txt", A, n);
				   _getch();
				   menu();
				   break;
		}
		case 3:{
				 
				   readFile("inputNhiPhan.txt", A, &n);
				   printf("\nDay so nhap tu file la: \n");
				   Output(A, n);
				   int x;
				   printf("\nNhap vao phan tu can tim: ");
				   scanf("%d", &x);
				   printf("Phan tu %d nam o vi tri thu %d", x, BinarySearch(A, x,0, n));
				   break;
		}
		}
	} while (temp<4);
	_getch();
}
