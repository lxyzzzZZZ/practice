#include <iostream>
#include <string>
using namespace std;

#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int f0 = 0;
	int f1 = 1;
	int fn;
	while (N > f1)
	{
		fn = f1 + f0;
		f0 = f1;
		f1 = fn;
	}
	int a = f1 - N;
	int b = N - f0;

	int n = a > b ? b : a;
	cout << n << endl;
	return 0;

}
class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		// write code here
		if (A.size() <= 0)
			return false;
		int Lcount = 0;
		int Rcount = 0;
		for (int i = 0; i < A.size(); i++)
		{
			if (A[i] == '(')
				Lcount++;
			else if (A[i] == ')')
				Rcount++;
			else
			{
				if (Lcount <= Rcount)
					return false;
			}
			if (Rcount > Lcount)
				return false;
		}
		if (Rcount == Lcount)
			return true;
		return false;
	}
};
int main()
{
	int n = 0;
	char ch;
	for (; ch = getchar()!= '\n'; n++);
	cout << n << endl;
	system("pause");
	return 0;
}