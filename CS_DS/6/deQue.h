#pragma once
typedef char element;

typedef struct DNode
{
	element data;
	struct DNode* llink;
	struct DNode* rlink;
} DNode;

typedef struct
{
	DNode* front,* rear;
} DQueType;

DQueType* createDQue(void);
int isDQueEmpty(DQueType* DQ);
void insertFront(DQueType* DQ, element item);
void insertRear(DQueType* DQ, element item);
element deleteFront(DQueType* DQ);
element deleteRear(DQueType* DQ);
element peekFront(DQueType* DQ);
element peekRaer(DQueType* DQ);
void printDQ(DQueType* DQ);