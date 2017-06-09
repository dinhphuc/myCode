#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <string.h>
typedef char item;
typedef struct Node{
	item data;
	Node *next;
};

typedef struct Stack{
	Node *Top;
};

void tao_stack(Stack &S){
	S.Top = NULL;
}

bool IsEmpty(Stack &S)
{

	return(S.Top == NULL) ? true : false;
}

Node *TaoNode(item x)
{

	Node *P = new Node;
	P->data = x;
	P->next = NULL;
	return P;
}

void Push(Stack &S, item x){
	Node *P = TaoNode(x);
	P->next = S.Top;
	S.Top = P;
}

void readFILE(char filename[50], Stack &S)
{

	FILE *F;
	F = fopen(filename, "r");
	if (F == NULL){
		printf("FILE NOT EXIST !\n\n");
	}
	else{
		int n;
		item x;
		while (!feof(F))
		{
			fscanf(F, "%c", &x);
			Push(S, x);
		}

	}
	fclose(F);

}


void DaoChuoi(Stack &S)
{
	char A[50];
	fflush(stdin);
	printf("\n\n\tNhap Vao Chuoi Can Dao: ");
	gets(A);
	fflush(stdin);
	for (int i = 0; i < strlen(A); i++){
		Push(S, A[i]);
	}
}
void Output(Stack S)
{
	Node *P = S.Top;
	printf("\n\n\tChuoi Duoc Dao La:  ");
	while (P != NULL)
	{
		printf("%c", P->data);
		P = P->next;
	}
	printf("\n\n\t");

}
void main()
{
	Stack S;
	printf("\n\n\t1. Dao Chuoi \n\t2. Thoat\n\n");
	int temp ;
	do{
		printf("\n\tChon thao tac: ");
		scanf("%d", &temp);
		switch (temp)
		{
		case 1:
			tao_stack(S);
			DaoChuoi(S);
			Output(S);
			break;
		case 2:
			return;
			break;
		}
	
	} while (temp<2);

	_getch();
}