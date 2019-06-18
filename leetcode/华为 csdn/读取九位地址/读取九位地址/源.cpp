#include <iostream>
#include <string>

using namespace std;
int main()
{
	char str[18] = { 1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8 };
	int sz = 18;
	for (int i = 0; i <= sz; i+=9)
	{
		if (str[i] == 1)
		{
			for (int j = i; j < i + 9; ++j)
			{
				cout << str[j];
			}
		}
		if (str[i] == 0)
		{
			for (int j = i + 8; j >= i; --j)
			{
				cout << str[j];
			}
		}
		cout << " ";
	}
	system("pause");
	return 0;
}