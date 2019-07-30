#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

int map[101][101];
int visited[101][101];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
vector<int> v;
int n, m;

int cnt;

void bfs(int x, int y, int cnt)
{
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visited[x][y] = cnt;
	int a = 0, b = 0;
	int S = 0;
	while (!q.empty())
	{
		a = q.front().first;
		b = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++)
		{
			int nx = a + dx[k];
			int ny = b + dy[k];
			if (0 <= nx && nx < m && 0 <= ny && ny < n)
			{
				if (map[nx][ny] == 0 && visited[nx][ny] == 0)
				{
					q.push(make_pair(nx, ny));
					S++;
					visited[nx][ny] = cnt;
				}
			}
		}
	} 
	v.push_back(S+1); // ³ÐÀÌ
}
int main()
{
	int k;
	cin >> m >> n >> k;
	for (int i = 0; i < k; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = y1; j < y2; j++)
		{
			for (int l = x1; l < x2; l++)
			{
				map[j][l] = 1;
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == 0 && visited[i][j] == 0)
			{
				bfs(i, j, ++cnt);
			}
		}
	}
	sort(v.begin(), v.end());
	cout << cnt << '\n';
	for (int i = 0; i < v.size(); i++)
	{
		cout << v.at(i) << " ";
	}
	return 0;
}