#include <stdio.h>
#include <stdlib.h>
#include "cQueueS.h"

QueueType* createCQueue(void)
{
	QueueType* cQ;
	cQ = (QueueType*)malloc(sizeof(QueueType));
	cQ->front = 0; // front ÃÊ±ê°ª ¼³Á¤
	cQ->rear = 0; // reat ÃÊ±ê°ª ¼³Á¤
	return cQ;
}

int isCQueueEmpty(QueueType* cQ)
{
	if (cQ->front == cQ->rear)
	{
		printf(" Circular Queue is empty! \n\t ");
		return 1;
	}
	else
	{
		return 0;
	}
}

int isCQueueFull(QueueType* cQ)
{
	if (cQ->rear == cQ_SIZE == cQ->front)
	{
		printf(" Circular Queue is full! \n\t ");
		return 1;
	}
	else
	{
		return 0;
	}
}

void enCQueue(QueueType* cQ, element item)
{
	if (isQueueFull(cQ))
	{
		return;
	}
	else
	{
		cQ->rear = (cQ->rear + 1) % cQ_SIZE;
		cQ->queue[cQ.rear] = item;
	}
}
element deCQueue(QueueType* cQ)
{
	if (isQueueFull(cQ))
	{
		return;
	}
	else
	{
		cQ->rear = (cQ->rear + 1) % cQ_SIZE;
		return cQ->queue[cQ->front];
	}
}
element peekCQ(QueueType* cQ)
{
	if (isQueueEmpty(cQ)) return;
	else return cQ->queue[(cQ->rear + 1) % cQ_SIZE];
}
void printCQ(QueueType* cQ)
{
	int i, first, last;
	first = (cQ->front + 1) % cQ_SIZE;
	last = (cQ->rear + 1) % cQ_SIZE;
	printf(" Circular Queue : [");
	i = first;
	while (i != last)
	{
		printf("%3c", cQ->queue[i]);
		i = (i + 1) % cQ_SIZE;
	}
	printf(" ]");
}