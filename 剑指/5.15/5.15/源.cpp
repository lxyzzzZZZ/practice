#include <iostream>
#include<queue>
using namespace std;


struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
};
void Print(TreeNode* root)
{
	if (root == nullptr)
	{
		return;
	}
	queue<TreeNode*> ret;
	ret.push(root);
	int tobePrint = 1;
	int level = 0;
	while (!ret.empty())
	{
		TreeNode* pNode = ret.front();
		cout << pNode->val << " ";
		if (pNode->left != nullptr)
		{
			ret.push(pNode->left);
			level++;
		}
		if (pNode->right != nullptr)
		{	
			ret.push(pNode->right);
			level++;
		}
		ret.pop();
		tobePrint--;
		if (tobePrint == 0)
		{
			cout << endl;
			tobePrint = level;
			level = 0;
		}
	}

}

int MoreThanHalfNum(int* num, int length)
{
	if (num == nullptr || length <= 0)
	{
		return 0;
	}
	int Most = *num;
	int count = 1;
	for (int i = 1; i < length; i++)
	{
		if (count == 0)
		{
			Most = num[i];
			count = 1;
		}
		else if (Most == num[i])
		{
			count++;
		}
		else
		{
			count--;
		}
	}

	return Most;
	
}

//int main()
//{
//	int* num = nullptr;
//
//	cout << MoreThanHalfNum(num, 0) << endl;
//	system("pause");
//	return 0;
//}