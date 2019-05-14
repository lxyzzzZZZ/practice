#include <iostream>
#include <thread>
#include <mutex>


//饿汉模式

//构造函数私有
//防拷贝
//

class Singleton
{
public:
	static Singleton* Getinstance()
	{
		return &m_instance;
	}
private:
	Singleton(){}

	Singleton(Singleton const& Sin) = delete;
	Singleton& operator=(Singleton const& Sin) = delete;

	static Singleton m_instance;
};

Singleton Singleton::m_instance;


struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
};
class Solution {
public:
	bool isSubtree(TreeNode* s, TreeNode* t) {
		if (nullptr == t)
		{
			return true;
		}
		if (nullptr == s)
		{
			return false;
		}

		if (s->val != t->val)
		{
			return false;
		}

		return (isSubtree(s->left, t->left) && isSubtree(s->right, t->right));
	}
};

bool isSymmetrieal(TreeNode* root)
{
	return isSymmetrieal(root, root);
}

bool isSymmetrieal(TreeNode* rootA, TreeNode* rootB)
{
	TreeNode* ret = new TreeNode;
	if (rootA == nullptr && rootB == nullptr)
	{
		return true;
	}
	if (rootA == nullptr || rootB == nullptr)
	{
		return false;
	}
	if (rootA->val != rootB->val)
	{
		return false;
	}
	return isSymmetrieal(rootA->left, rootB->right)
		&& isSymmetrieal(rootA->right, rootB->left);
}
class Solution {
public:
	void flatten(TreeNode* root) {
		if (root == nullptr)
		{
			return;
		}
		flatten(root->left);
		flatten(root->right);
		TreeNode* tmp = root->right;
		root->right = root->left;
		root->left = nullptr;
		while (root->right != nullptr)
		{
			root = root->right;
		}
		root->right = tmp;
		return;
	}
};
