#include <iostream>
#include <queue>
#include <vector>
int piMemo[32001];
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	int N, M, A, B, i, j;
	cin >> N >> M;
	while (M--) {
		cin >> A >> B;
		piMemo[B] = A;
	}
	for (i = 1; i <= N; i++) {
		if (piMemo[i] == 0)
			pq.push(make_pair(i, i)); //pair.first is priority, pair.second is number of Problem
		else if(piMemo[i] != -1){
			j = i;
			while (true) {
				if (piMemo[j] == 0) {
					piMemo[j] = -1;
				}
				pq.push(make_pair(i++, piMemo[j]));
				j = piMemo[j];
			}
		}
	}

	while (!pq.empty()) {
			cout << pq.top().second << ' ';
			pq.pop(); 
	}
	return 0;
}