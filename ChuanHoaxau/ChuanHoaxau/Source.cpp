#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define distance 'a'-'A'
#define space 32
#define comma ','
#define dot '.'
#define colon ':'
#define question '?'
#define factorial '!'
#define semicolon ';'
#define ellipsis "..."

int isspecialchr(char ch)
{
	return  ch == comma || ch == dot || ch == colon ||
		ch == question || ch == factorial || ch == semicolon;
}

int nonupper(char ch)
{
	return  ch == comma || ch == semicolon;
}

int islower(char ch)
{
	return  'a' <= ch && ch <= 'z';
}

void append(char *sptr, char * &dptr)
{
	*dptr = *sptr;
	dptr++;
}

int isellipsis(char *s)
{
	return  *s == dot && *(s + 1) == dot && *(s + 2) == dot;
}

int ispunctuation(char ch)
{
	return ch == dot || ch == question || ch == factorial;
}
void addellipsis(char * &sptr, char * &dptr)
{
	if (*(dptr - 1) == space) dptr--;
	*dptr = *(dptr + 1) = *(dptr + 2) = dot;
	dptr += 3; sptr += 2;
}

char * strstd(char *src, char *dest)
{
	char * sptr = src, *dptr = dest;
	while (*sptr)
	{
		if (isellipsis(sptr)) addellipsis(sptr, dptr);
		else
		if (*sptr == space)
		{
			if (dptr > dest && *(dptr - 1) != *sptr)
				append(sptr, dptr);
		}
		else
		if (isspecialchr(*sptr))
		{
			if (dptr > dest)
			if (!isspecialchr(*(dptr - 1)))
			if (*(dptr - 1) == space) *(dptr - 1) = *sptr;
			else append(sptr, dptr);
		}
		else
		{
			if (isspecialchr(*(dptr - 1)))
			{
				*dptr = space; dptr++;
			}
			*dptr = *sptr;
			if (dptr == dest || isspecialchr(*(dptr - 2)) && !nonupper(*(dptr - 2)))
			if (islower(*dptr)) *dptr -= distance;
			dptr++;
		}
		sptr++;
	}

	dptr--;
	while (isspecialchr(*dptr) && !ispunctuation(*dptr) || *dptr == space) dptr--;
	if (!ispunctuation(*dptr)) { *(dptr + 1) = dot; *(dptr + 2) = 0; }
	else *(dptr + 1) = 0;

	return dest;
}

void main()
{
	char dest[100];
	char src1[100] = "  em hoi   anh :hom qua  di  dau  ???   anh  noi rang   anh   di giang cau ...  ";
	printf("\n%s\n", strstd(src1, dest));
	char src2[100] = "  ga gay ,,, troi   sang   ;;; onmimh  tinh   day  ,,,  code c++  ";
	printf("\n%s\n", strstd(src2, dest));

	char src3[100] = "  sao anh  lai ngo  loi    vao mot dem trang khuyet ? ";
	printf("\n%s\n", strstd(src3, dest));

	char src4[100] = "  de    bay gio    tham   tiec ...mot vang trang khong tron ! ,,,,";
	printf("\n%s\n", strstd(src4, dest));
	_getch();
}