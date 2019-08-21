#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int board[101][101];
int k, n,l,x;
int apx, apy;
char c;
int tailx = 0, taily = 0;
int t = 0;

char tmp;
priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> time;
queue<pair<int, int>> snake;

int dfs(int x, int y, int t, int d)
{
	board[x][y] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << board[i][j];
		cout << "\n";
	}
	cout << '\n';
	//방향 바꿀 시간이 됐다면
	if (!time.empty())
	{
		if (t == time.top().first)
		{
			// 바꿔야 하는 방향 설정
			tmp = time.top().second;
			if (tmp == 'L')
			{
				if (d == 0)
					d = 3;
				else if (d == 1)
					d = 0;
				else if (d == 2)
					d = 1;
				else if (d == 3)
					d = 2;
			}
			else
			{
				if (d == 0)
					d = 1;
				else if (d == 1)
					d = 2;
				else if (d == 2)
					d = 3;
				else if (d == 3)
					d = 0;
			}
			time.pop();
		}
	}

	if (d == 0)
	{
		if (y + 1 < n)
		{
			//그냥 이동시 
			if (board[x][y + 1] == 0)
			{
				snake.push({ x,y + 1 });
				tailx = snake.front().first;
				taily = snake.front().second;
				board[tailx][taily] = 0;
				snake.pop();
				//머리 이동
				dfs(x, y + 1, ++t, d);
			}
			//사과를 먹으면 그냥 머리만 이동
			else if (board[x][y + 1] == 2)
			{
				snake.push({ x,y + 1 });
				dfs(x, y + 1, ++t, d);
			}
			else
			{
				cout << t+1 << '\n';
				return 0;
			}
		}
		else
		{
			cout << t + 1 << '\n';
			return 0;
		}
	}
	else if (d == 1)
	{
		if (x + 1 < n)
		{
			if (board[x + 1][y] == 0)
			{
				snake.push({ x + 1,y });
				tailx = snake.front().first;
				taily = snake.front().second;
				board[tailx][taily] = 0;
				snake.pop();
				dfs(x + 1, y, ++t, d);
			}
			else if (board[x + 1][y] == 2)
			{
				snake.push({ x + 1,y });
				dfs(x + 1, y, ++t, d);
			}
			else
			{
				cout << t+1 << '\n';
				return 0;
			}
		}
		else
		{
			cout << t + 1 << '\n';
			return 0;
		}
	}
	else if (d == 2)
	{
		if (y - 1 >= 0)
		{
			if (board[x][y - 1] == 0)
			{
				snake.push({ x,y - 1 });
				tailx = snake.front().first;
				taily = snake.front().second;
				board[tailx][taily] = 0;
				snake.pop();
				dfs(x, y - 1, ++t, d);
			}
			else if (board[x][y - 1] == 2)
			{
				snake.push({ x,y - 1 });
				dfs(x, y - 1, ++t, d);
			}
			else
			{
				cout << t+1 << '\n';
				return 0;
			}
		}
		else
		{
			cout << t + 1 << '\n';
			return 0;
		}
	}
	else if (d == 3)
	{
		if (x - 1 >= 0)
		{
			if (board[x - 1][y] == 0)
			{
				snake.push({ x - 1,y });
				tailx = snake.front().first;
				taily = snake.front().second;
				board[tailx][taily] = 0;
				snake.pop();
				dfs(x - 1, y, ++t, d);
			}
			else if (board[x - 1][y] == 2)
			{
				board[x-1][y] = 1;
				dfs(x - 1, y, ++t, d);
			}
			else
			{
				cout << t+1 << '\n';
				return 0;
			}
		}
		else
		{
			cout << t + 1 << '\n';
			return 0;
		}
	}

}

int main()
{
	cin >> n >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> apx >> apy;
		board[apx - 1][apy - 1] = 2;
	}
	cin >> l;
	for (int i = 0; i < l; i++)
	{
		cin >> x >> c;
		time.push(make_pair(x, c)); // 시간,방향 정보 입력 
	}
	//board[0][0] = 1;
	snake.push({ 0,0 });
	dfs(0,0,0,0);

	return 0;
}