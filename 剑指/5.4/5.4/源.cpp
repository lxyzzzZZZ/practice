#include <iostream>


using namespace std;

bool match(char* str, char* pattern)
{
	if (str == nullptr || pattern == nullptr)
	{
		return false;
	}
	return matchCore(str, pattern);
}

bool matchCore(char* str, char* patten)
{
	if (*str == '\0' && patten == '\0')
	{
		return true;
	}
	if (*str != '\0' && *patten == '\0')
	{
		return false;
	}
	if (*(patten + 1) == '*')
	{
		if (*patten == *str || *patten == '.' && *str != '\0')
		{
			return matchCore(str + 1, patten + 2)
				|| matchCore(str + 1, patten)
				|| matchCore(str, patten + 2);
		}
		else
		{
			return matchCore(str, patten + 2);
		}
		if (*str == *patten || (*patten == '.' && *str != '\0'))
		{
			return matchCore(str + 1, patten + 1);
		}
		return false;
	}
}