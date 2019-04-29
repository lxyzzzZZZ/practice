#include <iostream>

using namespace std;

struct BinaryTreeNode
{
	BinaryTreeNode* right;
	BinaryTreeNode* left;
	BinaryTreeNode* parent;
	int val;
};

BinaryTreeNode* GetNext(BinaryTreeNode* Node)
{
	if (Node == nullptr)
	{
		return nullptr;
	}
	BinaryTreeNode* Next = nullptr;
	if (Node->right != nullptr)
	{
		BinaryTreeNode* pright = Node->right;
		while (pright->left != nullptr)
		{
			pright = pright->left;
		}
		Next = pright;
	}
	else if (Node->parent != nullptr)
	{
		BinaryTreeNode* Current = Node;
		BinaryTreeNode* pParent = Node->parent;
		while (pParent != nullptr && Current == pParent->right)
		{
			Current = pParent;
			pParent = pParent->parent;
		}
		Next = pParent;
	}
	return Next;
}