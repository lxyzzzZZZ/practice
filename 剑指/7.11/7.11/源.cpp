//// write your code here cpp
//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//	int n = 0;
//	cin >> n;
//	vector<string> arr;
//	arr.resize(n);
//	for (int i = 0; i < n; i++)
//	{
//		getline(cin, arr[i]);
//	}
//
//	for (int i = 0; i < arr.size(); i++)
//	{
//		cout << arr[i] << endl;
//	}
//	system("pause");
//	return 0;
//}
////int main()
////{
////	int n = 0;
////	cin >> n;
////	vector<string> arr;
////	int count = 0;
////	n = n + 1;
////	while (n)
////	{
////		string str;
////		getline(cin, str);
////		int flag = 0;
////		for (int j = 0; j < str.size(); j++)
////		{
////			if (str[j] == ' ' || str[j] == ',')
////			{
////				flag = 1;
////				break;
////			}
////		}
////		if (flag == 1)
////		{
////			str.push_back('"');
////			str.insert(str.begin(), '"');
////		}
////		arr.push_back(str);
////		n--;
////	}
////	cout << arr.size() << endl;
////	for (int i = 0; i < arr.size(); i++)
////	{
////		if (i == arr.size() - 1)
////		{
////			cout << arr[i].c_str() << endl;
////			break;
////		}
////		if (i == 0)
////		{
////			continue;
////		}
////		cout << arr[i].c_str() << ", ";
////	}
////	system("pause");
////	return 0;
////}
//
//
//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		cin.get();
//		string name;
//		for (int i = 0; i < n; i++)
//		{
//			getline(cin, name);
//			if (i != n - 1)
//			{
//				if (name.find(',') != -1 || name.find(' ') != -1)
//					cout << '\"' << name << '\"' << ',' << ' ';
//				else
//					cout << name << ',' << ' ';
//			}
//			else
//			{
//				if (name.find(',') != -1 || name.find(' ') != -1)
//					cout << '\"' << name << '\"' << endl;
//				else
//					cout << name << endl;
//			}
//		}
//	}
//	return 0;
//}