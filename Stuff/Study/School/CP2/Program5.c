#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void seat(int n, int c, int* buf)
{
	int temp;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (buf[i] > buf[j])
			{
				temp = buf[i];
				buf[i] = buf[j];
				buf[j] = temp;
			}
		}

		printf("%d ", buf[i]);
		if (i != 0 && (i + 1) % c == 0) printf("\n");
	}
}

void main()
{
	int n, c; // �л� ��, �ڸ� ��
	scanf("%d %d", &n, &c);
	int* buf = malloc(sizeof(int) * n); // �л��� Ű �� ����, �����Ϳ� int(4Byte) * n ��ŭ �����Ҵ�
	for (int i = 0; i < n; i++) scanf("%d", &buf[i]);
	seat(n, c, buf);
	free(buf);
}