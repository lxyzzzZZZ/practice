#include <iostream>
#include <string>
using namespace std;
class Building
{
public:
	string  m_address;
	string m_buildingNum;

	Building(string address = "00", string buildingNum = "000")
		:m_address(address),
		m_buildingNum(buildingNum)
	{
		;
	}

	void Bprint(Building b)
	{
		cout << "地址：" << b.m_address.c_str() << endl << "楼号：" << b.m_buildingNum.c_str() << endl;
	}
};

class House : public Building
{
public:
	string m_HouseNum;
	double m_HouseArea;

	House(string address = "00", string buildingNum = "000",string HouseNum = "000", double HouseArea = 0.0)
		:m_HouseNum(HouseNum),
		m_HouseArea(HouseArea)
	{
		m_address = address;
		m_buildingNum = buildingNum;
	}

	void Hprint(House h)
	{
		cout << "房号：" << h.m_HouseNum.c_str() << endl << "面积：" << h.m_HouseArea << endl;
	}

};

class Office : public Building
{
public:
	string m_OfficeName;
	string m_TelephoneNum;

	Office(string address = "00", string buildingNum = "000",string name = "空", string telephoneNum = "000-0000000")
		:m_OfficeName(name),
		m_TelephoneNum(telephoneNum)
	{
		m_address = address;
		m_buildingNum = buildingNum;
	}

	void Oprint(Office o)
	{
		cout << "办公室名字：" << o.m_OfficeName.c_str() << endl << "办公室电话：" << o.m_TelephoneNum.c_str() << endl;
	}
};

int main()
{
	Building b("西安市岳伟伟海景小区","02");
	b.Bprint(b);
	House h("西安市岳伟伟海景小区", "02","022", 222.22);
	h.Bprint(h);
	h.Hprint(h);
	Office o("西安市岳伟伟海景小区", "02", "伟伟科技", "438-3838438");
	o.Bprint(o);
	o.Oprint(o);
	system("pause");
	return 0;
}