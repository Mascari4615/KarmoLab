#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int f1(int n)
{
	if (n <= 0)
	{
		return 0;
	}
	else if (n <= 2)
	{
		return n;
	}
	else
	{
		return f1(n - 3) + f1(n - 2) + f1(n - 1);
	}
}

int recursive(int n)
{
	if (n < 1)
	{
		return 2;
	}
	else
	{
		return(22 * recursive(n - 1) + 1);
	}
}

int xxx(int n)
{
	if (n==0)
	{
		return 4;
	}
	return 1 + xxx(n - 1);
}

int f(int n)
{
	printf("한 번\n");
	if (n == 0 || n == 1)
	{
		return n;
	}
	return f(n - 1) + f(n - 2);
}

void hanoi_tower(int n, char from, char tmp, char to)
{
	if (n == 1)
	{
		printf("원판 1을 %c에서 %c로 옮긴다. \n", from, to);
	}
	else
	{
		hanoi_tower(n - 1, from, to, tmp);
		printf("원판 %d을 %c에서 %c로 옮긴다. \n", n, from, to);
		hanoi_tower(n - 1, tmp, from, to);
	}
}

int main()
{
	hanoi_tower(4, 'A', 'B', 'C');

	return 0;
}
