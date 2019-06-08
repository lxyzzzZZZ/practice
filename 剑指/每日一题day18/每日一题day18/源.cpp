#include <iostream>
#include <string>
#include <vector>

using namespace std;
//class A
//{
//public:
//	void print()
//	{
//		cout << "A" << endl;
//	}
//};
//class B : private A
//{
//public:
//	void print()
//	{
//		cout << "B" << endl;
//	}
//};
//class C : public B
//{
//public:
//	void print()
//	{
//		A::print();
//	}
//};
//int f(int n)
//{
//	static int i = 1;
//	if (n >= 5)
//		return n;
//	n += i;
//	i++;
//	return f(n);
//}
//int main()
//{
//	cout << f(1) << endl;
//	//double b = 1.215525412;
//
//	//printf("%-30.4e", b);
//	//int a[] = {1,2,3};
//	//int n = 3;
//	//while (n)
//	//{
//	//	cout << *a << endl;
//	//	a++, n--;
//	//}
//	system("pause");
//	return 0;
//}
bool Mate(const char* A, const char* B)
{
	if (*A == '\0' && *B == '\0')
		return true;
	if (*A == '\0' || *B == '\0')
		return false;

	if (*A == '?')
		return Mate(A + 1, B + 1);
	else if (*A == '*')
		return Mate(A + 1, B) || Mate(A + 1, B + 1) || Mate(A + 1, B + 1);
	else if (*A == *B)
		return Mate(A + 1, B + 1);

	return false;
}

int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		if (Mate(str1.c_str(), str2.c_str()))
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
	return 0;
}
//
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int month;
//	while (cin >> month)
//	{
//		int sum = 1;
//		int front = 1;
//		int back = 1;
//		while (month > 2)
//		{
//			sum = front + back;
//			front = back;
//			back = sum;
//			month--;
//		}
//		cout << sum << endl;
//	}
//	return 0;
//}