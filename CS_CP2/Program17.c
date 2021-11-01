#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int word_count(char* string);

void main()
{
	char* str = malloc(sizeof(char) * 256 + 1);
	printf("Enter a string: ");
	gets(str);

	printf("%d\n", word_count(str));
}

int word_count(char* string)
{
	int count = 0;
	char* ptr = strtok(string, " ");
	while (ptr != NULL)
	{
		count++;
		ptr = strtok(NULL, " ");
	}

	return count;
}