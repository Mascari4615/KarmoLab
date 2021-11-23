#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Find(char** inputs, int maxRow, char* word);
void Try8Direction(char** inputs, int maxRow, char* word, int r, int c);
int CanFindWord(char** inputs, char* word, int originR, int originC, int verticalDirection, int horizontalDirecton);

void main()
{
	int i, inputCount, stringLength, wordLength; // 1이상 40이하, 1이상 20이하
	char **inputs, temp[100] = { NULL, }, ** inputWords;

	scanf("%d %d", &inputCount, &stringLength);
	inputs = (char**)malloc(sizeof(char*) * inputCount);
	for (i = 0; i < inputCount; i++)
	{
		inputs[i] = (char*)malloc(sizeof(char) * stringLength + 1);
		scanf("%s", inputs[i]);
	}

	scanf("%d", &wordLength);
	inputWords = (char**)malloc(sizeof(char*) * inputCount);
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
		Find(inputs, inputCount, inputWords[i]);
		free(inputWords[i]);
	}
	free(inputWords);

	for (i = 0; i < inputCount; i++)
		free(inputs[i]);
	free(inputs);
}

void Find(char** inputs, int maxRow, char* word)
{
	int r, c, maxCol = strlen(inputs[0]);

	for (r = 0; r < maxRow; r++)
	{
		for (c = 0; c < maxCol; c++)
		{
			if (inputs[r][c] != word[0] && 
				inputs[r][c] != word[0] + 32)
				continue;
			Try8Direction(inputs, maxRow, word, r, c);
		}
	}
}

void Try8Direction(char** inputs, int maxRow, char* word, int r, int c)
{
	int ud, lr, maxCol = strlen(inputs[0]), wordLength = strlen(word);

	/*		
			lr -1  0  1
		ud
		-1	   WN 0N EN
		 0     0W  - 0E
		 1     WS 0S ES
	*/

	for (ud = -1; ud <= 1; ud++)
	{
		if ((ud == -1 && r - wordLength < 0) || 
			(ud == 1 && maxRow - (r + wordLength) < 0))
			continue;

		for (lr = -1; lr <= 1; lr++)
		{
			if ((lr == -1 && c - wordLength < 0) || 
				(lr == 0 && ud == 0) ||
				(lr == 1 && maxCol - (c + wordLength) < 0))
				continue;

			if (CanFindWord(inputs, word, r, c, ud, lr))
			{
				printf("%d %d\n", r + 1, c + 1);
			}	
		}
	}
}

int CanFindWord(char** inputs, char* word, int originR, int originC, int verticalDirection, int horizontalDirecton)
{
	int i, wordLength = strlen(word);
	char curChar;

	for (i = 1; i < wordLength; i++)
	{
		curChar = inputs[originR + i * verticalDirection][originC + i * horizontalDirecton];
		if (curChar != word[i] && curChar != word[i] + 32)
			return 0;
	}

	return 1;
}

//void Find(char** inputs, int maxRow, char* word)
//{
//	for (int r = 0; r < maxRow; r++)
//	{
//		for (int c = 0; c < strlen(inputs[0]); c++)
//		{
//			for (int ud = -1; ud <= 1; ud++)
//			{
//				if ((ud == -1 && r - (int)strlen(word) < 0) || (ud == 1 && maxRow - (r + (int)strlen(word)) < 0))
//					continue;
//
//				for (int lr = -1; lr <= 1; lr++)
//				{
//					if ((lr == -1 && c - (int)strlen(word) < 0) || (lr == 1 && (int)strlen(inputs[0]) - (c + (int)strlen(word)) < 0))
//						continue;
//
//					for (int i = 0; i < strlen(word); i++)
//						if (inputs[r + i * ud][c + i * lr] != word[i] && inputs[r + i * ud][c + i * lr] != word[i] + 32)
//							goto EXIT;
//
//					printf("%d %d\n", r + 1, c + 1);				
//				EXIT:;
//				}
//			}
//		}
//	}
//}