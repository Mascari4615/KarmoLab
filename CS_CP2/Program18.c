#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Find(char** inputStrings, int inputLength, char* word);
void TryN(char** inputStrings, char* word, int r, int c);
void TryNE(char** inputStrings, char* word, int r, int c);
void TryE(char** inputStrings, char* word, int r, int c);
void TrySE(char** inputStrings, char* word, int r, int c);
void TryS(char** inputStrings, char* word, int r, int c);
void TrySW(char** inputStrings, char* word, int r, int c);
void TryW(char** inputStrings, char* word, int r, int c);
void TryNW(char** inputStrings, char* word, int r, int c);

void main()
{
	int i, inputLength, stringLength; // 1이상 40이하
	scanf("%d %d", &inputLength, &stringLength);

	char** inputStrings = (char**)malloc(sizeof(char*) * inputLength);
	for (i = 0; i < inputLength; i++)
	{
		inputStrings[i] = (char*)malloc(sizeof(char) * stringLength + 1);
		scanf("%s", inputStrings[i]);
	}

	int wordLength; // 1이상 20이하
	scanf("%d", &wordLength);

	char temp[100] = { NULL, };
	char** inputWords = (char**)malloc(sizeof(char*) * inputLength);
	for (i = 0; i < wordLength; i++)
	{
		scanf("%s", temp);
		for (int i = 0; i < strlen(temp); i++)
		{
			if (temp[i] >= 97)
			{
				temp[i] -= 32;
			}
		}
		inputWords[i] = (char*)malloc(sizeof(char) * strlen(temp) + 1);
		strcpy(inputWords[i], temp);
	}

	for (i = 0; i < wordLength; i++)
	{
		Find(inputStrings, inputLength, inputWords[i]);
	}

	for (i = 0; i < inputLength; i++)
		free(inputStrings[i]);
	free(inputStrings);
	for (i = 0; i < wordLength; i++)
		free(inputWords[i]);
	free(inputWords);
}

void Find(char** inputStrings, int inputLength, char* word)
{
	int r, c, stringLength = strlen(inputStrings[0]);

	for (r = 0; r < inputLength; r++)
	{
		for (c = 0; c < stringLength; c++)
		{
			if (inputStrings[r][c] != word[0] && inputStrings[r][c] != word[0] + 32) continue;

			TryN(inputStrings, word, r, c);
			TryNE(inputStrings, word, r, c);
			TryE(inputStrings, word, r, c);
			TrySE(inputStrings, word, r, c);
			TryS(inputStrings, word, r, c);
			TrySW(inputStrings, word, r, c);  
			TryW(inputStrings, word, r, c);
			TryNW(inputStrings, word, r, c);
		}
	}
}

void TryN(char** inputStrings, char* word, int r, int c)
{
	if (r - (int)strlen(word) < 0) return;
	for (int i = 0; i < strlen(word); i++)
		if (inputStrings[r-i][c] != word[i] && inputStrings[r-i][c] != word[i] + 32) return;
	printf("N %d %d\n", r+1, c+1);
}

void TryNE(char** inputStrings, char* word, int r, int c)
{
	if (r - (int)strlen(word) < 0 || 11 - (c + (int)strlen(word)) < 0) return;
	for (int i = 0; i < (int)strlen(word); i++)
		if (inputStrings[r-i][c+i] != word[i] && inputStrings[r-i][c+i] != word[i] + 32) return;
	printf("NE %d %d\n", r+1, c+1);
}

void TryE(char** inputStrings, char* word, int r, int c)
{
	if (11 - (c + (int)strlen(word)) < 0) return;
	for (int i = 0; i < strlen(word); i++)
		if (inputStrings[r][c+i] != word[i] && inputStrings[r][c+i] != word[i] + 32) return;
	printf("E %d %d\n", r+1, c+1);
}

void TrySE(char** inputStrings, char* word, int r, int c)
{
	if (8 - (c + (int)strlen(word)) < 0 || 11 - (c + (int)strlen(word)) < 0) return;
	for (int i = 0; i < strlen(word); i++)
		if (inputStrings[r+i][c+i] != word[i] && inputStrings[r+i][c+i] != word[i] + 32) return;
	printf("SE %d %d\n", r+1, c+1);
}

void TryS(char** inputStrings, char* word, int r, int c)
{
	if (8 - (c + (int)strlen(word)) < 0) return;
	for (int i = 0; i < strlen(word); i++)
		if (inputStrings[r + i][c] != word[i] && inputStrings[r + i][c] != word[i] + 32) return;
	printf("S %d %d\n", r+1, c+1);
}

void TrySW(char** inputStrings, char* word, int r, int c)
{
	if (c - (int)strlen(word) < 0|| 8 - (c + (int)strlen(word)) < 0) return;
	for (int i = 0; i < strlen(word); i++)
		if (inputStrings[r+1][c-i] != word[i] && inputStrings[r+i][c-i] != word[i] + 32) return;
	printf("SW %d %d\n", r+1, c+1);
}

void TryW(char** inputStrings, char* word, int r, int c)
{
	if (c - (int)strlen(word) < 0) return;
	for (int i = 0; i < strlen(word); i++)
		if (inputStrings[r][c-i] != word[i] && inputStrings[r][c-i] != word[i] + 32) return;
	printf("W %d %d\n", r+1, c+1);
}

void TryNW(char** inputStrings, char* word, int r, int c)
{
	if (r - (int)strlen(word) < 0 || c - (int)strlen(word) < 0) return;
	for (int i = 0; i < strlen(word); i++)
		if (inputStrings[r-i][c-i] != word[i] && inputStrings[r-i][c-i] != word[i] + 32) return;
	printf("NW %d %d\n", r+1, c+1);
}