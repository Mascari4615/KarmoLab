// 첫 풀이
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <limits.h>
//
//using namespace std;
//
//vector<int> solution(vector<string> gems)
//{
//    vector<int> answer;
//
//    vector<string> gemsCopy(gems);
//    sort(gemsCopy.begin(), gemsCopy.end());
//    gemsCopy.erase(unique(gemsCopy.begin(), gemsCopy.end()), gemsCopy.end());
//    int gemsCount = gemsCopy.size();
//
//    if (gemsCount == gems.size())
//    {
//        answer.push_back(1);
//        answer.push_back(gemsCount);
//        return answer;
//    }
//
//    int efficientStartIndex = 0;
//    int minLen = gems.size();
//    for (int startIndex = 0; startIndex < gems.size(); startIndex++)
//    {
//        if ((efficientStartIndex != 0) && (startIndex >= gems.size() - gemsCount))
//        {
//            break;
//        }
//
//        vector<string> foundedGems;
//        for (int j = startIndex; j < gems.size(); j++)
//        {
//            if (find(foundedGems.begin(), foundedGems.end(), gems[j]) != foundedGems.end())
//            {
//                continue;
//            }
//            else
//            {
//                foundedGems.push_back(gems[j]);
//
//                if (foundedGems.size() == gemsCount)
//                {
//                    if (j - startIndex + 1 < minLen)
//                    {
//                        efficientStartIndex = startIndex;
//                        minLen = j - startIndex + 1;
//                    }
//                    break;
//                }
//            }
//        }
//    }
//
//    answer.push_back(efficientStartIndex + 1);
//    answer.push_back(efficientStartIndex + minLen);
//    return answer;
//}

// 두 번째 풀이
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <limits.h>
//
//using namespace std;
//
//vector<int> solution(vector<string> gems)
//{
//    vector<int> answer;
//
//    vector<string> gemsCopy(gems);
//    sort(gemsCopy.begin(), gemsCopy.end());
//    gemsCopy.erase(unique(gemsCopy.begin(), gemsCopy.end()), gemsCopy.end());
//    int gemsCount = gemsCopy.size();
//
//    if (gemsCount == gems.size())
//    {
//        answer.push_back(1);
//        answer.push_back(gemsCount);
//        return answer;
//    }
//
//    int minLen = gemsCount;
//
//    while (true)
//    {
//        for (int startIndex = 0; startIndex < gems.size(); startIndex++)
//        {
//            if ((startIndex != 0) && (startIndex > gems.size() - minLen))
//            {
//                break;
//            }
//
//            vector<string> foundedGems;
//            for (int i = startIndex; i < startIndex + minLen; i++)
//            {
//                if (find(foundedGems.begin(), foundedGems.end(), gems[i]) == foundedGems.end())
//                    foundedGems.push_back(gems[i]);
//            }
//
//            if (foundedGems.size() == gemsCount)
//            {
//                answer.push_back(startIndex + 1);
//                answer.push_back(startIndex + minLen);
//                return answer;
//            }
//        }
//        minLen++;
//    }
//}

//#include <string>
//#include <vector>
//#include <algorithm>
//#include <limits.h>
//#include <unordered_map>
//
//using namespace std;
//
//vector<int> solution(vector<string> gems)
//{
//    vector<int> answer;
//    unordered_map<string, int> hashMap;
//
//    for (int i = 0; i < gems.size(); i++)
//    {
//        if (hashMap.find(gems[i]) == hashMap.end())
//            hashMap.insert(unordered_map<string, int>::value_type(gems[i], -1));
//    }
//    int gemsCount = hashMap.size();
//
//    if (gemsCount == gems.size())
//    {
//        answer.push_back(1);
//        answer.push_back(gemsCount);
//        return answer;
//    }
//
//    int efficientStartIndex = 0;
//    int minLen = gems.size();
//    for (int startIndex = 0; startIndex < gems.size(); startIndex++)
//    {
//        if ((efficientStartIndex != 0) && (startIndex >= gems.size() - gemsCount))
//        {
//            break;
//        }
//
//        int foundedGemCount = 0;
//        for (int j = startIndex; j < gems.size(); j++)
//        {
//            if (j - startIndex + 1 >= minLen)
//                break;
//
//            if (hashMap[gems[j]] != startIndex)
//            {
//                hashMap[gems[j]] = startIndex;
//                foundedGemCount++;
//
//                if (foundedGemCount == gemsCount)
//                {
//                    if (j - startIndex + 1 < minLen)
//                    {
//                        efficientStartIndex = startIndex;
//                        minLen = j - startIndex + 1;
//                    }
//                    break;
//                }
//            }
//        }
//    }
//
//    answer.push_back(efficientStartIndex + 1);
//    answer.push_back(efficientStartIndex + minLen);
//    return answer;
//}