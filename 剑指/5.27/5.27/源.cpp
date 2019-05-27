#include <iostream>

using namespace std;



//share_ptr��ѭ����������

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

	//Node1��node2����ֻ�����ü�����һ������Ҫnode2��prev������node1����delete��
	//�෴node1��next������node2����delete��
	//node1��node2���޷��������Ա������
	//�����Ծ������һ����ѭ��---ѭ������
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



	//weak_ptr:ר�Ž��shared_ptr��ѭ���������⣬���ǲ��ܵ���ʹ��
	//����ͨ��share_ptr��ʼ��
	//weak_ptr������ı�shared����ָ������ü���


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

