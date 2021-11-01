#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> // 명시하지 않아도 실행되는 이유가 컴파일러가 자동으로 추가해 준다고함.
#include <malloc.h> // 위와 다르게 이건 명시하지 않으면 우연찮게 실행되는 거라던 대.. 
					// 더 공부해 봐야겠음.. 별개로 <stdlib.h> 에도 malloc, free 함수가 정의돼 있음

int IsCouple(char* string);
void SortString(char* string);
void FormatString(char* string);
void KillCouple(char* string);

// 내 스타일대로 끄적여 본 것
int main()
{
	int n = 1;
	printf("Enter N : "); scanf("%d", &n);

	// char* inputs[n]로 쓰고 싶었지만, VS에서는 가변 길이 배열(VLA)을 지원하지 않았음.. 
	// 때문에 이중 포인터를 사용하고, malloc 함수를 이용해 동적 할당하는 방법 사용
	char** inputs = (char**)malloc(sizeof(char*) * n);
	char temp[100] = { NULL, };

	for (int i = 0; i < n; i++)
	{
		scanf("%s", temp);
		inputs[i] = (char*)malloc(sizeof(char) * strlen(temp) + 1);
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