#include <string>
#include <vector>
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int n = 0;
	vector<string> filename;
	vector<int> count, arr;
	while (n < 8)
	{
		n++;
		string str;
		string ret;
		int num;
		cin >> str >> num;
		if (str.size() < 1)
			break;
		for (int i = str.size() - 1; i >= str.size() - 16; --i)
		{
			if (str[i] == '\\')
				break;
			ret.insert(ret.begin(), str[i]);
		}
		int flag = 0;
		for (int i = 0; i < filename.size(); ++i)
		{
			if ((strcmp(filename[i].c_str(), ret.c_str()) == 0) && arr[i] == num)
			{
				flag = i;
				break;
			}
		}
		if (flag != 0)
		{
			count[flag]++;
		}
		else
		{
			filename.push_back(ret);
			count.push_back(1);
			arr.push_back(num);
		}
	}
	for (int i = 0; i < filename.size(); ++i)
	{
		cout << filename[i].c_str() << " ";
		cout << arr[i] << " ";
		cout << count[i] << endl;
	}
	system("pause");
	return 0;
}