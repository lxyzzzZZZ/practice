
#include<iostream>
#include<vector>
using namespace std;
void help(int n, int m, vector<int>& v, int beg) {
	//if (beg>n) return;
	if (m == 0) {
		for (int i = 0; i < v.size(); i++) {
			i == 0 ? cout << v[i] : cout << " " << v[i];
		}
		cout << endl;
	}
	for (int i = beg; i <= n && i <= m; i++) {
		v.push_back(i);
		help(n, m - i, v, i + 1);
		v.pop_back();
	}
}
int main() {
	int n, m;
	while (cin >> n >> m) {
		vector<int>v;
		help(n, m, v, 1);
	}
}
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//char ret[26] = { '2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7','7','7','7','8','8','8','9','9','9','9' };
//string Judge(string str)
//{
//	string New;
//	if (str.size() < 1)
//		return nullptr;
//	for (int i = 0; i < str.size(); i++)
//	{
//		if (str[i] == '-')
//			continue;
//		else if (str[i] >= 'A' || str[i] <= 'Z')
//		{
//			New.push_back(ret[str[i] - 'A']);
//		}
//		else if (str[i] >= 0 || str[i] <= 9)
//			New.push_back(str[i]);
//	}
//	return New;
//}
//int main()
//{
//	int n = 0;
//	cin >> n;
//	vector<string> arr;
//	arr.resize(n);
//	for (int i = 0; i < n; i++)
//	{
//		string str;
//		cin >> str;
//		arr[i] = str;
//	}
//	vector<string> ret;
//	ret.resize(n);
//	for (int i = 0; i < n; i++)
//	{
//		ret[i] = Judge(arr[i]);
//		ret[i].insert(3, '-');
//	}
//
//	for (int i = 0; i < n; i++)
//	{
//		cout << ret[i].c_str() << " ";
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//}
//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//
//	int left = 0;
//	int right = n;
//	int flag = 0;
//	while (left <= right && right <= n && left >= 0)
//	{
//		if (left + right > m)
//			right--;
//		else if (left + right < m)
//			left++;
//		else
//		{
//			if (left == 0)
//				flag = 1;
//			else
//				cout << left << " " << right << endl;
//
//			right--;
//		}
//	}
//	if (flag == 1)
//		cout << m << endl;
//	return 0;
//}