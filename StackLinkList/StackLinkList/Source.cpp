#define _CRT_SECURE_NO_WARNINGS
#include<conio.h>
#include<stdio.h>
#include<windows.h>
typedef int datatype;
struct Node{
	datatype data; // dung de chua kieu du lieu data
	Node *Next;// cho tro next de tro den node ke tiep
	};
typedef Node *List;
int isEmptyList(List L)// kiem tra danh sach co rong hay ko?
{
	return (L==NULL);
}
void InsertAtFirst(List* first,datatype v)// HAM thêm mot nut vao dau danh sach
{
	Node* temp;//Tao ra node moi;
	temp =new(Node);// cap phat contro node
	temp->data= v;
	temp->Next = *first;//Cho con con tro cua node moi tao ra tro den first;
	(*first)= temp;
}



int InsertAtLast(List *first,datatype v)// HAM them mot node vao cuoi danh sach
{		Node *temp;
		temp= new (Node);
		temp->data=v;
	
	if(isEmptyList(*first)==1)
	{
		InsertAtFirst(first,v);
		return 1;
	}
	Node *temp1;
	temp1= *first;
	
	while(temp1->Next!=NULL)
	{
		temp1=temp1->Next;
	} 
	temp1->Next=temp;
	temp->Next=NULL;
	return 1;
}

int InsertAtPos(List *first, datatype v, int Pos)// them mot phan tu vao vi tri bat ki

{
	
	if(isEmptyList(*first)==1)
	{	
		printf("gia tri ban muon them vao");
		scanf("%d",&v);
		InsertAtFirst(first,v);
		return 1;
	}
	
	else
	{	printf("pan muon them vao phan tu so : ");
		scanf("%d",&Pos);
		printf("gia tri ban muon them vao");
		scanf("%d",&v);
	
		Node *temp1;// tao ra mot node temp 1 duyet  tu dau den vi tri can them vao hoawc den hets danh sach
		temp1= *first;
		int t =0;
		while(temp1!=NULL)
		{
			t++;
			temp1=temp1->Next;
		}
		if((0<Pos)&&(Pos<t))
		{
			Node *temp;
			temp= new Node;
			temp->data=v;
			temp1 = *first;
			for(int i=1;i<(Pos-1);i++) 
			{
				temp1=temp1->Next;
			}
			temp->Next=temp1->Next;
			temp1->Next=temp;
		}	
		if(Pos>t)
		{
			printf("vi tri ban muon them ko ton tai ");
			exit(0);
		}
	}
		
		
		}

 

int DeleteAtFirst(List *first)//Ham xoa 1 phan tu o dau danh sach
{
	if(isEmptyList(*first)==1) printf("DANH SACH NAY DANG RONG KO THE XOA DC");
	else
	{	
		Node *temp;
		temp= new Node;
		temp=*first;//gan temp cho chinh con tro phan tu dau
		*first=temp->Next;
		delete(temp);
			printf("\nphan tu dan dc xoa an 6 de kiem tra lai danh sach:");
	}
	return 1;
	
}
int DeleteAtPos(List * first, int Pos)// xoa 1 phan tu bat ki
{
	if(isEmptyList(*first)==1)
	{
		printf("\ndanh sach rong ko xoa dc");
		return 1;
	}
	else
	{	printf("\nnhap vao vi tri muon xoa: ");
		scanf("%d",&Pos);
		int t=1;
		Node *temp1,*temp2;
		temp1=*first;
	
		while((temp1->Next!=NULL)&&(t<(Pos-1)))
		{	
		temp1=temp1->Next;
		t++;
		}
		temp2=temp1->Next ;
		temp1->Next=temp2->Next;
		delete(temp2);
		}	
		
		//printf("\n=>phan tu ban muon xoa ko nam trong danh sach");	
	}


int DeleteAtLast(List *first)// Ham xoa phan tu o cuoi LIST
{	int t=0;
	if(isEmptyList(*first)==1)
	{
	printf("Danh sach rong ko the xoa sc !!!!!!!!!!!!!!!");
	return 1;	
	}
	else
	{ Node *temp1, *temp2;
	temp1=temp2=*first;
	while(temp2->Next!=NULL)
	{
		temp2=temp2->Next;
		
	}
	while(temp1->Next!=temp2)
	{
		temp1=temp1->Next;
	}
	temp1->Next=NULL;
	delete(temp2);
	
	}
}



 
//void input(List *first,FILE *f,char duongdan[45])
//{	int v;
//
//	printf("nhap ten file can lay:\n");
//	gets(duongdan);
//	f=fopen(duongdan,"r");
//	//printf("\nhay nhap 1 pt cho danh sach:\n");
//	printf("\nso phan tu lay ra tu file: ");
//	fscanf(f,"%d",&v);
	
//	if(isEmptyList(*first)==1)// kiem tra co pt dau tien hay ko
//	InsertAtFirst(first,v);// thi them vao dau danh sach
//	else
//	InsertAtLast(first,v);// neu danh sach ko rong thi them vao sau phan tu do
//	fclose(f);
//}

	datatype docfile(FILE *f)
	{
	datatype v;
	fscanf(f,"%d",&v);
	return v;
	}
void output (List L){
	
	Node *first = L;
	while (first!=NULL){
		printf (" %d ", first->data);
		first=first->Next;
	}
}
//in ra menu
void menu()	
{
	printf("++++++++++++++++++++++++MENU++++++++++++++++++++++++\n");
	printf("1.kiem tra danh sach co rong ko\n");
	printf("2.Nhap danh sach\n");
	printf("3.them vao dau danh sach\n");
	printf("4.them vao sau danh sach\n");
	printf("5.them vao vi tri bat ki vao danh sach \n");
	printf("6.in ra danh sach\n");
	printf("7.xoa phan tu dau cua danh sach\n");
	printf("8.xoa mot vi tri bat ki trong List\n");
	printf("9. vi tri cuoi trong List\n\n");	
	printf("123.XOA MAN HINH\n");
	printf("456.IN MENU\n\n");
	
}
int main()                                   
{	List L =NULL;// toa ra mot danh sach rong vs phan tu dau tien la first
	int X,Y,Z=0,vitri=0,v;
	int LUACHON;
	char duongdan[45];// tao ra 1 file de lay data
	FILE *f;
	
	menu();
	do{
	printf("\n\nlua chon cua ban la: ");
	scanf("%d", &LUACHON);
                 	 
 		 int t=0;
	switch(LUACHON)
	{	case 123:
				 system("cls"); 
				 break;// xoa man hinh
		case 456: menu(); break;// in menu
	
		case 1:// kiem tra danh sach
				if(isEmptyList(L)==1) 
				printf("\n=> DANH SACH NAY RONG!");
				else
				printf("=> DANH SACH NAY KO RONG DAU! ");
				break;
		
		case 2:
			fflush(stdin);
			printf("nhap ten file can lay:\n");
			gets(duongdan);
			f=fopen(duongdan,"r");
			char c;
			
				do{		InsertAtLast(&L,docfile(f));
						printf("\nnhap enter de tt :");	
						c=_getch();
				}while(c==13);
					
			fclose(f);
			break;
		// nhap phan tu vao danh sac
//				if(isEmptyList(L)==1) 
//				printf("=>danh sach rong ");
//				else
//				{
//				printf("=>danh sach ko rong");
//				printf("\n\nnhap vao danh sach");
//				}
//				char c;
//				do{
				//input(&L,f,duongdan);
//					printf("bam enter de nhap tiep:\n");
//					c=getch();
//					
//				}while(c==13);
		
		
		
		case 3:// them 1 phan tu vao dau danh sach
				printf("ban muon them phan tu nao vao danh sach : ");
				scanf("%d",&X);
				InsertAtFirst(&L,X);
				break;
		case 4:// 
				printf("ban muon them cao phan tu nao: ");
				scanf("%d",&Y);		
				InsertAtLast(&L,Y);
				break;
		case 5:	// them 1 phan tu sau danh sach 	
			InsertAtPos(&L,Z,vitri);
			break;
		
		
			
		case 6:// in ra danh sach
				printf("\n\t\t\t\=====>danh sach la :");
				output(L);
				break;
		
		
		case 7:// xoa phan tu dau cua danh sach
				DeleteAtFirst(&L);
				break;
				
		case 8:// xoa phan tu bat ki
				DeleteAtPos(&L,vitri);
				break;
				
		case 9:// xoa phan tu o cuoi List
		DeleteAtLast(&L);
		break	;
							
		}}while(LUACHON!=0);
	//	InsertAtFirst(&L,32);// them pt 32 vao dau danh sach
		
		
		_getch();
		return 0;
	
}
