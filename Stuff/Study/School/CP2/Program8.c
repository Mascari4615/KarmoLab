#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

// �����ϴ� ������� �ִ� ����
#define FACTORS_LENGTH 10

int testPerfect(int number, int* factors);
void printFactors(int number);

int main()
{
	int n = 0, input = 0; // �ݺ� Ƚ��, �Է°�
	printf("How many numbers would you like to test? ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		printf("Please enter a possible perfect number: ");
		scanf("%d", &input);
		printFactors(input);
		printf("\n\n");
	}
	return 0;
}

// ������ �Ǻ�
int testPerfect(int number, int* factors)
{
	// �������� �ڱ� �ڽ��� ������ ���� ������ ������ �� �ڱ� �ڽ��� ��
	// �ڱ� �ڽ��� ������ ���� ���ϱ� ����, 
	int sum = 0;
	for (int i = 1; i < FACTORS_LENGTH; i++)
	{
		if (factors[i] == NULL) break;
		sum += factors[i];
	}

	if (sum == number) return 1;
	else return 0;
}

// �Ѱܹ޴� ���� ���������, ��� ���
void printFactors(int number)
{
	// �Ѱܹ��� ���� ���������� �Ǻ��ϱ� ���ؼ���, ����� ����ϱ� ���ؼ��� ���� ����� ���ؾ���

	int factors[FACTORS_LENGTH] = { NULL, };
	int i = 0;
	int numberSqrt = (int)sqrt(number);;

	// �Ѱܹ��� ���� ����� ã�� �迭�� �ִ� �ݺ���
	// � �ڿ��� n�� �����, n�� ������ ������ ����� ���ϸ�, n�� �� ����� ���� ���� �� ����
	// ��) 28�� ������ 5.3 => 28, 14, 7 | 4, 2, 1
	for (int curFactor = 1; curFactor <= numberSqrt; curFactor++)
	{
		// ������ �������� ���
		if (number % curFactor == 0)
		{
			// (n�� ������ ������) ��� ����
			factors[i++] = curFactor;
			// ���� curFactor�� �������� ���, ���� ���ڰ� �ߺ��Ǿ� ����Ǵ� ���� ����
			if (curFactor != number / curFactor)
			{
				// (n�� ������ ������) ����� n�� ���� �� �ٸ� ��� ����
				factors[i++] = number / curFactor;
			}
		}
	}

	// ������� ������������ ����
	int temp = 0;
	for (int j = 0; j < i - 1; j++)
	{
		for (int k = j + 1; k < i; k++)
		{
			if (factors[j] < factors[k])
			{
				temp = factors[j];
				factors[j] = factors[k];
				factors[k] = temp;
			}
		}
	}

	printf("%d:", number);

	// ���� �Ѱܹ��� ���� �������
	if (testPerfect(number, factors))
	{
		// �ݺ����� ���� 1��° ��� ���� ��� (�Է� ���� ���� �����ϰ� ����϶�� ���� ����, 0��° ����� �ڱ� �ڽ��̱� ����)
		for (int j = 1; j < FACTORS_LENGTH; j++)
		{
			if (factors[j] == NULL) break;
			printf("%d ", factors[j]);
		}
	}
	// �Ѱܹ��� ���� ������ �ƴ϶��
	else
	{
		printf("NOT PERFECT");
	}
}