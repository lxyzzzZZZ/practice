#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int M, N;
	cin >> M;
	cin >> N;
	vector<int> arr;
	while (M > 0)
	{
		arr.push_back(M%N);
		M = (M - M % N) / N;
	}
	string str;
	char c;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] > 9)
		{
			c = (char)"A" + (arr[i] - 10);
			str.push_back(c);
		}
		else
		{
			c = (char)"0" + (arr[i] - '0');
			str.push_back(c);
		}
	}
	for (int i = str.size() - 1; i >= 0; i--)
	{
		cout << str[i];
	}
	system("pause");
	return 0;
}
// A-B A+C A+B B -C
//int main()
//{
//	vector<int> arr;
//	int num;
//	while (cin >> num)
//	{
//		arr.push_back(num);
//	}
//	int A = (arr[0] + arr[2]);
//	int B = A - arr[0];
//	int C = B - arr[3];
//	if ((A - B) == arr[0] && (A + C) == arr[1]
//		&& (A + B) == arr[2] && (B - C) == arr[2])
//	{
//		cout << A << " " << B << " " << C << endl;
//	}
//	else
//	{
//		cout << "No" << endl;
//	}
//	system("pause");
//	return 0;
//}