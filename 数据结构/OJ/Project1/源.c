#include <stdio.h>
//ɾ�������е��ڸ���ֵ val �����нڵ㡣
 //Definition for singly-linked list.
 struct ListNode {
     int val;
     struct ListNode *next;
 };

struct ListNode* removeElements(struct ListNode* head, int val) {
	if (head == NULL){
		printf("����Ϊ��\n");
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

//��תһ��������
//
//ʾ�� :
//
//���� : 1->2->3->4->5->NULL
//��� : 5->4->3->2->1->NULL
// ���� :
//����Ե�����ݹ�ط�ת�������ܷ������ַ�����������
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

//����һ������ͷ��� head �ķǿյ���������������м��㡣
//
//����������м��㣬�򷵻صڶ����м��㡣

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

//����һ�������ҵ�����ĵ����� n ���ڵ㣬���ҷ��ء�
//
//ʾ����
//

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
	if (head == NULL){
		printf("����Ϊ��\n");
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

//����һ������ɾ������ĵ����� n ���ڵ㣬���ҷ��������ͷ��㡣
//
//ʾ����
//
//����һ������ : 1->2->3->4->5, �� n = 2.
//
//		 ��ɾ���˵����ڶ����ڵ�������Ϊ 1->2->3->5.
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
	if (head == NULL){
		printf("����Ϊ��\n");
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

//��������������ϲ�Ϊһ���µ������������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ�
//
//ʾ����
//
//���룺1->2->4, 1->3->4
//�����1->1->2->3->4->4
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

//	���ж�һ�������Ƿ�Ϊ��������
//
//		ʾ�� 1:
//
//���� : 1->2
//��� : false
//	 ʾ�� 2 :
//
// ���� : 1->2->2->1
//  ��� : true

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

//����һ�������ж��������Ƿ��л���
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

//����һ��������������ʼ�뻷�ĵ�һ���ڵ㡣 ��������޻����򷵻� null��
//ע�⣺�����ڵ������Ľڵ㲻���뻷�ڵ�
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