#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

void Program2_17()
{
	int subject1Scores[10];
	int subject2Scores[10];
	int subject3Scores[10];

	for (int i = 0; i < 10; i++)
	{
		printf("%d 학번 학생의 성적 입력\n", i + 1);
		scanf("%d %d %d", &subject1Scores[i], &subject2Scores[i], &subject3Scores[i]);
	}

	for (int i = 0; i < 10; i++)
	{
		int total = subject1Scores[i] + subject2Scores[i] + subject3Scores[i];
		float average = (float)total / 3;
		printf("학번\t국어\t영어\t수학\t총점\t평균\n");
		printf("**************************************\n");
		printf("%d\t%d\t%d\t%d\t%d\t%f\n\n", i, subject1Scores[i], subject2Scores[i], subject3Scores[i], total, average);
	}
}

void Program2_18()
{
	int arr[6] = { 19,2,25,92,36,45 };

	printf("배열 요소 출력\n");
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", arr[i]);
	}

	printf("\n\n최솟값 최댓값 출력\n");
	int min = arr[0], max = arr[0];
	for (int i = 0; i < 6; i++)
	{
		if (min > arr[i])
			min = arr[i];

		if (max < arr[i])
			max = arr[i];
	}
	printf("%d %d", min, max);

	printf("\n\n평균 출력\n");
	int total = 0;
	float average = 0;
	for (int i = 0; i < 6; i++)
	{
		total += arr[i];
	}
	printf("%f", average = (float)total / 6);

	printf("\n\n분산 출력\n");
	float variance = 0;
	for (int i = 0; i < 6; i++)
	{
		variance += pow(arr[i] - average, 2);
	}
	printf("%f", variance /= 6);

}

void Program2_19()
{
	char** strings;

	while ((strings = (char**)malloc(sizeof(char*) * 5)) == NULL);
	for (int i = 0; i < 5; i++)
	{
		while ((strings[i] = (char*)malloc(sizeof(char) * 100)) == NULL);
		scanf("%s", strings[i]);
		while (getchar() != '\n');
		strings[i] = (char*)realloc(strings[i], strlen(strings[i]) + 1);
	}

	for (int i = 0; i < 5; i++)
	{
		printf("%s\n", strings[i]);
	}
}

void Program2_20()
{
	char** strings;

	while ((strings = (char**)malloc(sizeof(char*) * 2)) == NULL);
	for (int i = 0; i < 2; i++)
	{
		while ((strings[i] = (char*)malloc(sizeof(char) * 100)) == NULL);
		scanf("%s", strings[i]);
		while (getchar() != '\n');
		strings[i] = (char*)realloc(strings[i], strlen(strings[i]) + 1);
	}

	if (strcmp(strings[0], strings[1]) == 0)
	{
		printf("문자열 같음");
	}
	else
	{
		printf("문자열 다름");
	}
}

void Program2_21(float* x, float* y)
{
	float* tmp = x;
	x = y;
	y = tmp;

	printf("%f %f", *x, *y);
}

void Program2_22(char* s)
{
	while (*s != 0)
	{
		if (*s >= 'A' && *s <= 'Z')
		{
			*s = *s + 32;
		}
		else if (*s >= 'a' && *s <= 'z')
		{
			*s = *s - 32;
		}
		s++;
	}
}

void Program2_23(char* s)
{
	for (int i = strlen(s) - 1; i >= 0; i--)
	{
		printf("%c", s[i]);
	}
}


int Program2_25(int n)
{
	if (n < 1)
	{
		return n;
	}

	return n + Program2_25(n - 1);
}

int Program2_26(int n)
{
	if (n == 0 || n == 2)
	{
		return n;
	}
	else
	{
		return Program2_26(n - 1) + Program2_26(n - 2);
	}
}

void main()
{
	/*float x = 1;
	float y = 2;
	Program2_21(&x, &y);*/

	/*char* string;
	while ((string = (char*)malloc(sizeof(char) * 100)) == NULL);
	scanf("%s", string);
	while (getchar() != '\n');
	string = (char*)realloc(string, strlen(string) + 1);
	Program2_22(string);
	printf("%s", string);*/

	/*char* string;
	while ((string = (char*)malloc(sizeof(char) * 100)) == NULL);
	scanf("%s", string);
	while (getchar() != '\n');
	string = (char*)realloc(string, strlen(string) + 1);
	Program2_23(string);*/

	// printf("%d", Program2_25(3));
	// printf("%d", Program2_26(3));

	return 0;
}