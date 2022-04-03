#pragma once
#define Q_SIZE 4
typedef char element;

typedef struct
{
	element queue[Q_SIZE];
	int front, rear;
} QueueType;

QueueType* createQueue(void);
int isQueueEmpty(QueueType* Q);
int isQueueFull(QueueType* Q);
void enQueue(QueueType* Q, element item);
element deQueue(QueueType* Q);
element peedQ(QueueType* Q);
void prentQ(QueueType* Q);