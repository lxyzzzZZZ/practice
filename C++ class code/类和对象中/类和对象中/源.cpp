#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

//1.类的六个默认成员函数

class Date
{
public:
	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	//无参构造函数
	Date()
	{}
	//带参构造函数
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;
};


typedef int DataType;
class SeqList
{
public:
	SeqList(int capacity = 10)
	{
		_pData = (DataType*)malloc(capacity * sizeof(DataType));
		assert(_pData);
		_size = 0;
		_capacity = capacity;
	}

	~SeqList()
	{
		if (_pData)
		{
			free(_pData);
			_pData = nullptr;
			_capacity = 0;
			_size = 0;
		}
	}
private:
	int* _pData;
	size_t _size;
	size_t _capacity;
};

//explicit关键字
//构造函数不仅可以构造与初始化对象，
//对于单个参数的构造函数，还具有类型转换的作用。
class date
{
public:
	date(int year)
		: _year(year)
	{

	}
	explicit date (int year)
		:_year(year)
	{}
private:
	int _year;
	int _month;
	int _day;
};




//友元函数

class date
{
	friend ostream& operator<<(ostream& _cout, const date& d);
	friend ostream& operator>>(ostream& _cin, const date& d);
public:
	date(int year, int month, int day)
		:_year(year)
		,_month(month)
		,_day(day)
	{}
	ostream& operator<<(ostream& _cout)
	{
		_cout << _year << "-" << _month << "-" << _day;
		return _cout;
	}
private:
	int _year;
	int _month;
	int _day;
};
