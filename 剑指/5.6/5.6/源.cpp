#include <iostream>

using namespace std;



void ReorderOddEven(int* pData, unsigned int length)
{
	if (pData == nullptr || length == 0)
	{
		return;
	}
	int* pBegin = pData;
	int* pEnd = pData + length - 1;
	while (pBegin < pEnd)
	{
		//直到找到奇数
		while (pBegin < pEnd && (*pBegin & 0x1) != 0)
		{
			pBegin++;
		}
		//直到找到偶数
		while (pEnd > pBegin && (*pEnd & 0x1) == 0)
		{
			pEnd++;
		}
		if (pBegin < pEnd)
		{
			int* tmp = pBegin;
			pBegin = pEnd;
			pEnd = tmp;
		}
	}
}

void Reorder(int* pData, unsigned int length, bool(*func)(int))
{
	if (pData == nullptr || length == 0)
	{
		return;
	}
	int* pBegin = pData;
	int* pEnd = pData + length - 1;
	while (pBegin < pEnd)
	{
		//直到找到奇数
		while (pBegin < pEnd && !func(*pBegin))
		{
			pBegin++;
		}
		//直到找到偶数
		while (pEnd > pBegin && func(*pEnd))
		{
			pEnd++;
		}
		if (pBegin < pEnd)
		{
			int* tmp = pBegin;
			pBegin = pEnd;
			pEnd = tmp;
		}
	}
}

bool isEven(int n)
{
	return ((n & 1) == 0);
}

void ReorderOddEven2(int* pData, unsigned int length)
{
	Reorder(pData, length, isEven);
}





