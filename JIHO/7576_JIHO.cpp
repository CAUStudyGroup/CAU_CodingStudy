#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int tomato_map[1001][1001];
int visited[1001][1001];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int max_;

int c=0;

int m, n; // n Çà m¿­

struct tomato
{
	int x;
	int y;
	int cnt;
};

queue <tomato> q;

void bfs()
{
	int x = 0,y = 0;
	while (!q.empty())
	{
		x = q.front().x;
		y = q.front().y;
		c = ++q.front().cnt;

		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m)
			{
				if (tomato_map[nx][ny] == 0 && visited[nx][ny] == 0)
				{
					q.push({ nx,ny,c });
					visited[nx][ny] = c;
					tomato_map[nx][ny] = 1;
				}
			}
		}
		max_ = max(max_, c);
	}
}

int main()
{

	cin >> m >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> tomato_map[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (tomato_map[i][j] != 1)
				break;
			else if (i == n - 1 && j == m - 1)
			{
				cout << 0;
				return 0;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			c = 0;
			if (tomato_map[i][j] == 1 && visited[i][j] == 0)
			{
				q.push({ i, j, c });
			}
		}
	}
	
	bfs();

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (tomato_map[i][j] == 0)
			{
				cout << -1;
				return 0;
			}
		}
	}
	cout << max_-1;
	return 0;
}