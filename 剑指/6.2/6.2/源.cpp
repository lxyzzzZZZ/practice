//#include <iostream>
//
//using namespace std;
//
//class A
//{
//public:
//	virtual void fun()
//	{
//		cout << "A" << endl;
//	}
//	int foo(char n)
//	{
//		return (int)n;
//	}
//	virtual int foo(int n)
//	{
//		return 2 * n;
//	}
//};
//class B : public A
//{
//public:
//	void fun()
//	{
//		cout << "B" << endl;
//	}
//	int foo(char n)
//	{
//		return (int)(-n);
//	}
//	int foo(int n)
//	{
//		return n / 2;
//	}
//};
////class A::~A()
////{
////	delete this;
////	this = NULL;
////}
////3+3*2+2/3+3*2+2
//void test1()
//{
//	int n[][3] = { 1,2,3,4,5,6 };
//	int(*p)[3];
//	p = n;
//	cout << p[0][0] << *(p[0] + 1) << (*p)[2] << endl;
//}
//
//int main()
//{
//	//test1();
//	//B b;
//	//b.fun();
//	B b;
//	A* a = &b;
//	cout << a->foo((char)(100)) << endl;
//	cout << a->foo(100) << endl;
//	system("pause");
//	return 0;
//}

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool isPrime(int n)
{
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

int main()
{
	int Num = 0;
	while (cin >> Num)
	{
		vector<int> arr;
		for (int i = 1; i <= Num / 2; i++)
		{
			if (isPrime(i) && isPrime(Num - i))
			{
				arr.push_back(i);
				arr.push_back(Num - i);
			}
		}
		cout << arr[arr.size() - 2] << endl;
		cout << arr[arr.size() - 1] << endl;
	}
	return 0;
}