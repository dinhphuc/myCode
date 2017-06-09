#include<stdio.h>
#include<stdlib.h>

typedef int item;
typedef struct LNode{
	item data;
	LNode *next;
};

typedef LNode *List;

void tao_list(List &L){
	L=NULL;
}

int do_dai(List L){
	LNode *P = L;
	int i=0;
	while(P!=NULL){
		i++;
		P=P->next;
	}
	return i;
}

LNode *tao_node(LNode *P, item x){
	P= (LNode*)malloc(sizeof(LNode));
	P->next=NULL;
	P->data=x;
}

void chen_dau(List &L, item x){
	LNode *P;
	P=tao_node(P, x);
	P->next=L;
	L=P;
}

void chen_bk(List &L, item x, int k){
	LNode *P, *Q;
	Q = L;
	int i = 1;
	if(k<1||k>do_dai(L)+1) printf("Vi tri chen ko hop le.");
	else{
		P = tao_node(P, x);
		if(k==1) chen_dau(L, x);
		else{
			while(Q!=NULL && i!=k-1){
				i++;
				Q=Q->next;
			}
			P->next=Q->next;
			Q->next=P;
		}
	}
}

int tim_node(List L, item x){
	LNode *P=L;
	int i=1;
	while(P!=NULL && P->data!=x){
		P=P->next;
		i++;
	}
	if(P!=NULL) return i;
	else return 0;
}

void xoa_dau(List &L){
	LNode *P=L;
	L=L->next;
	free(P);
}

void xoa_bk(List &L, int k){
	LNode *P, *Q=L;
	int i=1;
	if(k<1 || k>do_dai(L)) printf("Vi tri xoa ko hop le");
	else{
		if(k==1) xoa_dau(L);
		else{
			while(Q!=NULL && i!=k-1){
				Q=Q->next;
				i++;
			}
			P=Q->next;
			Q->next=Q->next->next;
			free(P);
		}
	}
}

void xoa_x(List &L, item x){
	while(tim_node(L, x)!=0){
		xoa_bk(L, tim_node(L, x));
	}
}
void Input(List &L){
	item x;
	int i=1;
	printf("Nhap vao danh sach: ");
	printf("\nAn 0 de ket thuc.\n");
	
	do{
		printf("Nhap vao so thu %d: ", i);
		scanf("%d", &x);
		if(x!=0) chen_bk(L, x, i);
		i++;
	}while(x!=0);
}

void output(List L){
	LNode *P=L;
	while(P!=NULL){
		printf("%3d", P->data);
		P=P->next;
	}
	printf("\n");
}
