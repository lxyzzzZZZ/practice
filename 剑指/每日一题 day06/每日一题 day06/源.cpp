#include <iostream>
#include <string>
using namespace std;


class solution
{
public:
	int strToint(string str)
	{
		if (str.size() <= 0)
			return 0;
		int num = 0;
		int flag = 0;
		for (int i = 0; i < str.size(); i++)
		{
			if (i == 0)
			{
				if (str[i] == '-')
				{
					flag = 1;
					continue;
				}
				if (str[i] == '+')
					continue;
			}
			if (str[i] < '0' || str[i] > '9')
				return 0;
			else
			{
				num *= 10;
				num = num + (str[i] - '0');
			}
		}
		if (flag == 1)
			return -num;
		return num;

	}
};

//if (W % 2 == 0)
//{
//	if ((W / 2) % 2 == 1)
//	{
//		if (W >= 4)
//			Wcount = (W / 4 + 1) * 2;
//		else
//		{
//			Wcount = 2;
//		}
//	}
//	else
//	{
//		if (W == 2)
//			Wcount = 2;
//		else
//			Wcount = W / 2;
//	}
//}
//else
//{
//	if ((W / 2) % 2 == 0)
//	{
//		if (W == 1)
//			Wcount = 1;
//		else
//			Wcount = W / 2 + 1;
//	}
//	else
//	{
//		if (W < 4)
//			Wcount = 2;
//		else
//			Wcount = ((W - 1) / 2 - 1) * 2;
//	}
//}
//
//if (H % 2 == 0)
//{
//	if ((H / 2) % 2 == 1)
//	{
//		if (H >= 4)
//			Hcount = (H / 4 + 1) * 2;
//		else
//		{
//			Hcount = 2;
//		}
//	}
//	else
//	{
//		if (H == 2)
//			Hcount = 2;
//		else
//			Hcount = H / 2;
//	}
//}
//else
//{
//	if ((H / 2) % 2 == 0)
//	{
//		if (H == 1)
//			Hcount = 1;
//		else
//			Hcount = H / 2 + 1;
//	}
//	else
//	{
//		if (H < 4)
//			Wcount = 2;
//		else
//			Hcount = ((H - 1) / 2 - 1) * 2;
//	}
//}
//
//char fun(char a, char b)
//{
//	if (a < b)
//		return a;
//	return b;
//}
//
//int main()
//{
//	char a = '1';
//	char b = '1';
//	char c = '2';
//	cout << fun(fun(a, b), fun(b, c)) << endl;
//	system("pause");
//	return 0;
//}