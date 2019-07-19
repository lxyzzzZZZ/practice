#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> arr;
	arr.resize(n);
	int ret;
	for (int i = 0; i < n; ++i)
	{
		cin >> ret;
		arr[i] = ret;
	}
	sort(arr.begin(), arr.end());
	int k, d;
	cin >> k >> d;
	int flag = 0;
	for (int i = 1; i < n; ++i)
	{
		if (arr[i] - arr[i - 1] > d)
		{
			flag = i - 1;
			break;
		}
		if (i == n - 1)
			flag = i;
	}

	int avg = 1;
	if (flag + 1 < k)
		return 0;
	else
	{
		while (k--)
		{
			avg *= arr[flag];
			flag--;
		}
	}
	cout << avg << endl;
	system("pause");
	return 0;
	
}