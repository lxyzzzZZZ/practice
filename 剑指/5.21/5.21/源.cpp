#include <string>
#include <iostream>
#include <vector>

using namespace std;

#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int> v;
	v.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	int ret = 1;
	for (int i = 1; i < n - 1; i++)
	{
		//找出波峰波谷
		if ((v[i - 1] < v[i] && v[i] > v[i + 1])
			|| (v[i - 1] > v[i] && v[i] < v[i + 1]))
		{
			ret++;
			// 这里对应处理的就是上面情况二描述的问题
			if (i != n - 3)
				i++;
		}
	}
	cout << ret << endl;
	system("pause");
	return 0;
}
//int main()
//{
//	int n = 0;
//	cin >> n;
//	vector<int> arr;
//	arr.resize(n);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> arr[i];
//	}
//
//	int count = 1;
//
//	for (int i = 1; i < n - 1; i++)
//	{
//		if ((arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
//			|| (arr[i] < arr[i - 1] && arr[i] < arr[i + 1]))
//		{
//			count++;
//			
//			if (i != n - 3)
//			{
//				i++;
//			}
//		}
//	}
//	cout << count << endl;
//	system("pause");
//	return 0;
//
//}
//
//int main()
//{
//	string str;
//	getline(cin, str);
//	int len = str.size();
//	string ret;
//	string Newstr;
//	char* s = (char*)" ";
//	string::iterator it = str.begin();
//	while (it != str.end())
//	{
//
//		if (*it != *s)
//		{
//			ret.push_back(*it);
//		}
//		if ((it+1) == str.end())
//		{
//			Newstr.insert(0, ret);
//			ret.erase(0);
//		}
//		else if (*it == *s)
//		{
//			Newstr.insert(0, ret);
//			Newstr.insert(0, " ");
//			ret.erase(0);
//		}
//		it++;
//	}
//	if (Newstr.front() == *s)
//	{
//		Newstr.erase(0, 1);
//	}
//	cout << Newstr.c_str() << endl;
//	system("pause");
//	return 0;
//}