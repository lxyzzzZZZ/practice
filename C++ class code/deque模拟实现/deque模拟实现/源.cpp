#include <iostream>
#include <stack>
#include <queue>
#include <deque>
#include <vector>

using namespace std;


class MinStack
{
public :
	MinStack()
	{
	}
	void push(int x)
	{
		//只要是压栈，就将元素压入_elem
		_elem.push(x);
		if (x <= _min.top() || _min.empty())
		{
			_min.push(x);
		}
	}
	void pop()
	{
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
		return _min.top();
	}
private:
	stack<int> _elem;
	stack<int> _min;
};

//栈的弹出压入序列
class Solution
{
	bool IsPopOrder(vector<int> pushV, vector<int> popV)
	{
		if (pushV.size() != popV.size())
		{
			return false;
		}
		int outIdx = 0;
		int inIdx = 0;
		stack<int> s;

		while (outIdx < popV.size())
		{
			while (s.empty() || s.top() != popV[outIdx])
			{
				if (inIdx < pushV.size())
				{
					s.push(pushV[inIdx]);
				}
				else
				{
					return false;
				}
			}
			s.pop();
			outIdx++;
		}
	}
};


template<class T, class Con = deque<T>>

class Stack
{
public:
	Stack(){}
	void Push(const T& x)
	{
		_c.push_back(x);
	}

	void Pop()
	{
		_c.pop_back();
	}

	T& Top()
	{
		return _c.back();
	}

	const T& Top() const
	{
		return _c.back();
	}

	size_t Size() const
	{
		return _c.size();
	}

	bool Empty const
	{
		return _c.empty();
	}
private:
	Con _c;
};

template <class T, class con = deque<T>>

class Queue
{
	Queue() {}

	void Push(const T& x)
	{
		_c.push_back(x);
	}

	void Pop()
	{
		_c.pop_front();
	}
	T& Back()
	{
		return _c.back();
	}
	const T& Back() const
	{
		return _c.back();
	}

	T& Front()
	{
		return _c.front();
	}
	const T& Front()
	{
		return _c.push_back;
	}

	size_t Size() const
	{
		return _c.size();
	}

	bool Empty() const
	{
		return _c.empty();
	}
private :
	con _c;
};