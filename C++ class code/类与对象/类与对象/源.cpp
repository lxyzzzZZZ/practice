#include <iostream>
using namespace std;
class Person
{
public:
	void PrintPersonInfo();
private:
	char _name[20];
	char _gender[3];
	int _age;
};

void Person::PrintPersonInfo()
{
	cout << _name << " " << _gender << _age << endl;
}

class A1
{
public:
	void f1()
	{}
private:
	int _a;
};

class Date
{
public:
	void Display()
	{
		cout << _year << "-" << _month << "-" << _day << endl;

	}
	void SetDate(int year, int month, int day)
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

