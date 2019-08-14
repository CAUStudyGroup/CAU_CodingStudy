#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <memory.h>
using namespace std;

char map[101][101];
int visited[101][101];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int n;
int cnt;

void bfs(int x, int y, int cnt)
{
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visited[x][y] = cnt;
	int a = 0, b = 0;
	char color = map[x][y]; // 현재 탐색하려는 색

	while (!q.empty())
	{
		a = q.front().first;
		b = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++)
		{
			int nx = a + dx[k];
			int ny = b + dy[k];
			if (0 <= nx && nx < n && 0 <= ny && ny < n)
			{
				if (map[nx][ny] == color && visited[nx][ny] == 0)
				{
					q.push(make_pair(nx, ny));
					visited[nx][ny] = cnt;
				}
			}
		}
	} 
}
int main()
{
	cin >> n;
	string s;
	cnt = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = 0; j < n; j++)
		{
			map[i][j] = s[j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visited[i][j] == 0)
			{
				bfs(i, j, ++cnt);
			}
		}
	}
	cout << cnt << " ";
	memset(visited, 0, sizeof(visited));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == 'G')
				map[i][j] = 'R';
		}
	}
	cnt = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visited[i][j] == 0)
			{
				bfs(i, j, ++cnt);
			}
		}
	}

	cout << cnt<<'\n';

	return 0;
}