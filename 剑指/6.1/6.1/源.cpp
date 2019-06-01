#include<iostream>

using namespace std;
//int main()
//{
//	int ret = 0;
//	int max = 0;
//	int Num = 0;
//	cin >> Num;
//	if (Num < 0 || Num > 255)
//		return -1;
//	while (Num)
//	{
//		if ((Num % 2) == 1)
//		{
//			ret++;
//			if (ret > max)
//				max = ret;
//		}
//		else
//		{
//			ret = 0;
//		}
//		Num >>= 1;
//	}
//	cout << max << endl;
//	system("pause");
//	return 0;
//}

class LCA {
public:
	int getLCA(int a, int b) {
		// write code here
		while (a != b)
		{
			if (a > b)
				a /= 2;
			if (b > a)
				b /= 2;
		}
		return a;
	}
};

int main() {
	int n;
	while (cin >> n)
	{
		int max = 0;
		for (int i = 0; i < 8; i++)
		{
			int count = 0;
			while (((n >> i) & 1) == 1)
			{
				count++;
				i++;
			}
			//一次完了
			if (count > max)
			{
				max = count;
			}
		}
		cout << max << endl;
	}
	return 0;
}
