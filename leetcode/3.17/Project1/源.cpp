//���дһ��������ʹ�����ɾ��ĳ�������и����ģ���ĩβ���ڵ㣬�㽫ֻ������Ҫ��ɾ���Ľڵ㡣
//
//����һ������ -- head = [4, 5, 1, 9]�������Ա�ʾΪ:
//
//
//
//
//
//ʾ�� 1:
//
//���� : head = [4, 5, 1, 9], node = 5
//��� : [4, 1, 9]
// ���� : ������������ֵΪ 5 �ĵڶ����ڵ㣬��ô�ڵ�������ĺ���֮�󣬸�����Ӧ��Ϊ 4 -> 1 -> 9.
//
//	  /**
//	  * Definition for singly-linked list.
//	  * struct ListNode {
//	  *     int val;
//	  *     struct ListNode *next;
//	  * };
//	  */
//	  void deleteNode(struct ListNode* node) {
//		  *node = *(node->next);
//		  return;
//	  }
//
//
//	 ����һ���������飬�ж��Ƿ�����ظ�Ԫ�ء�
//
//		 ����κ�ֵ�������г����������Σ��������� true�����������ÿ��Ԫ�ض�����ͬ���򷵻� false��
//
//		 ʾ�� 1:
//
// ���� : [1, 2, 3, 1]
// ��� : true
//
//	 class Solution {
//	 public:
//		 bool containsDuplicate(vector<int>& nums) {
//			 if (nums.size() <= 1){
//				 return false;
//			 }
//			 sort(nums.begin(), nums.end());
//			 for (int i = 0; i < nums.size() - 1; i++){
//				 if (nums[i] == nums[i + 1]){
//					 return true;
//				 }
//			 }
//			 return false;
//		 }
//	 };