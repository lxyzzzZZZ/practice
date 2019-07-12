#include <iostream>
#include <string>
#include <vector>
using namespace std;

int FindGreatestSumOfSubArray(vector<int> array) {
	if (array.empty()) {
		return -1;
	}
	// F(i)初始化
	int sum = array[0];
	// maxsum初始化
	int maxsum = array[0];
	for (int i = 1; i < array.size(); i++) {
		// F(i) = max(F(i-1) + array[i]，array[i])
		sum = (sum > 0) ? sum + array[i] : array[i];
		// maxsum = max( maxsum，F(i))
		maxsum = (sum < maxsum) ? maxsum : sum;
	}
	return maxsum;
}

int main()
{
	vector<int> arr = { 6,-2,-3,8,-15,2,3 };
	cout << FindGreatestSumOfSubArray(arr) << endl;
	system("pause");
	return 0;
}

//int main()
//{
//	string ret, str;
//	getline(cin, ret);
//	vector<string> arr;
//	arr.resize(100);
//	int i = 0;
//	int j = 0;
//	int flag = 0;
//	while(i < ret.size())
//	{
//		if (ret[i] == '"')
//		{
//			i++;
//			while (ret[i] != '"')
//			{
//				arr[j].push_back(ret[i]);
//				i++;
//			}
//			i++;
//			j++;
//		}
//		else if (ret[i] == ',')
//		{
//			i++;
//		}
//	}
//	i = 0;
//	while (arr[i].size() != 0)
//	{
//		cout << arr[i++].c_str() << endl;
//	}
//	system("pause");
//	return 0;
//
//}
//
//// write your code here cpp
//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	string s, res;
//	while (getline(cin, s))
//	{
//		getline(cin, res);
//		bool sta = false;
//		for (int i = 0; i < s.length(); i++)
//		{
//			string t;
//			if (s[i] == '"')
//			{
//				i++;
//				while (i < s.length() && s[i] != '"')
//				{
//					t += s[i];
//					i++;
//				}
//				if (t == res)
//				{
//					sta = true;
//					break;
//				}
//			}
//			else if (s[i] != ',')
//			{
//				while (i < s.length() && s[i] != ',')
//				{
//					t += s[i];
//					i++;
//				}
//				if (t == res)
//				{
//					sta = true;
//					break;
//				}
//			}
//		}
//		if (sta == true)
//			cout << "Ignore" << endl;
//		else
//			cout << "Important!" << endl;
//	}
//	return 0;
//}
//
//
//// write your code here cpp
//
//#include <iostream>
//#include <iomanip>
//using namespace std;
//
//
//double fac(int x)
//{
//	register double i, f = 1;  //定义寄存器变量  
//	for (int i = 1; i <= x; i++)
//		f *= i;
//	return f;
//}
//
//
//int main()
//{
//	int n;
//	long long a[21] = { 0,0,1 };
//	for (int i = 3; i < 21; i++)
//	{
//		a[i] = (i - 1)*(a[i - 1] + a[i - 2]);
//	}
//	while (cin >> n)
//	{
//		double tempAll = fac(n);
//		cout << fixed << setprecision(2) << (double)a[n] / tempAll * 100 << "%" << endl;
//	}
//}