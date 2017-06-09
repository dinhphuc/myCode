
#include <stdio.h>
#include <conio.h>

int BinarySearch(int a[], int n, int x)
{
	int left = 0;
	int right = n - 1;

	while (left <= right) {
		int mid = (left + right) / 2;
		if (x == a[mid])
			return mid;
		else if (x < a[mid])
			right = mid - 1;
		else if (x > a[mid])
			left = mid + 1;

	}
	return -1;
}
void main()
{

	int a[] = { 1, 4, 5, 8, 7, 8, 9, 8, 5, 4, 5, 7, 4, 1 };
	printf("%d",BinarySearch(a, 14, 7));

	_getch();
}