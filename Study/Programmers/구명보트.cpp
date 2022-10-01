#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit)
{
	int necessaryLifeBoatCount = 0;
	int count[241] = { };
	// Record Every Weight

	int first = 240;
	int end = 40;
	// First Will Be The Lightest Weight
	// End Will Be the Heaviest Weight

	for (int i = 0; i < people.size(); i++)
	{
		// If The Weight Equals To The Limit, Don't Record The Weight, But Add The Num Of Boats.
		// This Is Because People With That Weight, Can Only Ride A Boat By Themselves.
		if (people[i] == limit)
		{
			necessaryLifeBoatCount++;
			continue;
		}
		
		if (first > people[i])
			first = people[i];

		if (end < people[i])
			end = people[i];

		count[people[i]]++;
	}

	while (true)
	{
		if (first == end)
		{
			break;
		}

		if (count[first] == 0)
		{
			first++;
			continue;
		}

		if (count[end] == 0)
		{
			end--;
			continue;
		}

		// If The Sum Of Lightest Weight And Heaviest Weight Is Smaller Or Equals To The Limit
		// Ride Them A Boat
		if (first + end <= limit)
		{
			count[first]--;
			count[end]--;
			necessaryLifeBoatCount++;
		}
		// If Not, The Heaviest People Can Only Ride A Boat By Themselves,
		// So Each Person Picks Up One Boat
		else
		{
			necessaryLifeBoatCount += count[end];
			count[end] = 0;
		}
	}

	if (count[first] > 0)
	{
		if ((count[first] > 1) && (first + first <= limit))
		{
			necessaryLifeBoatCount += count[first] / 2;
			necessaryLifeBoatCount += count[first] % 2;
		}
		else
		{
			necessaryLifeBoatCount += count[first];
		}
	}

	return necessaryLifeBoatCount;
}

int main()
{
	cout << solution(vector<int>{ 70, 50, 80, 50 }, 100 );
}

// int solution(vector<int> people, int limit)
// {
//     int answer = 0;

//     sort(people.begin(), people.end());

//     int resizeSize = 0;
//     for (int i = people.size() - 1; i >= 0; i--)
//     {
//         if ((people[i] < limit) && (people[i] < 200))
//         {
//             resizeSize = i + 1;
//             break;
//         }
//     }

//     if (resizeSize != people.size())
//     {
//         answer += people.size() - resizeSize;
//         people.resize(resizeSize);
//     }

//     cout << resizeSize << '_' << people.size();

//     while (people.size() > 0)
//     {
//         int i = people.size() - 1;
//         if ((i != 0) && (people[0] + people[i] <= limit))
//         {
//             answer++;

//             people.erase(people.begin() + i);
//             if (people.size() >= 1)
//                 people.erase(people.begin());
//         }
//         else
//         {
//             answer++;
//             people.erase(people.begin() + i);
//         }
//     }

//     return answer;
// }