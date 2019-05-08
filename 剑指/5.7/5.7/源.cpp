#include <iostream>

using namespace  std;


struct ListNode
{
	int val;
	ListNode* left;
	ListNode* right;
};
class solution
{
public:
	void MirrorTree(ListNode* head)
	{
		ListNode* pNode = head;
		//若节点为空或无左右子节点则返回
		if (pNode == nullptr || (pNode->left == nullptr && pNode->right == nullptr))
		{
			return;
		}

		//交换节点
		ListNode* tmp = head->left;
		head->left = head->right;
		head->right = tmp;

		//遍历左子树
		if (pNode->left != nullptr)
		{
			MirrorTree(pNode->left);
		}

		//遍历右子树
		if (pNode->right != nullptr)
		{
			MirrorTree(pNode->right);
		}
	}

	void SequencePrintMatrix(int** numers, int cols, int rows)
	{
		if (*numers == nullptr || cols <= 0 || rows <= 0)
		{
			return;
		}
		int start = 0;
		while (cols > 2 * start && rows > 2 * start)
		{
			PrintMatrix(numers, cols, rows, start);
			start++;
		}
	}

	void PrintMatrix(int** numers, int cols, int rows, int start)
	{
		int endx = cols - start - 1;
		int endy = rows - start - 1;
		for (int i = start; i <= endx; ++i)
		{
			cout << numers[start][i] << " ";
		}

		//边界问题主要是要考虑到numers寻找地址的 x 与 y

		//最上方的已经打印  所以从start + 1 开始
		if (start < endx)
		{
			for (int i = start + 1; i <= endy; ++i)
			{
				cout << numers[i][endy] << " ";
			}
		}

		//最右边的已经打印  所以从endx-1开始
		if (start < endx && start < endy)
		{
			for (int i = endx - 1; i >= start; --i)
			{
				cout << numers[endy][i] << " ";
			}
		}
		//因为最后一行已经打印了（即是endy-1行已经打印了）  所以 start 必须 小于 endy-1  
		//同理 最上方已经打印了  所以只能打印到start+1处
		if (start < endx && start < endy - 1 )
		{
			for (int i = endy - 1; i >= start + 1; --i)
			{ 
				cout << numers[start][i] << " ";
			}
		}
	}
};