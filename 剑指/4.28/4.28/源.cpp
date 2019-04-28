#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
};

//链尾加一个节点
void AddToTail(ListNode** head, int val)
{
	ListNode* New = new ListNode();
	New->val = val;
	New->next = nullptr;
	if (*head == nullptr)
	{
		*head = New;
	}
	else
	{
		ListNode* Node = *head;
		while (Node->next != nullptr)
		{
			Node = Node->next;
		}
		Node->next = New;
	}
}


//找到给定节点 删除

void RemoveNode(ListNode** head, int val)
{
	if (head == nullptr&&*head == nullptr)
	{
		return;
	}
	ListNode* ret = nullptr;
	if ((*head)->val == val)
	{
		ret = *head;
		*head = (*head)->next;
	}
	else
	{
		ListNode* Node = *head;
		while (Node->next != nullptr&&Node->next->val != val)
		{
			if (Node->next != nullptr&&Node->next->val == val)
			{
				ret = Node->next;
				Node->next = Node->next->next;
			}
			Node = Node->next;
		}
	}
	if (ret != nullptr)
	{
		delete  ret;
		ret = nullptr;
	}
}