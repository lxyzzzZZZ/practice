#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void is_divisor(int N, vector<int>& arr)
{
	for (int i = 2; i <= sqrt(N); i++)
	{
		if (N % i == 0)
		{
			arr.push_back(i);
			if (N / i != i)
			{
				arr.push_back(N / i);
			}
		}
	}
}

int main()
{
	int N, M;
	cin >> N >> M;
	vector<int> steps(M + 1, 0);
	steps[N] = 1;
	for (int i = N; i <= M; ++i) {
		if (steps[i] == 0)
			continue;
		vector<int> arr;
		is_divisor(i, arr);
		for (int j = 0; j < arr.size(); ++j)
		{
			if (arr[j] + i <= M)
			{
				if (steps[arr[j] + i] == 0)
					steps[arr[j] + i] = steps[i] + 1;
				else
					steps[arr[j] + i] = (steps[i] + 1) < steps[arr[j] + i] ? (steps[i] + 1) : steps[arr[j] + i];
			}
		}
	}

	if (steps[M] == 0)
		cout << -1 << endl;
	else
		cout << steps[M] - 1 << endl;
	return 0;
}
//int main()
//{
//	string str;
//	getline(cin, str);
//
//	string::iterator it = str.begin();
//	while (it != str.end())
//	{
//		cout << (int)(*it) << endl;
//		it++;
//	}
//	cout << (char)(80) << endl;
//	system("pause");
//	return 0;
//}
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//	string str;
//	getline(cin, str);
//	int count = 1;
//	vector<string> arr;
//	int flag = 0;
//	string ret;
//	for (size_t i = 0; i < str.size(); i++)
//	{
//		if (str[i] == 34)
//		{
//			flag = 1;
//			continue;
//		}
//		else if (str[i] == 34)
//		{
//			flag = 0;
//			continue;
//		}
//
//		if (flag == 0)
//		{
//			if (str[i] == 32)
//			{
//				count++;
//				arr.push_back(ret);
//				ret.clear();
//			}
//			else
//			{
//				ret.push_back(str[i]);
//			}
//		}
//		else
//		{
//			ret.push_back(str[i]);
//		}
//	}
//	if (ret.size() > 0)
//	{
//		arr.push_back(ret);
//	}
//	cout << count << endl;
//	vector<string> ::iterator it = arr.begin();
//	while (it != arr.end())
//	{
//		cout << *it << endl;
//		it++;
//	}
//	return 0;
//}