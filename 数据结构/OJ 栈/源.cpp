//
//����һ��ֻ���� '('��')'��'{'��'}'��'['��']' ���ַ������ж��ַ����Ƿ���Ч��
//
//��Ч�ַ��������㣺
//
//�����ű�������ͬ���͵������űպϡ�
//�����ű�������ȷ��˳��պϡ�
//ע����ַ����ɱ���Ϊ����Ч�ַ�����
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
//						  // ����������������
//						  return false;
//					  }
//
//					  char left = StackTop(&stack);
//					  StackPop(&stack);
//					  if (!((left == '(' && *p == ')')
//						  || (left == '[' && *p == ']')
//						  || (left == '{' && *p == '}'))) {
//
//						  // �������Ų�ƥ��
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
//		// �����Ŷ���������
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
//�������� �ǿ� ������������ʾ�����Ǹ������������У����Ǹ��Ե�λ���ǰ��� ���� �ķ�ʽ�洢�ģ��������ǵ�ÿ���ڵ�ֻ�ܴ洢 һλ ���֡�
//
//��������ǽ��������������������᷵��һ���µ���������ʾ���ǵĺ͡�
//
//�����Լ���������� 0 ֮�⣬���������������� 0 ��ͷ��
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