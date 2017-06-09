#include <stdio.h>
#include <conio.h>
#include <Windows.h>


//#define console_Width 80
//#define console_height 25





// Hàm thay đổi kích cỡ của khung cmd.

// Hàm tô màu.
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}

// Hàm dịch chuyển con trỏ đến tọa độ x, y.
void gotoxy(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x - 1, y - 1 };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
void textbackground(WORD color) // màu nền
{

	HANDLE hconsolerOutput;
	hconsolerOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hconsolerOutput, &screen_buffer_info);
	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	color <<= 4;
	wAttributes &= 0xff0f;
	wAttributes |= color;
	SetConsoleTextAttribute(hconsolerOutput, wAttributes);

}

// Hàm xóa màn hình.
void XoaManHinh()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}

void AscII()
{
	char c;
	for (int i = 0; i < 255; i++)
	{
		printf("%d -> %c\n\n", i,i);
	}
}

void paint()
{
	for (int i = 0; i <500; i++)
	{
		textcolor(i);
		printf("%d -> \n\n", i);
	}

}



void KhungCt()
{

	// Ve Khung Gioi Thieu

	char c = 205;  //ống Ngang
	char d = 186;  // ống dọc
	char c1 = 201; // góc trái trên
	char c2 = 200; // góc trái dưới
	char c3 = 187; // góc phải trên 
	char c4 = 188; // góc phải dưới
	char c5 = 202; // Ống căm lên
	char c6 = 203; // ống cắm xuống
	char c7 = 206; // ống Dấu cộng

}
void MaPhim()
{
	while (1){
		fflush(stdin);
		char c = _getch();
		printf("\nNguoi dung dang nhan vao phim %d", c);
	}
}

void main()
{
	AscII();
	
	_getch();
}