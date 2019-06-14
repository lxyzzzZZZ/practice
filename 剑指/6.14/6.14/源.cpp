#include <iostream>
#include <vector>
#include <stack>
using namespace std;

using namespace std;

typedef struct point
{
	int x;
	int y;
}step;

bool should_continue(stack<step> sta, step end)//while条件判断，是否运行到出口位置
{
	bool flag1 = (sta.top().x == end.x);
	bool flag2 = (sta.top().y == end.y);
	if (flag1 && flag2)
		return true;
	return false;
}

int main()
{
	int N, M;
	int maze[10][10];//记录地图

	while (cin >> N >> M)
	{
		for (int i = 0; i != N; i++)
			for (int j = 0; j != M; j++)
				cin >> maze[i][j];

		int flag[10][10] = { 0 };//记录该结点是否已经访问过

		stack<step> sta;
		step begin, end, now;//记录起始结点
		begin.x = 0; begin.y = 0;
		end.x = N - 1; end.y = M - 1;
		now = begin;
		sta.push(begin);
		flag[0][0] = 1;
		while (!should_continue(sta, end))
		{
			if (now.x + 1 <= N - 1 && now.y <= M - 1 && maze[now.x + 1][now.y] == 0 && flag[now.x + 1][now.y] == 0)//是否越界或已经到达过，向下走
			{
				flag[now.x + 1][now.y] = 1;
				now.x += 1;
				sta.push(now);
				continue;
			}
			else if (now.x <= N - 1 && now.y + 1 <= M - 1 && maze[now.x][now.y + 1] == 0 && flag[now.x][now.y + 1] == 0)//向右走
			{
				flag[now.x][now.y + 1] = 1;
				now.y += 1;
				sta.push(now);
				continue;
			}
			else//后退
			{
				sta.pop();
				now.x = sta.top().x;
				now.y = sta.top().y;
			}
		}
		stack<step> stb;
		while (!sta.empty())
		{
			stb.push(sta.top());
			sta.pop();
		}
		while (!stb.empty())
		{
			cout << "(" << stb.top().x << "," << stb.top().y << ")" << endl;
			stb.pop();
		}
	}
	return 0;
}
class Bonus {
public:
	int getMost(vector<vector<int> > board) {
		// write code here
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (i == 0 && j == 0)
					continue;
				else if (i == 0)
					board[i][j] += board[i][j - 1];
				else if (j == 0)
					board[i][j] += board[i - 1][j];
				else
				{
					int A = board[i - 1][j];
					int B = board[i][j - 1];

					if (A > B)
						board[i][j] += A;
					else
						board[i][j] += B;
				}
			}
		}
		return board[5][5];
	}
};