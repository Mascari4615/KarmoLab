#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>

int IsCouple(char* string);

// char* inputs[n]로 쓰고 싶었지만, VS에서는 가변 길이 배열(VLA)을 지원하지 않았음.. 
// 때문에 이중 포인터를 사용하고, malloc 함수를 이용해 동적 할당하는 방법 사용

void main()
{
	int n;
	printf("Enter N : ");
	scanf("%d", &n);

	char** inputs, temp[100] = { NULL, };
	while ((inputs = malloc(sizeof(char*) * n)) == NULL);

	for (int i = 0; i < n; i++)
	{
		scanf("%s", temp);
		while ((inputs[i] = malloc(strlen(temp) + 1)) == NULL);
		strcpy(inputs[i], temp);
	}

	printf("\n");

	for (int i = 0; i < n; i++)
	{
		if (IsCouple(inputs[i])) 
			printf("Good");
		else
		{
			// 짝이 없는 알파벳 거꾸로 출력
			for (int j = strlen(inputs[i]); j >= 0; j--) 
				if (inputs[i][j] != '#')
					printf("%c", inputs[i][j]);
		}
		printf("\n");

		// 문자열을 더 사용하지 않기 때문에 할당 해제
		free(inputs[i]); 
	}

	// 이중 포인터도 할당 해제
	free(inputs); 
}

// 매개변수로 받은 문자열 내 알파벳들이 모두 짝이 있는지 확인
int IsCouple(char* string) 
{
	int coupleCount = 0;

	// 짝이 있는 알파벳을 찾아 #으로 바꾸고, coupleCount++
	for (int i = 0; i < strlen(string) - 1; i++) 
	{
		if (string[i] == '#')
			continue;

		for (int j = i + 1; j < strlen(string); j++)
		{
			if (string[i] == '#')
				continue;

			if (string[i] == string[j])
			{
				string[i] = string[j] = '#';
				coupleCount++;
				break;
			}
		}
	}

	return strlen(string) == coupleCount * 2;
}