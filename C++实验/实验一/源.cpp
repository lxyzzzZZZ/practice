#include <iostream>
#include <math.h>
using namespace std;

int main(){
	int i = 0;
	int j = 0;
	for (i = 2; i <= 100; i++){
		int k = 0;
		for (j = 1; j <= sqrt(i); j++){
			if (i % j == 0)
				++k;
			}
		if (k == 1){
			cout << i << endl;
		}
	}
	system("pause");
	return 0;
}