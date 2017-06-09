#include <stdio.h>
#include <conio.h>


 bool KT(int Y) {
	 if ((Y % 4) == 0 || (Y % 100 != 0) && (Y % 400 == 0))
	 {

		 return true;
	 }
	return false ;
	/**
	*
	* True là năm nhuận flase là năm không nhuận
	*/
}
 void FullDay(int Y, int M, int D) {
	 if (Y <= 0) {
		printf("Sai Dinh dang Nam");
	 }
		 if (M <= 0 || M >= 12) {
			printf("Sai DInh Dang Thang");
		 }
	switch (M) {
	case 2:
		if ((Y % 4) == 0 || (Y % 100 != 0) && (Y % 400 == 0)) {
			if ((D <= 0) || (D >= 30)) {
				printf("Sai Dinh Dang Ngay");
			}
		}
			if ((Y % 4) != 0 || (Y % 100 == 0) && (Y % 400 != 0))
			{
				if ((D <= 0) || (D >= 29))
				{
					printf("Sai Dinh Dang Ngay");
				}
			}
			
		
		break;
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		if ((D <= 0) || (D >= 32)) {
			printf("Sai Dinh Dang Ngay");

		}
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		if ((D <= 0) || (D >= 31)) {
			printf("Sai Dinh Dang Ngay");
		}
		break;
	}

}



void NhapNgayThangNam() {
	int D, M, Y;
	printf("Nhap Vao Ngay: ");
	scanf_s("%d", &D);
	printf("Nhap Vao Thang: ");
	scanf_s("%d", &M);
	printf("Nhap Vao Nam: ");
	scanf_s("%d", &Y);

}

void main()
{
	int D, M, Y;
	printf("Nhap Vao Ngay: ");
	scanf_s("%d", &D);
	printf("Nhap Vao Thang: ");
	scanf_s("%d", &M);
	printf("Nhap Vao Nam: ");
	scanf_s("%d", &Y);
    
	FullDay(Y, M, D);

	_getch();
}