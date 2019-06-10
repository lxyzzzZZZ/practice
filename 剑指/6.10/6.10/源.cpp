#include <iostream>
using namespace std;

//逆置字符串
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	while (cin >> str)
	{
		string ret;
		for (int i = 0; i < str.size(); i++)
		{
			ret.insert(ret.begin(), str[i]);
		}
		cout << ret.c_str() << endl;
	}
	return 0;
}
//最长公共字串长度

//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//int  fun(string A, string B)
//{
//	int pos = 0;
//	int maxlength = 0;
//	string ret;
//	for (size_t i = 0; i < B.size(); ++i)
//	{
//		for (size_t j = B.size() - i; j > 0; j--)
//		{
//			ret = B.substr(i, j);
//			if (A.find(ret) != string::npos && maxlength < ret.size())
//			{
//				maxlength = ret.size();
//			}
//		}
//	}
//	return maxlength;
//}
//int main()
//{
//	string str1, str2;
//	while (cin >> str1 >> str2)
//	{
//		int len;
//		if (str1.size() < str2.size())
//			len = fun(str2, str1);
//		else
//			len = fun(str1, str2);
//		cout << len << endl;
//	}
//	return 0;
//}



//int main()
//{
//	int c = 834827;
//	int *a = &c;
//	int b[] = {1,2,3,4,66,4,6 };
//	cout << b + 1 << " " << &b[1] << endl;
//	cout << sizeof(a) << endl;
//	cout << a + 1 << " " << &a[1] << endl;
//	cout << a[5] << endl;
//	long long Num;
//	while (cin >> Num)
//	{
//		int count = 0;
//		while (Num)
//		{
//			if (Num % 10 == 1)
//				count++;
//			Num /= 10;
//		}
//		cout << count << endl;
//	}
//	system("pause");
//	return 0;
//}