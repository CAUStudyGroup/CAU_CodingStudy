#include <iostream>
#include <queue>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	priority_queue<int, vector<int>,greater<int>> minPQ;
	int N,x;
	cin >> N;
	while (N--) {
		cin >> x;
		if (x > 0) {
			minPQ.push(x);
		}
		else if(x == 0){
			if (minPQ.empty()) {
				cout << 0 << '\n';
			}
			else {
				cout << minPQ.top() << '\n';
				minPQ.pop();
			}
		}
	}
	return 0;
}