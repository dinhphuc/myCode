#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef int item;
typedef struct Node{
	item data;
	Node *next;
	Node *prew;
};

typedef struct List{
	Node *Head;
	Node *End;
};

void tao_ds(List &L){
	L.Head = NULL;
	L.End = NULL;
}

bool isEmpty(List L){
	return (L.Head == NULL) ? true : false;
}
int do_dai(List L){
	int i = 0;
	Node *P, *Q;
	P = L.Head;
	Q = L.End;
	if (P != NULL) i = 1;
	while (P != Q){
		if (P == Q) break;
		P = P->next;
		i++;
		if (P == Q) break;

		Q = Q->prew;
		i++;
	}
	return i;
}

Node *Tao_node(item x){
	Node *P;
	P = (Node*)malloc(sizeof(Node));
	P->data = x;
	P->next = NULL;
	P->prew == NULL;

	return P;
}

void chen_dau(List &L, item x){
	Node *P = Tao_node(x);
	if (isEmpty(L)){
		L.Head = P;
		L.End = P;
	}
	else{
		P->next = L.Head;
		L.Head->prew = P;
		L.Head = P;
	}
}

void chen_cuoi(List &L, item x){
	Node *P = Tao_node(x);
	if (isEmpty(L)){
		L.Head = P;
		L.End = P;
	}
	else{
		L.End->next = P;
		P->prew = L.End;
		L.End = P;
	}
}

void chen_bk(List &L, item x, int k){
	if (k<1 || k>do_dai(L) + 1) printf("Vi tri chen ko hop le!");
	else{
		Node *temp = Tao_node(x);
		Node *P;
		if (k == 1) chen_dau(L, x);
		else if (k == do_dai(L) + 1) chen_cuoi(L, x);
		else{
			int i = 1;
			Node *Q = L.Head;
			while (Q != NULL && i != k - 1){
				Q = Q->next;
				i++;
			}
			P = Q->next;
			temp->next = P;
			temp->prew = Q;
			P->prew = temp;
			Q->next = temp;
		}
	}
}


void xoa_dau(List &L){
	if (isEmpty(L)){
		printf("Khong co du lieu de xoa");
	}
	else{
		Node *P = L.Head;
		L.Head = L.Head->next;
		//L.Head->prew=NULL;
		free(P);
	}
}

void xoa_cuoi(List &L){
	if (isEmpty(L)){
		printf("Khong co du lieu de xoa");
	}
	else{
		Node *P = L.End;
		L.End = L.End->prew;
		L.End->next = NULL;
		free(P);
	}
}

void xoa_bk(List &L, int k){
	if (k<1 || k>do_dai(L)) printf("Vi tri xoa khong hop le");
	else{
		if (k == 1) xoa_dau(L);
		else if (k == do_dai(L)) xoa_cuoi(L);
		else{
			Node *P, *Q;
			P = L.Head;
			int i = 1;
			while (P != NULL && i != k - 1){
				P = P->next;
				i++;
			}
			Q = P->next;
			P->next = P->next->next;
			Q->next->prew = P;
			Q->next = NULL;
			Q->prew = NULL;
			free(Q);
		}
	}
}

int tim_x(List L, item x){
	Node *P = L.Head;
	int i = 1;
	while (P != NULL){
		if (P->data == x){
			return i;
		}
		P = P->next;
		i++;
	}
	return 0;
}

void xoa_x(List &L, item x){
	if (tim_x(L, x) == 0){
		printf("Khong tim thay phan tu can xoa");
	}
	else{
		while (tim_x(L, x) != 0){
			xoa_bk(L, tim_x(L, x));
		}
	}
}

void chen_thutu(List &L, item x, bool opt){
	if (opt){//opt=true chen day tang
		if (x <= L.Head->data) chen_dau(L, x);
		else if (x >= L.End->data) chen_cuoi(L, x);
		else{
			Node *P = L.Head;
			int i = 2;
			while (P->next != NULL){
				if (P->data <= x && P->next->data >= x){
					break;
				}
				else{
					P = P->next;
					i++;
				}
			}
			chen_bk(L, x, i);
		}
	}
	else{
		if (x >= L.Head->data) chen_dau(L, x);
		else if (x <= L.End->data) chen_cuoi(L, x);
		else{
			Node *P = L.Head;
			int i = 2;
			while (P->next != NULL){
				if (P->data >= x && P->next->data <= x){
					break;
				}
				else{
					P = P->next;
					i++;
				}
			}
			chen_bk(L, x, i);
		}
	}
}

void xoa_trung(List &L){
	Node *P = L.Head;
	Node *Q;
	while (P != L.End){
		Q = P->next;
		while (Q != L.End->next){
			if (P->data == Q->data){
				xoa_x(L, P->data);
				P = L.Head;
				break;
			}
			else{
				Q = Q->next;
				if (Q == L.End->next){
					P = P->next;
				}
			}
		}
	}
}

void readFile(char filename[50], List &L){
	FILE *f;
	if ((f = fopen(filename, "r")) == NULL){
		printf("Khong mo dk file!");
	}
	else{
		int n;
		fscanf(f, "%d", &n);
		item x;
		printf("Danh sach co %d phan tu\n", n);
		for (int i = 1; i <= n; i++){
			fscanf(f, "%d", &x);
			chen_bk(L, x, i);
		}
		fclose(f);
	}
}
void Output(List L){
	Node *P = L.Head;
	while (P != L.End->next){
		printf("%3d", P->data);
		P = P->next;
	}
}
void menu()
{
	system("cls");
	printf("\nBai 4 Thao tac vs danh sach lien ket kep:");
	printf("\n1: Chen phan tu x vao vi tri k trong DS");
	printf("\n2: Tim mot phan tu trong DS");
	printf("\n3: Xoa phan tu tai vi tri k");
	printf("\n4: XOa phan tu x trong DS");
	printf("\n\n\n5: Bai 6 Chen phan tu vao day co thu tu");
	printf("\n\n\n6: Bai 8 Xoa phan tu bi trung");
}
void main(){
	List L;
	tao_ds(L);
	readFile("input.cpp", L);
	int temp;
	printf("\nDanh sach nhap tu file la: ");
	Output(L);
	menu();
	do{
		printf("\n\nBan chon: ");
		scanf("%d", &temp);
		switch (temp){
		case 1:{
				   item x;
				   int k;
				   printf("Nhap vao gia tri can chen: ");
				   scanf("%d", &x);
				   printf("Nhap vao vi tri can chen: ");
				   scanf("%d", &k);
				   chen_bk(L, x, k);
				   printf("Danh sach sau khi chen: ");
				   Output(L);
				   break;
		}
		case 2:{
				   item x;
				   printf("Nhap vao phan tu can tim: ");
				   scanf("%d", &x);
				   if (tim_x(L, x) == 0){
					   printf("Khong tim thay phan tu %d", x);
				   }
				   else{
					   printf("Phan tu can tim nam o vi tri thu %d", tim_x(L, x));
				   }
				   break;
		}
		case 3:{
				   int k;
				   printf("Nhap vao vi tri can xoa: ");
				   scanf("%d", &k);
				   xoa_bk(L, k);
				   printf("Danh sach sau khi xoa: ");
				   Output(L);
				   break;
		}
		case 4:{
				   item x;
				   printf("Nhap vao gia tri can xoa: ");
				   scanf("%d", &x);
				   if (tim_x(L, x) == 0){
					   printf("Khong co phan tu can xoa: ");
				   }
				   else{
					   xoa_x(L, x);
					   printf("Danh sach sau khi xoa: ");
					   Output(L);
				   }
				   break;
		}
		case 5:{
				   List L1;
				   tao_ds(L1);
				   readFile("input3.cpp", L1);
				   printf("Danh sach nhap tu file la: ");
				   Output(L1);
				   item x;
				   printf("\nNhap vao phan tu can chen: ");
				   scanf("%d", &x);
				   chen_thutu(L1, x, true);
				   printf("Danh sach sau khi chen: ");
				   Output(L1);
				   break;
		}
		case 6:{
				   List L2;
				   tao_ds(L2);
				   readFile("input1.cpp", L2);
				   printf("Danh sach nhap tu file la: ");
				   Output(L2);
				   xoa_trung(L2);
				   printf("\nDanh sach sau khi xoa trung la: ");
				   Output(L2);
				   break;
		}
		}
	} while (temp<7);
}
