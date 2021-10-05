#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int testPerfect(int* number);
void printFactors(int* number);
int* GetFactors(int number);

void main()
{
	int n = 0, input = 0; // 입력 받을 횟수, 
	int* inputP = &input;
	printf("How many numbers would you like to test? ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		printf("Please enter a possible perfect number: ");
		scanf("%d", &input);
		printFactors(inputP);
		printf("\n\n");
	}
	return 0;
}

int testPerfect(int* number)
{
	int* factors = GetFactors(*number);

	int sum = 0;
	for (int i = 1; i < 100; i++)
	{
		if (factors[i] == NULL) break;
		printf("%d ", factors[i]);
		sum += factors[i];
	}
	printf("## %d ##", sum);
	if (sum == *number) return 1;
	else return 0;
}

void printFactors(int* number)
{
	if (testPerfect(number))
	{
		int* factors = GetFactors(*number);

		printf("%d:", *number);
		for (int i = 1; i < 100; i++)
		{
			if (factors[i] == NULL) break;
			printf("%d ", factors[i]);		
		}
	}
	else
	{
		printf("%d:NOT PERFECT", *number);
	}
}

int* GetFactors(int number)
{
	int factors[100] = { NULL, };
	int index = -1;
	int lastFactor = 0;
	for (int i = 1; i <= number / 2; i++)
	{
		if (number % i == 0)
		{
			if (i == lastFactor) break;

			factors[++index] = i;
			if (i != number / i)
			{
				factors[++index] = number / i;
			}
			lastFactor = number / i;
		}
	}

	int temp = 0;
	for (int j = 0; j < index; j++)
	{
		for (int k = j + 1; k < index + 1; k++)
		{
			if (factors[j] < factors[k])
			{
				temp = factors[j];
				factors[j] = factors[k];
				factors[k] = temp;
			}
		}
		printf("%d ", factors[j]);
	}
	printf("-----");
	return factors;
}