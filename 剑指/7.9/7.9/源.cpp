//// write your code here cpp
//#include <iostream>
//
//using namespace std;
//
//int main() {
//	int year1, month1, day1, year2, month2, day2;
//	int d[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	while (cin >> year1 >> month1 >> day1 >> year2 >> month2 >> day2)
//	{
//		int sum = 0;
//		int year = year1;
//		//�����������ж��Ƿ�Ϊ����
//		for (int i = year1; i <= year2 - 1; ++i) {
//			if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) sum += 580;
//			else  sum += 579;
//		}
//		//��Ϊ���ϸ�ѭ���ǽ�һ�����ʱ�䶼���ȥ�ˣ�
//		//������Ҫ��ȥһ�����Ѿ���ȥ��������׬��Ǯ
//		for (int i = 0; i <= month1 - 1; ++i) {
//			int temp = 0;
//			if (i == month1 - 1)
//				temp = day1 - 1;
//			else
//				temp = d[i];
//			//�Ƿ�Ϊ�����·�
//			if (i != 1 && i != 2 && i != 4 && i != 6 && i != 10)
//				sum -= temp * 2;
//			else
//				sum -= temp;
//		}
//		//���Ͻϴ���ݵ��·���׬��Ǯ
//		for (int i = 0; i <= month2 - 1; ++i) {
//			int temp = 0;
//			if (i == month2 - 1)
//				temp = day2;
//			else
//				temp = d[i];
//			//�Ƿ�Ϊ�����·�
//			if (i != 1 && i != 2 && i != 4 && i != 6 && i != 10)
//				sum += temp * 2;
//			else
//				sum += temp;
//		}
//		cout << sum << endl;
//
//	}
//
//
//	return 0;
//}
//
//
//// write your code here cpp
//#include <iostream>
//#include <vector>
//#include <iomanip>
//using namespace std;
//
//int main()
//{
//	int n;
//	vector<int> arr;
//	arr.resize(1000001);
//	arr[0] = 1;
//	arr[1] = 1;
//	for (int i = 2; i < arr.size(); i++)
//	{
//		arr[i] = (arr[i - 1] + arr[i - 2]) % 1000000;
//	}
//	while (cin >> n)
//	{
//		if (n < 29)
//			cout << arr[n] << endl;
//		else
//			cout << setfill('0') << setw(6) << arr[n] << endl;
//	}
//	return 0;
//}