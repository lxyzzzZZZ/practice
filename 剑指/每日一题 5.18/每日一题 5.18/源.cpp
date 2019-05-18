#include <iostream>
#include <string>
using namespace std;

int sum = 0;
int GetPwdSecurityLevel(string pPasswordStr)
{
	int flag = 0;

	int count = 0;
	if (pPasswordStr.size() <= 4)
		sum += 5;
	else if (pPasswordStr.size() <= 7)
		sum += 10;
	else if (pPasswordStr.size() >= 8)
		sum += 25;


	string::iterator it = pPasswordStr.begin();
	while (it != pPasswordStr.end())
	{
		if (*it >= 'a' && *it <= 'z')
		{
			sum += 10;
			count++;
			break;
		}
		it++;
	}
	it = pPasswordStr.begin();
	while (it != pPasswordStr.end())
	{
		if (*it >= 'A' && *it <= 'Z')
		{
			sum += 10;
			count++;
			break;
		}
		it++;
	}
	it = pPasswordStr.begin();
	while (it != pPasswordStr.end())
	{
		if (*it >= '0' && *it <= '9')
		{
			flag++;
		}
		it++;
	}
	if (flag == 1)
	{
		sum += 10;
		count++;
	}
	else if (flag > 1)
	{
		sum += 20;
		count++;
	}
	flag = 0;
	it = pPasswordStr.begin();
	while (it != pPasswordStr.end())
	{
		if ((*it >= '!' && *it <= '/')
			|| (*it >= ':' && *it <= '@')
			|| (*it >= '[' && *it < 'a')
			|| (*it >= '{' && *it <= '~'))
		{
			flag++;
		}
		it++;
	}
	if (flag == 1)
	{
		sum += 10;
		count++;
	}
	else if (flag > 1)
	{
		sum += 25;
		count++;
	}

	if (count == 2)
	{
		sum += 2;
	}
	else if (count == 3)
	{
		sum += 3;
	}
	else if (count == 4)
	{
		sum += 5;
	}
	return sum;
}

int main()
{
	string input;
	cin >> input;
	if (input.size() > 0)
	{
		int sum = GetPwdSecurityLevel(input);
		if (sum >= 90)
		{
			cout << "VERY_SECURE" << endl;
		}
		else if (sum >= 80)
		{
			cout << "SECURE" << endl;
		}
		else if (sum >= 70)
		{
			cout << "VERY_STRONG" << endl;
		}
		else if (sum >= 60)
		{
			cout << "STRONG" << endl;
		}
		else if (sum >= 50)
		{
			cout << "AVERAGE" << endl;
		}
		else if (sum >= 25)
		{
			cout << "WEAK" << endl;
		}
		else if (sum >= 0)
		{
			cout << "VERY_WEAK" << endl;
		}
	}
	return 0;
}
