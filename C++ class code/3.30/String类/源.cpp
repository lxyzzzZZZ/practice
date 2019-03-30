#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

////找到字符串中第一个只出现一次的字符
//class Solution {
//public:
//	int firstUniqChar(string s) {
//		int hashtable[26] = { 0 };
//		//每个字符出现的次数
//		for (auto&e : s)
//		{
//			hashtable[e - 'a']++;
//		}
//		//按照s字符串的字符出现的顺序，找到第一个只出现依次的字符
//		for (int i = 0; i < s.size(); i++)
//		{
//			if (hashtable[s[i] - 'a'] == 1)
//				return i;
//		}
//		return -1;
//	}
//};
//
//// 查找最后一个字符串的长度
//int main()
//{
//	string s;
//	while (getline(cin, s))
//	{
//		//size_t非负  若找不到空格  则为pos最大值npos（相等于-1 ） -pos = 1  -pos-1 = 0  return size()
//		size_t pos = s.rfind(" "); 
//		//cout << s.size() - pos - 1 << endl;
//		if (pos == string::npos)
//		{
//			cout << s.size() << endl;
//		}
//		else
//		{
//			cout << s.size() - pos - 1 << endl;
//		}
//	}
//	return 0;
//}
//
////判断回文：给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
//
//class Solution {
//public:
//	//也可直接吧字符串中的小写转大写 直接比较就好
//	//for (auto& e : s）
//	//{
//	//	if (e >= 'a')
//	//	{
//
//	//		e -= 32;
//	//	}
//	//}
//	bool isNumberLetter(char c)
//	{
//		return ((c >= '0' && c <= '9') ||
//			(c >= 'a' && c <= 'z') ||
//			(c >= 'A' && c <= 'Z'));
//	}
//	bool isPalindrome(string s) {
//		int begin = 0;
//		int end = s.size() - 1;
//		while (begin < end)
//		{
//			while (begin < end)
//			{
//				if (isNumberLetter(s[begin]))
//				{
//					break;
//				}
//				begin++;
//			}
//			while (begin < end)
//			{
//				if (isNumberLetter(s[end]))
//				{
//					break;
//				}
//				end--;
//			}
//			if (begin < end)
//			{
//				if ((s[begin] + 32 - 'a') % 32 != (s[end] + 32 - 'a') % 32)
//				{
//					return false;
//				}
//			}
//			begin++;
//			end--;
//		}
//		return true;
//	}
//};
//
////字符串相加
//
////给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。
////
////注意：
////
////num1 和num2 的长度都小于 5100.
////num1 和num2 都只包含数字 0 - 9.
////num1 和num2 都不包含任何前导零。
//
//class Solution {
//public:
//	string addStrings(string num1, string num2) {
//		int len1 = num1.size() - 1;
//		int len2 = num2.size() - 1;
//		string ret;
//		int step = 0;
//		while (len1 >= 0 || len2 >= 0)
//		{
//			int curSum = 0;
//			curSum += step;
//
//			if (len1 >= 0)
//			{
//				curSum += num1[len1] - '0';
//			}
//			if (len2 >= 0)
//			{
//				curSum += num2[len2] - '0';
//			}
//			step = curSum / 10;
//			curSum %= 10;
//			ret.insert(0, 1, curSum + '0');
//			len1--;
//			len2--;
//		}
//		if (step == 1)
//		{
//			ret.insert(0, 1, '1');
//		}
//		return ret;
//	}
//};
//
////也可先直接相加  +=  即是 尾插   然后用reverse（ret.begin(),ret.end()) 逆置
//class Solution 
//{
//public:
//	string addStrings(string num1, string num2) {
//		int len1 = num1.size() - 1;
//		int len2 = num2.size() - 1;
//		string ret;
//		int step = 0;
//		while (len1 >= 0 || len2 >= 0)
//		{
//			int curSum = 0;
//			curSum += step;
//
//			if (len1 >= 0)
//			{
//				curSum += num1[len1] - '0';
//			}
//			if (len2 >= 0)
//			{
//				curSum += num2[len2] - '0';
//			}
//			step = curSum / 10; 
//			curSum %= 10;
//			ret += curSum + '0';
//			len1--;
//			len2--;
//		}
//		if (step == 1)
//		{
//			ret += '1';
//		}
//		reverse(ret.begin(), ret.end());
//		return ret;
//	}
//};
//
////String 类
//
////正确的无参构造方法
//
////申请一个字节大小的空间  用于存取'\0'
////new  所以析构也要用对应的delete删除
//class strings
//{
//public:
//	strings()
//	:_str(new char[1])
//	{
//		_str[0] = '\0';
//	}
//	~strings()
//	{
//		if (_str)
//		{
//			delete(_str);
//			_str = nullptr;
//		}
//	}
//private:
//	char* _str;
//};
//
////带参的构造  现代写法
//
//class String
//{
//public:
//	String(char* str = "")
//	{
//		assert(str != nullptr);
//		_str = new char[strlen(str) + 1];
//		strcpy(_str, str);
//	}
//	//拷贝构造:1.开空间 2.拷贝内容
//	//String(const String& s)
//	//	:_str(new char[strlen(s._str) + 1])
//	//{
//	//	strcpy(_str, s._str);
//	//}
//
//	//现代写法： 代码复用 简洁      自己不干活 让其他对象申请科技 拷贝内容      直接交换指针指向 间接完成拷贝构造
//	String(const String& s)
//		:_str(nullptr)
//	{
//		String tmp(s._str);
//		swap(_str, tmp._str);
//	}
//	//赋值运算符重载   深拷贝  1.释放原有空间 2.开辟新空间 3.拷贝内容
//	//String& operator=(const String& s)
//	//{
//	//	if (this != &s)
//	//	{
//	//		delete[] _str;
//	//		_str = new char[strlen(s._str) + 1];
//	//		strcpy(_str, s._str);
//	//	}
//	//	return *this;
//	//}
//
//	//现代写法 
//	//1.传值 拷贝构造一个局部临时对象 
//	//2.与临时对象交换指针指向，完成资源的更换 间接完成内容拷贝 
//	//3.临时对象生命周期结束，释放原有空间
//	String& operator=(String& s)
//	{
//		swap(_str, s._str);
//		return *this;
//	}
//	~String() 
//	{
//		if (_str)
//		{
//			delete(_str);
//			_str = nullptr;
//		}
//	}
//private:
//	char* _str;
//};

//char s1[] = "";  sizeof 1	 "\0"			strlen 0
//char s2[] = "\0";		  2	 "\0"、"\0"			   0
//char s3[] = "\\0";	  3	 "\"、"0"、"\0"		   2





