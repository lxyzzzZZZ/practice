#include <iostream>
#include <string>
using namespace std;

int OneCount(int num)
{
	int count = 0;
	while (num)
	{
		if (num % 10 == 1)
			count++;
		num /= 10;
	}
	return count;
}


int PowerBase(unsigned int n)
{
	int result = 1;
	for (unsigned int i = 0; i < n; ++i)
		result *= 10;
	return result;
}
int NumberOf2(char* str)
{
	if (!str || *str < '0' || *str > '9' || *str == '\0')
		return 0;
	int first = *str - '0';
	unsigned int length = static_cast<unsigned int>(strlen(str));
	if (length == 1 && first == 1)
		return 0;
	if (length == 1 && first > 0)
		return 1;
	int num = 0;
	if (first > 1)
		num = PowerBase(length - 1);
	else if (first == 1)
		num = atoi(str - 1);
	int numSecond = first * (length - 1)*PowerBase(length - 2);

	int num3 = NumberOf2(str + 1);
	return num + numSecond + num3;
}





int main()
{
	int Num;
	while (cin >> Num)
	{
		cout << OneCount(Num) << endl;
	}
	system("pause");
	return 0;
}