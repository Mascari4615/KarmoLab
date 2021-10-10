#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void PrintToBinary(unsigned char c)
{
	unsigned char mask = 0x80; // 0b1000'0000;

	for (int i = 0; i < 8; i++)
	{
		if (c & mask)
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
		mask = mask >> 1;
	}

	printf("\n");
}

void AND()
{
	unsigned char x = 0b0011'1111;
	unsigned char y = 0b1111'1100;
	unsigned char z = x & y;
	PrintToBinary(z); //0011'1100
}

void XOR()
{
	unsigned char x = 0b0011'1111;
	unsigned char y = 0b1111'1100;
	unsigned char z = x ^ y;
	PrintToBinary(z); //1100'0011
}

void OR()
{
	unsigned char x = 0b0011'1100;
	unsigned char y = 0b1100'1100;
	unsigned char z = x | y;
	PrintToBinary(z); //1111'0000
}

void NOT()
{
	unsigned char x = 0b0011'1100;
	PrintToBinary(~x);//1100'0011
}

int main()
{
	AND();
	XOR();
	OR();
	NOT();

	int x = 15;         //   15, ...0000'0000'0000'1111
	printf("%d", ~x);   //65520, ...1111'1111'1111'0000

	return 0;
}