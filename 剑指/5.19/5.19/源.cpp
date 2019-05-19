#pragma  pack(8)
#include <iostream>
#include <string>
using namespace std;
//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//protected:
////private:
//	string _name = "peter"; // 姓名
//	int _age = 18; // 年龄
//};
//
////class  Student : public Person
////class  Student : protected Person
////class  Student : private Person
//
//{
//public:
//	void fun()
//	{
//		//_name = "djslg";
//		//_age = 10;
//	}
//};
//
//int main()
//{
//	Person p;
//	p.Print();
//	Student s;
//	s._age = 10;
//	s.Print();
//	cout << sizeof(string) << endl;
//	cout << sizeof(Person) << endl;
//	cout << sizeof(Student) << endl;
//	return 0;
//}

//class A
//{};
//
//class B
//{};
//
//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//		cout << "id:" << _id << endl;
//	}
//
//	int fun(int a, int b, int c)
//	{
//		cout << "fun(int a, int b, int c)" << endl;
//	}
////protected:
////private:
//	string _name = "peter"; // 姓名  // min(4, 8)
//	int _age = 18; // 年龄
//	int _id = 1111;
//};
//
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//		cout << "id:" << _id << endl;
//		cout << "id:" << Person::_id << endl;
//	}
//
//	//重载：在同一个作用域下，函数名相同,参数不同
//	//重定义/隐藏：子类的成员函数与父类成员函数名称相同，构成同名隐藏
//	int fun()
//	{
//		cout << "fun()" << endl;
//	}
//
//private:
//	//子类的成员变量于父类成员变量名称相同，构成同名隐藏
//	int _id = 2019;
//};

//int main()
//{
//	//int a = 10;
//	//float f = 3.2;
//	//a = f;  // 隐式类型类型: 类型的意义接近
//	//int* pa = (int*) a;  // 强制类型转换
//	//A oa;
//	//B ob;
//
//	Person p;
//	p._age = 18;
//	Student s;
//	s._id = 2019;
//	p = s;  //切片：不存在转换，割肉
//	cout << p._age << endl;
//	//子类向父类的任何赋值都是支持的，切片操作
//	Person& rp = s;
//	Person* pp = &s;
//	//父类对象不能赋给子类对象
//	//s = p;
//	Person* sp = &s;  // sp指向子类对象
//	//Student* ps = (Student*) &p;  //父类指针赋给子类指针：不安全，访问越界
//	Student* ps = (Student*) sp;  // dynamic_cast
//
//	Student* pps = &s;
//	cout << ps->_id << endl;
//	cout << pps->_id << endl;
//	/*int i = 200000;
//	char* pc = (char*)&i;
//	int* pi = &i;
//	Person* ppi = (Person*)&i;
//	printf("pi: %p\n", pi);
//	printf("pc: %p\n", pc);
//	cout << *pc << endl;
//	cout <<*pi << endl;*/
//	//cout << "ppi: " << ppi << " " << (int) (*ppi) << endl;
//	
//	return 0;
//	//oa = ob;  
//	//*pa = 10;
//}

//int main()
//{
//	Person p;
//	Student s;
//	p.Print();
//	p.fun(1, 2, 3);
//	/*cout << "Student : Print" << endl;
//	s.Print();
//	cout << "Student.Person :: Print" << endl;
//	s.Person::Print();*/
//	s.fun();
//	s.Person::fun(1, 2, 3);
//	//cout << sizeof(Person) << endl;  // 36
//	//cout << sizeof(Student) << endl; // 40
//	return 0;
//}

//class Person
//{
//public:
//	Person(const char* name = "123")
//		: _name(name)
//	{
//		cout << "Person()" << endl;
//	}
//	Person(const Person& p)
//		: _name(p._name)
//	{
//		cout << "Person(const Person& p)" << endl;
//	}
//	Person& operator=(const Person& p)
//	{
//		cout << "Person operator=(const Person& p)" << endl;
//		if (this != &p)
//			_name = p._name;
//		return *this;
//	}
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//	void fun()
//	{}
//protected:
//	string _name;
//};
//
//class Student : public Person
//{
//public:
//	Student(char* str = "123")
//		:Person(str)
//	{
//		cout << "Student()" << endl;
//		//strcpy(_name, str);
//	}
//	//拷贝构造如果不显式调用父类的拷贝构造，在编译器自动调用父类的默认构造函数
//	//如果编译器生成的子类的拷贝构造，会自动调用父类的拷贝构造
//	Student(const Student& s)
//		:Person(s)
//	{
//		//strcpy(_name, s._name);
//	}
//	//如果编译器生成的子类的赋值运算符重载函数，会自动调用父类的赋值运算符重载函数
//	//如果不显式调用父类的赋值运算符重载函数，编译器不会自动调用父类的赋值运算符重载函数
//	Student& operator=(const Student& s)
//	{
//		if (this != &s)
//		{
//			//_name = s._name;
//			Person::operator=(s);
//		}
//		return *this;
//	}
//
//	~Student()
//	{
//		//父类的析构不需要显式的写，编译器自动调用
//		//~Person();  // destructor
//		//fun();
//		cout << "~Student()" << endl;
//	}
//
//	void fun()
//	{
//		cout << _name << endl;
//	}
//};
//
//int main()
//{
//	Student s;
//	//Student copy(s);
//	//s = copy;
//
//	return 0;
//}

//class Student;
//class Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);
//protected:
//	string _name; // 姓名
//public:
//	static int _si;
//};
//
//int Person::_si = 0;
//class Student : public Person
//{
//protected:
//	//friend void Display(const Person& p, const Student& s);
//	int _stuNum; // 学号
//};
//void Display(const Person& p, const Student& s)
//{
//	cout << p._name << endl;
//	//从父类中继承的成员，父类的友元函数可以访问
//	cout<<s._name<<endl;
//	//父类的友元函数不能访问子类自定义的私有和保护成员
//	//cout << s._stuNum << endl;
//}
//
//class Student2 : public Person
//{
//protected:
//	//friend void Display(const Person& p, const Student& s);
//	int _stuNum; // 学号
//
//};



//int main()
//{
//	/*Person p;
//	Student s;
//	Display(p, s);*/
//
//	Person p;
//	Person p2;
//	p._si = 1;
//	Student s;
//	Student s3;
//	s._si = 2;
//	Student2 s2;
//	Student2 s4;
//	s2._si = 3;
//
//	cout << &p._si << endl;
//	cout << &s._si << endl;
//	cout << &s2._si << endl;
//	return 0;
//
//}

class Person
{
public:
	string _name; // 姓名
};
//菱形虚拟继承解决数据冗余和二义性
class Student : virtual public Person
{
	//protected:
public:

	int _num; //学号
};
class Teacher : virtual public Person
{
	//protected:
public:

	int _id; // 职工编号
};
class Assistant : public Student, public Teacher
{
	//protected:
public:
	string _majorCourse; // 主修课程
	// _name, _num, _name, _id, _majorCourse
};

int main()
{
	Assistant assist;
	assist._id = 10;
	//访问不明确
	//assist._name = "h234";
	assist.Student::_name = "000";
	assist.Teacher::_name = "111";
	return 0;
}