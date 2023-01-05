#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 한 번호가 다른 번호의 접두어인 경우가 있는지
// phone_book 길이 1 <= x <= 1,000,000
// 중복 없음

bool solution(vector<string> phone_book)
{
	sort(phone_book.begin(), phone_book.end());

	for (int i = 0; i < phone_book.size() - 1; i++)
	{
		if (phone_book[i].size() > phone_book[i + 1].size())
			continue;

		for (int j = 0; j < phone_book[i].size(); j++)
		{
			if (phone_book[i][j] != phone_book[i + 1][j])
				break;

			if (j == phone_book[i].size() - 1)
				return false;
		}
	}

	return true;
}