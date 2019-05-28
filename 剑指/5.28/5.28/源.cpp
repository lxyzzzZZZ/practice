#include <iostream>
#include <string>
#include <vector>

using namespace std;

using namespace std;
//int main()
//{
//	int A, B;
//	cin >> A >> B;
//	int count = 1;
//	while (count <= B)
//	{
//		if ((A*count) % B == 0)
//		{
//			cout << A * count << endl;
//			return 0;
//		}
//		count++;
//	}
//}
int main()
{
	string N;
	getline(cin, N);
	int n = atoi(N.c_str());
	string str[100];
	for (int i = 0; i < n; i++)
		getline(cin, str[i]);
	int Lflag = 1;
	int Rflag = 1;
	for (int i = 0; i < n-1; i++)
	{
		if (str[i].size() <= str[i + 1].size())
		{
			Lflag = 0;
			break;
		}
	}

	for (int i = 0; i < n - 1; i++)
	{
		if (str[i] > str[i + 1])
		{
			Rflag = 0;
			break;
		}
	}

	if (Lflag == 0 && Rflag == 1)
		cout << "lexicographically" << endl;
	else if (Lflag == 1 && Rflag == 0)
		cout << "lengths" << endl;
	else if (Lflag == 1 && Rflag == 1)
		cout << "both" << endl;
	else
		cout << "none" << endl;
	system("pause");
	return 0;
}
//#include <iostream>
//
//using namespace std;
//
////class cal
////{
////	static int n;
////public:
////	cal() { n++; }
////	~cal() { n--; }
////	static int getn()
////	{
////		return n;
////	}
////
////};
////int cal::n = 0;
//
//class A
//{
//public:
//	A()
//		:_m(0)
//	{
//		test();
//	}
//	virtual void func()
//	{
//		cout << _m << " ";
//	}
//	void test()
//	{
//		func();
//	}
//public:
//	int _m;
//};
//class B :public A
//{
//public:
//	B() { test(); }
//	virtual void func()
//	{
//		++_m;
//		cout << _m << " ";
//	}
//};
//int main()
//{
//	A* p = new B;
//	p->test();
//	/*cal *p = new cal;
//	delete p;
//	cout << cal::getn() << endl;*/
//	//int a[] = { 1,2,3,4 };
//	//int* ptr = (int*)(&a + 1);
//	//cout << *(ptr - 1) << endl;
//	//int i = 10;
//	//int const *p2 = &i;
//
//	system("pause");
//	return 0;
//}