// write your code here cpp
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s, t;
	while (cin >> s >> t)
	{
		if (t.size() > s.size())
		{
			cout << 0 << endl;
			break;
		}
		int sz = t.size();
		int i = 0;
		int count = 0;
		while ((i + sz - 1) < s.size())
		{
			string ret;
			for (int j = i; j < sz + i; j++)
			{
				ret.push_back(s[j]);
			}
			cout << ret.c_str() << endl;
			if (strcmp(ret.c_str(),t.c_str()) == 0)
			{
				i = i + sz;
				count++;
			}
			else
			{
				i++;
			}
		}
		cout << count << endl;
	}
	system("pause");
	return 0;
}


//// write your code here cpp
//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main()
//{
//	int a, b;
//	while (cin >> a >> b)
//	{
//		vector<long> arr;
//		arr.resize(b + 1);
//		arr[0] = 0;
//		arr[1] = 1;
//		arr[2] = 1;
//		long count = 0;
//		for (int i = 2; i <= b; i++)
//			arr[i] = arr[i - 1] + arr[i - 2];
//		for (int i = a; i <= b; i++)
//		{
//			count += arr[i];
//		}
//		cout << count << endl;
//	}
//	return 0;
//}

//// write your code here cpp
//#include <iostream>
//#include <string>
//#include <string.h>
//using namespace std;
//int main()
//{
//	string s, t;
//	while (cin >> s >> t)
//	{
//		if (t.size() > s.size())
//		{
//			cout << 0 << endl;
//			break;
//		}
//		int sz = t.size();
//		int i = 0;
//		int count = 0;
//		while ((i + sz - 1) < s.size())
//		{
//			string ret;
//			for (int j = i; j < sz + i; j++)
//			{
//				ret.push_back(s[j]);
//			}
//			if (strcmp(ret.c_str(), t.c_str()) == 0)
//			{
//				i = i + sz;
//				count++;
//			}
//			else
//			{
//				i++;
//			}
//		}
//		cout << count << endl;
//	}
//	return 0;
//}