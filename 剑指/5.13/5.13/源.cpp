#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode* pNext;
};


ListNode* MeetingNode(ListNode* pHead)
{
	if (pHead == nullptr || pHead->pNext == nullptr)
	{
		return nullptr;
	}
	ListNode* slow = pHead->pNext;
	ListNode* fast = slow->pNext;
	while (slow != nullptr && fast != nullptr)
	{
		if (slow == fast)
		{
			return fast;
		}
		slow = slow->pNext;
		fast = fast->pNext;
		if (fast != nullptr)
		{
			fast = fast->pNext;
		}
	}
	return nullptr;
}

ListNode* EnterNodefloop(ListNode* pHead)
{
	ListNode* MeetNode = MeetingNode(pHead);
	if (MeetNode == nullptr)
	{
		return nullptr;
	}
	int len = 1;
	ListNode* pNode = MeetNode;
	while (pNode->pNext != MeetNode)
	{
		pNode = pNode->pNext;
		++len;
	}
	ListNode* Fast = pHead;
	for (int i = 0; i < len; ++i)
	{
		Fast = Fast->pNext;
	}
	ListNode* Slow = pHead;
	while (Slow != Fast)
	{
		Slow = Slow->pNext;
		Fast = Fast->pNext;
	}
	return Fast;
}


ListNode* ReverseList(ListNode* pHead)
{
	if(pHead == nullptr)
	{
		return nullptr;
	}
	ListNode* pNode = pHead->pNext;
	ListNode* rHead = pHead;
	while (pNode != nullptr)
	{
		ListNode* ret = pNode->pNext;
		pNode->pNext = rHead;
		rHead = pNode;
		pNode = ret;
	}
	return rHead;
}

ListNode* Merge(ListNode* AHead, ListNode* BHead)
{
	if (AHead == nullptr && BHead == nullptr)
	{
		return nullptr;
	}
	else if (AHead == nullptr && BHead != nullptr)
	{
		return BHead;
	}
	else
	{
		return AHead;
	}
	ListNode* NewHead = nullptr;
	if (AHead->val <= BHead->val)
	{
		NewHead = AHead;
		AHead = AHead->pNext;
	}
	else
	{
		NewHead = BHead;
		BHead = BHead->pNext;
	}
	while (AHead != nullptr || BHead != nullptr)
	{
		if (AHead == nullptr)
		{
			NewHead->pNext = BHead;
			break;
		}
		if (BHead == nullptr)
		{
			NewHead->pNext = AHead;
			break;
		}
		ListNode* pNode = nullptr;
		if (AHead->val <= BHead->val)
		{
			pNode = AHead;
			AHead = AHead->pNext;
			NewHead = pNode;
			pNode->pNext = nullptr;
		}
		else
		{
			pNode = BHead;
			BHead = BHead->pNext;
			NewHead = pNode;
			pNode->pNext = nullptr;
		}
	}
	return NewHead;
}

ListNode* Merge(ListNode* Ahead, ListNode* Bhead)
{
	if (Ahead == nullptr)
	{
		return Bhead;
	}
	if (Bhead == nullptr)
	{
		return Ahead;
	}
	ListNode* NewHead = nullptr;
	if (Ahead->val <= Bhead->val)
	{
		NewHead = Ahead;
		NewHead->pNext = Merge(Ahead->pNext, Bhead);
	}
	else
	{

		NewHead = Bhead;
		NewHead->pNext = Merge(Ahead, Bhead->pNext);
	}
	return NewHead;
}
