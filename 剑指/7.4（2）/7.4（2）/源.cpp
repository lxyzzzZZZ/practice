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
//	 *  ����λ�϶�����������ż��λ�϶���ż��
//	 *  ���룺����arr�����ȴ���2
//	 *  len��arr�ĳ���
//	 *  ��arr����������λ�϶�����������ż��λ�϶���ż��
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