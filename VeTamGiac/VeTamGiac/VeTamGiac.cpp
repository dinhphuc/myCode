
#include <stdio.h>
#include <conio.h>
#include <windows.h>

 void VeTamGiac(int n,int k,int x){
	
	 for (int z = 0; z < x; z++)
	 {
		 printf("\n");
	 }
		 for (int i = 0; i < n - 1; i++)
			
		 {
			
			 for (int m = 0; m < k; m++){
				 printf(" ");
			 }
			 for (int j = n - 1; j >i; j--){
				 printf(" ");
			 }
			 for (int k = 0; k < 2 * i + 1; k++){
				 if (k == 0 || k == (2 * i))
				 {


					 printf("*");
					 Sleep(200);
				 }
				 else
					 printf(" ");


			 }
			 printf("\n");
		 
		 }
		 for (int m = 0; m < k; m++){
			 printf(" ");
		 }
		 for (int i = 0; i < 2 * n - 1; i++){
			 printf("*");
			 Sleep(200);
		 }


}


void main(){

	VeTamGiac(15,10,3);
	printf("\n\n");
	printf("               Coder");
	Sleep(500);
	printf(" By");
	Sleep(200);
	printf(" Phuc");
	Sleep(500);
	printf(" Binz");
	Sleep(500);
	printf(" ^^");
	_getch();
}