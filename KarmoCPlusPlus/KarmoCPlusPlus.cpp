#include <iostream>

using namespace std;

int main()
{
	int k, n;
	cin >> k >> n;

	int* l = new int[k];

	long long min = 1;
	long long max = 0;

	for (int i = 0; i < k; i++)
	{
		cin >> l[i];

		if (max < l[i])
			max = l[i];
	}

	if (n == 1)
	{
		cout << max;
		return 0;
	}

	long long length;
	
	while (true)
	{
		length = (min + max) / 2;

		if (min + 1 >= max || length == max)
			break;

		int count = 0;
		for (int i = 0; i < k; i++)
		{
			count += l[i] / length;
		}

		if (count < n)
		{
			max = length - 1;
		}
		else
		{
			min = length + 1;
		}
	}

	cout << length;

	delete[] l;
}