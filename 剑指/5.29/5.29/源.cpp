//#include <iostream>
//using namespace std;
//
//
//class UnusualAdd {
//public:
//	int addAB(int A, int B) {
//		// write code here
//		int a = A ^ B;
//		int b = A & B;
//		b = b << 1;
//		A = a;
//		B = b;
//		while (B)
//		{
//			a = A ^ B;
//			b = A & B;
//			b = b << 1;
//			A = a;
//			B = b;
//		}
//		return a;
//	}
//};
//for (int i = 1; i <= m; i++)
//{
//	s[1][i] = 1;
//}
//for (int j = 1; j <= n; j++)
//{
//	s[j][1] = 1;
//}
//
////填表：从左到右，从上到下
//for (int i = 2; i <= n; i++)
//{
//	for (int j = 2; j <= m; j++)
//	{
//		s[i][j] = s[i - 1][j] + s[i][j - 1];
//		//s[i - 1][j] -- 左
//		//s[i][j - 1] -- 上
//	}
//}
//
//return s[n][m];