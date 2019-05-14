#include <iostream>
#include <string>
#include <stdlib.h>
#include <mutex>
#include <thread>
//int globaVar = 1;//数据段
//
//static int staticGlobalVar = 1;//数据段
//void test()
//{
//	static int staticVar = 1;//数据段
//	int localVar = 1;//栈
//	int num1[10] = { 1,2,3,4 };//栈 sizeof  40
//	char char2[] = "abcd";//栈 sizeof  5 strlen 4
//	const char* pChar3("abcd");//栈 szieof
//	int* ptr1 = (int*)malloc(sizeof(int) * 4);//ptr 栈  *ptr 堆
//	int* ptr2 = (int*)calloc(4, sizeof(int));//
//	int* ptr3 = (int*)realloc(ptr2, sizeof(int) * 4);
//	free(ptr1);
//	free(ptr3);
//}
//
////设计一个类 该类只能在堆上创建对象
////1.将类的构造私有，拷贝构造声明成私有。防止别人调用拷贝在栈上生成对象
////2.提供一个静态的成员函数，在该静态成员函数中完成对象的创建
//
//class HeapOnly
//{
//public:
//	//完成对象 new 堆上
//	static HeapOnly* CreateObject()
//	{
//		return new HeapOnly;
//	}
//private:
//
//	//只声明 不实现 （不需要，且实现可能会很麻烦
//	HeapOnly(){}
//	//c98
//	HeapOnly(const HeapOnly& ){}
//	//c11
//	HeapOnly(const HeapOnly&) = delete;
//};
//
////设计一个类，该类只能在栈上创建对象
//
////1.封死构造函数
////2.提供static方法
//
////只要将new的功能屏蔽即可，既是屏蔽掉operator new 和定位 new 表达式  
////注意：屏蔽掉operator new 实际上也将定位new屏蔽掉
////
//class StackOnly
//{
//public:
//	static StackOnly CreatObject()
//	{
//		return StackOnly();
//	}
//private:
//	StackOnly(){}
//};
//
//
////单例模式
//
////饿汉模式：
////就是说不管你将来用不用，程序启动时就创建好了一个唯一的实例对象
//
////优点 简单
////缺点：可能会导致进程启动慢，且如果有多个单例类对象实例启动顺序不确定
//
////如果这个单例对象在多线程并发环境下频繁使用，性能要求较高，那么显然使用饿汉模式来避免资源
////竞争，提高响应速度更好
//class Singleton
//{
//public:
//	static Singleton* GetInstance()
//	{
//		return &_instance;
//	}
//private:
//	Singleton() {};
//
//	//c++98
//	Singleton(Singleton const&);
//	Singleton& operator=(Singleton const&);
//
//	//c++11
//	Singleton(Singleton const&) = delete;
//	Singleton& operator=(Singleton const&) = delete;
//
//	static Singleton _instance;
//
//};
//
//Singleton Singleton::_instance;//程序入口之前就完成单例对象的初始化
//
////懒汉模式
//
////优点：第一次使用对象时，创建对象。进程启动无负载 多个单例实例启动顺序自由控制
////缺点：复杂
//
//
////
////class singleton
////{
////public:
////	static singleton* Getinstance()
////	{
////		if (nullptr == m_pInstance)
////		{
////			m_mtx.lock();
////			if (nullptr == m_pInstance)
////			{
////				m_pInstance = new singleton();
////			}
////			m_mtx.unclock();
////		}
////		return m_pInstance;
////	}
////	class CGarbo {
////	public:
////		~CGarbo()
////		{
////			if (singleton::m_pInstance)
////				delete singleton::m_pInstance;
////		}
////	};
////
////private:
////	//构造函数私有
////	singleton(){}
////	//防拷贝
////	singleton (singleton const&){}
////	singleton& operator=(singleton const&){}
////
////	static singleton* m_pInstance;//单例对象指针
////	//static mutex m_mtx; //互斥锁
////
////};
////
////singleton* singleton::m_pInstance = nullptr;
////singleton::CGarbo Garbo;
//////mutex singleton::m_mtx;


 struct ListNode {
     int val;
     struct ListNode *next;
  };
 
struct ListNode* removeElements(struct ListNode* head, int val) {

	if (head == NULL)
	{
		return NULL;
	}
	while (head != NULL && head->val == val)
	{
		head = head->next;
	}
	if (head != NULL)
	{
		struct ListNode* pNode = head;
		while (pNode->next != NULL)
		{
			if (pNode->next->val == val)
			{
				pNode->next = pNode->next->next;
			}
			else
			{
				pNode = pNode->next;
			}

		}
	}

	return head;
}
int main()
{
	ListNode* head = NULL;
	system("pause");
	return 0;
}