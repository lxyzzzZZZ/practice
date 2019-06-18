//删除链表中等于给定值 val 的所有节点。
//
//示例 :
//
//输入 : 1->2->6->3->4->5->6, val = 6
//输出 : 1->2->3->4->5
//	 /**
//	 * Definition for singly-linked list.
//	 * struct ListNode {
//	 *     int val;
//	 *     ListNode *next;
//	 *     ListNode(int x) : val(x), next(NULL) {}
//	 * };
//	 */
//class Solution {
//public:
//	ListNode* removeElements(ListNode* head, int val) {
//		if (head == NULL)
//		{
//			return NULL;
//		}
//		struct ListNode* prev = head;
//		struct ListNode* cur = head->next;
//		while (cur)
//		{
//			if (cur->val == val)
//			{
//				prev->next = cur->next;
//				free(cur);
//				cur = prev->next;
//			}
//			else
//			{
//				prev = cur;
//				cur = cur->next;
//			}
//		}
//		struct ListNode* newhead = head;
//		if (head->val == val)
//		{
//			newhead = head->next;
//			free(head);
//		}
//		return newhead;
//	}
//};
//反转一个单链表。
//
//示例 :
//
//输入 : 1->2->3->4->5->NULL
//输出 : 5->4->3->2->1->NULL
//	 /**
//	 * Definition for singly-linked list.
//	 * struct ListNode {
//	 *     int val;
//	 *     ListNode *next;
//	 *     ListNode(int x) : val(x), next(NULL) {}
//	 * };
//	 */
//class Solution {
//public:
//	ListNode* reverseList(ListNode* head) {
//		struct ListNode* s1 = NULL;
//		struct ListNode* s2;
//		while (head)
//		{
//			s2 = head;
//			head = head->next;
//
//			s2->next = s1;
//			s1 = s2;
//		}
//		return s1;
//	}
//};