//请编写一个函数，使其可以删除某个链表中给定的（非末尾）节点，你将只被给定要求被删除的节点。
//
//现有一个链表 -- head = [4, 5, 1, 9]，它可以表示为:
//
//
//
//
//
//示例 1:
//
//输入 : head = [4, 5, 1, 9], node = 5
//输出 : [4, 1, 9]
// 解释 : 给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.
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
//	 给定一个整数数组，判断是否存在重复元素。
//
//		 如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。
//
//		 示例 1:
//
// 输入 : [1, 2, 3, 1]
// 输出 : true
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