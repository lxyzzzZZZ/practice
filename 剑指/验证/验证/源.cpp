#include <iostream>

using namespace std;


class A
{
public:
	double a;
private:
	int b;
	double c;
};

class B : public A
{

};

int main()
{
	cout << sizeof(A) << endl;
	cout << sizeof(B) << endl;

	system("pause");
	return 0;
}