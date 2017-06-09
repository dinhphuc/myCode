#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

typedef int DataType;
struct Node{
	DataType data;
	Node*next;
};
typedef Node*List;
int isEmptyList(List L){
	return (L == NULL);
}
void insertAtFirst(List *fist, DataType x)
{
	Node *temp = new Node;
	temp->data = x;
	temp->next = *fist;
	*fist = temp;
}
int insertAtLast(List*first, DataType v){
	
	Node *temp, *temp1;
	temp = new Node;
	temp->data = v;
	temp->next = NULL;
	if (*first == NULL)
	{
		*first = temp;
	}
	else
	{
		temp1 = *first;
		while (temp1->next!=NULL)
		{
			temp1 = temp1->next;	
		}
		/*temp->next = NULL;*/
		temp1->next = temp;
	}
	
	return 1;

}
void ReadtoList(List *first, char *fname){
	int v;
	FILE *f;
	f = fopen(fname, "r+");
	while (1){
		fscanf(f, "%d", &v);
		if (feof(f) != 0) break;
		insertAtLast(first, v);
	}
	fclose(f);
}
void ChenDaytang(List*first, DataType v){
	Node *temp, *temp1;
	temp = *first;
	temp1 = new Node;
	temp1->data = v;
	while (1)
	{
		if (temp->data > v)
		{
			insertAtFirst(first, v);
			break;
		}
		if (temp->data >= v)
		{
			temp1->next = temp->next;
			temp->next = temp1;
			break;
		}
		if ((temp->data < v) && (temp->next->next == NULL))
		{
			insertAtLast(first, v);
			break;
		}

		temp = temp->next;
	}

}
void ChenDayGiam(List*first, DataType v){
	Node*Temp, *Temp1;
	Temp = *first;
	Temp1 = new (Node);
	Temp1->data = v;
	while (1){
		if (Temp->data<v){
			insertAtFirst(first, v);
			break;
		}
		if ((Temp->next->data) <= v){

			Temp1->next = Temp->next;
			Temp->next = Temp1;
			break;
		}
		if (((Temp->next->data)>v) && (Temp->next->next) == NULL)
		{
			insertAtLast(first, v);
			break;
		}
		Temp = Temp->next;
	}
}

void DeleteDulp(List*first){
	Node*Temp = *first;
	Node*Temp1;
	while (Temp->next != NULL){
		while (1){
			if ((Temp->data) == (Temp->next->data)){
				Temp1 = Temp->next;
				Temp->next = Temp->next->next;
				free(Temp1);
			}
			else break;
		}
		Temp = Temp->next;
	}
}

void outPut(List L){
	Node*first = L;
	while (first != NULL){
		printf("%d ", first->data);
		first = first->next;
	}
	printf("\n");
}
void menu(){
	printf("1.De them vao day khong giam \n2.De them vao day khong tang\n3.Xoa Phan Tu trung Nhau\n");
}

int main(){
	int n;
	int lua_chon;


	do{
		system("cls");
		menu();
		printf("\nNhap Lua chon :");
		scanf("%d", &lua_chon);
		switch (lua_chon){
		case 1:{
				   List L = NULL;
				   ReadtoList(&L, "tang.txt");
				   do{
					   system("cls");
					   printf("\Danh sach Nhap tu File: ");
					   outPut(L);
					   printf("\nNhap gia tri can them: ");
					   scanf("%d", &n);
					   ChenDaytang(&L, n);
					   printf("\nDanh Sach Sau Khi them: ");
					   outPut(L);
					   printf("Nhan Enter de tiep tuc\n");
					   printf("\n\nPress any key to END...");
				   } while (_getch() == 13);
				   break;
		}
		case 2:{
				   List L = NULL;
				   ReadtoList(&L, "giam.txt");
				   do{
					   system("cls");
					   printf("\Danh sach Nhap tu File: ");
					   outPut(L);
					   printf("\nNhap gia tri can them: ");
					   scanf("%d", &n);
					   ChenDayGiam(&L, n);
					   printf("\nDanh Sach Sau Khi them: ");
					   outPut(L);
					   printf("Nhan Enter de tiep tuc\n");
					   printf("\n\nPress any key to END...");
				   } while (_getch() == 13);
				   break;
		}
		case 3:
		{

				  List L = NULL;
			  	  ReadtoList(&L, "tang.txt");				  
					  system("cls");
					  DeleteDulp(&L);
					  printf("Sau Khi Xoa: ");
					  outPut(L);
					  printf("\n\nPress any key to END...");
				      _getch();
				  break;
		}

		}
		} while (lua_chon < 4);
	
}

