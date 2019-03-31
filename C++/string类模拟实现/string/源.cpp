#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <assert.h>
#include <string>
#include <stdio.h>
using namespace std;




//string���ģ��ʵ��
class String
{
public:
	typedef char* Iterator;
	typedef const char* const_Iterator;
	//
	String(char* str = "")
	{
		assert(str != nullptr);
		//size����Ч�ַ�����  ������\0
		_size = strlen(str);
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
		_capacity = _size;
	}

	//
	void Swap(String& s)
	{
		swap(_str, s._str);
		swap(_size, s._size);
		swap(_capacity, s._capacity);
	}
	//
	String(const String& s)
		:_str(nullptr),
		_size(0),
		_capacity(0)
	{
		String tmp(s._str);
		Swap(tmp);
	}
	//
	char& operator[](size_t pos)
	{
		assert(pos < _size);
		return _str[pos];
	}
	//
	const char& operator[](size_t pos) const
	{
		assert(pos < _size);
		return _str[pos];
	}
	//
	int Size() const
	{
		return _size;
	}
	//
	void printfString(const String& s)
	{
		for (int i = 0; i < s.Size(); i++)
		{
			cout << s[i] << endl;
			//cout << s.operator[](i) << endl;
		}
	}
	//
	const_Iterator begin() const
	{
		return _str;
	}
	//
	const_Iterator end() const
	{
		return _str + _size;
	}

	//
	//
	//void printiterator(const String& s)
	//{
	//	const_Iterator sit = s.begin();
	//	while (sit != s.end())
	//	{
	//		cout << *sit << " ";
	//		++sit;
	//	}
	//	cout << endl;
	//}

	String& operator=(String& s)
	{
		swap(_str, s._str);
		return *this;
	}
	//
	~String()
	{
		if (_str)
		{
			delete(_str);
			_str = nullptr;
		}
	}
	//
	char* c_str()
	{
		return _str;
	}
	//β��
	void PushBack(char c)
	{
		if (_size == _capacity)
		{
			size_t newC = (_capacity == 0 ? 15 : 2 * _capacity);
			Reserve(newC);
		}
		_str[_size++] = c;
		_str[_size] = '\0';
	}

	//βɾ
	void PopBack()
	{
		if (_size > 0)
		{
			_str[--_size] = '\0';
		}
	}
	//ֻ���ݣ�����������
	void Reserve(size_t n)
	{
		if (n > _capacity)
		{
			char* tmp = new char[n + 1];
			strcpy(tmp, _str);
			delete _str;
			_str = tmp;
			_capacity = n;
		}
	}
	//
	//
	void Resize(size_t n, char c = '\0')
	{
		if (n > _capacity)
		{
			Reserve(n);
		}
		if (_size < n)
		{
			memset(_str + _size, c, n - _size);
		}
		_size = n;
		_str[_size] = '\0';
	}

	//���±�pos��ʼɾ��len���ַ�
	void Erase(size_t pos, size_t len)
	{
		assert(pos < _size);
		if (pos + len >= _size)
		{
			_size = pos;
			_str[_size] = '\0';
		}
		else
		{
			//��pos +lenλ�ÿ�ʼŲ�����ݣ�ÿ��������ǰŲ��len��λ��
			for (int i = pos + len; i <= _size; i++)
			{
				_str[pos++] = _str[i];
			}
			_size -= len;
		}
	}

	//β���ַ���
	void Append(const char* str)
	{
		//����
		size_t sz = strlen(str);
		if ((_size + sz) > _capacity)
		{
			Reserve(_size + sz);
		}
		strcpy(_str + _size, str);
		_size += sz;
	}

private:
	char* _str;
	size_t _size;
	size_t _capacity;
};
void printiterator(const String& s)
{
	String::const_Iterator sit = s.begin();
	while (sit != s.end())
	{
		cout << *sit << " ";
		++sit;
	}
	cout << endl;
}

void test()
{
	String s1;
	s1.PushBack('1');
	s1.PushBack('2');
	s1.PushBack('3');
	s1.PushBack('4');
	s1.Resize(15, 'q');
	s1.printfString(s1);
	//s1.Erase(2, 2);
	s1.Append("xiueraidazhao");
	printiterator(s1);

}

int main()
{

	test();
	system("pause");
	return 0;
}