#include <iostream>
#include <deque>
#include <stack>
#include <vector>
using namespace std;

//deque :本质是指针数组

//物理不连续  逻辑连续的数组


//随机访问（随机访问的效率低于vector）、增容代价小、头插头删、
//尾插尾删为O（1）、内存利用率高、内存碎片少
void PrintDeque(const deque<int>& d)
{ 
	for (const auto& e : d)
	{
		cout << e << " ";
	}
	cout << endl;
}



//最小栈
class MinStack
{
public :
	MinStack()
	{

	}
	void push(int x)
	{
		_elem.push(x);
		if (_min.top() == _elem.top())
		{
			_min.pop();
		}
		_elem.pop();
	}
	int top()
	{
		return _elem.top();
	}
	int getMin()
	{
		return _min.top;
	}
	int getMin()
	{
		return _min.top();
	}
private:
	stack<int> _elem;
	stack<int> _min;
};

//栈的压入  弹出序列
class solution
{
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV)
	{
		stack<int> st;
		int pushIdx = 0;
		int popIdx = 0;
		int sz = pushV.size();
		while (pushIdx < sz)
		{
			st.push(pushV[pushIdx++]);
			while (st.top() == popV[popIdx] && !st.empty())
			{
				st.pop();
				++popIdx;
			}
		}
		return st.empty();
	}
};

//逆波兰表达式

class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> st;
		int sz = tokens.size();
		for (int i = 0; i < sz; i++)
		{
			string num = tokens[i];
			if (num == "+" || num == "-"
				|| num == "*" || num == "/")
			{
				int right = st.top();
				st.pop();
				int left = st.top();
				st.pop();
				if (num == "+")
				{
					st.push(left + right);
				}
				if (num == "-")
				{
					st.push(left - right);
				}
				if (num == "*")
				{
					st.push(left * right);
				}
				if (num == "/")
				{
					st.push(left / right);
				}
			}
			else
			{
				st.push(atoi(num.c_str()));
			}
		}
		return st.top();
	}
};

//二叉树的前序遍历


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution2 {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> treeVec;
		stack<TreeNode*> st;
		TreeNode* cur = root;
		while (cur || !st.empty())
		{
			while (cur)
			{
				treeVec.push_back(cur->val);
				st.push(cur);
				cur = cur->left;
			}

			cur = st.top();
			st.pop();
			cur = cur->right;
		}

		return treeVec;
	}
};

///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     TreeNode *left;
// *     TreeNode *right;
// *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// * };
// */
//class Solution {
//public:
//	bool getPath(TreeNode* root, TreeNode* p, stack<TreeNode*> st)
//	{
//		if (root == nullptr)
//		{
//			return false;
//		}
//		st.push(root);
//		if (root == p)
//		{
//			return true;
//		}
//		if (getPath(root->left, p, st))
//		{
//			return true;
//		}
//		if (getPath(root->right, p, st))
//		{
//			return true;
//		}
//		st.pop();
//		return false;
//	}
//	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//		stack<TreeNode*> path1;
//		stack<TreeNode*> path2;
//		getPath(root, p, path1);
//		getPath(root, q, path2);
//		while (path1.size() != path2.size())
//		{
//			if (path1.size() > path2.size())
//			{
//				path1.pop();
//
//			}
//			else
//			{
//				path2.pop();
//			}
//			while (!path1.empty())
//			{
//				if (path1.top() == path2.top())
//				{
//					break;
//				}
//				else
//				{
//					path1.pop();
//					path2.pop();
//				}
//			}
//			return path1.top();
//		}
//	}
//};