#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // malloc, free
#include <math.h> // floor

// ���� : ���� ��� N���ϱ� ���� ���� �������ϴ� �ݾ��� ����

int main()
{
	int studentCount;
	scanf("%d", &studentCount);

	float* expenses = malloc(studentCount * sizeof(float));
	float totalExpenses = 0; // ��� ����

	// ģ������ �� ��� ģ�� ����ŭ �Է¹ް�, ���� ��� ���տ� ����
	for (int i = 0; i < studentCount; i++)
	{ 
		scanf("%f", &expenses[i]); 
		totalExpenses += expenses[i]; 
	}

	float expensesAverage = totalExpenses / studentCount; // ��� ���
	float totalTransfer = 0; // ���� �ݾ� ����

	// ������ �� ��� ��� ��պ��� ���� ���, �׸�ŭ �ٸ� ģ���鿡�� �޾ƾ��ϱ� ������, �� ���̸� ���� �ݾ׿� ����
	for (int i = 0; i < studentCount; i++)
		if (expenses[i] > expensesAverage)
			totalTransfer += floor((expenses[i] - expensesAverage) * 100) / 100;

	printf("%.2f", totalTransfer);
	free(expenses);

	return 0;
}