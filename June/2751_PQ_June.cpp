#include <iostream>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, greater<int>> pq;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, num, i;
	cin >> N;
	while (N--) {
		cin >> num;
		pq.push(num);
	}
	while (!pq.empty()) {
		cout << pq.top() << '\n';
		pq.pop();
	}
	return 0;
}