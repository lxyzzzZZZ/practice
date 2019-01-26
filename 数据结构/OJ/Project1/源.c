#include <stdio.h>
//删除链表中等于给定值 val 的所有节点。
 //Definition for singly-linked list.
 struct ListNode {
     int val;
     struct ListNode *next;
 };

struct ListNode* removeElements(struct ListNode* head, int val) {
	if (head == NULL){
		printf("链表为空\n");
		return NULL;
	}
	struct ListNode* cur = head;
	struct ListNode* prev = head->next;
	while (prev){
		if (prev->val == val){
			cur->next = prev->next;
			free(prev);
			prev = cur->next;
		}
		else{
			cur = cur->next;
			prev = cur->next;
		}
	}
	if (head->val == val){
		struct ListNode* old_head = head;
		head = head->next;
		free(old_head);
	}
	return head;
}

//反转一个单链表。
//
//示例 :
//
//输入 : 1->2->3->4->5->NULL
//输出 : 5->4->3->2->1->NULL
// 进阶 :
//你可以迭代或递归地反转链表。你能否用两种方法解决这道题
struct ListNode* reverseList(struct ListNode* head) {
	struct ListNode* Node = NULL;
	struct ListNode* cur;
	while (head){
		cur = head;
		head = head->next;
		cur->next = Node;
		Node = cur;
	}
	return Node;
}

//给定一个带有头结点 head 的非空单链表，返回链表的中间结点。
//
//如果有两个中间结点，则返回第二个中间结点。

struct ListNode* middleNode(struct ListNode* head){
	struct ListNode* fast = head;
	struct ListNode* slow = head;
	while (fast){
		fast = fast->next;
		if (fast == NULL){
			break;
		}
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}

//给定一个链表，找到链表的倒数第 n 个节点，并且返回。
//
//示例：
//

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
	if (head == NULL){
		printf("链表为空\n");
		return NULL;
	}
	struct ListNode* fast = head;
	struct ListNode* slow = head;
	for (; n > 0 && fast != NULL; n--){
		fast = fast->next;
	}
	if (fast == NULL){
		return NULL;
	}
	while (fast){
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}

//给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
//
//示例：
//
//给定一个链表 : 1->2->3->4->5, 和 n = 2.
//
//		 当删除了倒数第二个节点后，链表变为 1->2->3->5.
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
	if (head == NULL){
		printf("链表为空\n");
		return NULL;
	}
	struct ListNode* fast = head;
	struct ListNode* slow = head;
	for (; n > 0 && fast != NULL; n--){
		fast = fast->next;
	}
	if (fast == NULL){
		return slow->next;
	}
	while (fast->next){
		slow = slow->next;
		fast = fast->next;
	}
	struct ListNode* node = slow->next;
	slow->next = slow->next->next;
	free(node);
	return head;
}

//将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
//
//示例：
//
//输入：1->2->4, 1->3->4
//输出：1->1->2->3->4->4
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
	struct ListNode * ret;
	if (l1 == NULL && l2 == NULL){
		return NULL;
	}
	if (l1 == NULL){
		return l2;
	}
	if (l2 == NULL){
		return l1;
		    if(l1->val >= l2->val){
        ret = l2;
        l2 = l2->next;
    }
    else{
        ret = l1;
        l1 = l1->next;
    }
	if (l1->val >= l2->val){
		ret = l2;
		l2 = l2->next;
	}
	else{
		ret = l1;
		l1 = l1->next;
	}
	struct ListNode * head = ret;
	while (l1 && l2){
		if (l1->val <= l2->val){
			ret->next = l1;
			ret = ret->next;
			l1 = l1->next;
		}
		else{
			ret->next = l2;
			ret = ret->next;
			l2 = l2->next;
		}
	}
	if (l1 == NULL){
		ret->next = l2;
	}
	else{
		ret->next = l1;
	}
	return head;
}

//	请判断一个链表是否为回文链表。
//
//		示例 1:
//
//输入 : 1->2
//输出 : false
//	 示例 2 :
//
// 输入 : 1->2->2->1
//  输出 : true

struct ListNode* reverse(struct ListNode* head){
	if (head == NULL || head->next == NULL){
		return head;
	}
	struct ListNode* newhead = NULL;
	while (head){
		struct ListNode* ret = head->next;
		head->next = newhead;
		newhead = head;
		head = ret;
	}
	return newhead;
}
bool isPalindrome(struct ListNode* head) {
	if (head == NULL || head->next == NULL){
		return true;
	}
	struct ListNode *fast = head;
	struct ListNode *slow = head;
	while (fast){
		fast = fast->next;
		if (fast == NULL){
			break;
		}
		fast = fast->next;
		slow = slow->next;
	}
	slow = reverse(slow);
	fast = head;
	while (slow && head){
		if (fast->val != slow->val){
			return false;
		}
		fast = fast->next;
		slow = slow->next;
	}
	return true;
}

//给定一个链表，判断链表中是否有环。
bool hasCycle(struct ListNode *head) {
	struct ListNode* fast = head;
	struct ListNode* slow = head;
	while (fast != NULL && (fast = fast->next) != NULL){
		fast = fast->next;
		if (fast == NULL || fast->next == NULL){
			return false;
		}
		slow = slow->next;
		if (slow == fast){
			return true;
		}
	}
	return false;
}

//给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
//注意：快慢节点相遇的节点不是入环节点
struct ListNode *detectCycle(struct ListNode *head) {
	struct ListNode* fast = head;
	struct ListNode* slow = head;
	while (fast != NULL && (fast = fast->next) != NULL){
		fast = fast->next;
		if (fast == NULL || fast->next == NULL){
			return NULL;
		}
		slow = slow->next;
		if (slow == fast){
			break;
		}
	}
	if (fast != NULL){
		struct ListNode* node = head;
		while (slow != node){
			node = node->next;
			slow = slow->next;
		}
		return node;
	}
	return NULL;
}