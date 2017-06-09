#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef int item;
struct Node{
	item data;
	Node *next;
	Node *prew;
};

typedef struct Stack{
	Node *Top;
};

void tao_stack(Stack &S){
	S.Top = NULL;
}

bool isEmpty(Stack S){
	return (S.Top == NULL) ? true : false;
}

int do_dai(Stack S){
	Node *P = S.Top;
	int i = 0;
	while (P != NULL){
		i++;
		P = P->next;
	}
	return i;
}

Node *tao_node(item x){
	Node *P = (Node*)malloc(sizeof(Node));
	P->data = x;
	P->next = NULL;
	P->prew = NULL;
	return P;
}

void Push(Stack &S, item x){
	Node *P = tao_node(x);
	P->next = S.Top;
	S.Top = P;
}

int Peek(Stack S){
	return S.Top->data;
}

item Pop(Stack &S){
	if (!isEmpty(S)){
		item x = S.Top->data;
		S.Top = S.Top->next;
		return x;
	}
}

void readFile(char filename[50], Stack &S){
	FILE *f;
	if ((f = fopen(filename, "r")) == NULL){
		printf("khong mo dk tep!");
	}
	else{
		int n;
		item x;
		fscanf(f, "%d", &n);
		printf("Stack gom co %d phan tu", n);
		for (int i = 1; i <= n; i++){
			fscanf(f, "%d", &x);
			Push(S, x);
		}
		fclose(f);
	}
}

void Output(Stack S){
	Node *P = S.Top;
	while (P != NULL){
		printf("%3d", P->data);
		P = P->next;
	}
}

void main(){
	Stack S;
	tao_stack(S);
	readFile("input.cpp", S);
	printf("\nStack nhap tu file la: ");
	Output(S);
	printf("\nThao tac vs Stack: \n1. Kiem tra stack rong\n2. Do dai stack\n3. Them phan tu vao Stack\n4. Xoa phan tu khoi Stack\n5. Thoat");
	int temp;
	do{
		printf("\nChon thao tac: ");
		scanf("%d", &temp);
		switch (temp){
		case 1:{
				   if (isEmpty(S)){
					   printf("Stack rong!");
				   }
				   else{
					   printf("Stack khong rong!");
				   }
				   break;
		}
		case 2:{
				   printf("Do dai cua stack la: %d", do_dai(S));
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
				   Pop(S);
				   printf("\nStack sau khi xoa phan tu: ");
				   Output(S);
				   break;
		}
		case 5:{
				   break;
		}
		}
	} while (temp<5);
}
