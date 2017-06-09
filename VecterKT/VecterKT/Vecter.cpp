#include "Vecter.h"
#include <iostream>
using namespace std;

Vecter Vecter::NhapVecter()
{
	Vecter c(x, y, z);
	cout << "Nhap Vao Toa Do" << endl;
	cout << "Nhap Vao Toa x= "; cin >> this-> x;
	cout << "Nhap Vao Toa y= "; cin >> this->y;
	cout << "Nhap Vao Toa x= "; cin >> this->z;
	return c;
}
void Vecter::XuatVecter()
{
	cout << "Vecter : " << endl;
	cout << "( " << x << ";" << y << ";" << z << ")" << endl;;

}
Vecter::Vecter(int x, int y, int z)
{
	x = x;
	y = y;
	z = z;
}
Vecter::Vecter()
{
	x = 0;
	y = 0;
	z = 0;
}


Vecter::~Vecter()
{
}
