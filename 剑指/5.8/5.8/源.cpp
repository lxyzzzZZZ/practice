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



//ջ��ѹ���뵯������
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
			//��ѹ����������ѹ�븨��ջ ֱ������ջ����Ԫ�ص��ڵ������е�ջ������
			while (ret.empty() || ret.top() != *pPopNext)
			{
				if (pPushNext - pPush == length)
				{
					break;
				}
				ret.push(*pPushNext);
				pPushNext++;
			}
			//��ѹ��ջȫ��ѹ�븨��ջ ��û���ҵ��뵯��ջ����ȵ�Ԫ����false
			if (ret.top() != *pPopNext)
			{
				break;
			}
			ret.pop();
			pPopNext++;
		}
		//�����������Ϊ�� ��Ԫ��ȫ��������Ϊtrue
		if (pPopNext - pPop == length && ret.empty())
		{
			flag = true;
		}
	}
	return flag;
}


//���������
void PrintFromTopBottom(BinaryTreeNode* Treeroot)
{
	if (Treeroot == nullptr)
	{
		return;
	}
	//�ö��д�ȡ���Ľڵ�
	deque<BinaryTreeNode*>  ret;
	//�����ڵ�β�������
	ret.push_back(Treeroot);
	while (ret.size() > 0)
	{
		//��һ�����ڵ�洢����ǰ�ڵ� �������
		BinaryTreeNode* pNode = ret.front();
		//��Ϊͷ����������ݽ���  ����ɾ�� ��֤���˳����ȷ
		//�ұ��ڱ����ҽڵ�
		ret.pop_front();

		cout << pNode->val << " ";

		//��pNode�������ӽڵ�β�������
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