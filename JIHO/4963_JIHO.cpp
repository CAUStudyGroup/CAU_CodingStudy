#include <iostream>
#include <memory.h>
using namespace std;

//dfs
int map[51][51];
int visited[51][51];
int dx[8] = { 0,0,1,-1,1,1,-1,-1 };
int dy[8] = { 1,-1,0,0, -1,1,1,-1 };

int cnt;

int w, h; // За h ї­ w

void dfs(int x, int y,int cnt)
{
	visited[x][y] = cnt;

	for (int i = 0; i < 8; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < h&&ny >= 0 && ny < w)
		{
			if (map[nx][ny] == 1 && visited[nx][ny] == 0)
			{
				dfs(nx, ny, cnt);
			}
		}
	}
}
int main()
{
	while (1)
	{
		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));
		cnt = 0;
		cin >> w >> h;

		if (w == 0 && h == 0)
			return 0;

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (map[i][j] == 1 && visited[i][j] == 0)
				{
					dfs(i, j, ++cnt);
				}
			}
		}
		cout << cnt << '\n';
	}

	return 0;
}