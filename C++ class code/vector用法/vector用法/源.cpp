#include <iostream>
#include <vector>
#include <string>

using namespace std;

//int main()
//{
//	vector<int> first;
//	vector<int> second(4, 100);
//	vector<int> third(second.begin(), second.end());
//	vector<int> fourth(third);
//	
//	int myints[] = { 16,2,77,29 };
//	vector<int> fifth(myints, myints + sizeof(myints) / sizeof(int));
//	for (vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
//	{
//		cout << ' ' << *it;
//		cout << '\n';
//
//	}
//	system("pause");
//
//	return 0;
//}

void PrintVector(const vector<int>& v)
{
	vector<int>::const_iterator it = v.cbegin();
	while (it != v.cend())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}
//
//int main()
//{
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//	v.push_back(3);
//	v.push_back(2);
//	v.push_back(1);
//
//	vector<int>::iterator it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	it = v.begin();
//	while (it != v.end())
//	{
//		*it *= 2;
//		++it;
//	}
//
//	vector<int>::reverse_iterator rit = v.rbegin();
//	while (rit != v.rend())
//	{
//		cout << *rit << " ";
//		++rit;
//	}
//	cout << endl;
//
//	PrintVector(v);
//
//	system("pause");
//	return 0;
//}

// capacity 的代码在vs下按1.5倍增长，而gcc为2倍
//int main()
//{
//	size_t sz;
//	vector<int> foo;
//	sz = foo.capacity();
//	cout << "making foo grow:\n";
//	for (int i = 0; i < 100; ++i)
//	{
//		foo.push_back(i);
//		if (sz != foo.capacity())
//		{
//			sz = foo.capacity();
//			cout << "capacity changed:" << sz << '\n';
//		}
//	}
//	system("pause");
//	return 0;
//}

//vector的增删查改

//int main()
//{
//	int a[] = { 1,2,3,4,5,6,7 };
//	vector<int> v(a, a + sizeof(a) / sizeof(int));
//	//vector<int>::iterator it = v.begin();
//	//while (it != v.end())
//	//{
//	//	cout << *it << " ";
//	//	++it;
//	//}
//	PrintVector(v);
//
//	v.pop_back();
//
//	PrintVector(v);
//	vector<int>::iterator pos = find(v.begin(), v.end(), 3);
//	//在pos位置之前插入数据
//	v.insert(pos, 45);
//	PrintVector(v);
//	pos = find(v.begin(), v.end(), 3);
//	v.erase(pos);
//	PrintVector(v);
//	v[0] = 100;
//	for (size_t i = 0; i < v.size(); ++i)
//	{
//		cout << v[i] << " ";
//	}
//	cout << endl;
//
//	for (auto e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	vector <int> sswap;
//	sswap.swap(v);
//	PrintVector(sswap);
//	PrintVector(v);
//	system("pause");
//	return 0;
//}

//只出现一次的数字

class solution
{
public:
	int singlenNumber(vector<int>& nums)
	{
		int value = 0;
		for (size_t i = 0; i < nums.size(); ++i)
		{
			value ^= nums[i];
		}
		return value;
	}
};

//电话号码字母组合

string letterMap[10] = {"", "","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };

class solution2
{
public:
	void combineStr(const string digits, size_t index, const string str, vector<string> & strs)
	{
		if (index == digits.size())
		{
			strs.push_back(str);
			return;
		}

		string letters = letterMap[digits[index] - '0'];
		for (size_t i = 0; i < letters.size(); ++i)
		{
			combineStr(digits, index + 1, str + letters[i], strs);
		}
	}

	vector<string> letterCombinations(string digits)
	{
		vector<string>  strs;

		if (digits.empty())
		{
			return strs;
		}
		size_t index = 0;
		string str;
		combineStr(digits, index, str, strs);
		return strs;
	}
};

