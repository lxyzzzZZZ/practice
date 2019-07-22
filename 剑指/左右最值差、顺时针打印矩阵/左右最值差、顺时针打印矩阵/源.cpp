#include <iostream>
#include <string>;
#include <vector>
using namespace std;
class MaxGap {
public:
	int findMaxGap(vector<int> A, int n) {
		// write code here
		//int N = 0;
		int Max = 0;
		int a, b;
		for (int K = 0; K < n - 1; K++)
		{
			a = b = 0;
			for (int i = 0; i <= K; i++)
				a = a < A[i] ? A[i] : a;
			for (int j = K + 1; j <= n - 1; j++)
				b = b < A[j] ? A[j] : b;
			int ret = a > b ? a - b : b - a;
			Max = Max < ret ? ret : Max;
		}
		return Max;
	}
};

class Printer {
public:
	vector<int> clockwisePrint(vector<vector<int> > mat, int n, int m) {
		// write code here
		vector<int> ret;
		int x1 = 0, y1 = 0;
		int x2 = n - 1, y2 = m - 1;
		while (x1 <= x2 && y1 <= y2) {
			for (int j = y1; j <= y2; ++j)
				ret.push_back(mat[x1][j]);
			for (int i = x1 + 1; i < x2; ++i)
				ret.push_back(mat[i][y2]);
			for (int j = y2; x1 < x2 && j >= y1; --j)
				ret.push_back(mat[x2][j]);
			for (int i = x2 - 1; y1 < y2 && i > x1; --i)
				ret.push_back(mat[i][y1]);
			x1++; y1++;
			x2--; y2--;
		}
		return ret;
	}
};

class MaxGap {
public:
	int findMaxGap(vector<int> A, int n) {
		// write code here
		//int N = 0;
		int Max = 0;
		for (int i = 0; i < n; i++)
			Max = Max < A[i] ? A[i] : Max;
		int Min = A[0] > A[n - 1] ? A[n - 1] : A[0];
		return Max - Min;
	}
};