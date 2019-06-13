#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//
//int getValue(vector<int> gifts, int n) {
//	// write code here
//	//sort(gifts.begin(), gifts.end());
//	//int ret = gifts[n / 2];
//	int count = 0;
//	int ret = gifts[0];
//	for (int i = 1; i < n; i++)
//	{
//		if (ret == gifts[i])
//			count++;
//		else
//			count--;
//		if (count < 0)
//		{
//			ret = gifts[i];
//			count = 0;
//		}
//	}
//	return ret;
//}
//
//class Gift {
//public:
//	int getValue(vector<int> gifts, int n) {
//		// write code here
//		int count = 1;
//		int ret = gifts[0];
//		for (int i = 1; i < n; i++)
//		{
//			if (ret == gifts[i])
//				count++;
//			else
//				count--;
//			if (count < 1)
//			{
//				ret = gifts[i];
//				count = 1;
//			}
//		}
//		if (count > 1)
//			return ret;
//		return 0;
//	}
//};
#include<iostream>
#include<string>

using namespace std;


int main()
{
	string A, B;
	while (cin >> A >> B)
	{
		int len_A = A.length();
		int len_B = B.length();
		int D[len_B + 1][len_A + 1];
		D[0][0] = 0;
		for (int i = 1; i <= len_A; i++)
		{
			D[0][i] = i;
		}
		for (int i = 1; i <= len_B; i++)
		{
			D[i][0] = i;
		}
		for (int i = 1; i <= len_B; i++)
		{
			for (int j = 1; j <= len_A; j++)
				D[i][j] = min(min(D[i - 1][j] + 1, D[i][j - 1] + 1), (A[j - 1] == B[i - 1] ? D[i - 1][j - 1] : D[i - 1][j - 1] + 1));
		}
		cout << D[len_B][len_A] << endl;

	}
	return 0;
}



int main()
{
	//vector<int> arr = {1,2,6,8,4,2,2,2,2};
	//cout << getValue(arr, arr.size()) << endl;
	const char* a = "fvndkl";
	cout << strlen(a) << endl;
	system("pause");
	return 0;
}