#include <stdio.h>
#include <stdlib.h>
#include "queueS.h"

// 공백 순차 큐를 생성하는 연산
QueueType* createQueue(void)
{
	QueueType* Q;
	Q = (QueueType*)malloc(sizeof(QueueType));
	Q->front = -1; // front 초깃값 설정
	Q->rear = -1; // reat 초깃값 설정
	return Q;
}

// 순차 큐가 공백 상태인지 검사하는 연산
int isQueueEmpty(QueueType* Q)
{
	if (Q->front == Q->rear)
	{
		printf(" Queue is empty! \n\t ");
		return 1;
	}
	else
	{
		return 0;
	}
}

int isQueueFull(QueueType* Q)
{
	if (Q->rear == Q_SIZE - 1)
	{
		printf(" Queue is full! \n\t ");
		return 1;
	}
	else
	{
		return 0;
	}
}

void enQueue(QueueType* Q, element item)
{
	if (isQueueFull(Q))
	{
		return;
	}
	else
}
element deQueue(QueueType* Q);
element peedQ(QueueType* Q);
void prentQ(QueueType* Q);