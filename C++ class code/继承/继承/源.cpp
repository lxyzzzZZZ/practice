#include <iostream>
#include <string>
using namespace std;

//class Person
//{
//public :
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age: " << _age << endl;
//	}
//private:
//	string _name = "luoxiangyun";
//	size_t _age = 10;
//};
//
//class Student : public Person
//{
//protected:
//	int _stud;
//};
//
////Print()�ѱ�
//class Teather : public Person
//{
//protected:
//	int _jobid;
//};
//
//class Worker : public Teather
//{
//
//};

//void Test0()
//{
//	Student s;
//	Teather t;
//	Worker w;
//	s.Print();
//	t.Print();
//	w.Print();
//}

//�����ำֵ������  ��Ƭ
class Person
{
protected:
	string _name;
	string _sex;
	int age;
};

class Student : public Person
{
public:
	int _No;
};

void Test()
{
	Student sobj;
	Person pobj = sobj;

	Person* pp = &sobj;
	Person& rp = sobj;

	//����
	//sobj = pobj;
	//��������ͨ��ǿ������ת�� ��ɸ�ֵ
	pp = &sobj;
	Student* ps1 = (Student*)pp;
	cout << ps1->_No << endl;
	
	//����ַ���Խ������⣬�൱��pobjֻ����4���ֽڵĶ������������������
	//����������֣�pp����student����ת�����ģ����Ա�ǿ�ƻ�student�������
	//�����������ɿ��Է���
	pp = &pobj;
	Student* ps2 = (Student*)pp;
	//ps2->_No = 10;
}




int main()
{
	Test();
	system("pause");
	return 0;
}