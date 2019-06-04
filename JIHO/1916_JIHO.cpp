#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define INF 1999999999;
vector<pair<int, int>>arr[1003];
int dist[1003];

int n, m , s, e;

void dijkstra(int start)
{
	dist[start] = 0;
	
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start));

	while (!pq.empty())
	{
		int current = pq.top().second;
		int distance = -pq.top().first;

		if (current == e)
			return;

		pq.pop();
		
		if (dist[current] < distance)
			continue;

		for (int i = 0; i < arr[current].size(); i++)
		{
			int next = arr[current][i].second;
			int next_cost = distance + arr[current][i].first;

			if (next_cost <= dist[next])
			{
				dist[next] = next_cost;
				pq.push(make_pair(-next_cost, next));
			}
		}
	}

}
int main()
{
	
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
		dist[i] = INF;

	for (int i = 0; i < m; i++)
	{
		int x, y, cost;
		cin >> x >> y >> cost;
		arr[x].push_back(make_pair(cost, y)); //간선 초기화
	}
	cin >> s >> e;

	dijkstra(s);

	cout << dist[e];
	return 0;
}