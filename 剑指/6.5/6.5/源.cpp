#include <iostream>
#include <vector>
using namespace std;

//static int a = 4;
//
//void fun()
//{
//	static int a = 1;
//}
//void fun2()
//{
//	a = 2;
//}


static int count2 = 0;
class A
{
public:
	A()
	{
		count2++;
	}
	void foo()
	{
		delete this;
	}
};
int main()
{
	//fun();
	//cout << a << endl;
	//fun2();
	//cout << a << endl;
	A c[3];
	A* a = c;
	cout << count2 << endl;
	//A* a = new A();
	//a->foo();
	vector<int> arr;
	system("pause");
	return 0;
}

class Gloves {
public:
	int min(int a, int b)
	{
		if (a > b)
			return b;
		return a;
	}
	int findMinimum(int n, vector<int> left, vector<int> right) {
		// write code here
		int sum = 0;
		int lsum = 0;
		int rsum = 0;

		int lmin = 26;
		int rmin = 26;
		for (int i = 0; i < n; ++i)
		{
			if (left[i] * right[i] == 0)
				sum = left[i] + right[i] + sum;
			else
			{
				lsum += left[i];
				rsum += right[i];

				lmin = min(lmin, left[i]);
				rmin = min(rmin, right[i]);
			}

		}
		return (sum + min(lsum - lmin + 1, rsum - rmin + 1) + 1);
	}
};


#include <iostream>

using namespace std;

int main()
{
	int N = 0;
	while (cin >> N)
	{
		int count = 0;
		while (N)
		{
			if (N & 1 == 1)
				count++;
			N >>= 1;
		}
		cout << count << endl;
	}
}