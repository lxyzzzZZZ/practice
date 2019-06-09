//#include <iostream>
//
//using namespace std;
//
//int fun(int count)
//{
//	if (count < 2)
//		return 0;
//	else if (count == 2)
//		return 1;
//	if (count % 3 == 2)
//		return count/3 + fun(count / 3 + count % 3) + 1;
//	else
//		return count/3 + fun(count / 3 + count % 3);
//}
//
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//
//		cout << n << endl;
//	}
//	cout << fun(81) << endl;
//	system("pause");
//	return 0;
//}
//
//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		if (n == 0)
//			return 0;
//		int sum = 0;
//		while (n > 2)
//		{
//			sum += n / 3;
//			n = n / 3 + n % 3;
//		}
//		if (n == 2)
//			sum += 1;
//		cout << sum << endl;
//	}
//	return 0;
//}
//
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//string fun(string str1, string str2)
//{
//	/* 在这里实现功能，将结果填入输入数组中*/
//	int pos = 0, maxlen = 0;
//	string temp;
//	for (int i = 0; i < str2.size(); i++)
//	{
//		for (int j = str2.size() - i; j > 0; j--)
//		{
//			temp = str2.substr(i, j);
//			if ((str1.find(temp) != string::npos) && maxlen < temp.size())
//			{
//				maxlen = temp.size();
//				pos = i;
//			}
//		}
//	}
//	if (maxlen == 0)
//		return NULL;
//	else
//		return str2.substr(pos, maxlen);
//}
//
//int main()
//{
//	string  str1, str2;
//	while (cin >> str1 >> str2)
//	{
//		string ret;
//		if (str1.size() < str2.size())
//			ret = fun(str2, str1);
//		else
//			ret = fun(str1, str2);
//		cout << ret.c_str() << endl;
//	}
//	return 0;
//}