#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#define N 100 

struct Stack {
	int top;
	int  ArrStack[N];

};


void Init(Stack &s)
{ 
	s.top = 0;
}

//Kiem Tra Danh scash rong

bool IsEmpty(Stack &s)
{
	return(s.top == 0);	
}

//kiem tra danh sach day
bool IsFull(Stack &s)
{
	return(s.top == N);
}
// them cac phan tu vao danh sach
void InPut(Stack &s)
{
	printf("\nNhap vao so Luong phan tu: ");
	scanf_s("%d", &s.top);
	for (int i = 0; i < s.top; i++)
	{
		printf("A[%d]= ", i + 1);
		scanf_s("%d", &s.ArrStack[i]);
	}
}
// xuat danh sach
void OutPut(Stack &s)
{ 
	if (!IsEmpty(s)&&!IsFull(s))
	{

		for (int i = s.top - 1; i >= 0; i--)
		{
			printf("A[%d]= %d \n", i + 1, s.ArrStack[i]);
		}

	}
	else
	{
		IsEmpty(s) ? printf("Empty !!!!\n\n") : printf("NOT Empty\n\n");
		IsFull(s) ? printf("FULL !!!!\n\n") : printf("NOT FULL \n\n");
	}
}
// them 1 phan tu vao cuoi danh sach 
void AddTop(Stack &s )

{ 
	int x;
	printf("\nNhap Vap Phan Tu can them : ");
	scanf_s("%d", &x);
	if (!IsFull(s)){
		s.ArrStack[s.top] = x;
		s.top++;
	}
	

	/*if (IsEmpty(s))
	{
		printf("Khon Rong ");
	}
	else
	{
		printf("R");
	}
	if (IsFull(s))
	{
		printf("K Full ");
	}
	else
	{
		printf("Full");
	}*/
}
//Xoa 1 phan tu stack
void Delete(Stack &s)
{ 
	if (!IsEmpty(s))
	{
		s.top--;
	}
		

	
}
void GhiFile (Stack &s)
{
	long size = sizeof(s);

	FILE *F;
	F = fopen("PhucBinz.txt", "wb");
	printf("\nNhap vao so Luong phan tu: ");
	scanf_s("%d", &s.top);
	for (int i = 0; i < s.top; i++)
	{
		printf("A[%d]= ", i + 1);
		scanf_s("%d", &s.ArrStack[i]);
		fwrite(&s, size, 1, F);
	}
	fclose(F);
//	fwrite("%d", sizeof(int), 2, F);
}
void ShowDataFILE(Stack &s)
{
	long size = sizeof(s);
	FILE *F;
	F = fopen("PhucBinz.txt", "r");
	int i = 0;
	while (fread(&s, size, 1, F) > 0)
	{
		i++;
		printf("A[%d]= ", s.top);
		printf("%d \n", s.ArrStack[i]);
	}
	fclose(F);
}
void Menu()
{ 
	Stack s;
	Init(s);
	printf("1. Kiem Tra Danh sach Rong\n");
	printf("2. Kiem Tra Danh sach Day\n");
	printf("3. Nhap Danh sach\n");
	printf("4. Them Mot Phan Tu vao danh sach\n");
	printf("5. Xoa 1 phan tu Khoi danh sach\n");
	printf("6. Xem Danh sach \n");
	printf("7. exit\n\n\n\n");
	int Chose;
	do{
		printf("Nhap Vao So ban Lua chon : ");
		scanf_s("%d", &Chose);

		switch (Chose)
		{
		case 1:
		{
				  IsEmpty(s) ? printf("Empty !!!!\n\n") : printf("NOT Empty\n\n");
				  break;
		}
		case 2:
		{
				  IsFull(s) ? printf("FULL !!!!\n\n") : printf("NOT FULL \n\n");
				  break;
		}
		case 3:
		{
				  InPut(s);
				  break;
		}
		case 4:
		{
				  AddTop(s);
				  break;
		}
		case 5:
		{
				  GhiFile(s);
				 // Delete(s);
				  break;
		}
		case 6:
		{
				  ShowDataFILE(s);
				  //OutPut(s);
				  break;
		}
		case 7:
		{

				  break;
		}



		}
	} while (Chose != 7);
}
void main()
{
	Menu();
	
	_getch();
}