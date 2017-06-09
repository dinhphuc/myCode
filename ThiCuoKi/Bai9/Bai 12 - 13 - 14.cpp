#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "List.h"


typedef int item;
struct Node{
	item data;
	Node *next;
};



typedef Node* Stack;

void tao_stack(Stack &S){
	S=NULL;
}

bool isEmpty(Stack S){
	if(S==NULL){
		return true;
	}
	return false;
}

int do_dai(Stack S){
	Node *P=S;
	int i=0;
	while(P!=NULL){
		i++;
		P=P->next;
	}
	return i;
}

Node *tao_node(item x){
	Node *P;
	P=(Node*)malloc(sizeof(Node));
	P->data=x;
	P->next=NULL;
	return P;
}

void Push(Stack &S, item x){
	Node *P=tao_node(x);
	P->next=S;
	S=P;
}

item Peek(Stack S){
	return S->data;
}

item Pop(Stack &S){
	if(!isEmpty(S)){
		item x=S->data;
	    S=S->next;
      	return x;
	}
}

void ReverseList(List L){
	LNode *P=L;
	Stack S;
	tao_stack(S);
	while(P!=NULL){
		Push(S, P->data);
		P=P->next;
	}
	
	while(!isEmpty(S)){
		printf("%3d", Pop(S));
	}
}

main(){
	

	
printf("\n\n1. Dao Danh Sach \n2. Thoat\n\n");
int temp;

do{
	printf("\nChon thao tac: ");
	scanf("%d", &temp);
	switch (temp)
	{
	case 1:
		List L;
		tao_list(L);
		Input(L);
		printf("\nDanh sach vua nhap la: ");
		output(L);
		printf("\nDanh sach sau khi dao la: ");
		ReverseList(L);
		Stack S;
		break;
	case 2:
		break;
	}

} while (temp<2);
}
