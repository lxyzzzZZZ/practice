#include <iostream>
#include <time.h>
using namespace std;

//2.1�����ռ�Ķ���

//1.��ͨ�������ռ�

namespace N1	//N1Ϊ�����ռ������
{
	//�����ռ��е����ݣ��ȿ����Ƕ���ı�����Ҳ���Զ��庯��
	int a;
	int  Add(int left, int right)
	{
		return left + right;
	}
}

//2.�����ռ����Ƕ��

namespace N2
{
	int a;
	int b;
	int Add(int left, int right)
	{
		return left + right;
	}
	namespace N3
	{
		int c;
		int d;
		int Sub(int left, int right)
		{
			return left - right;
		}
	}
}

//3.ͬһ��������������ڶ����ͬ���Ƶ������ռ�
//����������ϳ�һ�������ռ���

namespace N1
{
	int Mul(int left, int right)
	{
		return left + right;
	}
}

//ע�⣺һ�������ռ���ڶ�����һ���µ������������ռ��е��������ݶ�
//		�����ڸ������ռ���


//2.2�����ռ��ʹ��

//using N2::a;
//int main()
//{
//	cout << a <<endl;
//	system("pause");
//	return 0;
//}

//using namespace N1;
//int main(){
//	cout << a << endl;
//	system("pause");
//	return 0;
//}

//4.ȱʡ����

//ȫȱʡ����

void TestFunc(int a = 10, int b = 20, int c = 30)
{
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
}

//��ȱʡ����

void TestFunc2(int a, int b = 20, int c = 30)
{
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
}

//ע�⣺��ȱʡ����������ҵ������θ��������ܼ������
//		ȱʡ���������ں��������Ͷ�����ͬʱ����

//5.extern ��c��
// ��˼�Ǹ��߱����������ú�������C���Թ���������

//extern "C" int Add(int left, int right)
//{
//	;
//}
//int main()
//{
//	Add(1, 2); //����C�����޷�������ʼ����
//	return 0;
//}

//6.����

//���ò����¶���һ�����������Ǹ��Ѵ��ڵı���ȥһ��������
//����������Ϊ���ñ��������ڴ�ռ䣬�������õı�������ͬһ���ڴ�ռ�

//1.�����ڶ���ʱ�����ʼ��
//2.һ����������ӵ�ж������
//3.����һ������һ��ʵ�壬�ٲ�����������ʵ��
//4.������ʵ�����ͱ���һ��

//������
void Swap(int& left, int& right)
{
	int temp = left;
	left = right;
	right = temp;
}

//������ֵ

int& TestRefReturn(int& a)
{
	a += 10;
	return a;
}

int& Addx(int a, int b)
{
	int c = a + b;
	return c;
}

//int main()
//{
//	int& ret = Addx(1, 2);
//	Addx(3, 4);
//	cout <<"Addx is:"<< ret << endl;
//	system("pause");
//	return 0;
//}
//���Ϊ��7
//ע�⣺�����������ʱ���뿪�������������ջ�Ͽռ��Ѿ�����ϵͳ��
//		��˲�����ջ�ϵĿռ���Ϊ�������ͷ��ء�������������ͷ��أ�
//		����ֵ���������ڱ��벻�ܺ���������(���Ⱥ����������ڳ�)��

//��ֵ��������Ч�ʱȽ�

struct A
{
	int a[10000];
};

void TestFunC1(A a)
{
	;
}

void TestFunC2(A& a)
{
	;
}

void TestRefAndvalue()
{
	A a;
	//��ֵ
	size_t begin1 = clock();
	for (size_t i = 0; i < 10000; ++i)
	{
		TestFunC1(a);
	}
	size_t end1 = clock();

	//������
	size_t begin2 = clock();
	for (size_t i = 0; i < 10000; ++i)
	{
		TestFunC2(a);
	}
	size_t end2 = clock();

	cout << "C1:" << end1 - begin1 << endl;
	cout << "C2:" << end2 - begin2 << endl;
}

//int main()
//{
//	for (int i = 0; i < 10; ++i)
//	{
//		TestRefAndvalue();
//	}
//	system("pause");
//	return 0;
//}

//ͨ����������ıȽϣ����ִ�ֵ��ָ������Ϊ�����Լ�����ֵ������Ч�����ܴ�

//6.6������ָ�������

//1.���﷨���������þ���һ��������û�ж����Ŀռ䣬�������õ�ʵ��
//	����һ��ռ�
//2.�ڵײ���ʵ����ʵ�����пռ�ģ���Ϊ�����ǰ���ָ�뷽ʽ��ʵ�ֵ�


//7.��������

//7.1 ����

//��inline���εĺ���������������������ʱC++���������ڵ������������ĵط�չ����û�к���ѹջ�Ŀ�����
//�������������������е�Ч��

//7.2 ����

//1. inline��һ���Կռ任ʱ���������ʡȥ���ú�����������Դ���ܳ�������ѭ�� / �ݹ�ĺ���������ʹ
//����Ϊ����������
//2. inline���ڱ���������ֻ��һ�����飬���������Զ��Ż����������Ϊinline�ĺ���������ѭ�� / �ݹ��
//�ȣ��������Ż�ʱ����Ե�������
//3. inline�����������Ͷ�����룬����ᵼ�����Ӵ�����Ϊinline��չ������û�к�����ַ�ˣ����Ӿͻ���
//������

//8.auto�ؼ���

int TestAuto()
{
	return 10;
}

//int main()
//{
//	int a = 10;
//	auto b = a;
//	auto c = 'a';
//	auto d = TestAuto();
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//	system("pause");
//	return 0;
//}

//8.2 auto��ʹ��ϸ��

//1.auto ��ָ������ý������ʹ��

//��auto ����ָ�����ͣ���auto��auto* û���κ����𣬵���auto������������ʱ������&

//int main()
//{
//	int x = 10;
//	auto a = &x;
//	auto* b = &x;
//	auto& c = x;
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//
//	*a = 20;
//	*b = 30;
//	c = 40;
//	system("pause");
//	return 0;
//}

//2. ��ͬһ�ж���������
//����ͬһ�������������ʱ����Щ������������ͬ�����ͣ�������������ᱨ����Ϊ������ʵ��ֻ�Ե�һ��
//���ͽ����Ƶ���Ȼ�����Ƶ����������Ͷ�������������

void Testauto()
{
	auto a = 1, b = 2;
	//auto c = 3, d = 4.0;//����ʧ��
}

//8.3   auto������Ϊ�����Ĳ���
//		auto����ֱ��������������

//9.���ڷ�Χ��forѭ��

void TestFor()
{
	int array[] = { 1, 2, 3, 4, 5, 6 };
	for (auto& e : array)
	{
		e *= 2;
	}

	for (auto e : array)
	{
		cout << e << " ";
	}
	return;
}
