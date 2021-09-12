#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

void sum_diff_mul(int x, int y);

void main()
{
	int x = 0, y = 0;
	bool restart = true;
	char yn;

	do
	{
	ReInput_XY:

		printf(" =====================================================\n");
		printf(" 두 정수 x와 y의 값을 입력해주세요. (이때, x는 y보다 크다)\n");

		printf(" x: ");
		scanf("%d", &x);
		printf("%d", x);
		getchar();

		printf(" y: ");
		scanf("%d", &y);
		printf("%d", y);
		getchar();

		printf("\n");

		if (x <= y)
		{
			printf(" x가 y보다 작거나 같습니다. x는 y보다 커야합니다. 다시 입력해주세요.\n\n");
			goto ReInput_XY;
		}

		sum_diff_mul(x, y);

	ReInput_YN:

		printf(" 다시 실행하시겠습니까 ? (Y/N) : ");
		scanf("%c", &yn);
		getchar();

		printf("\n");

		switch (yn)
		{
		case 'Y': case 'y':
			printf(" 다시 실행합니다.\n\n");
			restart = true;
			break;
		case 'N': case 'n':
			printf(" 다시 실행하지 않습니다.\n\n");
			restart = false;
			break;
		default:
			printf(" %c 는 올바르지 않은 입력입니다. Y 또는 N 을 입력해주세요.\n\n", yn);
			goto ReInput_YN;
		}

	} while (restart);

	printf(" 프로그램을 종료합니다. 감사합니다.\n");

	return 0;
}

void sum_diff_mul(int x, int y)
{
	int sum = x + y;
	int diff = x - y;
	int mul = x * y;

	printf(" 결과 - ");
	printf("합(SUM) : %d, ", sum);
	printf("차(DIFF) : %d, ", diff);
	printf("곱(MUL) : %d\n\n", mul);
}