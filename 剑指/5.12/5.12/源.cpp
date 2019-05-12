#include <iostream>

using namespace std;


struct ListNode
{
	int val;
	ListNode* pNext;
};

ListNode* FindKthToTail(ListNode* pHead, unsigned int k)
{
	if (pHead == nullptr || k == 0)
	{
		return nullptr;
	}
	ListNode* ret = pHead;
	for (int i = 0; i < k - 1; ++i)
	{
		if (ret->pNext != nullptr)
		{
			ret = ret->pNext;
		}
		//k大于链表长度
		else
		{
			return nullptr;
		}
	}
	ListNode* pAhead = pHead;
	while (ret->pNext != nullptr)
	{
		ret = ret->pNext;
		pAhead = pAhead->pNext;
	}

	return pAhead;
	
}