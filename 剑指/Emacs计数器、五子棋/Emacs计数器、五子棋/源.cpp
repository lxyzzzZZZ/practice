// write your code here cpp
// write your code here cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int atoi(string s) {
	int res = 0;
	for (int i = 0; i < s.size(); ++i) {
		res *= 10;
		res += s[i] - '0';
	}
	return res;
}
int main()
{
	int n;
	while (cin >> n)
	{
		vector<string> str;
		str.resize(n);
		for (int i = 0; i < n; i++)
			cin >> str[i];
		vector<int> arr;
		int a, b;
		for (int i = 0; i < n; i++)
		{
			if (arr.size() > 1)
			{
				a = arr[arr.size() - 2];
				b = arr[arr.size() - 1];
			}
			if (str[i] == "+")
			{
				arr.pop_back();
				arr.pop_back();
				arr.push_back(a + b);
			}
			else if (str[i] == "-")
			{
				arr.pop_back();
				arr.pop_back();
				arr.push_back(a - b);
			}
			else if (str[i] == "*")
			{
				arr.pop_back();
				arr.pop_back();
				arr.push_back(a * b);
			}
			else if (str[i] == "/")
			{
				arr.pop_back();
				arr.pop_back();
				arr.push_back(a / b);
			}
			else
				arr.push_back(atoi(str[i]));
		}
		cout << arr[0] << endl;
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

int atoi(string s) {
	int res = 0;
	for (int i = 0; i < s.size(); ++i) {
		res *= 10;
		res += s[i] - '0';
	}
	return res;
}

int main()
{
	int n;
	while (cin >> n) {
		vector<string> v(n);
		stack<int> st;
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
			if (v[i] != "+" && v[i] != "-" && v[i] != "*" && v[i] != "/") {
				st.push(atoi(v[i]));
			}
			else {
				int right = st.top();
				st.pop();
				int left = st.top();
				st.pop();
				if (v[i] == "+")
					st.push(left + right);
				else if (v[i] == "-")
					st.push(left - right);
				else if (v[i] == "*")
					st.push(left * right);
				else if (v[i] == "/") {
					if (right != 0)
						st.push(left / right);
					else
						return 0;
				}
			}
		}
		cout << st.top() << endl;
	}
	return 0;
}

链接：https://www.nowcoder.com/questionTerminal/a811535fed784ea492b63622c28c75c5
来源：牛客网

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <exception>
#include <iomanip>
#include <memory>
#include <sstream>

using namespace std;

int main(int argc, char** argv)
{
	//freopen("in.txt", "r", stdin);
	vector<vector<char>> checkBoard(20, vector<char>(20));

	char c;
	while ((c = getchar()) != EOF)
	{
		ungetc(c, stdin);
		for (int i = 0; i < 20; ++i)
		{
			for (int j = 0; j < 20; ++j)
			{
				c = getchar();
				checkBoard[i][j] = c;
			}
			getchar();
		}

		bool found = false;
		for (int i = 0; i < 20; ++i)
		{
			if (found) break;
			for (int j = 0; j < 20; ++j)
			{
				if (checkBoard[i][j] == '.') continue;
				c = checkBoard[i][j];
				checkBoard[i][j] = '.';
				int curCount = 1;
				int x = i + 1;
				while (x < 20 && checkBoard[x][j] == c)
				{
					checkBoard[x][j] = '.';
					++curCount;
					++x;
				}
				if (curCount >= 5)
				{
					found = true;
					break;
				}
				curCount = 1;
				int y = j + 1;
				while (y < 20 && checkBoard[i][y] == c)
				{
					checkBoard[i][y] = '.';
					++curCount;
					++y;
				}
				if (curCount >= 5)
				{
					found = true;
					break;
				}
				curCount = 1;
				x = i + 1, y = j + 1;
				while (x < 20 && y < 20 && checkBoard[x][y] == c)
				{
					checkBoard[x][y] = '.';
					++curCount;
					++x; ++y;
				}
				if (curCount >= 5)
				{
					found = true;
					break;
				}
			}
		}

		if (found) cout << "Yes" << endl;
		else cout << "No" << endl;
	}

	return 0;
}