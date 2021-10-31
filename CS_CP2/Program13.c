#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // 꼭 명시하지 않아도 됨, 컴파일러가 경고와 함께 자동으로 추가해줌
#include <malloc.h>

int IsCouple(char* string);
void SortString(char* string);
void FormatString(char* string);
void KillCouple(char* string);

int main()
{
	int n = 1;
	printf("Enter N : ");
	scanf("%d", &n);

	char** inputs = (char**)malloc(sizeof(char*) * n);
	char temp[100] = { NULL, };

	for (int i = 0; i < n; i++)
	{
		scanf("%s", temp);
		inputs[i] = (char*)malloc(sizeof(char) * 100);
		strcpy(inputs[i], temp);
	}

	printf("\n");

	for (int i = 0; i < n; i++)
	{
		if (IsCouple(inputs[i]))
			printf("Good\n");
		else
		{
			FormatString(inputs[i]);
			printf("%s\n", inputs[i]);
		}
		free(inputs[i]);
	}

	free(inputs);
	return 0;
}

int IsCouple(char* string)
{
	int dead = 0;
	char* temp = malloc(strlen(string) + 1);
	strcpy(temp, string);

	KillCouple(temp);

	for (int i = 0; i < strlen(string); i++)
		if (temp[i] == '#')
			dead++;

	free(temp);
	return strlen(string) == dead;
}

void KillCouple(char* string)
{
	for (int i = 0; i < strlen(string) - 1; i++)
	{
		if (string[i] == '#') continue;

		for (int j = i + 1; j < strlen(string); j++)
		{
			if (string[j] == '#') continue;

			if (string[i] == string[j])
			{
				string[i] = '#';
				string[j] = '#';
				break;
			}
		}
	}
}

void FormatString(char* string)
{
	int dead = 0;
	char* temp = malloc(strlen(string) + 1);
	strcpy(temp, string);

	KillCouple(temp);
	SortString(temp);

	for (int i = 0; i < strlen(string); i++)
	{
		string[i] = ' ';
		if (temp[i] == '#')
			dead++;	
	}

	int i = 0;
	for (int j = 0; j < strlen(string); j++)
		if (temp[j] != '#')
			string[i++] = temp[j];
	
	free(temp);
}

void SortString(char* string)
{
	int temp;

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