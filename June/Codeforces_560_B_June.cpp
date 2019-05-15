#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	priority_queue<int, vector<int>, greater<int>> pq;
	int n, a, k=1;
	cin >> n;
	while (n--) {
		cin >> a;
		pq.push(a);
	}
	while (!pq.empty())
	{
		if (k <= pq.top()) {
			k++;
		}
		pq.pop();
	}
	cout << k-1;
	return 0;
}