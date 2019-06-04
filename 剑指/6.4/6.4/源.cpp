//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//	char a[] = "wang\0wang";
//	cout << strlen(a) << sizeof(a) << endl;
//	system("pause");
//	return 0;
//}
//#include <iostream>
//#include <string>
//using namespace std;
//
//bool is_leapyear(int year)
//{
//	if ((year % 4 == 0 && year % 100 != 0) ||
//		year % 400 == 0)
//	{
//		return true;
//	}
//	return false;
//}
//int main()
//{
//	string year, month, day;
//	getline(cin, year);
//	getline(cin, month);
//	getline(cin, day);
//	int Y = atoi(year.c_str());
//	int M = atoi(month.c_str());
//	int D = atoi(day.c_str());
//	cout << Y << M << D << endl;
//	int arr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//	if (is_leapyear(Y) == true)
//	{
//		arr[2] = 29;
//	}
//	int days = 0;
//	for (int i = 1; i < M; i++)
//	{
//		days += arr[i];
//	}
//	cout << days + D << endl;
//	system("pause");
//	return 0;
//}
#include <iostream>
#include <string>
using namespace std;

bool is_leapyear(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) ||
		year % 400 == 0)
	{
		return true;
	}
	return false;
}
int main()
{
	int Y, M, D;
	while (cin >> Y >> M >> D)
	{
		int arr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		if (is_leapyear(Y) == true)
		{
			arr[2] = 29;
		}
		int days = 0;
		for (int i = 1; i < M; i++)
		{
			days += arr[i];
		}
		cout << days + D << endl;
	}
	return 0;
}

#include<iostream>
#include<algorithm>
using namespace std;

int n;
int *x = NULL;
int count(int pos, int add, long long  mul)
{
	int num = 0;
	for (int i = pos; i < n; ++i)
	{
		add += x[i];
		mul *= x[i];

		if (add > mul)
			num += 1 + count(i + 1, add, mul);
		else if (x[i] == 1)
			num += count(i + 1, add, mul);
		else
			break;

		add -= x[i];
		mul /= x[i];

		while (x[i + 1] == x[i] && i + 1 < n)
		{
			++i;
		}
	}

	return num;
}


int main()
{
	cin >> n;
	x = new int[n];
	int add = 0;            //ºÍ
	long long mul = 1;      //»ý
	for (int i = 0; i < n; ++i)
	{
		cin >> x[i];
	}


	sort(x, x + n);
	int num = count(0, add, mul);
	cout << num;

	if (x != NULL)
	{
		delete[]x;
		x = NULL;
	}

	return 0;
}