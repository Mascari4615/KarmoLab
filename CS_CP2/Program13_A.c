#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>

int IsCouple(char* string);

int main()
{
	int n = 1;
	printf("Enter N : ");
	scanf("%d", &n);

	// char* inputs[n]로 쓰고 싶었지만, VS에서는 가변 길이 배열(VLA)을 지원하지 않았음.. 
	// 때문에 이중 포인터를 사용하고, malloc 함수를 이용해 동적 할당하는 방법 사용
	char** inputs = (char**)malloc(sizeof(char*) * n);
	char temp[100] = { NULL, };

	for (int i = 0; i < n; i++)
	{
		scanf("%s", temp);
		// 문자열도 malloc 함수를 이용해 동적 할당
		inputs[i] = (char*)malloc(sizeof(char) * strlen(temp));
		strcpy(inputs[i], temp);
	}

	printf("\n");

	for (int i = 0; i < n; i++)
	{
		if (IsCouple(inputs[i]))
			printf("Good");
		else
		{
			// IsCouple 함수에서 짝이 있는 알파벳들을 #으로 바꿨음, #이 아닌 알파벳만 출력
			for (int j = 0; j < strlen(inputs[i]); j++)
			{
				if (inputs[i][j] != '#')
					printf("%c", inputs[i][j]);
			}
		}

		printf("\n");
		// 문자열에 더 이상 접근하지 않기 때문에, free 함수를 이용해 할당 해제
		free(inputs[i]);
	}

	// 동적 할당한 모든 문자열을 할당 해제 한 이후, 이중 포인터도 할당 해제
	free(inputs);
	return 0;
}

// 매개변수로 받은 문자열 내 알파벳들이 모두 짝이 있는지 확인
int IsCouple(char* string)
{
	// 알파벳 쌍의 수, 마지막 줄에서 반환 값을 결정하는 데 사용함
	int coupleCount = 0;

	// 짝이 있는 알파벳을 찾아 #으로 바꾸고, coupleCount++
	for (int i = 0; i < strlen(string) - 1; i++)
	{
		if (string[i] == '#') continue;

		for (int j = i + 1; j < strlen(string); j++)
		{
			if (string[j] == '#') continue;

			if (string[i] == string[j])
			{
				string[i] = '#';
				string[j] = '#';
				coupleCount++;
				break;
			}
		}
	}

	// char도 결국 숫자형 데이터 타입, 알파벳(숫자) 순으로 정렬
	char temp;
	for (int i = 0; i < strlen(string) - 1; i++)
	{
		for (int j = i + 1; j < strlen(string); j++)
		{
			if (string[i] > string[j])
			{
				temp = string[i];
				string[i] = string[j];
				string[j] = temp;
			}
		}
	}

	return (strlen(string) - coupleCount * 2 == 0);
}