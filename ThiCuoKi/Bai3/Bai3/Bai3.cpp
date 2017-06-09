#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>
#define max 10000

typedef int item;

typedef struct list
{
	item Array[max];
	int size;
};
void CreatList(list &L)
{
	L.size = 0;
}
bool IsNull(list &L)
{
	return (L.size == 0) ? true : false;
}
int IsFull(list &L)
{
	return (L.size == max) ? true : false;
}
// CHÈN VÀO VI TRÍ BẤT KÌ
void chen_bk(list &L, item x, int k){
	if (IsNull(L)){
		printf("Danh sach full!");
	}
	else if (k<1 || k> L.size + 1){
		printf("Vi tri chen khong hop le!");
	}
	else{
		for (int i = L.size; i >= k; i--){
			L.Array[i + 1] = L.Array[i];
		}
		L.Array[k] = x;
		L.size++;
	}
}
// TÌM MỘT PHẦN TỬ BẤT KÌ QUA VỊ TRÍ
void TimX(int b[] ,list L, item x, int *Soluong)
{
	b[max] = { 0 };
	int j=0;
	for (int i = 0; i < L.size; i++)
	{
		if (L.Array[i] == x)
		{
			b[j] = i+1;
			j++;
		}
		*Soluong = j;
	}
	
}
// XÓA MỘT PHẦN TỬ BẤT KÌ QUA VỊ TRÍ
void XoaBatKi(list &L, int k)
{
	if (!IsNull)
	{
		printf("Danh Sach Rong");
		return;
	}
	else
	{
		if (L.size+1 < k||k < 1)
		{
			printf("Ban Nhap Vi Tri Khong Hop Le");
		}
		else
		{
			for (int i = k-1; i < L.size; i++)
			{
				L.Array[i] = L.Array[i + 1];
			}
			L.size--;
		}
	}
}
//XÓA MỘT PHẦN TỬ BẤT KÌ QUA GIÁ TRỊ
void XoaX(list &L, item x)
{
	if (!IsNull)
	{
		printf("Danh Sach Rong");
		return;
	}
	else
	{
		if (x < 0)
		{
			printf("Ban Nhap Vi Tri Khong Hop Le");
		}
		else
		{
			for (int i = 0; i < L.size; i++)
			{
				if (L.Array[i] == x)
				{		
					for (int j = i; j < L.size; j++)
					{
						L.Array[j] = L.Array[j + 1];
						i--;
					}	
					L.size--;
				}
				
			}
		}
	}
}
//TẠO FILE VỚI SỐ LƯỢNG PHẦN TỬ
void CreatFIle(list &L)
{
	system("cls");
	
	printf("Nhap Vao so Luong Phan Tu cua FILE n: ");
	scanf("%d", &L.size);
	FILE *F;

	F = fopen("input.txt", "w");
	if (F == NULL)
	{
		printf("\n\nFile Not exists");
		_getch();

		return;
	}
	else{
		for (int i = 0; i < L.size; i++)
		{
			int temp;
			temp = rand() % L.size;
			fprintf(F, "%d ", temp);

		}
		fclose(F);
		printf("\n\nDone! xong.\n");
		printf("\n\nPress any key to continue...");
		_getch();
	}
}
// LẤY DỮ LIỆU ĐỌC VÀO FILE
void Input(list &L,int *n)
{
	FILE *F;
	F = fopen("input.txt", "r");
	if ((F) == NULL)
	{
		printf("\n\nFile Not exists");
		_getch();

		return;
	}
	else{
		int i = 0;
		while (!feof(F))
		{
			int temp;
			fscanf(F, "%d", &temp);
			if (!feof(F)){
				L.Array[i] = temp;
				i++;
			}
			*n = i;
		}
	}
	fclose(F);
}
//XUẤT DỮ LIỆU RA MÀN HÌNH CONSOLE
void Output(list L,int n){
	printf(" Danh Sach : \n\n");
	for (int i = 0; i < L.size; i++){
		printf(" %d", L.Array[i]);	
	}

}
//MENU CHÍNH
void Menu() 
{
	
	system("cls");
	printf("\n\t\t\t--------------KIEM TRA HK1---------------\n\n");
	printf("Bai Tap 3: Cai Dat cac thao tac voi Danh sach lien ket don ( Use Array )\n\n");
	printf("\t Chose (1-n) : \n");
	printf("\t 0. tao file  \n");
	printf("\t 1. Chen them  \n");
	printf("\t 2. Tim  \n");
	printf("\t 3. Xoa  \n");
	printf("\t 4. Xoa vi tri bat ki \n");
	printf("\t 5. Exit \n\n\n\n\n");
	

}
void main()
{
	int A[max];
	list L;
	CreatList(L);
	Menu();
	int c, n, soluong;
	int B[max];
	do
	{
		printf("\n\n\nNhap Vao Lua Chon: ");
		scanf("%d", &c);
		switch (c)
		{
		case 0: //TẠO FILE VỚI SỐ LƯỢNG PHẦN TỬ
			CreatFIle(L);
			Input(L, &n);
			Menu();
			break;
		case 1:// CHÈN VÀO VỊ TRÍ BẤT KÌ
			system("cls");
		
			Input(L, &n);
			L.size = n;
			Output(L, n);
			item x;
			int c;
			do{
				int k;
				printf("\nNhap gia tri can chen: ");
				scanf("%d", &x);
				printf("\nNhap vi tri can chen: ");
				scanf("%d", &k);
				chen_bk(L, x, k);
				printf("\nSau khi chen ");
				Output(L, n);
				printf("\n\n\nEnter De chen tiep.\nESC de thoat ");
				c = _getch();
			} while (c == 13);
			printf("\n\nPress any key to continue...");
			_getch();
			Menu();
			break;
		case 2: // TÌM MỘT PHẦN TỬ BẤT KÌ QUA VỊ TRÍ
		{
					system("cls");
					Input(L, &n);
					L.size = n;
					Output(L, n);
					item x;
					int c;
					do{
						printf("\n\n\nNhap phan tu can tim: ");
						scanf("%d", &x);

						printf("\nvi tri chua phan tu x la: ");
						
						TimX(B, L, x, &soluong);
						if (soluong == 0) printf("\n\n   Khong co ");
						for (int j = 0; j < soluong; j++) printf("%3d ", B[j]);
						printf("\n\n\nEnter De tim tiep.\nESC de thoat ");
						c = _getch();
					} while (c == 13);
					printf("\n\nPress any key to continue...");
					_getch();
					Menu();
					break;
		}

		case 3: // XÓA MỘT PHẦN TỬ BẤT KÌ QUA VỊ TRÍ
		{

					system("cls");
					Input(L, &n);
					L.size = n;
					Output(L, n);
					do{
						int k;
						printf("\n\nNhap Phan tu can xoa: ");
						scanf("%d", &k);
						XoaX(L, k);
						printf("\n\nSau Khi Xoa");
						Output(L, n);
						printf("\n\n\nEnter De Xoa tiep.\nESC de thoat ");
						c = _getch();
					} while (c == 13);
					printf("\n\nPress any key to continue...");
					_getch();
					Menu();

		}
			break;
		case 4: // XÓA MỘT PHẦN TỬ BẤT KÌ QUA VỊ TRÍ
		{
					system("cls");
					Input(L, &n);
					L.size = n;
					Output(L, n);
					int c;
					do{
						
						int k;
						printf("\n\nNhap vao vi tri can xoa: ");
						scanf("%d", &k);
						XoaBatKi(L, k);
						printf("\n\nSau Khi Xoa");
						Output(L, n);
						printf("\n\n\nEnter De tim tiep.\nESC de thoat ");
						c = _getch();
					} while (c == 13);
					printf("\n\nPress any key to continue...");
					_getch();
					Menu();
		}
			break;
		case 5:
			return;
			break;
		}
		} while (c < 6);
	
		_getch();
	
}
