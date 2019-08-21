#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int prnt[10001];

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
	int v, e;
	cin >> v >> e;

	vector<Edge> t;

	int a, b, c;
	for (int i = 0; i < e; i++)
	{
		cin >> a >> b >> c;
		t.push_back({ a,b,c });
	}

	sort(t.begin(), t.end());

	for (int i = 0; i < v; i++)
	{
		prnt[i] = i;
	}
	int sum = 0; 
	for (int i = 0; i < t.size(); i++)
	{
		if (!find(prnt, t[i].node[0] - 1, t[i].node[1] - 1))
		{
			sum += t[i].cost;
			unionprnt(prnt, t[i].node[0] - 1, t[i].node[1] - 1);
		}
	}

	cout << sum << '\n';
	return 0;
}