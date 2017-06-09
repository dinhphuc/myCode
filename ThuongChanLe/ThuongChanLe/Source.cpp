#include<iostream>
using namespace std;

int main() {
	int luachon;
	float a;
	float b;

	while (69) {
		cout << "\n\n\t\t ================== Danh Sách Tính Toán ==================";
		cout << "\n1. tinh tong 2 so a va b: ";
		cout << "\n2. tinh tich 2 so a va b: ";
		cout << "\n3. tinh hieu 2 so a va b: ";
		cout << "\n4. tinh thuong 2 so a va b: ";
		cout << "\n0. ket thuc :)) ";
		cout << "\n\n\t\t ================== Bat Dau Lam Viec=====================";

		cout << "\nhap vao gia tri cua a = ";
		cin >> a;
		cout << "\nNhap vao gia tri cua b = ";
		cin >> b;
		cout << "nhap lua chon: ";
		cin >>  luachon;




		//di kiem tra lua chon!
		if (luachon != 0 && luachon != 1 && luachon != 2 && luachon != 3 && luachon != 4) {
			cout << " lua chon khong hop le. vui long kiem tra lai 😞";
			system("pause");
		}

		switch (luachon)
		{
		case 1:
			cout << "tong cua a+b:" << a + b << endl;
			system("pause");
			break;
		case 2:
			cout << "tich cua axb: " << a * b << endl;
			system("pause");
			break;
		case 3:
			cout << "hieu cua a - b: " << a - b << endl;
			system("pause");
			break;
		case 4:
			cout << "thuong cua a va b là: " << a / b << endl;
			system("pause");
			break;
		}
		system("cls");
	}
	return 0;
	system("pause");

}