#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // sprintf
#include <stdlib.h> // malloc, free

void TryLeftStep(char* originStr, int remainStairs, int leftAmount);
void TryRightStep(char* originStr, int remainStairs);

// ���� : n���� ����� ���� �� �ִ� ����� �� ��� 
// ���� : �޹� 1 ~ 3ĭ, ������ 1ĭ 
// �ذ� : (����)����Լ� ����� sprintf �Լ� �̿�

// ���� strcat, strcpy �Լ��� ����Ϸ��ߴµ�, sprintf �Լ� �ϳ��� �ذ��� �� �־���!
// printf : PRINT Formatted	: ���� ���ڿ��� �ֿܼ� ���
// sprintf : String PRINTF	: ���� ���ڿ��� char �迭(���ڿ�)�� ���(����?)

int main()
{
	int n;
	printf("How many steps do you want: "); scanf("%d", &n);

	// main�Լ����� Ʈ���� ù ������ ����
	char temp[1] = "";
	TryLeftStep(temp, n, 3);
	TryLeftStep(temp, n, 2);
	TryLeftStep(temp, n, 1);
	TryRightStep(temp, n);
	
	return 0;
}

// �޹� ������ �õ� (�Ű������� ���� ĭ �� ����, 1 ~ 3ĭ)
void TryLeftStep(char* originStr, int remainStairs, int stepAmount)
{
	char* totalStr = malloc(strlen(originStr) + 4);
	sprintf(totalStr, "%s%dL ", originStr, stepAmount);

	remainStairs -= stepAmount;
	if (remainStairs > 0) TryRightStep(totalStr, remainStairs);
	else if (remainStairs == 0) printf("%s\n", totalStr);

	free(totalStr);
}

// ������ ������ �õ� (�������� 1ĭ ����)
void TryRightStep(char* originStr, int remainStairs)
{
	char* totalStr = malloc(strlen(originStr) + 4);
	sprintf(totalStr, "%s1R ", originStr);

	if (--remainStairs > 0)
	{
		TryLeftStep(totalStr, remainStairs, 3);
		TryLeftStep(totalStr, remainStairs, 2);
		TryLeftStep(totalStr, remainStairs, 1);
	}
	else printf("%s\n", totalStr);

	free(totalStr);
}