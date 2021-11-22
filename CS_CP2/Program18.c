#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Find(char** inputStrings, int inputLength, char* word);
void Try(char** inputStrings, char* word, int r, int c, int rAdd, int cAdd);

void main()
{
	int i, inputLength, stringLength, wordLength; // 1이상 40이하, 1이상 20이하
	char **inputStrings, temp[100] = { NULL, }, ** inputWords;

	scanf("%d %d", &inputLength, &stringLength);
	inputStrings = (char**)malloc(sizeof(char*) * inputLength);
	for (i = 0; i < inputLength; i++)
	{
		inputStrings[i] = (char*)malloc(sizeof(char) * stringLength + 1);
		scanf("%s", inputStrings[i]);
	}

	scanf("%d", &wordLength);
	inputWords = (char**)malloc(sizeof(char*) * inputLength);
	for (i = 0; i < wordLength; i++)
	{
		scanf("%s", temp);
		for (int i = 0; i < strlen(temp); i++)
		{
			if (temp[i] >= 97)
				temp[i] -= 32;
		}
		inputWords[i] = (char*)malloc(sizeof(char) * strlen(temp) + 1);
		strcpy(inputWords[i], temp);
	}

	for (i = 0; i < wordLength; i++)
	{
		Find(inputStrings, inputLength, inputWords[i]);
		free(inputWords[i]);
	}
	free(inputWords);
	for (i = 0; i < inputLength; i++)
		free(inputStrings[i]);
	free(inputStrings);
}

void Find(char** inputStrings, int maxRow, char* word)
{
	int r, c, ud, lr, maxCol = strlen(inputStrings[0]), wordLength = (int)strlen(word);

	for (r = 0; r < maxRow; r++)
	{
		for (c = 0; c < maxCol; c++)
		{
			if (inputStrings[r][c] != word[0] && inputStrings[r][c] != word[0] + 32) continue;

			for (ud = -1; ud <= 1; ud++)
			{
				if ((ud == -1 && (r - wordLength < 0))|| (ud == 1 && (maxRow - (c + wordLength) < 0))) 
					continue;

				for (lr = -1; lr <= 1; lr++)
				{
					if ((lr == -1 && c - wordLength < 0) || (lr == 1 && maxCol - (c + wordLength) < 0)) 
						continue;

					Try(inputStrings, word, r, c, ud, lr);
				}
			}
		}
	}
}

void Try(char** inputStrings, char* word, int r, int c, int rAdd, int cAdd)
{
	for (int i = 0; i < strlen(word); i++)
		if (inputStrings[r + i * rAdd][c + i * cAdd] != word[i] 
		 && inputStrings[r + i * rAdd][c + i * cAdd] != word[i] + 32) return;
	printf("%d %d\n", r + 1, c + 1);
}