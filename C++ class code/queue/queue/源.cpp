#include <iostream>
#include <queue>
#include <stack>
#include <functional> // greater算法的头文件
#include <deque>
using namespace std;


void TestPriorityQueue()
{
	 //默认情况下，创建的是大堆，其底层按照小于号比较
	vector<int> v{ 3,2,7,6,0,4,1,9,8,5 };
	priority_queue<int> q1;
	for (auto& e : v)
		q1.push(e);
	cout << q1.top() << endl;
	 //如果要创建小堆，将第三个模板参数换成greater比较方式
	priority_queue<int, vector<int>, greater<int>> q2(v.begin(), v.end());
	cout << q2.top() << endl;
}
int main()
{
	TestPriorityQueue();
	system("pause");
	return 0;
}







//用俩个队列实现栈
class fun
{
public:
	void push(int x)
	{
		q1.push(x);
	}
	int top()
	{
		if (!q1.empty())
		{
			return q1.back();
		}
		if (!q2.empty())
		{
			return q2.back();
		}
	}
	int pop()
	{
		int val;
		if (q1.empty)
		{
			while (q2.size() > 1)
			{
				q1.push(q2.front());
				q2.pop();
			}
			val = q2.front();
			q2.pop();
		}
		else
		{
			while (q1.size() > 1)
			{
				q2.push(q1.front());
				q1.pop();
			}
			val = q1.front();
			q1.pop();
		}
		return val;
	}
	bool empty()
	{
		return q1.empty() && q2.empty();
	}
private:
	queue<int> q1;
	queue<int> q2;
};


//一个队列实现栈
class fun2
{
public:
	void push(int x)
	{
		q1.push(x);
	}
	int top()
	{
			return q1.back();
	}
	int pop()
	{
		int val;
		int len = q1.size() - 1;
		while (len)
		{
			//123  1231
			q1.push(q1.front());
			//1231 -》 231
			q1.pop();
			len--;
			
		}
		val = q1.front();
		q1.pop();
		return val;
	}
	bool empty()
	{
		return q1.empty();
	}
private:
	queue<int> q1;

};


//层序遍历
typedef struct TreeNode
{
	int val;
	TreeNode* right;
	TreeNode* left;
};

class fun3
{
public:
	int getHeight(TreeNode* root)
	{
		if (root == nullptr)
		{
			return 0;
		}
		int left = getHeight(root->left);
		int right = getHeight(root->right);
		return left > right ? left + 1 : right + 1;
	}
	vector<vector<int>> levelOrder(TreeNode* root)
	{
		queue<int> pIdx;
		queue<TreeNode*> pNode;
		vector<vector<int>> treeVec;
		treeVec.resize(getHeight(root));
		if (root)
		{
			pNode.push(root);
			pIdx.push(0);
		}
		while (!pNode.empty())
		{
			TreeNode* cur = pNode.front();
			pNode.pop();
			int curIdx = pIdx.front();
			pIdx.pop();
			treeVec[curIdx].push_back(cur->val);
			if (cur->left)
			{
				pNode.push(cur->left);
				pIdx.push(curIdx + 1);
			}
			if (cur->right)
			{
				pNode.push(cur->right);
				pIdx.push(curIdx + 1);
			}
		}
		return treeVec;
	}
};


template<class T, class Con = deque<T>>
class Queue
{
public:
	void push(const T& val)
	{
		return _c.push_front(val);
	}
	void Pop()
	{
		_c.pop_front();
	}
	T& Front()
	{
		return _c.front();
	}
	T& Back()
	{
		return _c.back();
	}
	size_t Size()
	{
		return _c.size();
	}
	bool Empty()
	{
		return _c.empty();
	}
private:
	ConF_c;
};