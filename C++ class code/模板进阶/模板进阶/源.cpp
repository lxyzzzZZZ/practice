#include <iostream>
#include <string>

using namespace std;

template <class T>

bool bigger(T& a, T& b)
{
	return	a > b;
}


void test()
{
	char* p1 = (char*)"10";
	char* p2 = (char*)"20";
	cout << bigger(p1, p2) << endl;
}

//int main()
//{
//	test();
//	system("pause");
//	return 0;
//}
//类的全特化

template<class T1, class T2>
class Data
{
public:
	Data()
	{
		cout << "<T1, T2>" << endl;
	}
private:
	T1 _d1;
	T2 _d2;
};
template<>
class Data<int, char>
{
public:
	Data()
	{
		cout << "<int, char>" << endl;
	}
private:
	int _d1;
	char _d2;
};

//int main()
//{
//	Data<int, int> a;
//	Data<int, char> b;
//	system("pause");
//	return 0;
//}


//偏特化
template<class T1>
class Data<T1, int>
{
public:
	Data()
	{
		cout << "Data<T1, int>" << endl;
	}
private:
	T1 _d1;
	int _d2;
};

//俩个参数偏特化为指针类型
template<class T1, class T2>
class Data<T1*, T2*>
{
public:
	Data()
	{
		cout << "<T1*, T2*>" << endl;
	}
private:
	T1* _d1;
	T2* _d2;
};

//将俩个参数偏特化为引用类型
template<class T1, class T2>
class Data<T1&, T2&>
{
public:
	Data(const T1& d1, const T2& d2)
		:_d1(d1)
		,_d2(d2)
	{
		cout << "<T1&, T2&>" << endl;
	}
private:
	const T1& _d1;
	const T2& _d2;
};

void Test2()
{
	Data<double, int> d1;
	Data<int, double> d2;
	Data<int*, int*> d3;
	Data<int&, int&> d4(1, 2);
}
//int main()
//{
//	Test2();
//	system("pause");
//	return 0;
//}
//
//template<size_t N>
//class A
//{
//
//};
//
//template<>
//class A<10>
//{
//
//};

//累加
//特殊：编译时递归
template<size_t N>
class Sum
{
public:
	enum{RET = Sum<N-1>::RET + N};
};
template<>
class Sum<1>
{
public:
	enum { RET = 1 };
};
//int main()
//{
//	//默认最高递归次数为500次 所以Sum<501>会出错 由于Sum<1>
//	//不用递归  所以Sum<500>可以通过
//	cout << Sum<10>::RET << endl;
//	system("pause");
//	return 0;
//}

////浅拷贝 内存拷贝
//template<class T>
//void Copy(T* dst, const T* src, size_t size)
//{
//	memcpy(dst, src, sizeof(T)*size);
//}
//
////深拷贝 值拷贝
//template<class T>
//void Copy(T* dst, const T* src, size_t size)
//{
//	for (size_t i = 0; i < size; ++i)
//	{
//		dst[i] = src[i];
//	}
//}

//内置类型用浅拷贝
//自定义类型用深拷贝

//因为内置类型的个数是确定的 所以可一将内置类型集合在一起
//加以判断
bool isPODType(const char* type)
{
	//内置类型
	const char* podArr[] = { "int","double","float","char","short","long","long long","long double" };
	int sz = sizeof(podArr) / sizeof(podArr[0]);
	for (int i = 0; i < sz; ++i)
	{
		if (!strcmp(type, podArr[i]))
		{
			return true;
		}
		//if(!strcmp(type, podArr[i])
		//{
		//	return true;
		//}
	}
	return false;
}

//可以通过typeid来确认所拷贝对象的类型
//然后通过isPODType函数枚举，
//但缺点效率低，因为：枚举需要将所有类型都遍历一遍 且 每次都是字符串的比较

template<class T>
void Copy(T* dst, const T* src, size_t size)
{
	if (isPODType(typeid(T).name()))
	{
		memcpy(dst, src, sizeof(T)*size);
		cout << "浅" << endl;
	}
	else
	{
		for (size_t i = 0; i < size; ++i)
		{
			dst[i] = src[i];
		}
		cout << "深" << endl;
	}
}
//int main()
//{
//	int arr[5] = { 1,2,3,4,5 };
//	int arrcopy[5];
//	Copy(arrcopy, arr, 5);
//	string str[5] = { "2","3","4","5","1" };
//	string strcopy[5];
//	Copy(strcopy, str, 5);
//	system("pause");
//	return 0;
//}

//类型萃取

//代表内置类型
struct TrueType
{
	static bool Get()
	{
		return true;
	}
};
//代表自定义类型
struct FalseType
{
	static bool Get()
	{
		return false;
	}
};

template<class T>
struct TypeTraits
{
	typedef FalseType isPODType;
};

template<>
struct TypeTraits<char>
{
	typedef TrueType isPODType;
};
template<>
struct TypeTraits<short>
{
	typedef TrueType isPODType;
};
template<>
struct TypeTraits<int>
{
	typedef TrueType isPODType;
};
template<>
struct TypeTraits<long>
{
	typedef TrueType isPODType;
};
template<>
struct TypeTraits<long long>
{
	typedef TrueType isPODType;
};
template<>
struct TypeTraits<float>
{
	typedef TrueType isPODType;
};
template<>
struct TypeTraits<double>
{
	typedef TrueType isPODType;
};
template<>
struct TypeTraits<long double>
{
	typedef TrueType isPODType;
};

template<class T>
void Copy2(T* dst, const T* src, size_t size)
{
	if (TypeTraits<T>::isPODType::Get())
	{
		memcpy(dst, src, sizeof(T)*size);
		cout << "浅" << endl;
	}
	else
	{
		for (size_t i = 0; i < size; ++i)
		{
			dst[i] = src[i];
		}
		cout << "深" << endl;
	}
}
int main()
{
	int a1[] = { 1,2,3,4,5,6,7,8,9,0 };
	int a2[10];
	Copy2(a2, a1, 10);

	string s1[] = { "1111", "2222", "3333", "4444" };
	string s2[4];
	Copy2(s2, s1, 4);
	system("pause");
	return 0;
}
