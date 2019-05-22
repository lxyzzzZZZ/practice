#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main()
{
	vector<int> arr;
	int num;
	while (cin >> num)
	{
		//if (cin.get() == '\n')
			//break;
		arr.push_back(num);
	}
	int morehalf = arr[0];
	int count = 1;
	for (int i = 1; i < arr.size(); i++)
	{
		if (arr[i] != morehalf)
			count--;
		else
			count++;

		if (count <= 0)
		{
			morehalf = arr[i];
			count = 1;
		}
	}
	cout << morehalf << endl;
	system("pause");
	return 0;
}
//
//int main()
//{
//	string str;
//	getline(cin, str);
//	string ret;
//	string maxstr;
//	for (int i = 0; i < str.size(); i++)
//	{
//		if (str[i] >= '0' && str[i] <= '9')
//		{
//			if (str[i - 1] < '0' || str[i - 1] > '9')
//			{
//				ret.push_back(str[i]);
//				continue;
//			}
//
//			else if (str[i + 1] < '0' || str[i + 1] > '9')
//			{
//				ret.push_back(str[i]);
//				if (ret.size() > maxstr.size())
//				{
//					maxstr.erase(0);
//					maxstr.append(ret.c_str());
//				}
//				ret.erase(0);
//			}
//			else
//			{
//				ret.push_back(str[i]);
//			}
//		}
//	}
//	cout << maxstr.c_str() << endl;
//	system("pause");
//	return 0;
//}
//int main()
//{
//	string str("123");
//	cout << str.c_str() << endl;
//	str.erase(0);
//	cout << str.c_str() << " " << str.size()<< endl;
//	system("pause");
//	return 0;
//}