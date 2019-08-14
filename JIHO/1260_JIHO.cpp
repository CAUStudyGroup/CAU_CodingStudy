#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <memory.h>
#include <vector>
using namespace std;

int n, m, v;
vector<int> graph[1002];

void bfs(int x)
{

	int visited[1002];
	memset(visited, 0, sizeof(visited));
	queue<int> q;
	q.push(x);
	while (!q.empty())
	{
		int a = q.front();
		if(visited[a]==0)
			cout << q.front()<<" ";
		visited[a]++;
		q.pop();
		if (visited[a] == 1)
		{
			for (int i = 0; i < graph[a].size(); i++)
			{
				if (visited[graph[a][i]] == 0)
					q.push(graph[a][i]);
			}
		}
	}
	
}

void dfs(int x)
{

	int visited[1002];
	memset(visited, 0, sizeof(visited));
	stack<int> s;
	s.push(x);
	while (!s.empty())
	{
		int a = s.top();
		if (visited[a] == 0)
			cout << s.top()<<" ";
		visited[a]++;
		s.pop();
		if (visited[a] == 1)
		{
			for (int i = graph[a].size()-1; i >= 0; i--)
			{
				if (visited[graph[a][i]] == 0)
					s.push(graph[a][i]);
			}
		}
	}
}
int main()
{
	cin >> n >> m >> v;

	for (int i = 0; i < m; i++)
	{
		int x, y;

		cin >> x >> y;

		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < graph[i].size(); j++)
		{
			sort(graph[i].begin(), graph[i].end()); //오름차순 정렬
		}
	}
	dfs(v);
	cout << '\n';
	bfs(v);
	return 0;
}