#include <iostream>
#include <utility>
#include <queue>
#include <memory.h>
#include <string>

using namespace std;
char map[101][101];
char visited[101][101];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int n, m;

struct info
{
	int x ;
	int y ;
	int cnt ;
};

int bfs(int x, int y)
{
	int cnt = 1;
	queue<struct info> q;
	q.push({ x,y,1 });
	visited[x][y] = '1';
	memset(visited, '0', sizeof(visited));
	while (!q.empty())
	{
		int a = q.front().x;
		int b = q.front().y;
		int c = q.front().cnt;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = a + dx[i];
			int ny = b + dy[i];
			if (0 <= nx < n && 0 <= ny < m)
			{
				if (visited[nx][ny] == '0'&& map[nx][ny]=='1')
				{
					q.push({ nx,ny,c+1 });
					visited[nx][ny] = '1';
				}
				if (!q.empty())
				{
					if (q.front().x == n - 1 && q.front().y == m - 1)
					{
						cout << q.front().cnt << '\n';
						return 0;
					}
				}
			}
		}
	}
	return 0;
}
int main()
{
	string s;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = 0; j < s.size(); j++)
		{
			map[i][j] = s[j];
		}
	}
	bfs(0, 0);
	return 0;
}