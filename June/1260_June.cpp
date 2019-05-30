#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
vector<int> adj[1001];
vector<int> visitNode;
bool visited[1001];
int V, E, S, a, b;
void dfs(int x) {
	visited[x] = true;
	visitNode.push_back(x);
	for (int y : adj[x]) {
		if (!visited[y]) {
			dfs(y);
		}
	}
}

void bfs(int startx) {
	queue<int> q;
	q.push(startx);
	visited[startx] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		visitNode.push_back(x);
		for (int y : adj[x]) {
			if (!visited[y]) {
				q.push(y);
				visited[y] = true;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i;
	cin >> V >> E >> S;
	for (i = 1; i <= V; i++) {
		adj[i].clear();
	}
	for (i = 0; i < E; i++) {
		cin >> a >> b;
		//¾ç¹æÇâ
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (i = 1; i <= V; i++) {
		sort(adj[i].begin(), adj[i].end());
	}
	memset(visited, 0, sizeof(visited));
	visitNode.clear();
	dfs(S);
	for (int dn : visitNode) {
		cout << dn << ' ';
	}
	cout << '\n';

	memset(visited, 0, sizeof(visited));
	visitNode.clear();
	bfs(S);
	for (int bn : visitNode) {
		cout << bn << ' ';
	}
	return 0;
}