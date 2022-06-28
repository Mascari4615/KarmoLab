#include <stdio.h>
#include <stdlib.h>
#include "deQue.h"

DQueType* createDQue(void)
{
	DQueType* DQ;
	DQ = (DQueType*)malloc(sizeof(DQueType));
	DQ->front = NULL; // front ÃÊ±ê°ª ¼³Á¤
	DQ->rear = NULL; // reat ÃÊ±ê°ª ¼³Á¤
	return DQ;
}

int isDQueEmpty(DQueType* DQ)
{
	if (DQ->front == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void insertFront(DQueType* DQ, element item)
{
	DNode* newNode = (DNode*)malloc(sizeof(DNode));
	newNode->data = item;
	if (isDQueEmpty(DQ))
	{
		DQ->front == newNode;
		DQ->rear = newNode;
		newNode->rlink = NULL;
		newNode->llink = NULL;
	}
	else
	{
		DQ->front->llink == newNode;
		newNode->rlink = DQ->front;
		newNode->llink = NULL;
		DQ->front = newNode;
	}
}
void insertRear(DQueType* DQ, element item)
{
	DNode* newNode = (DNode*)malloc(sizeof(DNode));
	newNode->data = item;
	if (isDQueEmpty(DQ))
	{
		DQ->front == newNode;
		DQ->rear = newNode;
		newNode->rlink = NULL;
		newNode->llink = NULL;
	}
	else
	{
		DQ->rear->rlink == newNode;
		newNode->llink = DQ->front;
		newNode->rlink = NULL;
		DQ->rear = newNode;
	}
}
element deleteFront(DQueType* DQ)
{
	DNode* old = DQ->front;
	element item;
	if (isDQueEmpty(DQ))
	{
		return;
	}
	else
	{
		item = old->data;
		if (DQ->front->rlink == NULL)
		{
			DQ->front = NULL;
			DQ->rear = NULL;
		}
		else
		{
			DQ->front = DQ->front->rlink;
			DQ->front->llink = NULL;
		}
		free(old);
		return item;
	}
}
element deleteRear(DQueType* DQ)
{
	DNode* old = DQ->rear;
	element item;
	if (isDQueEmpty(DQ))
	{
		return;
	}
	else
	{
		item = old->data;
		if (DQ->rear->llink == NULL)
		{
			DQ->front = NULL;
			DQ->rear = NULL;
		}
		else
		{
			DQ->rear = DQ->rear->llink;
			DQ->rear->rlink = NULL;
		}
		free(old);
		return item;
	}
}
element peekFront(DQueType* DQ)
{
	element item;
	if (isDQueEmpty(DQ)) return;
	else 
	{
		item = DQ->front->data;
		return item;
	}
}
element peekRaer(DQueType* DQ)
{
	element item;
	if (isDQueEmpty(DQ)) return;
	else
	{
		item = DQ->rear->data;
		return item;
	}
}
void printDQ(DQueType* DQ)
{
	DNode* temp = DQ->front;
	printf(" DeQue : [");
	while (temp)
	{
		printf("%3c", temp->data);
		temp = temp->rlink;
	}
	printf(" ]");
}