#include <iostream>
#include <string>
using namespace std;

//�̳���ϵ�л���������඼�ж�����������
//����͸�������ͬ����Ա�������Ա�����θ����ͬ�������ķ��ʣ��Ȿ��Ϊ��ˣ��ض��壩
//    ��ͨ�����ࣺ���غ�����/��Ա  ��ʾ����
//     ��Ա���������ع���ֻҪ�Ǻ�������ͬ�͹�������



//ʵ��һ�����ܱ��̳е���

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

//��Ԫ��ϵ���ܼ̳У�Ҳ����˵������Ԫ���ܷ�������˽�кͱ�����Ա


//���ඨ����static��̬��Ա���������̳���ϵ����ֻ��һ�������ĳ�Ա������
//���ɳ����ٸ����࣬��ֻ��һ��ʵ��
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

	cout << "������" << Person::_count << endl;

	Student::_count = 0;
	cout << "������" << Person::_count << endl;
}
int main()
{
	Test1();
	system("pause");
	return 0;
}