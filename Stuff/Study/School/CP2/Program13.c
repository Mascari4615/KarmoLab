#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>

int IsCouple(char* string);
int KillAllCouple(char* string);
void SortString(char* string);

// char* inputs[n]�� ���� �;�����, VS������ ���� ���� �迭(VLA)�� �������� �ʾ���.. 
// ������ ���� �����͸� ����ϰ�, malloc �Լ��� �̿��� ���� �Ҵ��ϴ� ��� ���

void main()
{
	int n, i, j;
	printf("Enter N : ");
	scanf("%d", &n);

	char** inputs = NULL, temp[100] = { NULL, };
	while ((inputs = (char**)malloc(sizeof(char*) * n)) == NULL);

	for (i = 0; i < n; i++)
	{
		scanf("%s", temp);
		while ((inputs[i] = (char*)malloc(strlen(temp) + 1)) == NULL);
		strcpy(inputs[i], temp);
	}

	printf("\n");

	for (i = 0; i < n; i++)
	{
		if (KillAllCouple(inputs[i]))
			printf("Good");
		else
		{
			SortString(inputs[i]);

			// ¦�� ���� ���ĺ� �Ųٷ� ���
			for (j = 0; j < strlen(inputs[i]); j++)
				if (inputs[i][j] != '#')
					printf("%c", inputs[i][j]);
		}
		printf("\n");

		// ���ڿ��� �� ������� �ʱ� ������ �Ҵ� ����
		free(inputs[i]);
	}

	// ���� �����͵� �Ҵ� ����
	free(inputs);
}

// �Ű������� ���� ���ڿ� �ȿ� ¦�� ���ĺ��� �ִ��� Ȯ��
int IsCouple(char* string)
{
	int i, j;

	// ¦�� ���ĺ��� �ִ��� ã�� return
	for (i = 0; i < strlen(string) - 1; i++)
		for (j = i + 1; j < strlen(string); j++)
			if (string[i] == string[j] && string[i] != '#')
				return 1;

	return 0;
}

// �Ű������� ���� ���ڿ� �ȿ� �ִ� ��� ���ĺ� ���� #���� ����
// ���ڿ��� ��� #�� �Ǹ� 1, �ƴϸ� 0 ��ȯ
int KillAllCouple(char* string)
{
	int coupleCount = 0, i, j;

		// ¦�� �ִ� ���ĺ��� ã�� #���� �ٲٰ�, coupleCount++
		for (i = 0; i < strlen(string) - 1; i++)
		{
			if (string[i] == '#')
				continue;

			for (j = i + 1; j < strlen(string); j++)
			{
				if (string[i] == '#')
					continue;

				if (string[i] == string[j])
				{
					string[i] = string[j] = '#';
					coupleCount++;
					break;
				}
			}
		}
	}

	return strlen(string) == coupleCount * 2;
}

void SortString(char* string)
{
	char temp;

	for (int i = 0; i < strlen(string) - 1; i++)
	{
		for (int j = i + 1; j < strlen(string); j++)
		{
			if (string[i] > string[j])
			{
				temp = string[i];
				string[i] = string[j];
				string[j] = temp;
			}
		}
	}
}