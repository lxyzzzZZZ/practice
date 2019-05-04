#include <iostream>

using namespace std;


class Project
{
public:
	bool isNumeric(const char* str)
	{
		if (str == nullptr)
		{
			return false;
		}
		bool numeric = scanInteger(&str);
		if (*str == '.')
		{
			++str;
		}
		if (*str == 'e' || *str == 'E')
		{
			++str;
		}
		numeric = numeric && scanInteger(&str);
		return numeric && *str == '\0';
	}


	bool scanUnsignedInteger(const char **str)
	{
		const char* before = *str;
		while (**str != '\0' && **str >= '0' && **str <= '10')
		{
			++(*str);
		}
		return *str > before;
	}

	bool scanInteger(const char** str)
	{
		if (**str == '+' || **str == '-')
		{
			++(*str);
		}
		return scanUnsignedInteger(str);
	}
};