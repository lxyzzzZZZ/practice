#include <iostream>
#include <string>
#include <assert.h>

using namespace std;
//1.泛性编程

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

//函数重载虽然可以实现，但是有几个弊端：
//重载函数仅仅只是类型不同，代码复用率比较低，只要新类型出现时，就需要增加函数
//代码的可维护性比较低，一个出错可能所有的重载均出错


//2.函数模板

//函数模板格式
//template<typenameT1,typenameT2,......,typenameTn>

//返回值类型 函数名（参数列表）{}

template<typename T>

void Swap(T& left, T& right)
{
	T temp = left;
	left = right;
	right = temp;
}

//模板是一个蓝图，他本身并不是函数，是编译器用使用方式特定具体类型函数的磨具。所以其实模板
//就是将本来应该我们做的重复的事情交给了编译器
//编译器根据传入的实参类型来推演生成对应的类型函数



//函数模板实例化

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

//模板参数的匹配原则

//一个非模板函数可以和一个同名的函数模板同时存在，而且该函数模板还可以被实例化为这个非模板函数

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
	ADD(1, 2);//与非模板函数匹配，编译器不需要特化
	ADD<int>(1, 2);//调用编译器特化的ADD版本
}

//对于非模板函数和同名函数模板，如果其他条件都相同，在调动是会优先调用非模板函数而不会从更改模板产生出一个实例
//如果模板可以产生一个具有更好匹配的函数，那么将选择模板

template<class T1, class T2>
T1 ADD(T1 left, T2 right)
{
	return left + right;
}
void Test2()
{
	ADD(1, 2); //调用非模板函数
	ADD(1, 2.0); //调用模板
}

//类模板

//类模板的定义格式

//template<class T1, class T2,....,class Tn>
//class 类名
//{
//
//};

//动态顺序表
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
//Vector不是具体的类，是编译器根据被实例化的类型生成具体类的模具

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