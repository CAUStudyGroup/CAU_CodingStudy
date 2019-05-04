#include <iostream>
#include <vector>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, greater<int>> pq;
vector<int> prob[32001];
int inEdgeNum[32001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, A, B, i;
	cin >> N >> M;

	while (M--) {
		cin >> A >> B;
		prob[A].push_back(B); //A -> B
		inEdgeNum[B]++; //How many nodes are pointing to B
	}

	for (i = 1; i <= N; i++) {
		if (inEdgeNum[i] == 0) //Nodes that are connected to nothing
			pq.push(i);
	}
	while (!pq.empty()) {
		int q = pq.top(); 
		cout << q << ' ';
		pq.pop();
		for (i = prob[q].size(); i--;) {
			int k = prob[q][i];
			if (--inEdgeNum[k] == 0) {
				pq.push(k);
			}
		}
	}
	return 0;
}