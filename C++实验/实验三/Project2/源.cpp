#include <iostream>
#include <cstring>
using namespace std;

class Student{
public:
	//构造函数
	Student(string id = "200000000001", string name = "张三", int grade = 0)
		: _id(id),
		_name(name),
		_grade(grade)
	{
	}
	void deplay(){
		cout << "准考证号：" << _id.c_str() << "姓名：" << _name.c_str() << "成绩：" << _grade << endl;
	}

//private:
	const string _id;
	string _name;
	int _grade;
};
void Grade(int g1 = 0, int g2 = 0, int g3 = 0){
	cout << "总成绩：" << (g1 + g2 + g3) << endl;
}
int main(){
	Student s1("201606060624","罗祥云",99);
	Student s2("201606060625", "罗云祥", 99);
	Student s3("201606060626", "祥罗云", 99);
	s1.deplay();
	s2.deplay();
	s3.deplay();
	Grade(s1._grade, s2._grade, s3._grade);
	system("pause");
}