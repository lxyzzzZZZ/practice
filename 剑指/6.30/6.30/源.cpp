#include <iostream>
using namespace std;

//// write your code here cpp
//#include <iostream>
//#include <string>
//using namespace std;
//
//int main()
//{
//	string num;
//	while (cin >> num)
//	{
//		int sum = 0;
//		while (num.size())
//		{
//			sum += num.back() - '0';
//			num.pop_back();
//			if (num.size() == 0 && sum > 9)
//			{
//				num = to_string(sum);
//				sum = 0;
//			}
//		}
//		cout << sum << endl;
//	}
//	system("pause");
//	return 0;
//}
//
//// write your code here cpp#include<stdio.h>
//#include <iostream>
//using namespace std;
//int main()
//{
//	int n, i, j;
//	int a[10005];
//	a[1] = 1;
//	a[2] = 2;
//	for (i = 3; i <= 10000; i++)
//	{
//		a[i] = (a[i - 1] + a[i - 2]);
//		if (a[i] >= 10000)
//			a[i] = a[i] % 10000;
//	}
//	while (cin >> n)
//	{
//		for (i = 1; i <= n; i++)
//		{
//			cin >> j;
//			printf("%04d", a[j]);
//		}
//		cout << endl;;
//	}
//	return 0;
//}
//
//

int main()
{
	int a = 10;
	double b = 1.20;
	cout << sizeof(b) << sizeof(a) << sizeof(a+b) << endl;
	system("pause");
	return 0;
}
