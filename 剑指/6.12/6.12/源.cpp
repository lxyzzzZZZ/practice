//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int Max_Divisor(int A, int B)
//{
//	int ret = 1;
//	int num = 1;
//	while (ret <= A && ret <= B)
//	{
//		if (A % ret == 0 && B % ret == 0)
//			num = ret;
//		ret++;
//	}
//	return num;
//}
//int main()
//{
//	int count, a;
//	while (cin >> count >> a)
//	{
//		vector<int> arr;
//		arr.resize(count);
//		for (int i = 0; i < count; i++)
//		{
//			cin >> arr[i];
//		}
//		for (int i = 0; i < count; i++)
//		{
//			if (a >= arr[i])
//				a += arr[i];
//			else
//				a += Max_Divisor(a, arr[i]);
//		}
//		cout << a << endl;
//	}
//	return 0;
//
//}
//
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int main()
//{
//	string str;
//	while (cin >> str)
//	{
//		int flag = 0;
//		int arr[256];
//		for (int i = 0; i < 256; i++)
//			arr[i] = 0;
//		for (int i = 0; i < str.size(); i++)
//		{
//			arr[str[i]]++;
//		}
//		for (int i = 0; i < str.size(); i++)
//		{
//			if (arr[str[i]] == 1)
//			{
//				cout << str[i] << endl;
//				flag = 1;
//				break;
//			}
//		}
//		if (flag == 0)
//			cout << -1 << endl;
//	}
//	return 0;
//}