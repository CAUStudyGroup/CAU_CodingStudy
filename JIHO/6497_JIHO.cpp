#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define N 200001

class Edge
{
public :
	int node[2];
	int cost;

	Edge(int a, int b, int c)
	{
		this->node[0] = a;
		this->node[1] = b;
		this->cost = c;
	}

	bool operator<(Edge &edge)
	{
		return this->cost < edge.cost;
	}
};

int prnt[N];
vector<Edge> v;

int getprnt(int *prnt, int x)
{
	if (prnt[x] == x)return x;
	return prnt[x] = getprnt(prnt, prnt[x]);
}

void unionprnt(int *prnt, int a, int b)
{
	a = getprnt(prnt, a);
	b = getprnt(prnt, b);

	if (a < b) prnt[b] = a;
	else prnt[a] = b;
}

int find(int *prnt, int a, int b)
{
	a = getprnt(prnt, a);
	b = getprnt(prnt, b);

	if (a == b) return 1;
	else return 0;
}

int main()
{

	int sum = 0;
	int a, b, c;
	int max = 0;
	int m, n;

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (1)
	{
		cin >> m >> n;
		
		if (m == 0 && n == 0)
			return 0;

		max = 0;
		sum = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> a >> b >> c;
			v.push_back({ a,b,c });
			max += c;
		}

		sort(v.begin(), v.end());

		for (int i = 0; i < m; i++)
		{
			prnt[i] = i;
		}

		for (int i = 0; i < v.size(); i++)
		{
			if (!find(prnt, v[i].node[0], v[i].node[1]))
			{
				sum += v[i].cost;
				unionprnt(prnt, v[i].node[0], v[i].node[1]);
			}
		}
		cout << max-sum << '\n';
		v.clear();
	}
	return 0;
}