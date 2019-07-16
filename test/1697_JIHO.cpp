#include <iostream>
#include <queue>

using namespace std;

int n, k;
int newposition[100001];
void bfs(int n,int cnt)
{

	queue<pair<int,int>> q;
	q.push(make_pair(n,cnt));
	
	while (q.front().first!=k)
	{
		int nx = 0;
		n = q.front().first;
		cnt = q.front().second;
		q.pop();
		for (int i = 0; i < 3; i++)
		{
			if (i == 0)
				nx = n + 1;
			else if (i == 1)
				nx = n - 1;
			else
				nx = 2 * n;
			if (nx <= 100000)
			{
				if (!newposition[nx])
				{
					newposition[nx] = 1;
					q.push(make_pair(nx, cnt + 1));
				}
				if (nx == k)
				{
					cout << cnt + 1;
					return;
				}
			}
		}
	}
}
int main()
{

	cin >> n >> k;
	if (n == k)
		cout << "0";
	else
		bfs(n,0);

	return 0;
}