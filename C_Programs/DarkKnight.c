#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void Problem18();
void Problem19();

void main()
{
	int n;
	double pi = 0;
	printf("반복횟수:");
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		double temp = (double)4 / (i * 2 - 1);
		if (i % 2 == 1) pi += temp;
		else pi -= temp;
	}

	printf("Pi = %f", pi);
	
	return 0;
}

void Problem18()
{
	int cash = 50;
	int target = 250;
	int bets = 0;
	int win = 0;

	printf("초기금액 $%d\n", cash);
	printf("목표금액 $%d\n", target);

	while (cash < target && cash > 0)
	{
		bets++; // 배팅 횟수 증가
		if ((double)rand() / RAND_MAX < 0.5)
		{
			cash++; // $1을 딴다.
			win++;
		}
		else cash--; // $1을 잃는다.
	}

	printf("%d 중의 %d번 승리\n", bets, win);
	printf("이긴 확률=%f", (double)win / bets * 100);
}

void Problem19()
{
	int n;
	double pi = 0;
	printf("반복횟수:");
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		double temp = (double)4 / (i * 2 - 1);
		if (i % 2 == 1) pi += temp;
		else pi -= temp;
	}

	printf("Pi = %f", pi);
}