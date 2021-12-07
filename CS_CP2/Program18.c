#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct InputData {
	char** inputs;
	int maxRow;
	int maxCol;
} inputData;

typedef struct Direction {
	int vertical;
	int horizontal;
} direction;

direction const NW = { .vertical = -1, .horizontal = -1 };
direction const N = { .vertical = -1, .horizontal = 0 };
direction const NE = { .vertical = -1, .horizontal = 1 };
direction const E = { .vertical = 0, .horizontal = 1 };
direction const SE = { .vertical = 1, .horizontal = 1 };
direction const S = { .vertical = 1, .horizontal = 0 };
direction const SW = { .vertical = 1, .horizontal = -1 };
direction const W = { .vertical = 0, .horizontal = -1 };

void Find(inputData inputData, char* word);
void FindWord(inputData inputData, char* word, int r, int c, direction d);
int CantSearchThatDirection(inputData inputData, int wordLength, int r, int c, direction d);

void main()
{
	int i, j, m, n, wordCount; // 1이상 40이하, 1이상 20이하
	char** inputs;
	char** words;
	inputData inputData;

	scanf("%d %d", &m, &n);
	while ((inputs = (char**)malloc(sizeof(char*) * m)) == NULL);
	for (i = 0; i < m; i++)
	{
		while ((inputs[i] = (char*)malloc(sizeof(char) * n + 1)) == NULL);
		scanf("%s", inputs[i]);
	}

	inputData.inputs = inputs;
	inputData.maxRow = m;
	inputData.maxCol = n;

	scanf("%d", &wordCount);
	while ((words = (char**)malloc(sizeof(char*) * wordCount)) == NULL);
	for (i = 0; i < wordCount; i++)
	{
		while ((words[i] = (char*)malloc(sizeof(char) * 101)) == NULL);
		scanf("%s", words[i]);
		while ((words[i] = (char*)realloc(words[i], strlen(words[i]) + 1)) == NULL);
	}

	for (i = 0; i < wordCount; i++)
		Find(inputData, words[i]);

	for (i = 0; i < wordCount; i++)
		free(words[i]);
	free(words);

	for (i = 0; i < m; i++)
		free(inputs[i]);
	free(inputs);
}

void Find(inputData inputData, char* word)
{
	int r, c, wordLen = strlen(word);

	for (c = 0; c < wordLen; c++)
	{
		if (word[c] >= 97) // A 대문자
			word[c] -= 32; // a 소문자
	}

	for (r = 0; r < inputData.maxRow; r++)
	{
		for (c = 0; c < inputData.maxCol; c++)
		{
			if (inputData.inputs[r][c] != word[0] &&
				inputData.inputs[r][c] != word[0] + 32)
				continue;
			
			FindWord(inputData, word, r, c, N);
			FindWord(inputData, word, r, c, NW);
			FindWord(inputData, word, r, c, W);
			FindWord(inputData, word, r, c, SW);
			FindWord(inputData, word, r, c, S);
			FindWord(inputData, word, r, c, SE);
			FindWord(inputData, word, r, c, E);
			FindWord(inputData, word, r, c, NE);
		}
	}
}

void FindWord(inputData inputData, char* word, int r, int c, direction d)
{
	int i, wordLength = strlen(word);
	char curChar;

	if (CantSearchThatDirection(inputData, wordLength, r, c, d))
		return;

	for (i = 1; i < wordLength; i++)
	{
		curChar = inputData.inputs[r + i * d.vertical][c + i * d.horizontal];
		if (curChar != word[i] && curChar != word[i] + 32)
			return;
	}

	printf("%d %d\n", r + 1, c + 1);
}

int CantSearchThatDirection(inputData inputData, int wordLength, int r, int c, direction d)
{
	return (d.vertical == -1 && r - (wordLength - 1) < 0) ||
		   (d.vertical == 1 && r + (wordLength - 1) > inputData.maxRow) ||
		   (d.horizontal == -1 && c - (wordLength - 1) < 0) ||
		   (d.horizontal == 1 && c + (wordLength - 1) > inputData.maxCol);
}