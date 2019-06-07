#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main()
{
	string str1, str2;

	getline(cin, str1);
	getline(cin, str2);

	string sum;
	int flag = 0;
	while (!str1.empty() || !str2.empty())
	{
		int a = 0;
		int b = 0;
		if (str1.size() > 0)
			a = str1.back() - '0';
		if (str2.size() > 0)
			b = str2.back() - '0';
		char c = ((a + b + flag) % 10 + '0');
		sum.insert(sum.begin(), c);
		flag = (a + b + flag) / 10;
		if (str1.size() > 0)
			str1.pop_back();
		if (str2.size() > 0)
			str2.pop_back();
	}
	cout << sum.c_str() << endl;
	reverse(sum.begin(), sum.end());
	system("pause");
	return 0;
}





//#include <stdio.h>
//
//using namespace std;
////template <class T>
////struct A
////{
////public:
////	static void foo(T a, T b)
////	{
////		cout << a << b;
////	}
////};
////A<int>::foo(1,3);
//
//class A
//{
//public:
//	A() { p(); }
//	virtual void p()
//	{
//		cout << "A";
//	}
//	virtual ~A() { p(); }
//};
//class B : public A
//{
//public:
//	B() { p(); }
//	void p()
//	{
//		cout << "B";
//	}
//	~B() { p(); }
//};
//int main()
//{
//	//long long a = 1, b = 2, c = 3;
//	//printf("%d %d %d", a, b, c);
//	//int a[] = { 1,2,3,4,5 };
//	//int* p[] = { a,a + 1,a + 2,a + 3,a + 4 };
//	//int **q = p;
//	//cout << *(p[0] + 1) + **(q + 2);
//	A* a = new B();
//	delete a;
//	system("pause");
//	return 0;
//}

int yanghui()
{
	int n;
	while (cin >> n)
	{
		vector <vector<int>> arr(n);
		for (int i = 0; i < n; i++)
		{
			arr[i].resize(2 * n + 2);
			arr[i][1] = 1;
			arr[i][2 * i + 1] = 1;
		}

		for (int i = 1; i < n; i++)
		{
			for (int j = 2; j < 2 * n + 2; j++)
			{
				arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1] + arr[i - 1][j - 2];
			}
		}
		for (int i = 1; i < n; i++)
		{
			if (arr[n - 1][i] % 2 == 0)
			{
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}