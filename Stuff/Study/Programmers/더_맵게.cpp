#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

// ����
// return ��� ���� K �̻�, ����� �ϴ� �ּ� Ƚ��
// �Ұ��� �ϸ� -1

// ����
// ���� ���� + �� ��°�� ���� * 2

using namespace std;

int solution(vector<int> scoville, int K)
{
	int mixCount = 0;
	bool containsKHigh = false;
	priority_queue<int, vector<int>, greater<int>> q;

	for (int i = 0; i < scoville.size(); i++)
	{
		if (scoville[i] < K)
			q.push(scoville[i]);
		else
			containsKHigh = true;
	}

	while (q.size() > 1)
	{
		int mix = q.top();
		q.pop();
		mix += q.top() * 2;
		q.pop();

		mixCount++;

		if (mix >= K)
			containsKHigh = true;
		else
			q.push(mix);
	}

	if (q.size() == 1)
	{
		if (containsKHigh)
			mixCount++;
		else
			return -1;
	}

	return mixCount;
}

// ó���� Vector�� Ǯ���ٰ� �ð� �ʰ�

/*
int solution(vector<int> scoville, int K)
{
	int mixCount = 0;

	while (true)
	{
		sort(scoville.begin(), scoville.end());

		if (scoville[0] < K)
		{
			if (scoville.size() <= 1)
				return -1;

			scoville.push_back(scoville[0] + scoville[1] * 2);
			scoville.erase(scoville.begin() + 1);
			scoville.erase(scoville.begin() + 0);
			mixCount++;
		}
		else
		{
			break;
		}
	}

	return mixCount;
}
*/