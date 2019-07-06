// write your code here cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	string str;
	string ret("VWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ");
	while (getline(cin, str))
	{
		string str2;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == ' ')
			{
				str2.push_back(' ');
				continue;
			}
			int j = str[i] - 'A';
			str2.push_back(ret[j]);

		}
		cout << str2.c_str() << endl;
	}
}
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		int count = 2;
//		vector<int> ret;
//		int sum = 0;
//		while (n > 1 && count <= n)
//		{
//			if (n % count == 0)
//			{
//				n /= count;
//				ret.push_back(count);
//				count = 2;
//			}
//			else
//			{
//				count++;
//			}
//		}
//		int flag = -1;
//		for (int i = 0; i < ret.size(); i++)
//		{
//			if (ret[i] != flag)
//			{
//				sum++;
//				flag = ret[i];
//			}
//		}
//		cout << sum << endl;
//	}
//	system("pause");
//	return 0;
//}

//
//#include <iostream>
//#include <vector>
//#include <cmath>
//using namespace std;
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		int count = 0;
//		for (int i = 2; i <= sqrt(n); i++)
//		{
//			if (n % i == 0)
//			{
//				count++;
//				while (n % i == 0)
//					n /= i;
//			}
//		}
//		if (n > 1)
//			count++;
//		cout << count << endl;
//	}
//	return 0;
//}
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		int count = 2;
//		vector<int> ret;
//		while (n > 1 && count <= n)
//		{
//			if (n % count == 0)
//			{
//				n /= count;
//				ret.push_back(count);
//				count = 2;
//			}
//			else
//			{
//				count++;
//			}
//		}
//		cout << count << endl;
//	}
//	system("pause");
//	return 0;
//}


//class Solution {
//public:
//	/**
//	 *	正数数组中的最小不可组成和
//	 *	输入：正数数组arr
//	 *	返回：正数数组中的最小不可组成和
//	 */
//	int getFirstUnFormedNum(vector<int> arr, int len) {
//		int min = arr[0];
//		int max = arr[0];
//		for (int i = 1; i < len; i++)
//		{
//			max += arr[i];
//			if (min > arr[i])
//				min = arr[i];
//		}
//
//		vector<int> ret(max + 1, 0);
//		for (int i = 0; i < len; i++)
//		{
//			for (int j = max; j >= arr[i]; j--)
//			{
//				if (ret[j - arr[i]] + arr[i] > ret[j])
//					ret[j] = ret[j - arr[i]] + arr[i];
//				else
//					ret[j] = ret[j];
//			}
//		}
//		for (int i = min; i <= max; i++)
//		{
//			if (ret[i] != i)
//				return i;
//		}
//		return max + 1;
//	}
//};
//
//
//// write your code here cpp
//
//#include <iostream>
//using namespace std;
//int main()
//{
//	int num;
//	while (cin >> num)
//	{
//		if (num == 0)
//			break;
//		int count = 0;
//		while (num > 1)
//		{
//			if (num % 3 == 0)
//				num = num / 3;
//			else
//				num = num / 3 + 1;
//			count++;
//		}
//		cout << count << endl;
//	}
//	return 0;
//}