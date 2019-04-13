#include <iostream>
#include <string>
#include <assert.h>
#include <algorithm>

using namespace std;

template<class T>
class Vector
{
public:
	//Vector的迭代器是一个原生指针
	typedef T* iterator;
	typedef const T* const_iterator;

	void PushBack(const T& val)
	{
		Insert(end(), val);
	}
	void PopBack()
	{
		Erase(end() - 1);
	}
	void Swap(Vector<T>& v)
	{
		swap(_start, v._start);
		swap(_finish, v._finish);
		swap(_endOfStorage, v._endOfStorage);
	}
	const Vector<T> operator=(Vector<T> v) const
	{
		Swap(v);
		return *this;
	}
	Vector<T> operator=(Vector<T> v)
	{
		Swap(v);
		return *this;
	}
	void Insert(iterator pos, const T& val)
	{
		assert(pos <= _finish && pos >= _start);
		size_t len = pos - _start;
		if (_finish == _endOfStorage)
		{
			size_t newC = _start == nullptr ? 1 : 2 * Capacity();
			Reserve(newC);
		}
		pos = _start + len;
		iterator end = _finish;
		while (end > pos)
		{
			*end = *(end - 1);
			end--;
		}
		*pos = val;
		_finish++;
	}
	void Reserve(size_t n)
	{
		//调用自定义类型的运算符重载 ，进行深拷贝
		if (n > Capacity())
		{
			int len = Size();
			T* tmp = new T[n];
			if (_start)
			{
				for (int i = 0; i < len; ++i)
				{
					tmp[i] = _start[i];
				}
				delete[] _start;
			}
			_start = tmp;
			_finish = _start + len;
			_endOfStorage = _start + n;
		}
	}
	void Resize(size_t n, const T& val = T())
	{
		if (n < Size())
		{
			_finish = _start + n;
		}
		else
		{
			if (n > Capacity())
			{
				Reserve(n);
			}
			while (_finish != _start + n)
			{
				*_finish = val;
				++_finish;
			}
		}
	}
	iterator Erase(iterator pos)
	{
		assert(pos < _finish && pos >= _start);
		iterator begin = pos + 1;
		while (begin < _finish)
		{
			*(begin - 1) = *begin;
			begin++;
		}
		_finish--;
		return pos;
	}
	~Vector()
	{
		if (_start)
		{
			delete[] _start;
			_start = _finish = _endOfStorage = nullptr;
		}
	}
	size_t Capacity() const
	{
		return _endOfStorage - _start;
	}
	size_t Size() const
	{
		return _finish - _start;
	}
	bool Empty()
	{
		return _start == _finish;
	}
	iterator begin()
	{
		return _start;
	}
	iterator end()
	{
		return _finish;
	}
	const_iterator begin() const
	{
		return _start;
	}
	const_iterator end() const
	{
		return _finish;
	}
	const T& operator[](size_t pos) const
	{
		assert(pos < Size());
		return _start[pos];
	}
	T& operator[](size_t pos)
	{
		assert(pos < Size());
		return _start[pos];
	}
	Vector()
		:_start(nullptr)
		,_finish(nullptr)
		,_endOfStorage(nullptr)
	{}
	Vector(const Vector<T>& v)
	{
		//考虑深拷贝
		 _start = new T[v.Capacity()];
		for (int i = 0; i < v.Size(); ++i)
		{
			_start[i] = v[i];
		}
		_finish = _start + v.Size();
		_endOfStorage = _start + v.Capacity();
	}
	
private:
	iterator _start;	//指向数据块的开始
	iterator _finish;	//指向有效数据的尾
	iterator _endOfStorage;	//指向存储容量的尾
};
template <class T>
void PrintVector(const Vector<T>& v)
{
	for (int i = 0; i < v.Size(); i++)
	{
		//v.operator[](i);
		//v[i] = 10;
		cout << v[i] << " ";
	}
	cout << endl;
}

template <class T>
void PrintVectorIterator(const Vector<T>& v)
{
	//Vector<T>::const_iterator--->vit;
	auto vit = v.begin();
	while (vit != v.end())
	{
		//*vit = 10;
		cout << *vit << " ";
		++vit;
	}
}


template <class T>
void PrintVectorFor(const Vector<T>& v)
{
	for (const auto& e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}


void testVector()
{
	//Vector<int> v;
	//v.PushBack(1);
	//v.PushBack(2);
	//v.PushBack(3);
	//v.PushBack(4);
	//v.PushBack(5);

	//for (int i = 0; i < v.Size(); i++)
	//{
	//	//v.operator[](i);
	//	cout << v[i] << " ";
	//}
	//cout << endl;

	Vector<string> v2;
	v2.PushBack("123");
	v2.PushBack("abc");
	v2.PushBack("abc");
	v2.PushBack("abc");
	v2.PushBack("abc");
	v2[2] = "789";
	auto vit = v2.begin();
	*vit = "ghg";
	/*PrintVector(v2);
	PrintVectorIterator(v2);*/
	PrintVectorFor(v2);
}


void TestVector3()
{
	Vector<int> v;
	v.PushBack(1);
	v.PushBack(2);
	v.PushBack(3);
	v.PushBack(4);

	auto vit = v.begin();
	while (vit != v.end())
	{
		if (*vit % 2 == 0)
			vit = v.Erase(vit);
		else
			++vit;
	}
	PrintVectorFor(v);
}



void TestVector5()
{
	Vector<int> v;
	v.PushBack(1);
	v.PushBack(2);
	v.PushBack(3);
	v.PushBack(4);  // int()
	// 为了支持泛型，内置类型也可以使用类似于构造函数的方式创建变量
	int b = int();  // b = 0
	int c = int(3); // c = 3

	v.Resize(7, 10);
	PrintVectorFor(v);
}
void TestVector6()
{
	Vector<int> v;
	v.PushBack(1);
	v.PushBack(2);
	v.PushBack(3);
	v.PushBack(4);  // int()
	Vector<int> v2(v);

	Vector<int> v3, v4, v5, v6;
	Vector<int> v7;
	v7.PushBack(11);
	v7.PushBack(12);
	v7.PushBack(13);
	v7 = v3 = v4 = v5 = v6 = v2;
	cout << "v2:" << endl;
	PrintVectorFor(v2);
	cout << "v3:" << endl;
	PrintVectorFor(v3);
	cout << "v7:" << endl;
	PrintVectorFor(v7);

}

void TestVector2()
{
	Vector<string> v;
	v.PushBack("1");
	v.PushBack("2");
	v.PushBack("3");
	v.PushBack("4");
	v.Insert(v.begin(), "0");  // 01234
	v.Insert(v.end(), "5"); // 012345
	v.Insert(v.begin() + 1, "a"); // 0a12345
	PrintVectorFor(v);

}

int main()
{
	TestVector3();
	system("pause");
	return 0;
}