#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

void Sort(int* arr);

void main()
{
	int numOfThings, maxWeight;
	scanf("%d %d", &numOfThings, &maxWeight);

	int* valueOfThings = (int*)malloc(sizeof(int) * numOfThings);
	int* weightOfThings = (int*)malloc(sizeof(int) * numOfThings);

	for (int i = 0; i < numOfThings; i++)
		scanf("%d", &valueOfThings[i]);

	printf("\n");

	for (int i = 0; i < numOfThings; i++)
		scanf("%d", &weightOfThings[i]);

	printf("Max value: %d");
	for (int i = 0; i < 4; i++)
		printf("%d");
}

void Sort(int* arr)
{
	int temp;

	for (int i = 0; i < (sizeof(arr) / sizeof(int)) - 1; i++)
	{
		for (int j = i + 1; j < (sizeof(arr) / sizeof(int)); j++)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}