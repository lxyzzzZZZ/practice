#include <iostream>

using namespace std;



//share_ptr的循环引用问题

struct ListNode
{
	int _data;
	shared_ptr<ListNode> _prev;
	shared_ptr<ListNode> _next;
	~ListNode() { cout << "~ListNode()" << endl; }
};
struct ListNodeB
{
	int _data;
	weak_ptr<ListNodeB> _prev;
	weak_ptr<ListNodeB> _next;
	~ListNodeB() { cout << "~ListNodeB()" << endl; }
};
int main()
{

	//Node1与node2析构只是引用计数减一，必须要node2的prev析构了node1才能delete，
	//相反node1的next析构了node2才能delete，
	//node1与node2都无法控制其成员的析构
	//，所以就造成了一个死循环---循环引用
	shared_ptr<ListNode> node1(new ListNode);
	shared_ptr<ListNode> node2(new ListNode);
	cout << "node1:" << node1.use_count() << endl;//1
	cout << "node2:" << node2.use_count() << endl;//1
	node1->_next = node2;
	node2->_prev = node1;
	cout << "node1:" << node1.use_count() << endl;//2
	cout << "ndoe2:" << node2.use_count() << endl;//2
	cout << "ndoe1->_next:" << node1->_next.use_count() << endl; //2
	//cout << "ndoe1->_prev:" << node1->_prev.use_count() << endl;//0
	cout << "ndoe2->_prev:" << node2->_prev.use_count() << endl; //2
	//cout << "ndoe2->_next:" << node2->_next.use_count() << endl;//0



	//weak_ptr:专门解决shared_ptr的循环引用问题，但是不能单独使用
	//必须通过share_ptr初始化
	//weak_ptr：不会改变shared智能指针的引用计数


	shared_ptr<ListNodeB> Node1(new ListNodeB);
	shared_ptr<ListNodeB> Node2(new ListNodeB);
	cout << "node1:" << Node1.use_count() << endl;//1
	cout << "node2:" << Node2.use_count() << endl;//1
	node1->_next = node2;
	node2->_prev = node1;
	cout << "node1:" << Node1.use_count() << endl;//1
	cout << "node2:" << Node2.use_count() << endl;//1
	cout << "node1->_next:" << Node1->_next.use_count() << endl; //0
	//cout << "node1->_prev:" << Node1->_prev.use_count() << endl;//0
	cout << "node2->_prev:" << Node2->_prev.use_count() << endl; //0
	//cout << "ndoe2->_next:" << Node2->_next.use_count() << endl;//0
	system("pause");
	return 0;
}
//template<class T>
//class UniquePtr
//{
//public:
//	UniquePtr(T* ptr = nullptr)
//		:_ptr(ptr){}
//
//	~UniquePtr()
//	{
//		if (_ptr)
//		{
//			delete _ptr;
//		}
//	}
//
//	T& operator*()
//	{
//		return *_ptr;
//	}
//
//	T* operator->()
//	{
//		return _ptr;
//	}
//private:
//	T* _ptr;
//
//	UniquePtr(UniquePtr<T> const&  ) = delete
//	UniquePtr& operator=(UniquePtr<T> const& ) = delete;
//};

