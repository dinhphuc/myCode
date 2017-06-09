#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

typedef int DataType;
struct Node{
	DataType data;
	Node *next;
};
typedef Node* List;
typedef Node* Stack;

int InputFromFile(const char [], List*);
int OutputToFile(const char [], List*);
void Menu();
void executePractice7();

int main(){
	char choice;
	while(1){
		Menu();
		do{
			choice = getch();
		}while((choice!=27)&&(choice!='1'));
		system("cls");
		switch(choice){
			case 27:{
				printf("\nKet thuc chuong trinh\n");
				getch();
				return 1;
			}
			case '1':{
				executePractice7();
				break;
			}
		
		}
		getch();
	}
}

void Menu(){
	system("cls");
	printf("\t\t\t ********************************\n");
	printf("\n\t\tTHI KET THUC HOC PHAN - BO MON: KY THUAT LAP TRINH\n");
	printf("\n\t\tBAI THUC HANH 11-14: MOT SO BAI TOAN SU DUNG STACK\n");
	printf("\n\t\t\t ********************************\n");
	printf("\nChon cong viec muon thuc hien:\n\n");
	printf("\t1.\tBai 7: Chuyen doi so nguyen duong sang he nhi phan.\n");

	printf("\nNhan ESC de thoat chuong trinh.\n\n");
}
int IsEmptyList(List *first){
	return !*first;
}
int ListLength(List *first){
	int length; Node *countTemp;
	for(length=0, countTemp=*first; countTemp; length++, countTemp=countTemp->next);
	return length;
}
void InsertAtFirst(List *first, DataType value){
	Node *Temp = new (Node);
	Temp->data = value;
	Temp->next = *first;
	*first = Temp;
}
void InsertAtLast(List *first, DataType value){
	if(IsEmptyList(first)) InsertAtFirst(first, value);
	else{
		Node *countTemp, *Temp = new (Node);
		Temp->data = value;
		Temp->next = NULL;
		for(countTemp=*first; countTemp->next; countTemp=countTemp->next);
		countTemp->next = Temp;
	}
}
void DeleteAtFirst(List *first){
	if(!IsEmptyList(first)){
		Node *Temp = *first;
		*first = Temp->next;
		free(Temp);
	}
}
void DeleteAtLast(List *first){
	if(ListLength(first)<=1) DeleteAtFirst(first);
	else{
		Node *Temp;
		for(Temp=*first; Temp->next->next; Temp=Temp->next);
		free(Temp->next);
		Temp->next = NULL;
	}
}
int InputFromFile(const char filename[], List *first){
	FILE *f = fopen(filename, "r");
	if(!f){
		fclose(f);
		return 0;
	}
	int Buffer;
	fscanf(f, "%d", &Buffer);
	return Buffer;
}
int OutputToFile(const char filename[], List *first){
	FILE *f = fopen(filename, "w");
	if(IsEmptyList(first)){
		fclose(f);
		return 0;
	}
	while(!IsEmptyList(first)){
		fprintf(f, "%d ", (*first)->data);
		DeleteAtFirst(first);
	}
	fclose(f);
	return 1;
}
int IsEmptyStack(Stack *firstStack){
	return !*firstStack;
}
void MakeEmptyStack(Stack *firstStack){
	while(!IsEmptyStack(firstStack)){
		DeleteAtFirst(firstStack);
	}
}
void PushToStack(Stack *firstStack, DataType value){
	InsertAtFirst(firstStack, value);
}
int PopFromStack(Stack *firstStack, DataType *value){
	if(IsEmptyStack(firstStack)) return 0;
	*value = (*firstStack)->data;
	DeleteAtFirst(firstStack);
	return 1;
}
DataType* PeekFromStack(Stack *firstStack){
	DataType *Temp = NULL;
	if(!IsEmptyStack(firstStack)) Temp = &(*firstStack)->data;
	return Temp;
}
int IntegerToBinary(int n, Stack *firstStack){
	if(n<0) return 0;
	else if(!IsEmptyStack(firstStack)) MakeEmptyStack(firstStack);
	for(n; n!=0; PushToStack(firstStack, n%2), n = n/2);
	return 1;
}
int OutprintBinary(List *firstStack){
	if(IsEmptyStack(firstStack)) return 0;
	for(Node *Temp=*firstStack; Temp; Temp=Temp->next){
		 printf("%d", Temp->data);
	}
	return 1;
}
void executePractice7(){
	fflush(stdin);
	int n; List S = NULL;char choice;
	printf("Ban muon nhap so tu ban phim hay lay tu file?:\n");
	printf("\n\t\t1.Nhap tu ban phim\n");
	printf("\n\t\t2.Lay tu file\n");
	choice = getch();
	switch(choice){
		case '1':	printf("Nhap so nguyen duong muon chuyen sang he nhi phan:\n\n");
					scanf("%d", &n);
					if(IntegerToBinary(n, &S)){
					printf("\nChuyen doi thanh cong. Ket qua:\n\n");
					OutprintBinary(&S);
					}
					else printf("\nCo loi xay ra!\nSo da nhap khong la so nguyen duong.");
					break;
		case '2':	char filename[50];
					printf("Nhap ten File muon doc:\n\n");
					gets(filename);					
					n=InputFromFile(filename, &S);
					if(IntegerToBinary(n, &S)){
					printf("\nChuyen doi thanh cong. Ket qua:\n\n");
					OutprintBinary(&S);
					}
					else printf("\nCo loi xay ra!\nSo da nhap khong la so nguyen duong.");
					break;
	}

}
