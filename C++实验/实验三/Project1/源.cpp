#include <iostream>
#include <math.h>
using namespace std;
void fun(int r){
	double S = 0;
	double L = 0;
	S = (pow((3 + r), 2) - pow(3, r)) * 3.14 * 35;
	L = 2 * 3.14*(3 + r) * 20;
	cout << "��������:" << S << endl << "դ������:" << L << endl;
}

int main(){
	double  r = 0;
	cin >> r ;
	fun(r);
	system("pause");
}