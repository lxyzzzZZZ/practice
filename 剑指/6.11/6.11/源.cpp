////#include <iostream>
////#include <vector>
////#include <string>
////using namespace std;
////
////vector<int> fun(vector<int> A, int k, int n)
////{
////	while (k)
////	{
////		vector<int> ret;
////		int i = n - 1;
////		int j = 2 * n - 1;
////		while (i >= 0 && j >= n)
////		{
////			ret.push_back(A[j]);
////			ret.push_back(A[i]);
////			i--;
////			j--;
////		}
////		k--;
////		A = ret;
////	}
////	return A;
////}
////int main()
////{
////	int T;
////	cin >> T;
////	while (T--)
////	{
////		int n, k;
////		vector<int> arr;
////		cin >> n >> k;
////		arr.resize(2 * n);
////		for (int i = 0; i < 2 * n; i++)
////			cin >> arr[i];
////
////		vector<int> ret = fun(arr, k, n);
////		for (int i = 0; i < ret.size() - 1; i++)
////		{
////			cout << ret[i] << " ";
////		}
////		cout << ret[ret.size() - 1] << endl;
////	}
////	system("pause");
////	return 0;
////}
//
//
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//void fun(int n, string str)
//{
//	if (n <= 4)
//	{
//		for (int i = 0; i < str.size(); i++)
//		{
//			int ret = 1;
//			if (str[i] == 'U' && ret == 1)
//				ret = n;
//			else if (str[i] == 'D' && ret == 4)
//				ret = 1;
//			else if (str[i] == 'U')
//				ret--;
//			else
//				ret++;
//		}
//		for (int i = 1; i <= n; i++)
//		{
//			if (i == n)
//				cout << i << endl;
//			else
//				cout << i << " ";
//		}
//		cout << ret << endl;
//	}
//	else
//	{
//		int i, j, k;
//		int index = 1;
//		int list[4];
//		for (i = 1; i <= 4; i++)
//			list[i] = i;
//
//		for (i = 0; i < str.size(); i++)
//		{
//			if (str[i] == 'U')
//			{
//				if (index == 1 && list[1] == 1)//当前为第一首
//				{
//					//重新赋值，并改变index的值
//					for (j = n, k = 4; k >= 1; j--, k--)
//						list[k] = j;
//					index = 4;
//				}
//				else if (index == 1 && list[1] != 1)
//				{
//					for (k = 4; k >= 2; k--)
//						list[k] = list[k - 1];
//					list[1] = (list[1] - 1);
//				}
//				else
//				{
//					index--;
//				}
//			}
//			else if (str[i] == 'D')
//			{
//				if (index == 4 && list[4] == n)
//				{
//					index = 1;
//					for (k = 1; k <= 4; k++)
//						list[k] = k;
//				}
//				else if (index == 4 && list[4] != n)
//				{
//					index = 4;
//					for (k = 1; k <= 3; k++)
//						list[k] = list[k + 1];
//					list[4] = list[4] + 1;
//				}
//				else
//					index++;
//			}
//		}
//		for (i = 1; i <= 4; i++)
//		{
//			if (i != 4)
//				cout << list[i] << ' ';
//			else
//				cout << list[i] << endl;
//		}
//		cout << list[index] << endl;
//	}
//}
//int main()
//{
//	int num;
//	string str;
//	while (cin >> num >> str)
//	{
//		fun(num, str);
//	}
//	system("pause");
//	return 0;
//}
//
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
//vector<int> fun(vector<int> A, int k, int n)
//{
//	while (k)
//	{
//		vector<int> ret;
//		ret.resize(2 * n);
//		int i = n - 1;
//		int j = 2 * n - 1;
//		while (i >= 0 && j >= n)
//		{
//			ret.push_back(A[j]);
//			ret.push_back(A[i]);
//			i--;
//			j--;
//		}
//		k--;
//		A = ret;
//	}
//	return A;
//}
//int main()
//{
//	int T;
//	cin >> T;
//	while (T--)
//	{
//		int n, k;
//		vector<int> arr;
//		cin >> n >> k;
//		arr.resize(2 * n);
//		for (int i = 0; i < 2 * n; i++)
//			cin >> arr[i];
//
//		vector<int> ret = fun(arr, k, n);
//		for (int i = 0; i < ret.size() - 1; i++)
//		{
//			cout << ret[i] << " ";
//		}
//		cout << ret[ret.size() - 1] << endl;
//	}
//	return 0;
//}