#include <iostream>
using namespace std;

int& Add(int a, int b){
	a = a + b;
	return a;
}
int main(){
	int& ret = Add(1, 2);
	//Add(2, 3);
	cout << ret <<endl;
	system("pause");
	return 0;
}