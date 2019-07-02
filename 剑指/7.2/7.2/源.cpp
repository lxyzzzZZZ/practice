#include <iostream>
#include <string>
using namespace std;
//
//int main()
//{
//	string L, R;
//	while (cin >> L >> R)
//	{
//		string r1, r2, r3;
//		int flag = 0;
//		for (int i = 0; i < R.size(); i++)
//		{
//			int ret = R[i] - '0';
//			r1[i] = (ret * 8) % 10 + flag + '0';
//			flag = (ret * 8) / 10;
//		}
//		if (flag > 0)
//		{
//			char c = flag + '0';
//			r1.insert(r1.begin(), c);
//		}
//		flag = 0;
//		for (int i = 0; i < R.size(); i++)
//		{
//			int ret = R[i] - '0';
//			r2[i] = (ret * 2) % 10 + flag + '0';
//			flag = (ret * 2) / 10;
//		}
//		if (flag > 0)
//		{
//			char c = flag + '0';
//			r2.insert(r2.begin(), c);
//		}
//		r2.push_back('0');
//		flag = 0;
//		for (int i = 0; i < R.size(); i++)
//		{
//			int ret = R[i] - '0';
//			r3[i] = (ret * 6) % 10 + flag + '0';
//			flag = (ret * 6) / 10;
//		}
//		if (flag > 0)
//		{
//			char c = flag + '0';
//			r3.insert(r3.begin(), c);
//		}
//		r3.push_back('0');
//		r3.push_back('0');
//		string r;
//		flag = 0;
//		while (r1.size() || r2.size())
//		{
//			int ret;
//			if (r1.size() == 0)
//				ret = r2.back() - '0' + flag;
//			else if (r2.size() == 0)
//				ret = r1.back() - '0' + flag;
//			else
//				ret = r1.back() + r2.back() - '0'+ flag;
//			char c = ret % 10 + '0';
//			flag = ret / 10;
//			r.push_back(c);
//			if (r1.size() != 0)
//				r1.pop_back();
//			if (r2.size() != 0)
//				r2.pop_back();
//		}
//		if (flag > 0)
//		{
//			char c = flag + '0';
//			r.insert(r.begin(), c);
//		}
//		r = r1;
//		r1 = r3;
//		r2 = r;
//		flag = 0;
//		while (r1.size() || r2.size())
//		{
//			int ret;
//			if (r1.size() == 0)
//				ret = r2.back() - '0' + flag;
//			else if (r2.size() == 0)
//				ret = r1.back() - '0' + flag;
//			else
//				ret = r1.back() + r2.back() - '0' + flag;
//			char c = ret % 10 + '0';
//			flag = ret / 10;
//			r.push_back(c);
//			if (r1.size() != 0)
//				r1.pop_back();
//			if (r2.size() != 0)
//				r2.pop_back();
//		}
//		if (flag > 0)
//		{
//			char c = flag + '0';
//			r.insert(r.begin(), c);
//		}
//		L.push_back('0');
//		L.push_back('0');
//		cout << "L" << L.c_str() << endl;
//		cout << "R" << R.c_str() << endl;
//		if (L <= r)
//			cout << "Yes" << endl;
//		else
//			cout << "No" << endl;
//	}
//	system("pause");
//	return 0;
//}