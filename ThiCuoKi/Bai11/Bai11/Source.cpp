#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int item;
struct Node{
	item data;
	Node *prev;
	Node *next;
};
struct Queue{
	Node *Head, *End;
};
void tao_queue(Queue &Q){
	Q.Head = NULL;
	Q.End = NULL;
}
bool isEmpty(Queue Q){
	if (Q.Head == NULL){
		return true;
	}
	else{
		return false;
	}
}
Node *Tao_Node(item x){
	Node *p = (Node*)malloc(sizeof(Node));
	p->next = NULL;
	p->prev = NULL;
	p->data = x;
	return p;
}
void Push(Queue &Q, item x){//Them vao cuoi
	Node *p = Tao_Node(x);
	if (isEmpty(Q)){
		Q.Head = p;
		Q.End = p;
	}
	else{
		Q.End->next = p;
		p->prev = Q.End;
		Q.End = p;
	}
}
item Pop(Queue &Q){//Xoa dau va in ra gia tri phan tu
	if (isEmpty(Q)) return 0;
	Node *p = Q.Head;
	item x = p->data;
	Q.Head = Q.Head->next;
	if (Q.Head == NULL)
		Q.End == NULL;
	free(p);
	return x;
}
item Peek(Queue Q){
	return Q.Head->data;
}
void readFile(char filename[50], Queue &Q){
	FILE *f;
	int n;
	item x;
	if ((f = fopen(filename, "r")) == NULL){
		printf("Khong mo duoc file");
	}
	else{
		fscanf(f, "%d", &n);
		printf("Queue gom %d phan tu", n);
		for (int i = 1; i <= n; i++){
			fscanf(f, "%d", &x);
			Push(Q, x);
		}
	}
}
void Output(Queue Q){
	Node *p = Q.Head;
	while (p != Q.End->next){
		printf("%3d", p->data);
		p = p->next;
	}
	printf("\n");
}
void main(){
	Queue Q;
	tao_queue(Q);
	readFile("input.cpp", Q);
	printf("\nQueue dk nhap tu file la: ");
	Output(Q);
	int temp;
	printf("Moi ban chon phep toan voi DS LKD:");
	printf("\n1: Kiem tra Queue rong");
	printf("\n2: Them phan tu vao Queue");
	printf("\n3: Xoa phan tu trong Queue");
	printf("\n4: Xuat Queue");
	printf("\n5: Thoat");
	do
	{
		printf("\nBan chon: ");
		scanf("%d", &temp);
		switch (temp)
		{
		case 1:
		{
				  if (isEmpty(Q)) printf("Queue rong !");
				  else printf("Queue khong rong !");
				  break;
		}
		case 2:
		{
				  item x;
				  printf("Nhap phan tu can chen vao Queue: ");
				  scanf("%d", &x);
				  Push(Q, x);
				  break;
		}
		case 3:
		{
				  Pop(Q);
				  break;
		}
		case 4:
		{
				  Output(Q);
				  break;
		}
		case 5: break;
		}
	} while (temp != 5);
}
