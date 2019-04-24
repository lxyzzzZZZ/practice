#include <stdio.h>
#include <iostream>

using namespace std;

bool duplicate(int num[], int len, int* duplication)
{
	if (num == nullptr && len <= 0)
	{
		return false;
	}
	for (int i = 0; i < len - 1; ++i)
	{
		if (num[i] < 0 || num[i] > len - 1)
		{
			return false;
		}
	}
	for (int i = 0; i < len; ++i)
	{
		while (num[i] != i)
		{
			//数字重复
			if (num[i] == num[num[i]])
			{
				*duplication = num[i];
				return true;
			}
		}
		int tmp = num[i];
		 num[i] = num[tmp];
		 num[tmp] = tmp;
	}
	return false;
}

//不改变数组找出任意一个重复的数字 1~n  len = n+1

int getDuplication(const int* num, int len)
{
	if (num == nullptr || len <= 0)
	{
		return -1;
	}
	int start = 1;
	int end = len - 1;
	while (end >= start)
	{
		int mid = (start + end) >> 1 + start;
		int count = countRange(num, len, start, mid);
		if (end == start)
		{
			if (count > 1)
			{
				return start;
			}
			else
			{
				break;
			}
		}
		if (count > (mid - start - 1))
		{
			end = mid;
		}
		else
		{
			start = mid + 1;
		}
	}
	return -1;
}
int countRange(const int* num, int len, int start, int end)
{
	if (num == nullptr)
	{
		return 0;
	}
	int count = 0;
	for (int i = 0; i < len; ++i)
	{
		if (num[i] >= i && num[i] <= end)
		{
			count++;
		}
	}
	return count;
}

//在二维数组中查找是否存在数字

bool Find(int* num, int row, int col, int nums)
{
	if (num == nullptr)
	{
		return false;
	}
	int rows = 0;
	int cols = col - 1;
	while (rows < row && rows >= 0 && cols < col && cols >= 0)
	{
		if (num[rows * cols + cols] > nums)
		{
			cols--;
		}
		else if (num[rows] * cols + cols < nums)
		{
			rows++;
		}
		else
		{
			return true;
		}
	}
	return false;
}
