#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

////�ҵ��ַ����е�һ��ֻ����һ�ε��ַ�
//class Solution {
//public:
//	int firstUniqChar(string s) {
//		int hashtable[26] = { 0 };
//		//ÿ���ַ����ֵĴ���
//		for (auto&e : s)
//		{
//			hashtable[e - 'a']++;
//		}
//		//����s�ַ������ַ����ֵ�˳���ҵ���һ��ֻ�������ε��ַ�
//		for (int i = 0; i < s.size(); i++)
//		{
//			if (hashtable[s[i] - 'a'] == 1)
//				return i;
//		}
//		return -1;
//	}
//};
//
//// �������һ���ַ����ĳ���
//int main()
//{
//	string s;
//	while (getline(cin, s))
//	{
//		//size_t�Ǹ�  ���Ҳ����ո�  ��Ϊpos���ֵnpos�������-1 �� -pos = 1  -pos-1 = 0  return size()
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
////�жϻ��ģ�����һ���ַ�������֤���Ƿ��ǻ��Ĵ���ֻ������ĸ�������ַ������Ժ�����ĸ�Ĵ�Сд��
//
//class Solution {
//public:
//	//Ҳ��ֱ�Ӱ��ַ����е�Сдת��д ֱ�ӱȽϾͺ�
//	//for (auto& e : s��
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
////�ַ������
//
////���������ַ�����ʽ�ķǸ����� num1 ��num2 ���������ǵĺ͡�
////
////ע�⣺
////
////num1 ��num2 �ĳ��ȶ�С�� 5100.
////num1 ��num2 ��ֻ�������� 0 - 9.
////num1 ��num2 ���������κ�ǰ���㡣
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
////Ҳ����ֱ�����  +=  ���� β��   Ȼ����reverse��ret.begin(),ret.end()) ����
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
////String ��
//
////��ȷ���޲ι��췽��
//
////����һ���ֽڴ�С�Ŀռ�  ���ڴ�ȡ'\0'
////new  ��������ҲҪ�ö�Ӧ��deleteɾ��
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
////���εĹ���  �ִ�д��
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
//	//��������:1.���ռ� 2.��������
//	//String(const String& s)
//	//	:_str(new char[strlen(s._str) + 1])
//	//{
//	//	strcpy(_str, s._str);
//	//}
//
//	//�ִ�д���� ���븴�� ���      �Լ����ɻ� ��������������Ƽ� ��������      ֱ�ӽ���ָ��ָ�� �����ɿ�������
//	String(const String& s)
//		:_str(nullptr)
//	{
//		String tmp(s._str);
//		swap(_str, tmp._str);
//	}
//	//��ֵ���������   ���  1.�ͷ�ԭ�пռ� 2.�����¿ռ� 3.��������
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
//	//�ִ�д�� 
//	//1.��ֵ ��������һ���ֲ���ʱ���� 
//	//2.����ʱ���󽻻�ָ��ָ�������Դ�ĸ��� ���������ݿ��� 
//	//3.��ʱ�����������ڽ������ͷ�ԭ�пռ�
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
//char s2[] = "\0";		  2	 "\0"��"\0"			   0
//char s3[] = "\\0";	  3	 "\"��"0"��"\0"		   2





