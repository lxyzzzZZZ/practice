#include <iostream>
using namespace std;

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day){
		//if (getday(year, month, day) == true){
		//	_year = year;
		//	_month = month;
		//	_day = day;
		//}
		if (getday(year, month, day) == false){
			cout << "输入有误，已改为默认日期" << endl;
			_year = 1900;
			_month = 1;
			_day = 1;
		}

	}
	Date(const Date& d){
			_year = d._year;
			_month = d._month;
			_day = d._day;
	}
	bool getday(int year, int month, int day){
		int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
			days[1] = 29;
		}
		if (year <= 0 || month <= 0 || month > 12 || day >= days[month-1] || day <=0 ){
			return false;
		}
		//else{
		//	_year = year;
		//	_month = month;
		//	_day = day;
		//}
		return true;
	}
	Date& operator=(const Date& d){
		if (this != &d){
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
	Date operator+(int days){
		int day[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		while (days > 0){
			if ((_year % 4 == 0 && _year % 100 != 0) || _year % 400 == 0){
				day[1] = 29;
			}
			int d = days + _day;
			if (d > day[_month - 1]){
				++_month;
				if (_month > 12){
					++_year;
					_month = 1;
				}
				_day = d - day[_month - 1];
				days = _day;
			}
			else{
				_day = d;
				days = 0;
			}
		}
		return *this;
	}
	Date operator-(int days){
		int day[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		while (days > 0 ){
			if ((_year % 4 == 0 && _year % 100 != 0) || _year % 400 == 0){
				day[1] = 29;
			}
			int d = _day - days;
			if (d <= 0){
				--_month;
				if (_month <= 0){
					--_year;
					_month = 12;
				}
				_day = day[_month - 1];
				days = days - _day;
			}
			else{
				_day = d;
				days = 0;
			}
		}
		return *this;
	}
	Date operator+=(int days){
		return (*this = (*this + days));
	}
	Date operator-=(int days){
		return (*this = (*this - days));
	}
	int operator-(const Date& d);
	Date& operator++(){
		return *this = *this + 1;
	}
	Date operator++(int){
		Date ret(*this);
		*this = *this + 1;
		return ret;
	}
	Date& operator--(){
		return *this = *this - 1;
	}
	Date operator--(int){
		Date ret(*this);
		*this = *this - 1;
		return ret;
	}
	bool operator>(const Date& d) const {
		if (_year > d._year){
			return true;
		}
		else if (_year == d._year && _month > d._month){
			return true;
		}
		else if (_year == d._year && _month == d._month&&_day > d._day){
			return true;
		}
		return false;
	}
	bool operator>=(const Date& d) const {
		if (_year >= d._year){
			return true;
		}
		else if (_year == d._year && _month >= d._month){
			return true;
		}
		else if (_year == d._year && _month == d._month&&_day >= d._day){
			return true;
		}
		return false;
	}
	bool operator<(const Date& d) const {
		if (_year < d._year){
			return true;
		}
		else if (_year == d._year && _month < d._month){
			return true;
		}
		else if (_year == d._year && _month == d._month&&_day < d._day){
			return true;
		}
		return false;
	}
	bool operator<=(const Date& d) const {
		if (_year <= d._year){
			return true;
		}
		else if (_year == d._year && _month <= d._month){
			return true;
		}
		else if (_year == d._year && _month == d._month&&_day <= d._day){
			return true;
		}
		return false;
	}
	bool operator==(const Date& d) const {
		return _year == d._year&&
			_month == d._month&&
			_day == d._day;
	}
	bool operator!=(const Date& d) const {
		return !operator==(d);
	}
	void display(){
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};void main(){	Date d1(2025, 7, 14);	Date d2(2015, 1, 25);	d1 -= 14;	d1.display();	cout << (d1 > d2) << endl;	system("pause");}