#include <iostream>

using namespace std;

class Vehicle
{
protected:
	size_t Wheels;
	size_t Weight;
public:
	Vehicle(size_t _Wheels = 4, size_t _Weight = 0)
		:Wheels(_Wheels)
		,Weight(_Weight)
	{}
	virtual void show()
	{
		cout << "车轮个数：" << Wheels << endl;
		cout << "车重：" << Weight << endl;
	}
};

class Car : private Vehicle
{
private:
	size_t passenger_load;
public:
	Car(size_t _Wheels = 4, size_t _Weight = 0, size_t _passenger = 1)
		:Vehicle(_Wheels, _Weight)
		,passenger_load(_passenger)
	{}
	virtual void show()
	{
		cout << "车轮个数：" << Wheels << endl;
		cout << "车重：" << Weight << endl;
		cout << "人数：" << passenger_load << endl;
	}
};

class Tuck : private Vehicle
{
private:
	size_t passenger_load;
	size_t payload;
public:
	Tuck(size_t _Wheels = 4, size_t _Weight = 0, size_t _passenger = 1, size_t _payload = 0)
		:Vehicle(_Wheels, _Weight)
		, passenger_load(_passenger)
		,payload(_payload)
	{}
		virtual void show()
		{
			cout << "车轮个数：" << Wheels << endl;
			cout << "车重：" << Weight << endl;
			cout << "人数：" << passenger_load << endl;
			cout << "载重量：" << payload << endl;
		}
};


int main()
{
	Vehicle A(1, 2);
	Car B(4, 5, 6);
	Tuck C(7, 8, 9, 10);
	A.show();
	B.show();
	C.show();
	system("pause");
	return 0;
}