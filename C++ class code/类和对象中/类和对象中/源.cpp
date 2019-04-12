#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

//1.�������Ĭ�ϳ�Ա����

class Date
{
public:
	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	//�޲ι��캯��
	Date()
	{}
	//���ι��캯��
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

//explicit�ؼ���
//���캯���������Թ������ʼ������
//���ڵ��������Ĺ��캯��������������ת�������á�
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




//��Ԫ����

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
