#include <iostream>
#include <string>
#include <stdlib.h>
#include <mutex>
#include <thread>
//int globaVar = 1;//���ݶ�
//
//static int staticGlobalVar = 1;//���ݶ�
//void test()
//{
//	static int staticVar = 1;//���ݶ�
//	int localVar = 1;//ջ
//	int num1[10] = { 1,2,3,4 };//ջ sizeof  40
//	char char2[] = "abcd";//ջ sizeof  5 strlen 4
//	const char* pChar3("abcd");//ջ szieof
//	int* ptr1 = (int*)malloc(sizeof(int) * 4);//ptr ջ  *ptr ��
//	int* ptr2 = (int*)calloc(4, sizeof(int));//
//	int* ptr3 = (int*)realloc(ptr2, sizeof(int) * 4);
//	free(ptr1);
//	free(ptr3);
//}
//
////���һ���� ����ֻ���ڶ��ϴ�������
////1.����Ĺ���˽�У���������������˽�С���ֹ���˵��ÿ�����ջ�����ɶ���
////2.�ṩһ����̬�ĳ�Ա�������ڸþ�̬��Ա��������ɶ���Ĵ���
//
//class HeapOnly
//{
//public:
//	//��ɶ��� new ����
//	static HeapOnly* CreateObject()
//	{
//		return new HeapOnly;
//	}
//private:
//
//	//ֻ���� ��ʵ�� ������Ҫ����ʵ�ֿ��ܻ���鷳
//	HeapOnly(){}
//	//c98
//	HeapOnly(const HeapOnly& ){}
//	//c11
//	HeapOnly(const HeapOnly&) = delete;
//};
//
////���һ���࣬����ֻ����ջ�ϴ�������
//
////1.�������캯��
////2.�ṩstatic����
//
////ֻҪ��new�Ĺ������μ��ɣ��������ε�operator new �Ͷ�λ new ���ʽ  
////ע�⣺���ε�operator new ʵ����Ҳ����λnew���ε�
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
////����ģʽ
//
////����ģʽ��
////����˵�����㽫���ò��ã���������ʱ�ʹ�������һ��Ψһ��ʵ������
//
////�ŵ� ��
////ȱ�㣺���ܻᵼ�½�����������������ж�����������ʵ������˳��ȷ��
//
////���������������ڶ��̲߳���������Ƶ��ʹ�ã�����Ҫ��ϸߣ���ô��Ȼʹ�ö���ģʽ��������Դ
////�����������Ӧ�ٶȸ���
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
//Singleton Singleton::_instance;//�������֮ǰ����ɵ�������ĳ�ʼ��
//
////����ģʽ
//
////�ŵ㣺��һ��ʹ�ö���ʱ���������󡣽��������޸��� �������ʵ������˳�����ɿ���
////ȱ�㣺����
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
////	//���캯��˽��
////	singleton(){}
////	//������
////	singleton (singleton const&){}
////	singleton& operator=(singleton const&){}
////
////	static singleton* m_pInstance;//��������ָ��
////	//static mutex m_mtx; //������
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