#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// �Ű������� ���� ������ ������ ��ȯ�ϴ� �Լ�. (���� ������ ����� ���� �Լ�)
unsigned int GetReverse(unsigned int origin)
{
	unsigned int reverse = 0;
	for (unsigned int temp = origin; temp != 0; temp /= 10)
	{
		reverse = (reverse * 10) + temp % 10;
	}
	return reverse;
}

// �Ű������� ���� �������� ���� �Ųٷε� ���� ���ϴ� �Լ�. (�ݵ�� �����ؾ� ��, ��������)
void reverse_add(unsigned int* origin)
{
	*origin += GetReverse(*origin);
}

// �Ű������� ���� ������ ȸ������ �Ǵ��ϴ� �Լ�. (�ݵ�� �����ؾ� ��, ��������)
// ȸ���̶�� 1, �ƴ϶�� 0�� ��ȯ�Ѵ�.
int is_palindrome(unsigned int num)
{
	return num == GetReverse(num);
}

void main()
{
	int r = 0; // ������ ���� Ƚ��
	unsigned int p = 0; // ȸ���� 4,294,967,295���� ũ�� ���� (����)
	unsigned int* pPointer = &p;
	printf("Please enter a number : "); scanf("%d", &p);

	while (r++ < 1000) // ������ ���ϴ� �۾� 1000�� �̳� ȸ���� ã�� �� ���� (����)
	{
		reverse_add(pPointer);
		if (is_palindrome(p)) break;
	}

	if (r < 1000) printf("%d %d", r, p);
	else printf("There is no palindrome.");
}

/* �ʼ� ���� �Լ��� ���ٸ�, �Ʒ� ���� �ڵ差�� ���� ���� ����.
void main()
{
	int r = 0; // ������ ���� Ƚ��
	unsigned int p = 0, reverse = 0, temp = 0; // ȸ���� 4,294,967,295���� ũ�� ���� (����)
	printf("Please enter a number : "); scanf("%d", &p);

	for (temp = p; temp != 0; temp /= 10)
		reverse = (reverse * 10) + temp % 10;

	while (++r < 1000) // ������ ���ϴ� �۾� 1000�� �̳� ȸ���� ã�� �� ���� (����)
	{
		p += reverse;
		reverse = 0;
		for (temp = p; temp != 0; temp /= 10)
			reverse = (reverse * 10) + temp % 10;
		if (p == reverse) break;
	}

	if (r < 1000) printf("%d %d", r, p);
	else printf("There is no palindrome.");
}
*/