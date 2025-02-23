#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

void processSieve(int* primes, int upper, int lower);
void getBoundaries(int* upper, int* lower);
bool isUpperBiggerThenLower(int upper, int lower);
void showPrimes(int* primes, int upper, int lower);

int main()
{
	// �Ҽ����� �ƴ��� ���θ� ��Ÿ���� �迭 ���� ���� 1�̸� �Ҽ�, �׷��� ������ �Ҽ��� �ƴ�.
	int primes[50001] = { NULL, }; 
	// ���ñ� �Ҽ� ����� ���� ������ �ִ밪, �ּҰ�
	int upper = 0, lower = 0;

	getBoundaries(&upper, &lower);
	processSieve(primes, upper, lower);
	showPrimes(primes, upper, lower);

	return 0;
}

void getBoundaries(int* upper, int* lower)
{
	do
	{
		do printf("Please enter the lower boundary (between 1 and 50000): ");
		while (!scanf("%d", lower) || (*lower < 1 || *lower > 50000));

		do printf("Please enter the upper boundary (between 1 and 50000): ");
		while (!scanf("%d", upper) || (*upper < 1 || *upper > 50000));

	} while (!isUpperBiggerThenLower(*upper, *lower));
}

bool isUpperBiggerThenLower(int upper, int lower)
{
	if (upper > lower) return true;
	else { printf("Your upper boundary cannot be smaller than your lower boundary"); return false; }
}

void processSieve(int* primes, int upper, int lower)
{
	// 2���� upper�� �����ٱ����� ��� �� num���� �˻�
	for (int num = 2; num < sqrt(upper); num++)
	{
		// ���� num�� �ƹ��� ǥ�ð� ���� �ʾҴٸ�
		if (primes[num] == NULL)
		{
			// �� ���� �Ҽ�, 1�� ǥ��
			primes[num] = 1;

			// ��, �Ҽ��� ������� �Ҽ��� �ƴ�, -1�� ǥ��
			for (int multiples = num * num; multiples < upper; multiples += num)
			{
				primes[multiples] = -1;
			}
		}
	}

	// ǥ�õ��� �ʴ� ���� �Ҽ�, 1�� ǥ��
	// lower���� �۰�, upper���� ū ���� �ʿ����� �ʱ� ������ �˻翡�� ����
	for (int index = lower; index < upper; index++)
	{
		if (primes[index] == NULL)
		{
			primes[index] = 1;
		}
	}
}

void showPrimes(int* primes, int upper, int lower)
{
	int count = 0;
	printf("Here are all of the sexy prime pairs in the range %d to %d:\n", lower, upper);
	for (int i = lower; i <= upper - 6; i++)
	{
		if (primes[i] == 1 && primes[i + 6] == 1)
		{
			printf("%d and %d\n", i, i + 6);
			count++;
		}
	}
	printf("There were %d sexy prime pairs displayed between %d and %d", count, lower, upper);
}