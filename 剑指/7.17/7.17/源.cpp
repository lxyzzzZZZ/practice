#include <iostream>
#include <string>
#include <vector>
#include <string.h>
using namespace std;

bool is_True(string A, string B)
{
	int ret[27] = { 0 };
	for (int i = 0; i < B.size(); i++)
		++ret[B[i] - 'a'];
	for (int i = 0; i < A.size(); i++)
		--ret[A[i] - 'a'];
	for (int i = 0; i < 27; i++)
	{
		if (ret[i] > 0)
			return false;
	}
	return true;
}

int main()
{
	int n;
	cin >> n;
	vector<string> arr;
	for (int i = 0; i < n; i++)
	{
		string ret;
		cin >> ret;
		arr.push_back(ret);
	}
	string bother;
	int m = 0;
	cin >> bother >> m;
	int count = 0;
	vector<string> both;
	for (int i = 0; i < arr.size(); i++)
	{
		if (strcmp(bother.c_str(), arr[i].c_str()) == 0)
			continue;
		else if (is_True(bother, arr[i]) == true)
		{
			both.push_back(arr[i]);
			count++;
		}
	}
	cout << count << " " << both[m - 1].c_str() << endl;
	system("pause");
	return 0;
}

#include <iostream>
#include <string>
#include <vector>
//#include <string.h>
#include <algorithm>
using namespace std;

bool is_True(string str, string s)
{
	if (str.size() == s.size())
	{
		if (str == s)
			return false;
		sort(str.begin(), str.end());
		sort(s.begin(), s.end());
		if (str == s)
			return true;
	}
	return false;
}

int main()
{
	int n;
	while (cin >> n)
	{
		vector<string> arr;
		string ret;
		for (int i = 0; i < n; i++)
		{
			cin >> ret;
			arr.push_back(ret);
		}
		sort(arr.begin(), arr.end());
		string bother;
		int m = 0;
		cin >> bother;
		cin >> m;
		int count = 0;
		string both;
		for (int i = 0; i < n; i++)
		{
			if (is_True(bother, arr[i]))
			{
				count++;
				if (count == m)
					both = arr[i];
			}
		}
		//sort(both.begin(), both.end());
		if (!arr.empty())
			cout << count << endl;
		if (m <= count)
			cout << both << endl;
	}
	return 0;
}

// write your code here cpp
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string A, B;
	while (cin >> A >> B)
	{
		int ret[27] = { 0 };
		for (int i = 0; i < B.size(); i++)
			++ret[B[i] - 'A'];
		for (int i = 0; i < A.size(); i++)
			--ret[A[i] - 'A'];
		for (int i = 0; i < 27; i++)
		{
			if (ret[i] > 0)
			{
				cout << "No" << endl;
				break;
			}
			else if (i == 26)
				cout << "Yes" << endl;
		}

	}
	return 0;
}