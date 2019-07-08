//// write your code here cpp
//#include <string>
//#include <iostream>
//#include <cmath>
//using namespace std;
//bool is_prime(int num)
//{
//	for (int i = 2; i <= sqrt(num); i++)
//	{
//		if (num % i == 0)
//		{
//			return false;
//		}
//	}
//	return true;
//}
//int main()
//{
//	int num;
//	while (cin >> num)
//	{
//		string arr;
//		int ret = 2;
//		int NUM = num;
//		while (num > 1)
//		{
//
//			if (num % ret == 0)
//			{
//				num /= ret;
//				arr.push_back(ret + '0');
//				arr.push_back('*');
//			}
//			else
//			{
//				while (1)
//				{
//					ret++;
//					if (is_prime(ret))
//						break;
//				}
//			}
//		}
//		if (arr.size() > 1)
//		{
//			arr.pop_back();
//		}
//		cout << NUM << " =";
//		for (int i = 0; i < arr.size(); i++)
//		{
//			cout << " " << arr[i];
//		}
//		cout << endl;
//	}
//	system("pause");
//	return 0;
//}
//
//
//// write your code here cpp
//#include <vector>
//#include <iostream>
//#include <cmath>
//using namespace std;
//bool is_prime(int num)
//{
//	for (int i = 2; i <= sqrt(num); i++)
//	{
//		if (num % i == 0)
//		{
//			return false;
//		}
//	}
//	return true;
//}
//int main()
//{
//	int num;
//	while (cin >> num)
//	{
//		int NUM = num;
//		vector<int> arr;
//		int ret = 2;
//		while (num > 1)
//		{
//			if (num % ret == 0)
//			{
//				num /= ret;
//				arr.push_back(ret);
//			}
//			else
//			{
//				while (1)
//				{
//					ret++;
//					if (is_prime(ret))
//						break;
//				}
//			}
//		}
//		cout << NUM << " =";
//		for (int i = 0; i < arr.size(); i++)
//		{
//			if (i == arr.size() - 1)
//			{
//				cout << " " << arr[i] << endl;
//				break;
//			}
//			cout << " " << arr[i] << " " << "*";
//		}
//	}
//	return 0;
//}
//
//// write your code here cpp
//#include <vector>
//#include <iostream>
//#include <cmath>
//using namespace std;
//void Print(int NUM, vector<int> arr)
//{
//	cout << NUM << " =";
//	for (int i = 0; i < arr.size(); i++)
//	{
//		if (i == arr.size() - 1)
//		{
//			cout << " " << arr[i] << endl;
//			break;
//		}
//		cout << " " << arr[i] << " " << "*";
//	}
//}
//int main()
//{
//	int num;
//	while (cin >> num)
//	{
//		int NUM = num;
//		vector<int> arr;
//		int ret = 2;
//		while (num > 1)
//		{
//			if (num % ret == 0)
//			{
//				num /= ret;
//				arr.push_back(ret);
//				continue;
//			}
//			ret++;
//		}
//		Print(NUM, arr);
//	}
//	return 0;
//}
//
//
//
//
//// write your code here cpp
//
//#include <iostream>
//using namespace std;
//int WeekToDay(int y, int m, int c, int w, bool B)
//{
//	int d, week, i;
//	if (m == 1)
//	{
//		m = 13;
//		y--;
//	}
//	if (m == 2)
//	{
//		m = 14;
//		y--;
//	}
//	i = 0;
//	for (d = B ? 1 : 31; d <= B ? 31 : 1; B ? (d++) : (d--))
//	{
//		week = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;
//		if (week + 1 == w)
//			++i;
//		if (i == c)
//			break;
//	}
//	return d;
//}
//
//int main(void) {
//	int y;
//	while (cin >> y) {
//		cout << y << "-01-01" << endl;
//		printf("%d-01-%02d\n", y, WeekToDay(y, 1, 3, 1, 1));
//		printf("%d-02-%02d\n", y, WeekToDay(y, 2, 3, 1, 1));
//		printf("%d-05-%02d\n", y, WeekToDay(y, 5, 1, 1, 0));//µ¹Êý
//		cout << y << "-07-04" << endl;
//		printf("%d-09-%02d\n", y, WeekToDay(y, 9, 1, 1, 1));
//		printf("%d-11-%02d\n", y, WeekToDay(y, 11, 4, 4, 1));
//		cout << y << "-12-25" << endl << endl;
//	}
//	return 0;
//}