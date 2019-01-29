//
//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
//
//有效字符串需满足：
//
//左括号必须用相同类型的右括号闭合。
//左括号必须以正确的顺序闭合。
//注意空字符串可被认为是有效字符串。
//
//bool isValid(char* s) {
//	char *p = s;
//	Stack stack;
//	StackInit(&stack);
//	while (*p != '\0') {
//		switch (*p) {
//		case '{':
//		case '[':
//		case '(':
//			StackPush(&stack, *p);
//			break;
//		case '}':
//		case ']':
//		case ')': {
//					  if (StackEmpty(&stack)) {
//						  // 左括号少于右括号
//						  return false;
//					  }
//
//					  char left = StackTop(&stack);
//					  StackPop(&stack);
//					  if (!((left == '(' && *p == ')')
//						  || (left == '[' && *p == ']')
//						  || (left == '{' && *p == '}'))) {
//
//						  // 左右括号不匹配
//						  return false;
//					  }
//		}
//			break;
//		}
//
//		p++;
//	}
//
//	if (!StackEmpty(&stack)) {
//		// 左括号多于右括号
//		return false;
//	}
//
//	return true;
//}



/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
//给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
//
//如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
//
//您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
//struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
//	int carry = 0;
//	struct ListNode* l3 = NULL;
//	while (l1 != NULL || l2 != NULL){
//		int x = 0;
//		int y = 0;
//		if (l1 != NULL){
//			int x = l1->val;
//		}
//		if (l2 != NULL){
//			int y = l2->val;
//		}
//		int sum = x + y + carry;
//		carry = sum / 10;
//		l3->next->val = sum % 10;
//		l3->next->next = NULL;
//		if (l1 != NULL){
//			l1 = l1->next;
//		}
//		if (l2 != NULL){
//			l2 = l2->next;
//		}
//	}
//	return l3->next;
//}
//public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
//	ListNode dummyHead = new ListNode(0);
//	ListNode p = l1, q = l2, curr = dummyHead;
//	int carry = 0;
//	while (p != null || q != null) {
//		int x = (p != null) ? p.val : 0;
//		int y = (q != null) ? q.val : 0;
//		int sum = carry + x + y;
//		carry = sum / 10;
//		curr.next = new ListNode(sum % 10);
//		curr = curr.next;
//		if (p != null) p = p.next;
//		if (q != null) q = q.next;
//	}
//	if (carry > 0) {
//		curr.next = new ListNode(carry);
//	}
//	return dummyHead.next;
//}