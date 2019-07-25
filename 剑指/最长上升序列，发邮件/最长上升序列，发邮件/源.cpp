// write your code here cpp
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> arr;
		arr.resize(n);
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		vector<int> ret(n, 1);
		int len = 1;
		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < i; j++)
				if (arr[i] > arr[j])
					ret[i] = ret[i] > (ret[j] + 1) ? ret[i] : (ret[j] + 1);
			len = len > ret[i] ? len : ret[i];
		}
		cout << len << endl;
	}
}

// write your code here cpp
#include <iostream>
using namespace std;

int main()
{
	int n = 0;
	while (cin >> n)
	{
		if (n < 2)
			return 0;
		long a = 0;
		long b = 1;
		long sum = 1;
		for (int i = 3; i <= n; i++)
		{
			sum = (i - 1) * (a + b);
			a = b;
			b = sum;
		}
		cout << sum << endl;
	}
	return 0;
}