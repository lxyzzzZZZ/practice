#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
};

void DeleteNOde(ListNode** head, ListNode* pToBeDeleted)
{
	if (!head || !pToBeDeleted)
	{
		return;
	}
	if (pToBeDeleted->next != nullptr)
	{
		ListNode* pnext = pToBeDeleted->next;
		pToBeDeleted->val = pnext->val;
		pToBeDeleted->next = pnext->next;
	}
	else if (*head == pToBeDeleted)
	{
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
		*head = nullptr;
	}
	else
	{
		ListNode* pNode = *head;
		while (pNode->next != pToBeDeleted)
		{
			pNode = pNode->next;
		}
		pNode->next = nullptr;
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
	}
}