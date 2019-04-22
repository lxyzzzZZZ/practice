#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

//求链表中的倒数第k个节点
//typedef struct LListNode {
//	int val;
//	LListNode* next;
//
//}LListNode,*LListNode;
//
//typedef struct head {
//	LListNode* head;
//}ListNode,*ListNode;
//ListNode* FindKthToTail(ListNode* head, unsigned int k)
//{
//	if (head == nullptr && k == 0)
//	{
//		return nullptr;
//	}
//	ListNode* p1 = head;
//	ListNode* p2 = head;
//	int len = 0;
//	while (p1)
//	{
//		++len;
//		p1 = p1->next;
//	}
//	p1 = head;
//	while (k)
//	{
//		p1 = p1->next;
//	}
//	while (p1->next != nullptr)
//	{
//		p1 = p1->next;
//		p2 = p2->next;
//	}
//	return p2;
//}

//字符串转数字
//
//int StrToInt(char* str)
//{
//
//	int num = 0;
//	int flag = 1;
//	if (*str == '-')
//	{
//		flag = -1;
//		str++;
//	}
//	else if (*str == '+')
//	{
//		str++;
//	}
//	while (str)
//	{
//		if (*str < 0 || *str > 9)
//		{
//			return NULL;
//		}
//		if(num)
//		num = num * 10 + *str - '0';
//		++str;
//	}
//	if (flag == -1)
//	{
//		num = -num;
//	}
//	return num;
//}

//int main()
//{
//	int i = 0;
//	for (; env[i]; i++)
//	{
//		printf("%s\n", env[i]);
//	}
//	return 0;
//}
//
//int main(int argc, char* argv[])
//{
//	extern char** environ;
//	int i = 0;
//	for (; environ[i]; i++)
//	{
//		printf("%s\n", environ[i]);
//	}
//	return 0;
//}
//
//int main()
//{
//	printf("%s\n", getenv("PATH"));
//	system("pause");
//	return 0;
//}
