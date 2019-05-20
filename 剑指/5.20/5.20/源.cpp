#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int main()
{
	string str1;
	string str2;

	getline(cin, str1);
	getline(cin, str2);
	int len = str1.size();
	for (int i = 0; i < str2.size(); i++)
	{
		for (int j = 0; j < len; j++)
		{
			if (str1[j] == str2[i])
			{
				for (int k = j; k < len - 1; ++k)
				{
					str1[k] = str1[k + 1];
				}
				str1.pop_back();
				len--;
			}
		}
	}
	cout << str1.c_str() << endl;
	system("pause");
	return 0;
}




























//
//
//
//int main()
//{
//	string N;
//	getline(cin, N);
//	int n = atoi(N.c_str());
//	string ret;
//	getline(cin, ret);
//	vector<int> arr;
//	stringstream ret2(ret);
//	int x;
//	while (ret2 >> x)
//	{
//		arr.push_back(x);
//	}
//	if (arr.size() / n != 3)
//	{
//		return 0;
//	}
//	sort(arr.begin(), arr.end());
//	/*for (int i = 0; i < arr.size(); i++)
//	{
//		for (int j = i; j < arr.size(); j++)
//		{
//			if (arr[j] < arr[i])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[i];
//				arr[i] = tmp;
//			}
//		}
//	}*/
//	//vector<int> ::iterator it = arr.begin();
//	//while (it != arr.end())
//	//{
//	//	cout << *it << " ";
//	//	it++;
//	//}
//	long sum = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		sum += arr[3 * n - i * 2];
//	}
//	cout << sum << endl;
//	system("pause");
//	return 0;
//	
//}
























//int main()
//{
//	int i = 2;
//	int j = 0;
//	for (i = 0, j = 0; (j = 123) && i < 4; i++)
//	{
//		cout << "1" << " ";
//	}
//
//	printf("%5.3s", "computer");
//	int a = 3;
//	double b = 0.3;
//	cout << 'A' + a + b << endl;
//	system("pause");
//	return 0;
//}