#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> P;
const int INF = 1000000000; // 절대 나올 수 없는 경로값
int N, M, dist[500];
int main() {
	cin >> N >> M;
	vector<P> adj[500];
	for (int i = 0; i<M; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		adj[A - 1].push_back(P(B - 1, C)); //A->B 의 시간은 C
	}
	bool minusCycle = false;
	fill(dist, dist + N, INF);

	dist[0] = 0;
	for (int i = 0; i<N; i++) { // (N-1) + 1번의 루프. 마지막은 음의 싸이클 존재 여부 확인용
		for (int j = 0; j<N; j++) {// j -> next 의 시간은 d
			for (auto &p : adj[j]) { 
				int next = p.first, d = p.second;
				if (dist[j] != INF && dist[next] > dist[j] + d) {
					dist[next] = dist[j] + d;
					// N번째 루프에 값이 갱신되면 음의 싸이클이 존재한다.
					if (i == N - 1) 
						minusCycle = true;
				}
			}
		}
	}
	if (minusCycle) puts("-1");
	else {
		for (int i = 1; i<N; i++)
			printf("%d\n", dist[i] != INF ? dist[i] : -1);
	}
}