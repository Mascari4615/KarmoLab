#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void sum_diff_mul(int x, int y);

void main()
{
	int x = 0, y = 0;
	char yn = "";

	// X, Y �Է�
Input_XY:
	printf(" =====================================================\n");
	printf(" �� ���� x�� y�� ���� �Է����ּ���. (�̶�, x�� y���� ũ��)\n");

	// X �Է�
Input_X:
	printf(" x : ");
	if (!scanf("%d", &x))
	{
		printf(" �ùٸ��� ���� x�� �Է��Դϴ�. �ٽ� �Է����ּ���. \n");
		while (getchar() != '\n') {}
		goto Input_X;
	}
	while (getchar() != '\n') {}

	// Y �Է�
Input_Y:
	printf(" y : ");
	if (!scanf("%d", &y))
	{
		printf(" �ùٸ��� ���� y�� �Է��Դϴ�. �ٽ� �Է����ּ���. \n");
		while (getchar() != '\n') {}
		goto Input_Y;
	}
	while (getchar() != '\n') {}

	// X > Y ���� Ȯ��
	printf("\n");
	if (x <= y)
	{
		if (x < y) printf(" x�� y���� �۰ų� �����ϴ�.");
		else if (x == y) printf(" x�� y�� �����ϴ�.");
		printf(" x�� y���� Ŀ���մϴ�. �ٽ� �Է����ּ���.\n\n");
		goto Input_XY;
	}

	// �Լ� ����
	sum_diff_mul(x, y);

	// ���α׷� ����� ���� Ȯ��
Input_YN:
	printf(" ���α׷��� �ٽ� �����Ͻðڽ��ϱ� ? (Y/N) : ");
	scanf("%c", &yn);
	while (getchar() != '\n') {}
	if (yn == 'Y' || yn == 'y')
	{
		printf(" �ٽ� �����մϴ�.\n\n");
		goto Input_XY;
	}
	else if (yn == 'N' || yn == 'n')
		printf(" ���α׷��� �����մϴ�. �����մϴ�.\n\n");
	else
	{
		printf(" �ùٸ��� ���� �Է��Դϴ�. �ٽ� �Է����ּ���.\n\n");
		goto Input_YN;
	}

	return 0;
}

void sum_diff_mul(int x, int y)
{
	int sum = x + y;
	int diff = x - y;
	int mul = x * y;

	printf(" - ��� -\n");
	printf(" ��(SUM) \t: %d + %d = %d\n", x, y, sum);
	printf(" ��(DIFF) \t: %d - %d = %d\n", x, y, diff);
	printf(" ��(MUL) \t: %d * %d = %d\n\n", x, y, mul);
}