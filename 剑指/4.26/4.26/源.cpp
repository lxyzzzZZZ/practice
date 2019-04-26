#include <iostream>

using namespace std;
int  movingCount(int th, int rows, int cols)
{
	if (th < 0 || rows <= 0 || cols <= 0)
	{
		return ;
	}
	bool* visit = new bool[rows *cols];
	for (int i = 0; i < rows*cols; i++)
	{
		visit = false;
	}
	int count = movingCountCore(th, rows, cols, 0, 0, visit);
	delete[] visit;
	return count;
}
int movingCountCore(int th, int rows, int cols, int row, int col, bool* visit)
{
	int count = 0;
	if (check(th, rows, cols, row, col, visit))
	{
		visit[row*col + 1] = true;

		count = 1 + movingCountCore(th, rows, cols, row - 1, col, visit)
			+ movingCountCore(th, rows, cols, row, col - 1, visit)
			+ movingCountCore(th, rows, cols, row, col + 1, visit)
			+ movingCountCore(th, rows, cols, row, col + 1, visit);
	}
	return count;
}
bool check(int th, int rows, int cols, int row, int col, bool* visit)
{
	if (row >= 0 && row < rows&& col >= 0 && col < cols
		&& getDigitSum(row) + getDigitSum(col) <= th
		&& !visit[row * cols + 1])

		return true;
}

int getDigitSum(int number)
{
	int sum = 0;
	while (number > 0)
	{
		sum += number % 10;
		number /= 10;
	}
	return sum;
}