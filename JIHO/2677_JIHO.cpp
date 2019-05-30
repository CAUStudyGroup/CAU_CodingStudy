#include <cstdio>
#include<iostream>
#include <algorithm>
//#include <queue>
#include <vector>
using namespace std;;
//dfs

int map[30][30];
int check[30][30];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
vector <int> v;
int n,a;

void dfs(int x,int y,int cnt)
{
	a++;
	check[x][y] = cnt;
	int nx, ny;
	for (int i = 0; i < 4; i++)
	{
		nx = x + dx[i];
		ny = y + dy[i];
		if (nx >= 0 && nx < n&&ny >= 0 && ny < n)
		{
			if (map[nx][ny] == 1 && check[nx][ny] == 0)
			{
				dfs(nx, ny, cnt);
			}
		}
	}
}

void bfs(int x, int y, int cnt)
{
	a++;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	check[x][y] = cnt;
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < n)
			{
				if (map[nx][ny] == 1 && check[nx][ny] == 0)
				{
					q.push(make_pair(nx, ny));
					check[nx][ny] = cnt;
				}
			}
		}
	}
}

int main()
{

	int cnt = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			scanf("%1d", &map[i][j]);
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == 1 && check[i][j] == 0)
			{
				a = 0;
				dfs(i, j, ++cnt);
				v.push_back(a);
			}
		}
	}

	printf("%d\n", cnt);

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
	{
		printf("%d\n", v.at(i));
	}
	
	return 0;
}