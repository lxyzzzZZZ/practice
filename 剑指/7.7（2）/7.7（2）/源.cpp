#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int a, b, c;
	while (cin >> a >> b >> c)
	{
		if (b % 2 == 0)
			cout << (a * a) % c << endl;
		else
			cout << a % c << endl;

		int ret = 1;
		for (int i = 0; i < b; i++)
		{
			ret = (ret * a) % c;
		}
		cout << ret << endl;
		ret = 1;
		for (int i = 0; i < b; i++)
			ret *= a;
		cout << ret % c << endl;
	}
	system("pause");
	return 0;
}