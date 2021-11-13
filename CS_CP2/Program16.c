#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int IsAnagram(char* string1, char* string2);

void main()
{
	int n, i;
	char** inputs, temp[202] = { NULL, }, * string1, * string2;
	scanf("%d", &n);
	while (getchar() != '\n');

	while ((inputs = (char**)malloc(sizeof(char*) * n)) == NULL);
	for (i = 0; i < n; i++)
	{
		scanf("%[^\n]s", temp);
		while (getchar() != '\n');
		while ((inputs[i] = (char*)malloc(sizeof(char) * strlen(temp) + 1)) == NULL);
		strcpy(inputs[i], temp);
	}

	printf("\n");

	for (i = 0; i < n; i++)
	{
		string1 = strtok(inputs[i], " ");
		string2 = strtok(NULL, " ");
		printf("%s & %s are", string1, string2);
		printf("%sanagrams.\n", IsAnagram(string1, string2) ? " " : " NOT ");
	}

	for (i = 0; i < n; i++)
		free(inputs[i]);
	free(inputs);
}

int IsAnagram(char* string1, char* string2)
{
	if (strlen(string1) != strlen(string2)) return 0;

	int i, j, kill = 0;
	for (i = 0; i < strlen(string1); i++)
	{
		for (j = 0; j < strlen(string2); j++)
		{
			if (string1[i] == string2[j])
			{
				string2[j] = '#';
				kill++;
				break;
			}
		}
	}

	return strlen(string1) - kill == 0;
}