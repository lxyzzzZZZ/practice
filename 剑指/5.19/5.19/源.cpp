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
//	string _name = "peter"; // ����
//	int _age = 18; // ����
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
//	string _name = "peter"; // ����  // min(4, 8)
//	int _age = 18; // ����
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
//	//���أ���ͬһ���������£���������ͬ,������ͬ
//	//�ض���/���أ�����ĳ�Ա�����븸���Ա����������ͬ������ͬ������
//	int fun()
//	{
//		cout << "fun()" << endl;
//	}
//
//private:
//	//����ĳ�Ա�����ڸ����Ա����������ͬ������ͬ������
//	int _id = 2019;
//};

//int main()
//{
//	//int a = 10;
//	//float f = 3.2;
//	//a = f;  // ��ʽ��������: ���͵�����ӽ�
//	//int* pa = (int*) a;  // ǿ������ת��
//	//A oa;
//	//B ob;
//
//	Person p;
//	p._age = 18;
//	Student s;
//	s._id = 2019;
//	p = s;  //��Ƭ��������ת��������
//	cout << p._age << endl;
//	//����������κθ�ֵ����֧�ֵģ���Ƭ����
//	Person& rp = s;
//	Person* pp = &s;
//	//��������ܸ����������
//	//s = p;
//	Person* sp = &s;  // spָ���������
//	//Student* ps = (Student*) &p;  //����ָ�븳������ָ�룺����ȫ������Խ��
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
//	//���������������ʽ���ø���Ŀ������죬�ڱ������Զ����ø����Ĭ�Ϲ��캯��
//	//������������ɵ�����Ŀ������죬���Զ����ø���Ŀ�������
//	Student(const Student& s)
//		:Person(s)
//	{
//		//strcpy(_name, s._name);
//	}
//	//������������ɵ�����ĸ�ֵ��������غ��������Զ����ø���ĸ�ֵ��������غ���
//	//�������ʽ���ø���ĸ�ֵ��������غ����������������Զ����ø���ĸ�ֵ��������غ���
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
//		//�������������Ҫ��ʽ��д���������Զ�����
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
//	string _name; // ����
//public:
//	static int _si;
//};
//
//int Person::_si = 0;
//class Student : public Person
//{
//protected:
//	//friend void Display(const Person& p, const Student& s);
//	int _stuNum; // ѧ��
//};
//void Display(const Person& p, const Student& s)
//{
//	cout << p._name << endl;
//	//�Ӹ����м̳еĳ�Ա���������Ԫ�������Է���
//	cout<<s._name<<endl;
//	//�������Ԫ�������ܷ��������Զ����˽�кͱ�����Ա
//	//cout << s._stuNum << endl;
//}
//
//class Student2 : public Person
//{
//protected:
//	//friend void Display(const Person& p, const Student& s);
//	int _stuNum; // ѧ��
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
	string _name; // ����
};
//��������̳н����������Ͷ�����
class Student : virtual public Person
{
	//protected:
public:

	int _num; //ѧ��
};
class Teacher : virtual public Person
{
	//protected:
public:

	int _id; // ְ�����
};
class Assistant : public Student, public Teacher
{
	//protected:
public:
	string _majorCourse; // ���޿γ�
	// _name, _num, _name, _id, _majorCourse
};

int main()
{
	Assistant assist;
	assist._id = 10;
	//���ʲ���ȷ
	//assist._name = "h234";
	assist.Student::_name = "000";
	assist.Teacher::_name = "111";
	return 0;
}