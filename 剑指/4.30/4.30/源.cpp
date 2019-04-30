#include <iostream>
#include <stdio.h>
#include <math.h>
using	namespace std;


class solution
{
public:
	double PowerWithUnsignedExponent(double base, unsigned int exponent)
	{
		if (exponent == 0)
		{
			return 1;
		}
		if (exponent == 1)
		{
			return base;
		}
		double result = PowerWithUnsignedExponent(base, exponent >> 1);
		result *= result;
		if (exponent & 0x1 == 1)
		{
			result *= base;
		}

		return result;
	}

	double Power2(double base, unsigned int exponent)
	{
		double result = 1.0;
		for (int i = 0; i <= exponent; ++i)
		{
			result *= base;
		}
		return result;
	}
	bool g_InvalidInput = false;

	double Power(double base, int exponent)
	{
		g_InvalidInput = false;
		if (base == 0.0 && exponent < 0)
		{
			g_InvalidInput = true;
			return 0.0;
		}
		unsigned int absExonent = (unsigned int)(exponent);
		if (exponent < 0)
		{
			absExonent = (unsigned int)(-exponent);
		}
		double result = Power2(base, absExonent);
		if (exponent < 0)
		{
			result = 1.0 / result;
			return result;
		}

	
	}
};