#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>

typedef int item;
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

int Do_DaiStack(Stack &S)
{
	if (!IsEmpty)
	{
		printf("stack Rong");
		return 0;
	}
	else{
		
		Node *P = S.Top;
		int i = 0;
		while (P !=NULL)
		{
			i++;
			P = P->next;
		}
		return i;
	}

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
item Peek(Stack S)
{
	return S.Top->data;
}
item POP(Stack &S)
{
	if (!IsEmpty(S)){
		item x = S.Top->data;
		S.Top = S.Top->next;
		return x;
	}

}
void readFILE(char filename[50], Stack &S)
{
	
	FILE *F;
	F = fopen(filename, "r"); 
	if (F==NULL){
		printf("FILE NOT EXIST !\n\n");
	}
	else{
		int n;
		item x;
		fscanf(F, "%d", &n);
		printf("Stack gom co %d phan tu\n\n", n);
		for (int i = 1; i <= n; i++){
			fscanf(F, "%d", &x);
			Push(S, x);
		}
		fclose(F);
		
	}
}
void CoverBinary(Stack S, item x)
{
	
	int i;
	if (x == 0)
	{
		Push(S, 0);
	}
	else
	{


		while (x > 0)
		{
			i = x % 2;
			x /= 2;
			Push(S, i);

		}
	}
		while (!IsEmpty(S)){
			printf("%d", POP(S));
		
	}
}
void ReverseList(List L){

}

void Output(Stack S)
{
	Node *P = S.Top;
	while (P!=NULL)
	{
		printf("%2d", P->data);
		P = P->next;
	}

}
void main()
{
	Stack S;
	tao_stack(S);
	readFILE("input.cpp", S);
	printf("Stack nhap tu file la: ");
	Output(S);
	printf("\n\nThao tac vs Stack: \n1. Kiem tra stack rong\n2. Do dai stack\n3. Them phan tu vao Stack\n4. Xoa phan tu khoi Stack\n5. Bai 11 - Chuyen doi so ko am sang so nhi phan\n6. Thoat");

	int temp;
	do{
		printf("\nChon thao tac: ");
		scanf("%d", &temp);
		switch (temp){
		case 1:{
				   readFILE("input.cpp", S);
				   if (IsEmpty(S)){
					   printf("Stack rong!");
				   }
				   else{
					   printf("Stack khong rong!");
				   }
				   break;
		}
		case 2:{
				//   readFILE("input.cpp", S);
				   printf("Do dai cua stack la: %d", Do_DaiStack(S));
				   break;
		}
		case 3:{
				   item x;
				   printf("Nhap gia tri can them vao stack: ");
				   scanf("%d", &x);
				   Push(S, x);
				   printf("\nStack sau khi them phan tu: ");
				   Output(S);
				   break;
		}
		case 4:{
				   POP(S);
				   printf("\nStack sau khi xoa phan tu: ");
				   Output(S);
				   break;
		}
		case 5:{
				   Stack S1;
				   tao_stack(S1);
				   int x;
				   do{
					   printf("Nhap vao so can chuyen doi: ");
					   scanf("%d", &x);
					   if (x<0) printf("Chi chuyen doi dk so khong am. Nhap lai!");
				   } while (x<0);

				   printf("So %d chuyen sang so nhi phan la: ", x);
				   CoverBinary(S1, x);
				   break;
		}
		}
	} while (temp<6);

	_getch();
}

