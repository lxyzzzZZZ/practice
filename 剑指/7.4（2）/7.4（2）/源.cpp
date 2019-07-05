//// write your code here cpp
//#include <iostream>
//#include <cmath>
//using namespace std;
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		if (n == 0)
//		{
//			break;
//		}
//		long a = pow(5, n) - 4;
//		long b = pow(4, n) + n - 4;
//		cout << a << " " << b << endl;
//	}
//	return 0;
//}
//
//class Solution {
//public:
//	/**
//	 *  奇数位上都是奇数或者偶数位上都是偶数
//	 *  输入：数组arr，长度大于2
//	 *  len：arr的长度
//	 *  将arr调整成奇数位上都是奇数或者偶数位上都是偶数
//	 */
//	void oddInOddEvenInEven(vector<int>& arr, int len) {
//		int i = 0, j = 1;
//		while (i < len && j < len)
//		{
//			if (arr[len - 1] % 2 == 0)
//			{
//				swap(arr[len - 1], arr[i]);
//				i += 2;
//			}
//			else
//			{
//				swap(arr[len - 1], arr[j]);
//				j += 2;
//			}
//		}
//	}
//};