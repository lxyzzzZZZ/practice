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
////Print()已变
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

//派生类赋值给基类  切片
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

	//出错
	//sobj = pobj;
	//不过可以通过强制类型转换 完成赋值
	pp = &sobj;
	Student* ps1 = (Student*)pp;
	cout << ps1->_No << endl;
	
	//会出现访问越界的问题，相当于pobj只管理4个字节的东西，第五个不归他管
	//而上面的那种，pp是由student对象转换过的，所以被强制回student第五个空
	//闲下来的依旧可以访问
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