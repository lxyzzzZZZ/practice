#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		if (numbers.size() < 1)
			return 0;
		//sort(numbers.begin(), numbers.end());
		int num = numbers[numbers.size() / 2];
		int count = 0;
		for (int i = 0; i < numbers.size(); i++)
		{
			if (num == numbers[i])
				count++;
		}
		if (count > numbers.size() / 2)
			return num;
		else
			return 0;
	}
	int MoreThanHalfNum_Solution2(vector<int> numbers) {
		int flag = 1;
		int num = numbers[0];
		for (int i = 1; i < numbers.size(); i++)
		{
			if (numbers[i] != num)
				flag--;
			if (flag < 1)
			{
				flag = 1;
				num = numbers[i];
			}
			else
			{
				flag++;
			}
		}
		return num;
	}
};

//
//
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
//class Solution {
//public:
//	int MoreThanHalfNum_Solution(vector<int> numbers) {
//		if (numbers.size() < 1)
//			return 0;
//		//sort(numbers.begin(), numbers.end());
//		int num = numbers[numbers.size() / 2];
//		int count = 0;
//		for (int i = 0; i < numbers.size(); i++)
//		{
//			if (num == numbers[i])
//				count++;
//		}
//		if (count > numbers.size() / 2)
//			return num;
//		else
//			return 0;
//	}
//	int MoreThanHalfNum_Solution2(vector<int> numbers) {
//		int flag = 1;
//		int num = numbers[0];
//		for (int i = 1; i < numbers.size(); i++)
//		{
//			if (numbers[i] != num)
//				flag--;
//			if (flag < 1)
//			{
//				flag = 1;
//				num = numbers[i];
//			}
//			else
//			{
//				flag++;
//			}
//		}
//		return num;
//	}
//};



