//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//int main()
//{
//	string ret;
//	getline(cin, ret);
//	int n = atoi(ret.c_str());
//	vector<int> arr;
//	int num;
//	while (cin >> num)
//	{
//		arr.push_back(num);
//	}
//	int MaxNum = arr[0];
//	int sum = arr[0];
//
//	for (int i = 1; i < arr.size(); i++)
//	{
//		if (arr[i] >= 0)
//		{
//			sum += arr[i];
//		}
//		else if
//		{
//			if (MaxNum < sum)
//			{
//				MaxNum = sum;
//			}
//			sum = 0;
//		}
//		if (i == arr.size() - 1)
//		{
//			if (sum > MaxNum)
//			{
//				MaxNum = sum;
//			}
//		}
//	}
//	cout << MaxNum << endl;
//	system("pause");
//	return 0;
//}
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//int main()
//{
//	string ret;
//	getline(cin, ret);
//	int n = atoi(ret.c_str());
//	vector<int> arr;
//	int num;
//	while (cin >> num)
//	{
//		arr.push_back(num);
//	}
//	int MaxNum = arr[0];
//	int sum = arr[0];
//	for (int i = 0; i < arr.size(); i++)
//	{
//		int sum = arr[i];
//		if (MaxNum < sum)
//			MaxNum = sum;
//		for (int j = i + 1; j < arr.size(); j++)
//		{
//			sum += arr[j];
//			if (sum > MaxNum)
//				MaxNum = sum;
//		}
//	}
//	cout << MaxNum << endl;
//	return 0;
//}
//
//bool fun(string str)
//{
//	int left = 0;
//	int right = str.size() - 1;
//	while (left < right)
//	{
//		if (str[left] != str[right])
//		{
//			return false;
//		}
//		left++;
//		right--;
//	}
//	return true;
//}
//
//int main()
//{
//	string str1, str2;
//	getline(cin, str1);
//	getline(cin, str2);
//	int count = 0;
//	for (int i = 0; i <= str1.size(); i++)
//	{
//		string str3(str1);
//		str3.insert(i, str2.c_str());
//		if (fun(str3) == true)
//		{
//			count++;
//		}
//	}
//	cout << count << endl;
//	return 0;
//}
//int main()
//{
//	//string str;
//	//getline(cin, str);
//	//cout << str.c_str() << endl;
//	//int num = atoi(str.c_str());
//	//cout << num << endl;
//	//str.erase(0);
//	//while (num > 0)
//	//{
//	//	int temp = num % 10;
//	//	str.insert(str.begin(), '0' + temp);
//	//	num /= 10;
//	//}
//	//cout << str.c_str() << endl;
//	system("pause");
//	return 0;
//}