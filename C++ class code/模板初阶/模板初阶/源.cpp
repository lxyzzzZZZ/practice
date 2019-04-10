#include <iostream>
#include <string>
#include <assert.h>

using namespace std;
//1.���Ա��

void Swap(int& left, int& right)
{
	int tmp = left;
	left = right;
	right = tmp;
}

void Swap(double& left, double& right)
{
	double tmp = left;
	left = right;
	right = tmp;
}

void Swap(char& left, char& right)
{
	char tmp = left;
	left = right;
	right = tmp;
}

//����������Ȼ����ʵ�֣������м����׶ˣ�
//���غ�������ֻ�����Ͳ�ͬ�����븴���ʱȽϵͣ�ֻҪ�����ͳ���ʱ������Ҫ���Ӻ���
//����Ŀ�ά���ԱȽϵͣ�һ������������е����ؾ�����


//2.����ģ��

//����ģ���ʽ
//template<typenameT1,typenameT2,......,typenameTn>

//����ֵ���� �������������б�{}

template<typename T>

void Swap(T& left, T& right)
{
	T temp = left;
	left = right;
	right = temp;
}

//ģ����һ����ͼ�����������Ǻ������Ǳ�������ʹ�÷�ʽ�ض��������ͺ�����ĥ�ߡ�������ʵģ��
//���ǽ�����Ӧ�����������ظ������齻���˱�����
//���������ݴ����ʵ���������������ɶ�Ӧ�����ͺ���



//����ģ��ʵ����

template<class T>
T Add(const T& left, const T& right)
{
	return left + right;
}

void Test3()
{
	int a1 = 10;
	int a2 = 20;
	double d1 = 10.0;
	double d2 = 20.0;
	Add(a1, a2);
	Add(d1, d2);
	Add(a1, (int)d1);

}

//ģ�������ƥ��ԭ��

//һ����ģ�庯�����Ժ�һ��ͬ���ĺ���ģ��ͬʱ���ڣ����Ҹú���ģ�廹���Ա�ʵ����Ϊ�����ģ�庯��

int ADD(int left, int right)
{
	return left + right;
}

template<class T>
T ADD(T left, T right)
{
	return left + right;
}

void Test()
{
	ADD(1, 2);//���ģ�庯��ƥ�䣬����������Ҫ�ػ�
	ADD<int>(1, 2);//���ñ������ػ���ADD�汾
}

//���ڷ�ģ�庯����ͬ������ģ�壬���������������ͬ���ڵ����ǻ����ȵ��÷�ģ�庯��������Ӹ���ģ�������һ��ʵ��
//���ģ����Բ���һ�����и���ƥ��ĺ�������ô��ѡ��ģ��

template<class T1, class T2>
T1 ADD(T1 left, T2 right)
{
	return left + right;
}
void Test2()
{
	ADD(1, 2); //���÷�ģ�庯��
	ADD(1, 2.0); //����ģ��
}

//��ģ��

//��ģ��Ķ����ʽ

//template<class T1, class T2,....,class Tn>
//class ����
//{
//
//};

//��̬˳���
template <class T>
class Vector
{
public:
	Vector(size_t capacity = 10)
		:_pData(new T[capacity])
		,_size(0)
		,_capacity(capacity)
	{}

	~Vector();
	void PushBack(const T& data)
	{
		_pData[_size++] = data;
	}

	void PopBack()
	{
		--_size;
	}

	size_t Size()
	{
		return _size;
	}

	T& operator[](size_t pos)
	{
		assert(pos < _size);
		return _pData[pos];
	}

private:
	T* _pData;
	size_t _size;
	size_t _capacity;
};

template<class T>
Vector<T>::~Vector()
{
	if (_pData)
	{
		delete[] _pData;
	}
}
//Vector���Ǿ�����࣬�Ǳ��������ݱ�ʵ�������������ɾ������ģ��

int main()
{
	Vector<int> s1;
	s1.PushBack(1);
	s1.PushBack(2);
	s1.PushBack(3);

	Vector<double> s2;
	s2.PushBack(1.0);
	s2.PushBack(2.0);
	s2.PushBack(3.0);

	for (size_t i = 0; i < s1.Size(); i++)
	{
		cout << s1[i] << " ";
	}
	cout << endl;

	for (size_t i = 0; i < s2.Size(); i++)
	{
		cout << s2[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}