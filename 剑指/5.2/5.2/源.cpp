#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode* Next;
};
void DelteDuplication(ListNode** pHead)
{
	if (pHead == nullptr || *pHead == nullptr)
	{
		return;
	}
	ListNode* pPreNode = nullptr;
	ListNode* pNode = *pHead;
	while (pNode != nullptr)
	{
		ListNode *pNext = pNode->Next;
		bool needDlete = false;
		if (pNode != nullptr && pNext->val == pNode->val)
		{
			needDlete = true;
		}
		if (!needDlete)
		{
			pPreNode = pNode;
			pNode = pNode->Next;
		}
		else
		{
			int val = pNode->val;
			ListNode* pToBeDel = pNode;
			while (pToBeDel != nullptr && pToBeDel->val == val)
			{
				pNext = pToBeDel->Next;
				delete pToBeDel;
				pToBeDel = nullptr;
				pToBeDel = pNext;
			}
			if (pPreNode == nullptr)
			{
				*pHead = pNext;
			}
			else
			{
				pPreNode->Next = pNext;
			}
			pNode = pNext;
		}
	}
}