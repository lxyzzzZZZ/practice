// write your code here cpp
#include <string>
#include <iostream>
//#include <vector>
using namespace std;

int main()
{
	string A, B;
	while (cin >> A >> B)
	{
		int lena = A.size();
		int lenb = B.size();
		int arr[lena][lenb];
		arr[0][0] = (A[0] == B[0]) ? 1 : 0;
		for (int i = 1; i < lena; i++)
		{
			arr[i][0] = (A[i] == B[0]) ? 1 : 0;
			arr[i][0] = arr[i][0] > arr[i - 1][0] ? arr[i][0] : arr[i - 1][0];
		}
		for (int i = 1; i < lenb; i++)
		{
			arr[0][i] = (A[0] == B[i]) ? 1 : 0;
			arr[0][i] = arr[0][i] > arr[0][i - 1] ? arr[0][i] : arr[0][i - 1];
		}
		for (int i = 1; i < lena; i++)
			for (int j = 1; j < lenb; j++)
			{
				arr[i][j] = arr[i - 1][j] > arr[i][j - 1] ? arr[i - 1][j] : arr[i][j - 1];
				if (A[i] == B[j])
					arr[i][j] = arr[i - 1][j - 1] + 1 > arr[i][j] ? arr[i - 1][j - 1] + 1 : arr[i][j];
			}
		cout << arr[lena - 1][lenb - 1] << endl;
	}
	return 0;
}

#include<iostream>
#include<string>
#include<math.h>
using namespace std;
int main()
{
	string str1, str2;
	int len1, len2;
	while (cin >> str1 >> str2 >> len1 >> len2)
	{
		int i, j, l1, l2, num = 0;
		for (i = len1; i <= len2; i++)
			for (j = 0; j < i; j++)
				num += (str2[j] - str1[j]) * pow(26, i - j - 1);
		cout << num - 1 << endl;
	}
}