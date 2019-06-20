#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

class solution
{
public:
	vector<int> twoSum(vector<int> &num, int target)
	{
		unordered_map<int, int> mapping;
		vector<int> result;
		for (int i = 0; i < num.size(); i++)
		{
			mapping[num[i]] = i;
		}
		for (int i = 0; i < num.size(); i++)
		{
			const int gap = target - num[i];
			if (mapping.find(gap) != mapping.end() && mapping[gap] > i)
			{
				result.push_back(i + 1);
				result.push_back(mapping[gap] + 1);
				break;
			}
		}
		return result;
	}
};

int max(int A, int B)
{
	return A > B ? A : B;
}
class solution2
{
public:
	int longestConsecutive(const vector<int> &num)
	{
		unordered_map<int, bool> used;

		for (auto i : num)
			used[i] = false;

		int longest = 0;

		for (auto i : num)
		{
			if (used[i])
				continue;

			int length = true;

			for (int j = i + 1; used.find(j) != used.end(); ++j)
			{
				used[j] = true;
				++length;
			}

			for (int j = i - 1; used.find(j) != used.end(); --j)
			{
				used[j] = true;
				++length;
			}

			longest = max(longest, length);
		}
		return longest;
	}
};