#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>

using namespace std;

struct ToaDo
{
	float x;
	float y;
};

float KhoangCach(ToaDo a, ToaDo b)
{
	return (sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2)));
}

void nhapToaDo(ToaDo &a)
{
	cout << " Nhap Hoanh do x: ";
	cin >> a.x;
	cout << " Nhap tung do y: ";
	cin >> a.y;
	printf("\n\n");
}
bool KT_TamGiac(ToaDo a, ToaDo b, ToaDo c)
{

	if (((KhoangCach(a, b) + KhoangCach(a, c)) >= (KhoangCach(b, c))) &&
		((KhoangCach(a, c) + KhoangCach(b, c)) >= (KhoangCach(b, a))) &&
		((KhoangCach(c, b) + KhoangCach(a, b)) >= (KhoangCach(a, c))))
	{
		return true;
	}
	return false;

}

void Xuat(ToaDo a, ToaDo b, ToaDo c)
{
	cout << " toa do diem thu nhat: (" << a.x << ";" << a.y << ")" << endl;
	cout << " toa do diem thu Hai: (" << b.x << ";" << b.y << ")" << endl;
	cout << " toa do diem thu Ba: (" << c.x << ";" << c.y << ")" << endl;
}
void main()
{
	while (1)
	{
		ToaDo a, b, c;
		cout << " Nhap toa do diem thu nhat: " << endl;
		nhapToaDo(a);
		cout << " Nhap toa do diem thu Hai: " << endl;
		nhapToaDo(b);
		cout << " Nhap toa do diem thu Ba: " << endl;
		nhapToaDo(c);

		Xuat(a, b, c);

		if (KT_TamGiac(a, b, c))
		{
			cout << "                      3 diem  la ba canh tam giac" << endl;
		}
		else
			cout << "                      3 diem khong la ba canh tam giac" << endl;
		cout << endl;
		cout << "Nhap Tiep (enter)             Thoat ( ESC)" << endl;


		if (_getch() == 27)
		{
			return;
		}
		system("cls");
	}

	_getch();
}

