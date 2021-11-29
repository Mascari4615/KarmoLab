//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
///*
//typedef struct Drirection {
//	int vertical;
//	int horizontal;
//} direction;
//
//direction NW = { .vertical = -1, .horizontal = -1 };
//direction N; //~
//direction NE; //~
//direction E;
//direction SE;
//direction S;
//direction SW;
//direction W;
//*/
//
//void Find(char** inputs, int maxRow, char* word);
//void Try8Direction(char** inputs, int maxRow, char* word, int r, int c);
//int CanFindWord(char** inputs, char* word, int originR, int originC, int verticalDirection, int horizontalDirecton);
//
//void main()
//{
//	int i, j, m, n, wordCount; // 1이상 40이하, 1이상 20이하
//	char **inputs, ** words;
//
//	scanf("%d %d", &m, &n);
//	inputs = (char**)malloc(sizeof(char*) * m);
//	for (i = 0; i < m; i++)
//	{
//		inputs[i] = (char*)malloc(sizeof(char) * n + 1);
//		scanf("%s", inputs[i]);
//	}
//
//	scanf("%d", &wordCount);
//	words = (char**)malloc(sizeof(char*) * wordCount);
//	for (i = 0; i < wordCount; i++)
//	{
//		words[i] = (char*)malloc(sizeof(char) * 101);
//		scanf("%s", words[i]);
//		words[i] = (char*)realloc(words[i], strlen(words[i]) + 1);
//
//		for (j = 0; j < strlen(words[i]); j++)
//		{
//			if (words[i][j] >= 97)
//				words[i][j] -= 32;
//		}
//	}
//
//	for (i = 0; i < wordCount; i++)
//	{
//		Find(inputs, m, words[i]);
//		free(words[i]);
//	}
//	free(words);
//
//	for (i = 0; i < m; i++)
//		free(inputs[i]);
//	free(inputs);
//}
//
//void Find(char** inputs, int maxRow, char* word)
//{
//	int r, c, maxCol = strlen(inputs[0]);
//
//	for (r = 0; r < maxRow; r++)
//	{
//		for (c = 0; c < maxCol; c++)
//		{
//			if (inputs[r][c] != word[0] && 
//				inputs[r][c] != word[0] + 32)
//				continue;
//			Try8Direction(inputs, maxRow, word, r, c);
//		}
//	}
//}
//
//void Try8Direction(char** inputs, int maxRow, char* word, int r, int c)
//{
//	int ud, lr, maxCol = strlen(inputs[0]), wordLen = strlen(word);
//
//	/*		
//			lr -1  0  1
//		ud
//		-1	   WN 0N EN
//		 0     0W  - 0E
//		 1     WS 0S ES
//	*/
//
//	for (ud = -1; ud <= 1; ud++)
//	{
//		if ((ud == -1 && r - wordLen < 0) || 
//			(ud == 1 && maxRow - (r + wordLen) < 0))
//			continue;
//
//		for (lr = -1; lr <= 1; lr++)
//		{
//			if ((lr == -1 && c - wordLen < 0) || 
//				(lr == 0 && ud == 0) ||
//				(lr == 1 && maxCol - (c + wordLen) < 0))
//				continue;
//
//			if (CanFindWord(inputs, word, r, c, ud, lr))
//			{
//				printf("%d %d\n", r + 1, c + 1);
//			}	
//		}
//	}
//
//	/*
//	
//	
//	if ((ud == -1 && r - wordLength < 0)
//		CanFindWord(~~, r, c, -1, -1);
//	if ((ud == -1 && r - wordLength < 0)
//		CanFindWord(~~, r, c, -1, 0);
//	if ((ud == -1 && r - wordLength < 0)
//		CanFindWord(~~, r, c, -1, 1);
//	if ((ud == -1 && r - wordLength < 0)
//		CanFindWord(~~, r, c, 0, -1);
//
//		~~~~
//
//	*/
//
//	/*
//	CanFindWord(~~, r, c, NW);
//	CanFindWord(~~, r, c, N);
//
//
//	-----------------------------------
//
//	// NW
//	CanFindWord(~~, r, c, -1, -1);
//
//	//N
//	CanFindWord(~~, r, c, -1, 0);
//
//	*/
//}
//
//// int CanFindWord(char** inputs, char* word, int originR, int originC, Drirection direction)
//int CanFindWord(char** inputs, char* word, int originR, int originC, int verticalDirection, int horizontalDirecton)
//{
//	int i, wordLength = strlen(word);
//	char curChar;
//
//	for (i = 1; i < wordLength; i++)
//	{
//		curChar = inputs[originR + i * verticalDirection][originC + i * horizontalDirecton];
//		// curChar = inputs[originR + i * direction.vertical][originC + i * direction.horizontal];
//		if (curChar != word[i] && curChar != word[i] + 32)
//			return 0;
//	}
//
//	return 1;
//}
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Find(char** inputs, int maxRow, char* word);

void main()
{
	int i, j, m, n, wordCount; // 1이상 40이하, 1이상 20이하
	char** inputs, ** words;

	scanf("%d %d", &m, &n);
	inputs = (char**)malloc(sizeof(char*) * m);
	for (i = 0; i < m; i++)
	{
		inputs[i] = (char*)malloc(sizeof(char) * n + 1);
		scanf("%s", inputs[i]);
	}

	scanf("%d", &wordCount);
	words = (char**)malloc(sizeof(char*) * wordCount);
	for (i = 0; i < wordCount; i++)
	{
		words[i] = (char*)malloc(sizeof(char) * 101);
		scanf("%s", words[i]);
		words[i] = (char*)realloc(words[i], strlen(words[i]) + 1);

		for (j = 0; j < strlen(words[i]); j++)
		{
			if (words[i][j] >= 97)
				words[i][j] -= 32;
		}
	}

	for (i = 0; i < wordCount; i++)
	{
		Find(inputs, m, words[i]);
		free(words[i]);
	}
	free(words);

	for (i = 0; i < m; i++)
		free(inputs[i]);
	free(inputs);
}


void Find(char** inputs, int m, char* word)
{
	int r, c, n = strlen(inputs[0]), ud, lr, i, wordLen = strlen(word);

	for (r = 0; r < m; r++)
	{
		for (c = 0; c < n; c++)
		{
			for (ud = -1; ud <= 1; ud++)
			{
				if ((ud == -1 && r - wordLen < 0) || (ud == 1 && m - (r + wordLen) < 0))
					continue;

				for (lr = -1; lr <= 1; lr++)
				{
					if ((lr == -1 && c - wordLen < 0) || (lr == 1 && n - (c + wordLen) < 0))
						continue;

					for (i = 0; i < wordLen; i++)
						if (inputs[r + i * ud][c + i * lr] != word[i] && inputs[r + i * ud][c + i * lr] != word[i] + 32)
							goto EXIT;

					printf("%d %d\n", r + 1, c + 1);				
				EXIT:;
				}
			}
		}
	}
}