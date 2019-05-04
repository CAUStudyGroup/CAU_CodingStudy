#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> pi;
priority_queue<pi, vector<pi>, greater<pi>> pq;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, X, Y;
	cin >> N;
	while (N--) {
		cin >> X >> Y;
		pq.push(make_pair(X, Y));
	}
	while (!pq.empty()) {
		cout << pq.top().first << ' ' << pq.top().second << '\n';
		pq.pop();
	}
	return 0;
}
