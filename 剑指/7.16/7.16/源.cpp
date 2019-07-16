#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string str;
	getline(cin, str);
	string ret;
	vector<string> arr;
	for (int i = 0; i < str.size(); i++)
	{
		if ((str[i] < 'A' || str[i] > 'Z') && (str[i] < 'a' || str[i] > 'z'))
		{
			if (ret.size() < 1)
				continue;
			arr.insert(arr.begin(), ret);
			ret.clear();
			continue;
		}
		ret.push_back(str[i]);
	}
	if (ret.size() > 0)
		arr.insert(arr.begin(), ret);
	for (int i = 0; i < arr.size(); i++)
	{
		if (i == arr.size() - 1)
			cout << arr[i];
		else
			cout << arr[i] << " ";
	}
	return 0;
}

// write your code here cpp
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	while (cin >> str)
	{
		string ret;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '_')
				continue;
			else if (str[i - 1] == '_')
			{
				ret.push_back(str[i] - 32);
				continue;
			}
			ret.push_back(str[i]);
		}
		cout << ret.c_str() << endl;
	}
	return 0;
}
