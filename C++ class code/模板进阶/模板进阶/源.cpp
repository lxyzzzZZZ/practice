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
//���ȫ�ػ�

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


//ƫ�ػ�
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

//��������ƫ�ػ�Ϊָ������
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

//����������ƫ�ػ�Ϊ��������
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

//�ۼ�
//���⣺����ʱ�ݹ�
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
//	//Ĭ����ߵݹ����Ϊ500�� ����Sum<501>����� ����Sum<1>
//	//���õݹ�  ����Sum<500>����ͨ��
//	cout << Sum<10>::RET << endl;
//	system("pause");
//	return 0;
//}

////ǳ���� �ڴ濽��
//template<class T>
//void Copy(T* dst, const T* src, size_t size)
//{
//	memcpy(dst, src, sizeof(T)*size);
//}
//
////��� ֵ����
//template<class T>
//void Copy(T* dst, const T* src, size_t size)
//{
//	for (size_t i = 0; i < size; ++i)
//	{
//		dst[i] = src[i];
//	}
//}

//����������ǳ����
//�Զ������������

//��Ϊ�������͵ĸ�����ȷ���� ���Կ�һ���������ͼ�����һ��
//�����ж�
bool isPODType(const char* type)
{
	//��������
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

//����ͨ��typeid��ȷ�����������������
//Ȼ��ͨ��isPODType����ö�٣�
//��ȱ��Ч�ʵͣ���Ϊ��ö����Ҫ���������Ͷ�����һ�� �� ÿ�ζ����ַ����ıȽ�

template<class T>
void Copy(T* dst, const T* src, size_t size)
{
	if (isPODType(typeid(T).name()))
	{
		memcpy(dst, src, sizeof(T)*size);
		cout << "ǳ" << endl;
	}
	else
	{
		for (size_t i = 0; i < size; ++i)
		{
			dst[i] = src[i];
		}
		cout << "��" << endl;
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

//������ȡ

//������������
struct TrueType
{
	static bool Get()
	{
		return true;
	}
};
//�����Զ�������
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
		cout << "ǳ" << endl;
	}
	else
	{
		for (size_t i = 0; i < size; ++i)
		{
			dst[i] = src[i];
		}
		cout << "��" << endl;
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
