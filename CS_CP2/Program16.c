#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int IsAnagram(char* string1, char* string2);

void main()
{
	int n;
	scanf("%d", &n);
	while (getchar() != '\n');

	char** inputs = (char**)malloc(sizeof(char*) * n);
	char temp[202] = { NULL, };

	for (int i = 0; i < n; i++)
	{
		scanf("%[^\n]s", temp);
		while (getchar() != '\n');
		inputs[i] = (char*)malloc(sizeof(char) * strlen(temp) + 1);
		strcpy(inputs[i], temp);
	}

	printf("\n");

	char* string1, *string2;
	for (int i = 0; i < n; i++)
	{
		string1 = strtok(inputs[i], " ");
		string2 = strtok(NULL, " ");
		if (IsAnagram(string1, string2))
			printf("%s and %s are anagrams.\n", string1, string2);
		else
			printf("%s and %s are NOT anagrams.\n", string1, string2);
	}
}

int IsAnagram(char* string1, char* string2)
{
	if (strlen(string1) != strlen(string2)) return 0;

	char* tempStr1 = malloc(strlen(string1) + 1), *tempStr2 = malloc(strlen(string2) + 1);
	strcpy(tempStr1, string1);
	strcpy(tempStr2, string2);

	int kill = 0;
	for (int i = 0; i < strlen(tempStr1); i++)
	{
		for (int j = 0; j < strlen(tempStr2); j++)
		{
			if (tempStr1[i] == tempStr2[j])
			{
				tempStr2[j] = '#';
				kill++;
				break;
			}
		}
	}

	return strlen(tempStr1) - kill == 0;
}