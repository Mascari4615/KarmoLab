#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void get_date(char* birthday[]);
int validate_date(int year, int month, int day);
void crunch_date(int number);
void show_numerology(int number);

void main()
{
	// ���� ������ (���ڿ�) �迭
	char* birthday[3] = { "", "", "" };
	get_date(birthday);
	
	// ���ڿ��� ������ �ٲ��ִ� �Լ��� �̿��� ������ �ʱ�ȭ�մϴ�.
	int month = atoi(birthday[0]);
	int day = atoi(birthday[1]);
	int year = atoi(birthday[2]);

	int num = validate_date(year, month, day);

	// ��ȯ ���� ���� 0�� �ƴ϶��, �� �ùٸ��� �ԷµǾ��ٸ�
	if (num)
	{
		printf("Welcome to the numerogy report for %d/%d/%d :\n", month, day, year);
		crunch_date(num);
	}
}

// ��������� �Է¹޾� �⵵, ��, �Ϸ� �����Ͽ� ó��
void get_date(char* birthday[])
{
	char input[15];
	printf("Enter the birth date (mm / dd / yyyy) : ");
	scanf("%[^\n]", input);

	// �Է¹��� ���� " / " �� ������, ��ȯ ���� ���ڿ��� �ּҰ��� ���� ������ �迭�� �����մϴ�.
	char* result = strtok(input, " / ");
	while (result != NULL)
	{
		birthday = result;
		birthday++;
		printf("%s", birthday);
		result = strtok(NULL, " / ");
	}
}

// ��¥�� �ùٸ��� �ԷµǾ����� Ȯ���ϰ�, �׷��ٸ� ��� ���� ��, �ƴ϶�� 0�� ��ȯ�մϴ�.
int validate_date(int year, int month, int day)
{
	// 1880����� 2280������� �����Ѵٴ� ���� ����
	if (year < 1880 || year > 2280)
	{
		printf("Bad year : %d\n", year);
		null ������ ����
			0�� �� �� �� ����
			gets s ���ڿ�
		return 0;
	}

	// �Էµ� ���� ������ ��¥�� ���ϰ�, ���ÿ� �Էµ� ���� �ùٸ��� Ȯ��
	int lastDayOfMonth;
	switch (month)
	{
		case 2:
			if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
				lastDayOfMonth = 29;
			else
				lastDayOfMonth = 28;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			lastDayOfMonth = 30;
			break;
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			lastDayOfMonth = 31;
			break;
		default:
			printf("Bad month : %d\n", month);
			return 0;
	}

	// �Էµ� ��¥�� �ùٸ��� Ȯ��
	if (day <= 0 || day > lastDayOfMonth)
	{
		printf("Bad day for %d/%d : %d\n", month, year, day);
		return 0;
	}

	int number = year + month + day;
	return number;
}

// �Ѱܹ��� ������ ��� �ڸ����� 10���� �۾��� ������ ��Ĩ�ϴ�.
void crunch_date(int number)
{
	int nSum = 0;
	do
	{
		nSum = 0;
		while (number)
		{
			nSum += number % 10;
			number /= 10;
		}
		number = nSum;
	} while (nSum >= 10);

	show_numerology(nSum);
}

// �Ѱܹ��� ���ڿ� ���� ��� ����մϴ�.
void show_numerology(int number)
{
	printf(":%d: ", number);

	switch (number)
	{
		case 1:
			printf("Neither give cherries to pigs nor advice to a fool.");
			break;
		case 2:
			printf("Expect harmony and balance.");
			break;
		case 3:
			printf("Your dearest dream is coming true.");
			break;
		case 4:
			printf("Take a leap of faith.");
			break;
		case 5:
			printf("Your sweetheat may be too beautiful for words, but not for arguments.");
			break;
		case 6:
			printf("Rid your life of negative energy.");
			break;
		case 7:
			printf("Prepare for a spiritual awakening.");
			break;
		case 8:
			printf("You are almost there.");
			break;
		case 9:
			printf("Share your wisdom with the world.");
			break;
		case 0:
			printf("Your are on the right path");
			break;
	}
}