#include "LinkedQueueS.h"

int main(void)
{
	LQueueType* LQ = createLinkedQueue();
	element data;
	printf("\n ***** 연결 큐 연산 ***** \n");
	printf("\n 삽입 A>>"); enCQueue(LQ, 'A'); printCQ(LQ);
	printf("\n 삽입 B>>"); enCQueue(LQ, 'B'); printCQ(LQ);
	printf("\n 삽입 C>>"); enCQueue(LQ, 'C'); printCQ(LQ);
	data = peekQ(LQ); printf(" peek item : %c \n", data);
	printf("\n 삭제 >>"); data = deCQueue(LQ); printCQ(LQ);
	printf("\n삭제 데이터: %c", data);
	printf("\n 삭제 >>"); data = deCQueue(LQ); printCQ(LQ);
	printf("\n삭제 데이터: %c", data);
	printf("\n 삭제 >>"); data = deCQueue(LQ); printCQ(LQ);
	printf("\n삭제 데이터: %c", data);

	printf("\n 삽입 D>>"); enCQueue(LQ, 'D'); printCQ(LQ);
	printf("\n 삽입 E>>"); enCQueue(LQ, 'E'); printCQ(LQ);

	getchar(); return 0;
}