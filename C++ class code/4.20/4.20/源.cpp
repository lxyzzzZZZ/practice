#include <iostream>

using namespace std;


//void Size() 
//{
//	size_t count = 0;
//for (const auto& e : *this)
//{
//	count++;
//}
//	pNode ret = _head->next;
//	while (ret != _head)
//	{
//		count++;
//		ret = _head->next;
//	}
//	return count;
//}

//void clear()
//{
//	pNode ret = _head->next;
//	while (ret != _head)
//	{
//		_head->next = ret->next;
//		delete ret;
//		ret = _head->next;
//	}
//	_head->next = _head;
//	_head->prev = _head;
//}

//void PopBack()
//{
//	erase(--end());
//}

//void PopFront()
//{
//	erase(begin());
//}

//List<T>& operator=(const List<T>& l)
//{
//	if (this != l)
//	{
//		List<T> tmp(l);
//		this->swap(tmp);
//	}
//	return *this;
//}

//List(const List<T>& L)
//{
//	_head = new Node();
//	_head->next = _head;
//	_head->prev = _head;
//
//	List<T> tmp(L.begin(),L.end());
//	swap(_head,tmp._head);
//	while(const auto& e : L)
//	{
//		PushBack(e._val);
//	}
//}
