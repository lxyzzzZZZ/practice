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
		//���ڵ�Ϊ�ջ��������ӽڵ��򷵻�
		if (pNode == nullptr || (pNode->left == nullptr && pNode->right == nullptr))
		{
			return;
		}

		//�����ڵ�
		ListNode* tmp = head->left;
		head->left = head->right;
		head->right = tmp;

		//����������
		if (pNode->left != nullptr)
		{
			MirrorTree(pNode->left);
		}

		//����������
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

		//�߽�������Ҫ��Ҫ���ǵ�numersѰ�ҵ�ַ�� x �� y

		//���Ϸ����Ѿ���ӡ  ���Դ�start + 1 ��ʼ
		if (start < endx)
		{
			for (int i = start + 1; i <= endy; ++i)
			{
				cout << numers[i][endy] << " ";
			}
		}

		//���ұߵ��Ѿ���ӡ  ���Դ�endx-1��ʼ
		if (start < endx && start < endy)
		{
			for (int i = endx - 1; i >= start; --i)
			{
				cout << numers[endy][i] << " ";
			}
		}
		//��Ϊ���һ���Ѿ���ӡ�ˣ�����endy-1���Ѿ���ӡ�ˣ�  ���� start ���� С�� endy-1  
		//ͬ�� ���Ϸ��Ѿ���ӡ��  ����ֻ�ܴ�ӡ��start+1��
		if (start < endx && start < endy - 1 )
		{
			for (int i = endy - 1; i >= start + 1; --i)
			{ 
				cout << numers[start][i] << " ";
			}
		}
	}
};