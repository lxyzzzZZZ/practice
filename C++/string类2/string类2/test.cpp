#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <assert.h>
#include <string>
#include <stdio.h>
using namespace std;
class String
{
public:
	typedef char* iterator;
	typedef const char* const_iterator;
	//构造
	String(const char* str = "")
	{
		assert(str != nullptr);
		//strlen 不包括'\0'
		_size = strlen(str);
		//新建一个字符数组
		_str = new char[_size + 1];
		strcpy(_str, str);
		_capacity = _size;
	}
	void Swap(String& s)
	{
		swap(_str, s._str);
		swap(_size, s._size);
		swap(_capacity, s._capacity);
	}
	String(const String& s)
	{
		String tmp(s._str);
		Swap(tmp);
	}
	char& operator[](size_t pos)
	{
		assert(pos < _size);
		return _str[pos];
	}
	const char& operator[](size_t pos) const
	{
		assert(pos < _size);
		return _str[pos];
	}
	int Size() const
	{
		return _size;
	}
	int Capacity() const
	{
		return _capacity;
	}
	~String()
	{
		if (_str)
		{
			delete(_str);
			_str = nullptr;
			_size = 0;
			_capacity = 0;
		}
	}
	const_iterator begin() const
	{
		return _str;
	}
	const_iterator end() const
	{
		return _str + _size;
	}
	const char* c_str() const
	{
		return _str;
	}
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
	void PushBack(char c)
	{
		if (_size == _capacity)
		{
			size_t newc = (_capacity == 0 ? 15 : 2 * _capacity);
			Reserve(newc);
		}
		_str[_size] = c;
		_size++;
		_str[_size] = '\0';
	}
	void PopBack()
	{
		if (_size > 0)
		{
			_str[--_size] = '\0';
		}
	}
	void Resize(size_t n, char c = '\0')
	{
		if (n > _capacity)
		{
			Reserve(n);
		}
		if (n > _size)
		{
			memset(_str + _size, c, n - _size);
		}
		_size = n;
		_str[_size] = '\0';

	}
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
			for (int i = pos + len; i <= _size; i++)
			{
				_str[pos++] = _str[i];
			}
			_size -= len;
		}
	}
	void Append(const char* str)
	{
		size_t sz = strlen(str);
		if (_size + sz > _capacity)
		{
			Reserve(_size + sz);
		}
		strcpy(_str + _size, str);
		_size += sz;
	}
	void Insert(size_t pos, char c)
	{
		assert(pos <= _size);
		if (_size == _capacity)
		{
			size_t newc = (_capacity == 0 ? 15 : _capacity * 2);
			Reserve(newc);
		}
		size_t end = _size;
		while (end > pos)
		{
			_str[end] = _str[end - 1];
			--end;
		}
		_str[pos] = c;
		++_size;
		_str[_size] = '\0';
	}
	void Insert(size_t pos, const char* str)
	{
		assert(pos <= _size);
		size_t len = strlen(str);
		if (_size + len > _capacity)
		{
			Reserve(_size + len);
		}
		size_t  end = _size + len;
		//第一个挪动的是'\0';
		while (end > pos + len - 1)
		{
			_str[end] = _str[end - len];
			--end;
		}
		//插入新的字符串str,不能用strcpy(),
		//会把str中的'\0'一起拷贝过去，导致有效内容被覆盖
		strncpy(_str + pos, str, strlen(str));
		_size += len;
	}
	size_t Find(char c)
	{
		for (int i = 0; i < _size; i++)
		{
			if (_str[i] == c)
			{
				return i;
			}
		}
		return -1;
	}
	size_t Find(size_t pos, const char* str)
	{
		char* posPtr = strstr(_str + pos, str);
		if (posPtr)
		{
			return posPtr - _str;
		}
		else
			return -1;
	}
	String& operator+=(char c)
	{
		PushBack(c);
		return *this;
	}
	String& operator+=(const char* str)
	{
		Append(str);
		return *this;
	}
	String& operator+=(const String& s)
	{
		*this += s._str;
		return *this;
	}

private:
	friend ostream& operator<<(ostream& _cout, const String& s);
	char* _str;
	size_t _capacity;
	size_t _size;
};

void PrintStringIterator(const String& s)
{
	String::const_iterator sit = s.begin();
	while (sit != s.end())
	{
		cout << *sit << " ";
		sit++;
	}
}
//String operator+(const String& s1, const String& s2)
//{
//	String tmp(s1.c_str());
//	//tmp.operator+=(&tmp, s1);
//	/*tmp += s1;*/
//	tmp += s2;
//	return tmp;
//}
ostream& operator<<(ostream& _cout, const String& s)
{
	_cout << s.c_str() << endl;
	return _cout;
}
String operator+(const String& s1, const char* str)
{
	String tmp(s1);
	return tmp += str;  // return tmp
}
String operator+(const String& s1, char c)
{
	String tmp(s1);
	return tmp += c;
}
void teststring3()
{
	String s2;
	s2.PushBack('1');
	s2.PushBack('2');
	s2.PushBack('3');
	s2.Insert(0, "abc");
	s2.Insert(s2.Size(), "def");
	s2.Insert(4, "mon");
	PrintStringIterator(s2);   // abc1mon23def
	cout << s2.Find('a') << endl;  // 0
	cout << s2.Find('q') << endl;  // npos
	cout << s2.Find(0, "def") << endl; // 9
	cout << s2.Find(s2.Size() - 1, "abc") << endl; // npos

	/*size_t max = 0x7fffffff;
	cout << max<< endl;*/


}

void teststring4()
{
	String s;
	s += '0';
	cout << s << endl;  // 0
	s += "123";
	cout << s << endl; // 0123
	String s2("hello");
	s += s2;
	cout << s << endl; // 0123hello

	cout << (s + 'a') << endl;   // 0123helloa
	cout << (s + "world") << endl; // 0123helloworld
	//cout << (s + s2) << endl; // 0123hellohello

}
int main()
{
	teststring3();
	system("pause");
	return 0;
}