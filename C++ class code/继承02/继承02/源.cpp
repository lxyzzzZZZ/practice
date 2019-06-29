#include <iostream>
#include <string>
using namespace std;

//继承体系中基类和派生类都有独立的作用域
//子类和父类中又同名成员，子类成员将屏蔽父类对同名函数的访问，这本称为因此（重定义）
//    可通过基类：隐藏函数名/成员  显示访问
//     成员函数的隐藏构成只要是函数名相同就构成隐藏



//实现一个不能被继承的类

class NoneInherit
{
public:
	static NoneInherit GetInstance()
	{
		return NoneInherit();
	}
private:
	NoneInherit();
};

class noneinherit final
{

};

//友元关系不能继承，也就是说基类友元不能访问子类私有和保护成员


//基类定义了static静态成员，则整个继承体系里面只有一个这样的成员，无论
//生成出多少个子类，都只有一份实例
class Person
{
public:
	Person()
	{
		++_count;
	}
protected:
	string _name;
public:
	static int _count;
	
};

int Person::_count = 0;

class Student : public Person
{
protected:
	int _stuNum;
};


class Graduate : public Student
{
protected:
	string _seminarCourse;
};

void Test1()
{
	Student s1;
	Student s2;
	Student s3;
	Student s4;
	Graduate s5;

	cout << "人数：" << Person::_count << endl;

	Student::_count = 0;
	cout << "人数：" << Person::_count << endl;
}
int main()
{
	Test1();
	system("pause");
	return 0;
}