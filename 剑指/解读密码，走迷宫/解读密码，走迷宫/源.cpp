// write your code here cpp
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	while (getline(cin, str) && str.size() > 0)
	{
		string ret;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] >= '0' && str[i] <= 9)
				ret.push_back(str[i]);
		}
		cout << ret.c_str() << endl;
	}
	system("pause");
	return 0;
}

// write your code here cpp
#include<bits/stdc++.h>
using namespace std;

const int N = 10;
const int INF = 1e5 + 5;
void calculate(vector<vector<char>>& map, vector<vector<int>>& len, int x, int y)
{
	if (x < 1 || y < 1 || x > 8 || y > 8 || map[x][y] == '#')
		return;
	int MIN = min(min(len[x - 1][y], len[x + 1][y]), min(len[x][y - 1], len[x][y + 1])) + 1;
	if (MIN < len[x][y])
		len[x][y] = MIN;
	else
		return;

	calculate(map, len, x - 1, y);
	calculate(map, len, x + 1, y);
	calculate(map, len, x, y - 1);
	calculate(map, len, x, y + 1);
}

int main()
{
	vector<vector<char>> map(N, vector<char>(N));
	//freopen("a.txt", "r", stdin);
	while (cin >> map[0][0])
	{
		vector<vector<int>> len(N, vector<int>(N, INF));
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (i == 0 && j == 0)
					continue;
				char t;
				cin >> t;
				map[i][j] = t;
			}
		}
		len[0][1] = 0;
		calculate(map, len, 1, 1);
		cout << len[8][8] + 1 << endl;
	}
	return 0;
}