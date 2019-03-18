//编写一个程序，找到两个单链表相交的起始节点。
//
//如下面的两个链表：
//
//
//
//在节点 c1 开始相交。
///**
//* Definition for singly-linked list.
//* struct ListNode {
//*     int val;
//*     struct ListNode *next;
//* };
//*/
//struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
//	struct ListNode * ra = headA;
//	struct ListNode * rb = headB;
//	int l1 = 0;
//	int l2 = 0;
//	while (ra != NULL){
//		l1++;
//		ra = ra->next;
//	}
//	while (rb != NULL){
//		l2++;
//		rb = rb->next;
//	}
//	int k = 0;
//	ra = headA;
//	rb = headB;
//	if (l2 > l1){
//		k = l2 - l1;
//		while (k){
//			rb = rb->next;
//			k--;
//		}
//	}
//	else{
//		k = l1 - l2;
//		while (k){
//			ra = ra->next;
//			k--;
//		}
//	}
//	while (ra && rb){
//		if (ra == rb){
//			return ra;
//		}
//		ra = ra->next;
//		rb = rb->next;
//	}
//	return NULL;
//}
//
//给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。
//
//示例 1:
//
//输入 : 1->2->3->4->5->NULL, k = 2
//输出 : 4->5->1->2->3->NULL
// 解释 :
//向右旋转 1 步 : 5->1->2->3->4->NULL
//向右旋转 2 步 : 4->5->1->2->3->NULL
//
///**
//* Definition for singly-linked list.
//* struct ListNode {
//*     int val;
//*     struct ListNode *next;
//* };
//*/
//struct ListNode* rotateRight(struct ListNode* head, int k) {
//	if (head == NULL){
//		return NULL;
//	}
//	if (head->next == NULL || k == 0){
//		return head;
//	}
//	int len = 0;
//	struct ListNode* r = head;
//	while (r != NULL){
//		r = r->next;
//		len++;
//	}
//	k %= len;
//	for (int i = 0; i < k; i++){
//		struct ListNode* r1 = head;
//		struct ListNode* r2 = head;
//		while (r2->next->next != NULL){
//			r2 = r2->next;
//		}
//		r1 = r2->next;
//		r2->next = NULL;
//		r1->next = head;
//		head = r1;
//	}
//	return head;
//}