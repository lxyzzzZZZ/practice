#include <iostream>
#include <stack>
#include <queue>
#include <deque>
using namespace std;


struct BinaryTreeNode
{
	int val;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
};



//栈的压入与弹出序列
static bool IsPoporder(const int* pPush, const int* pPop, int length)
{
	if (pPush == nullptr && pPop == nullptr && length == 0)
	{
		return true;
	}
	bool flag = false;
	if (pPush != nullptr && pPop != nullptr && length > 0)
	{
		const int* pPushNext = pPush;
		const int* pPopNext = pPop;
		stack<int> ret;
		while (pPopNext - pPop < length)
		{
			//将压入序列依次压入辅助栈 直到辅助栈顶的元素等于弹出序列的栈顶跳出
			while (ret.empty() || ret.top() != *pPopNext)
			{
				if (pPushNext - pPush == length)
				{
					break;
				}
				ret.push(*pPushNext);
				pPushNext++;
			}
			//若压入栈全部压入辅助栈 都没有找到与弹出栈顶相等的元素则false
			if (ret.top() != *pPopNext)
			{
				break;
			}
			ret.pop();
			pPopNext++;
		}
		//如果辅助序列为空 切元素全部弹出则为true
		if (pPopNext - pPop == length && ret.empty())
		{
			flag = true;
		}
	}
	return flag;
}


//层序输出树
void PrintFromTopBottom(BinaryTreeNode* Treeroot)
{
	if (Treeroot == nullptr)
	{
		return;
	}
	//用队列存取树的节点
	deque<BinaryTreeNode*>  ret;
	//将根节点尾插入队列
	ret.push_back(Treeroot);
	while (ret.size() > 0)
	{
		//用一个树节点存储队列前节点 用于输出
		BinaryTreeNode* pNode = ret.front();
		//因为头结点已有数据接收  所以删除 保证输出顺序正确
		//且便于遍历右节点
		ret.pop_front();

		cout << pNode->val << " ";

		//将pNode的左右子节点尾插入队列
		if (pNode->left)
		{
			ret.push_back(pNode->left);
		}
		if (pNode->right)
		{
			ret.push_back(pNode->right);
		}
	}
}



int main()
{
	int a[] = { 1,2,3,4,5 };
	int b[] = { 4,6,3,2,1 };
	cout << IsPoporder(a, b, 5) << endl;
	system("pause");
	return 0;
}