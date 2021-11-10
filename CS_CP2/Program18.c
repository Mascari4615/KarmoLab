#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Find(char** inputStrings, int inputLength, char* word);
void TryN(char** inputStrings, char* word, int c, int r);
void TryNE(char** inputStrings, char* word, int c, int r);
void TryE(char** inputStrings, char* word, int c, int r);
void TrySE(char** inputStrings, char* word, int c, int r);
void TryS(char** inputStrings, char* word, int c, int r);
void TrySW(char** inputStrings, char* word, int c, int r);
void TryW(char** inputStrings, char* word, int c, int r);
void TryNW(char** inputStrings, char* word, int c, int r);

void main()
{
	int inputLength, stringLength; // 1이상 40이하
	scanf("%d %d", &inputLength, &stringLength);

	char** inputStrings = (char**)malloc(sizeof(char*) * inputLength);
	for (int i = 0; i < inputLength; i++)
	{
		inputStrings[i] = (char*)malloc(sizeof(char) * stringLength + 1);
		scanf("%s", inputStrings[i]);
	}

	int wordLength; // 1이상 20이하
	scanf("%d", &wordLength);

	char temp[100] = { NULL, };
	char** inputWords = (char**)malloc(sizeof(char*) * inputLength);
	for (int i = 0; i < wordLength; i++)
	{
		scanf("%s", temp);
		inputWords[i] = (char*)malloc(sizeof(char) * strlen(temp) + 1);
		strcpy(inputWords[i], temp);
	}

	for (int i = 0; i < wordLength; i++)
	{
		Find(inputStrings, inputLength, inputWords[i]);
	}

	printf("%d %d\n", inputLength, stringLength);

}

void Find(char** inputStrings, int inputLength, char* word)
{
	int stringLength = strlen(inputStrings[0]);
	printf("___ %d %d %d %d %d\n", strlen(inputStrings), inputLength, sizeof(inputStrings[0]), stringLength, sizeof(word));
	for (int c = 0; c < inputLength; c++)
	{
		for (int r = 0; r < stringLength; r++)
		{
			if (inputStrings[c][r] != word[0]) continue;

			TryN(inputStrings, word, c, r);
			TryNE(inputStrings, word, c, r);
			TryE(inputStrings, word, c, r);
			TrySE(inputStrings, word, c, r);
			TryS(inputStrings, word, c, r);
			TrySW(inputStrings, word, c, r);  
			TryW(inputStrings, word, c, r);
			TryNW(inputStrings, word, c, r);
		}
	}
}

void TryN(char** inputStrings, char* word, int c, int r)
{
	if (c - strlen(word) < 0) return;

	for (int i = 0; i < strlen(word); i++)
	{
		if (inputStrings[c][r] != word[i] || inputStrings[c][r] != word[i] + 32) break;
		c--;
	}

	printf("N %d %d\n", c, r);
}

void TryNE(char** inputStrings, char* word, int c, int r)
{
	if (c - strlen(word) < 0 || 11 - (r + strlen(word)) < 0) return;

	for (int i = 0; i < strlen(word); i++)
	{
		if (inputStrings[c][r] != word[i] || inputStrings[c][r] != word[i] + 32) break;
		c--;
		r++;
	}

	printf("NE %d %d\n", c, r);
}

void TryE(char** inputStrings, char* word, int c, int r)
{
	int wordLength = strlen(word);
	if (11 - (r + wordLength) < 0) return;

	for (int i = 0; i < wordLength; i++)
	{
		if (inputStrings[c][r] != word[i] || inputStrings[c][r] != word[i] + 32) break;
		r++;
	}

	printf("E %d %d\n", c, r);
}

void TrySE(char** inputStrings, char* word, int c, int r)
{
	int wordLength = strlen(word);
	if (8 - (r + wordLength) < 0 || 11 - (r + wordLength) < 0) return;

	for (int i = 0; i < wordLength; i++)
	{
		if (inputStrings[c][r] != word[i] || inputStrings[c][r] != word[i] + 32) break;
		c++;
		r++;
	}

	printf("SE %d %d\n", c, r);
}

void TryS(char** inputStrings, char* word, int c, int r)
{
	int wordLength = strlen(word);
	if (8 - (r + wordLength) < 0) return;

	for (int i = 0; i < wordLength; i++)
	{
		if (inputStrings[c][r] != word[i] || inputStrings[c][r] != word[i] + 32) break;
		c++;
	}

	printf("S %d %d\n", c, r);
}

void TrySW(char** inputStrings, char* word, int c, int r)
{
	int wordLength = strlen(word);
	if (r - wordLength < 0|| 8 - (r + wordLength) < 0) return;

	for (int i = 0; i < wordLength; i++)
	{
		if (inputStrings[c][r] != word[i] || inputStrings[c][r] != word[i] + 32) break;
		r--;
		c++;
	}

	printf("SW %d %d\n", c, r);
}

void TryW(char** inputStrings, char* word, int c, int r)
{
	int wordLength = strlen(word);
	if (r - wordLength < 0) return;

	for (int i = 0; i < wordLength; i++)
	{
		if (inputStrings[c][r] != word[i] || inputStrings[c][r] != word[i] + 32) break;
		r--;
	}

	printf("W %d %d\n", c, r);
}

void TryNW(char** inputStrings, char* word, int c, int r)
{
	int wordLength = strlen(word);
	if (c - wordLength < 0 || r - wordLength < 0) return;

	for (int i = 0; i < wordLength; i++)
	{
		if (inputStrings[c][r] != word[i] || inputStrings[c][r] != word[i] + 32) break;
		r--;
		c--;
	}

	printf("NW %d %d\n", c, r);
}