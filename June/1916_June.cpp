#include <iostream>
using namespace std;
int N, M, from, to, fee, A, B, minCost;
const int INF = 1999999999;
int feeTable[1001][1001];
bool visited[1001];
int optimizedFees[1001];

int getSmallIndex() {
	int min = INF;
	int index = 0;
	for (int i = 1; i <= N; i++) {
		if (optimizedFees[i] < min && !visited[i]) {
			min = optimizedFees[i];
			index = i;
		}
	}
	return index;
}

void Dijkstra(int start) {
	for (int i = 1; i <= N; i++)
		optimizedFees[i] = feeTable[start][i];
	visited[start] = true;
	for (int i = 1; i <= N-2; i++) {
		int cur = getSmallIndex();
		visited[cur] = true;
		for (int j = 1; j <= N; j++) {
			if (!visited[j]) {
				if (optimizedFees[cur] + feeTable[cur][j] < optimizedFees[j])
				{
					optimizedFees[j] = optimizedFees[cur] + feeTable[cur][j];
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			feeTable[i][j] = INF;
		}
	}
	for (int i = 1; i <= N; i++) {
		feeTable[i][i] = 0;
	}

	while (M--)
	{
		cin >> from >> to >> fee;
		feeTable[from][to] = fee;
	}
	cin >> A >> B;
	Dijkstra(A);
	minCost = optimizedFees[B];
	cout << minCost;
	return 0;
}