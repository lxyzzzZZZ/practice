#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
};

//之型打印树

void Print(TreeNode* root)
{
	if (nullptr == root)
	{
		return;
	}
	stack<TreeNode*> level[2];
	//表示当前需要打印的层，既当前stack的下标
	int currt = 0;		
	//表示下层需要打印的下标
	int next = 1;
	level[currt].push(root);
	while (level != nullptr)
	{
		//新建一个节点，保存但钱需要打印的节点
		TreeNode* pNode = level[currt].top();
		level[currt].pop();
		cout << pNode->val << " ";

		if (currt == 0)		//即为“奇数层” 先存入左节点
		{
			if (nullptr != pNode->left)
			{
				level[next].push(pNode->left);
			}
			if (nullptr != pNode->right)
			{
				level[next].push(pNode->right);
			}
				
		}
		else
		{
			if (nullptr != pNode->right)
			{
				level[next].push(pNode->right);
			}
			if (nullptr != pNode->left)
			{
				level[next].push(pNode->left);
			}
		}
		if (level[currt].empty)		//当当前遍历层  全部打印完毕 则 交换next 与 currt
		{
			cout << endl;
			currt = 1 - currt;
			next = 1 - next;
		}
	}
}


//验证二叉搜索树
//
//class Solution {
//public:
//	bool isValidBST(TreeNode* root) {
//		if (root->left != nullptr && root->left->val > root->val)
//		{
//			return false;
//		}
//		if (root->right != nullptr && root->right->val < root->val)
//		{
//			return false;
//		}
//
//		return isValidBST(root->left) && isValidBST(root->right);
//	}
//};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//class Tree
//{
//	Tree(TreeNode* left = nullptr, TreeNode* right = nullptr, int val = 0)
//	{
//		_root->left = left;
//		_root->right = right;
//		_root->val = val;
//	}
//	Tree(const Tree& root)
//	{
//		_root = root._root;
//	}
//	void push_left(int val)
//	{
//		TreeNode* NewNode = new TreeNode;
//		NewNode->left = nullptr;
//		NewNode->right = nullptr;
//		NewNode->val = val;
//
//		_root->
//	}
//private:
//	TreeNode* _root;
//};



class Solution {
public:
	bool isValidBST2(TreeNode* root, TreeNode* ret)
	{
		if (root != nullptr)
		{
			if (isValidBST2(root->left, ret) == false)
			{
				return false;
			}
			if (ret != nullptr && root->val <= ret->val)
			{
				return false;
			}
			ret = root;
			if (isValidBST2(root->right, ret) == false)
			{
				return false;
			}
		}

		return true;
	}
	bool isValidBST(TreeNode* root) {
		TreeNode* ret = nullptr;
		return isValidBST2(root, ret);
	}
};


//二叉树中和为某一值的路径
void FindPath(TreeNode* root, const int num)
{
	vector<int> find;
	int sum = 0;
	FindPath(root, num, find, sum);
}

void FindPath(TreeNode* root, const int num, vector<int> find, int sum)
{
	sum += root->val;
	find.push_back(root->val);

	// 因为如果存在负数  所以需要加上判断左右子节点 是否为空
	if (sum == num && root->left == nullptr && root->right == nullptr)
	{
		vector<int> ::iterator it = find.begin();
		while (it != find.end())
		{
			cout << *it << " ";
			it++;
		}
		cout << endl;
	}

	if (root->left != nullptr)
	{
		FindPath(root->left, num, find, sum);
	}
	if (root->right != nullptr)
	{
		FindPath(root->right, num, find, sum);
	}

	//sum -= find.back();
	find.pop_back();

}


/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
	vector<vector<int>> path;
	vector<int> find;
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		if (root != nullptr)
			Find(root, expectNumber);
		return path;
	}
	void Find(TreeNode* root, int expectNumber)
	{

		find.push_back(root->val);

		// 因为如果存在负数  所以需要加上判断左右子节点 是否为空
		if (expectNumber - root->val == 0 && root->left == nullptr && root->right == nullptr)
		{
			path.push_back(find);
		}

		if (root->left != nullptr)
		{
			Find(root->left, expectNumber - root->val);
		}
		if (root->right != nullptr)
		{
			Find(root->right, expectNumber - root->val);
		}


		find.pop_back();
	}

};