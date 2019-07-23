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
//	vector<char> ret;
//	char a;
//	string b;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> a >> b;
//		ret.push_back(a);
//		arr.push_back(b);
//	}
//	int Max = 1;
//	int count = 1;
//	a = ret[0];
//	for (int i = 1; i < n; i++)
//	{
//		if (count == 0)
//		{
//			count = 1;
//			a = ret[i];
//			continue;
//		}
//		if (ret[i] == a)
//			count--;
//		else
//			count++;
//		Max = Max < count ? count : Max;
//	}
//	cout << Max << endl;
//	system("pause");
//	return 0;
//}
//
//
//// write your code here cpp
//#include <iostream>
//#include <fstream>
//#include <algorithm>
//#include <string>
//#include <vector>
//using namespace std;
//
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		vector<string> list(n);
//		vector<bool> flag(n, true);
//		for (int i = 0; i < n; ++i) cin >> list[i];
//		sort(list.begin(), list.end());
//
//		for (int i = 0; i < list.size() - 1; ++i)
//		{
//			if (list[i] == list[i + 1]) flag[i] = false;
//			else if (list[i].size() < list[i + 1].size() && \
//				list[i] == list[i + 1].substr(0, list[i].size()) && list[i + 1][list[i].size()] == '/')
//				flag[i] = false;
//		}
//
//		for (int i = 0; i < list.size(); ++i)
//			if (flag[i]) cout << "mkdir -p " << list[i] << endl;
//		cout << endl;
//	}
//	return 0;
//}

链接：https://www.nowcoder.com/questionTerminal/ed9bc679ea1248f9a3d86d0a55c0be10
来源：牛客网

#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int n, m, k;
	while (scanf("%d%d%d", &n, &m, &k) != EOF) {
		vector<vector<int>> table((n + 1), vector<int>(m + 1));
		vector<vector<double>> P((n + 1), vector<double>(m + 1));
		int x, y;
		for (int i = 0; i < k; i++) {
			scanf("%d%d", &x, &y);
			table[x][y] = 1;
		}
		P[1][1] = 1.0;      //起点概率为1
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (!(i == 1 && j == 1)) {      //跳过起点
					P[i][j] = P[i - 1][j] * (j == m ? 1 : 0.5) + P[i][j - 1] * (i == n ? 1 : 0.5);   //边界的时候，概率为1
					if (table[i][j] == 1) P[i][j] = 0;        //如果该点有蘑菇，概率置为0
				}
			}
		}
		printf("%.2lf\n", P[n][m]);
	}
}