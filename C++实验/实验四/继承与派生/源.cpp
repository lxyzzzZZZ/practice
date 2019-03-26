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
		cout << "��ַ��" << b.m_address.c_str() << endl << "¥�ţ�" << b.m_buildingNum.c_str() << endl;
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
		cout << "���ţ�" << h.m_HouseNum.c_str() << endl << "�����" << h.m_HouseArea << endl;
	}

};

class Office : public Building
{
public:
	string m_OfficeName;
	string m_TelephoneNum;

	Office(string address = "00", string buildingNum = "000",string name = "��", string telephoneNum = "000-0000000")
		:m_OfficeName(name),
		m_TelephoneNum(telephoneNum)
	{
		m_address = address;
		m_buildingNum = buildingNum;
	}

	void Oprint(Office o)
	{
		cout << "�칫�����֣�" << o.m_OfficeName.c_str() << endl << "�칫�ҵ绰��" << o.m_TelephoneNum.c_str() << endl;
	}
};

int main()
{
	Building b("��������ΰΰ����С��","02");
	b.Bprint(b);
	House h("��������ΰΰ����С��", "02","022", 222.22);
	h.Bprint(h);
	h.Hprint(h);
	Office o("��������ΰΰ����С��", "02", "ΰΰ�Ƽ�", "438-3838438");
	o.Bprint(o);
	o.Oprint(o);
	system("pause");
	return 0;
}