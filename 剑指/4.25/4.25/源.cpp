#include <iostream>
#include <stdio.h>


using namespace std;

void ReplaceBlank(char str[], int len)
{
	if (str == nullptr || len <= 0)
	{
		return;
	}
	int length = 0;
	int num = 0;
	int i = 0;
	while (str[i] != '\0')
	{
		++length;
		if (str[i] == ' ')
		{
			++num;
		}
		++i;
	}
	int newlength = length + num * 2;
	if (newlength > len)
	{
		return;
	}
	int indexOfOriginal = length;
	int indexOfNew = newlength;
	while (indexOfNew >= 0 && indexOfNew > indexOfOriginal)
	{
		if (str[indexOfOriginal] == ' ')
		{
			str[indexOfOriginal--] = '0';
			str[indexOfOriginal--] = '2';
			str[indexOfOriginal--] = '%';
		}
		else
		{
			str[indexOfNew--] = str[indexOfOriginal];
		}
		--indexOfOriginal;
	}
}