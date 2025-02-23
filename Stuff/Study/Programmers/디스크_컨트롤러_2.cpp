#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct CompareProcessTime
{
	bool operator()(const vector<int>& v1, const vector<int>& v2)
	{
		// �켱���� ť�� ū �� ������� �����ϱ� ������,
		// ������������ ������ֱ� ���ؼ��� ���� ������ �ݴ��
		return v1[1] > v2[1];
	}
};

struct CompareReqTime
{
	bool operator()(const vector<int>& v1, const vector<int>& v2)
	{
		return v1[0] < v2[0];
	}
};

int solution(vector<vector<int>> jobs)
{
	priority_queue<vector<int>, vector<vector<int>>, CompareProcessTime> pq;

	sort(jobs.begin(), jobs.end(), CompareReqTime());
	auto it = jobs.begin();

	int sumOfElapsedTime = 0;
	int curTime = jobs[0][0];

	while ((it != jobs.end()) || !pq.empty())
	{
		while ((it != jobs.end()) && ((*it)[0] <= curTime))
		{
			pq.push((*it));
			it++;
		}

		if (!pq.empty())
		{
			curTime += pq.top()[1];
			sumOfElapsedTime += (curTime - pq.top()[0]);
			pq.pop();
		}
		else
		{
			curTime = (*it)[0];
		}
	}

	return sumOfElapsedTime / jobs.size();
}