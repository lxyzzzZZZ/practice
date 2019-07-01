#include <iostream>
#include <string>
using namespace std;

int main()
{
	string L, R;
	while (cin >> L >> R)
	{
		R.push_back('0');
		R.push_back('0');
		int flag = 0;
		for (int i = 0; i < R.size(); i++)
		{
			int ret = R[i] - '0';
			R[i] = (ret * 8) % 10 + flag + '0';
			flag = (ret * 8) / 10;
		}
		if (flag > 0)
		{
			char c = flag + '0';
			R.insert(R.begin(), c);
		}
		flag = 0;
		for (int i = 0; i < R.size(); i++)
		{
			int ret = R[i] - '0';
			R[i] = (ret * 2) % 10 + flag + '0';
			flag = (ret * 2) / 10;
		}
		if (flag > 0)
		{
			char c = flag + '0';
			R.insert(R.begin(), c);
		}
		flag = 0;
		for (int i = 0; i < R.size(); i++)
		{
			int ret = R[i] - '0';
			R[i] = (ret * 6) % 10 + flag + '0';
			flag = (ret * 6) / 10;
		}
		if (flag > 0)
		{
			char c = flag + '0';
			R.insert(R.begin(), c);
		}
		L.push_back('0');
		L.push_back('0');
		if (L < R)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}
//class Solution {
//public:
//	int jumpNum(int num)
//	{
//
//		if (num == 1 || num == 0)
//		{
//			return 1;
//		}
//		return 2 * jumpNum(num - 1);
//	}
//	int jumpFloorII(int number) {
//		return jumpNum(number);
//	}
//};