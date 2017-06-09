#include <stdio.h>
#include <conio.h>
#define Maxsize 100
struct P
{
	int giatri;
	P* bencanh;

};

P* Dau = new P;

void Init()
{
	Dau = NULL;
}

bool IsNull()
{
	return Dau == NULL ? true : false;
}

void Addlast(P* temp0)
{
	if (IsNull())
		Dau = temp0;
	else
	{
		
		P* temp = new P;
		temp = Dau;
		while (temp->bencanh !=NULL)
		{
			temp = temp->bencanh;
		}

		temp->bencanh = temp0;
	}
}
void AddFist(P* Vlaue)
{
	if (IsNull())
	{
		Dau = Vlaue;
	}
	else

	{
		Vlaue->bencanh = Dau;
	}
}

void AddPos(P* temp0, int pos)
{
	P* temp = new P;
	temp = Dau;
	int count = 0;
	while (temp != NULL)
	{
		count++;
		temp = temp->bencanh;
	}
	if (pos > count)
		return;
	
	else
	{
		P* temp2 = new P;
		P* temp3 = new P;
		temp2 = Dau;
		for (int i = 1; i < pos; i++)
		{
			temp2 = temp2->bencanh;
		}

		temp3 = temp2->bencanh;

		temp2->bencanh = temp0;
		temp0->bencanh = temp3;
	}


}


void HienThi()
{
	if (IsNull())
	{
		return;
	}

	P* temp = Dau;
	while (temp!=NULL)
	{
		printf("%d   ", temp->giatri);
		temp = temp->bencanh;
	}
	printf("\n");
}

void main()
{
	Init();

	

	for (int i = 1; i <= 5; i++)
	{
		P* p1 = new P;
		scanf_s("%d", &(p1->giatri));
		p1->bencanh = NULL;
		Addlast(p1);
	}

	HienThi();

	P* p6 = new P;
	p6->giatri = 13;
	//p6->bencanh = NULL;
	Addlast(p6);
	//AddFist(p6);
	HienThi();

	_getch();
}