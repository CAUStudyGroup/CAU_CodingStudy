#include <iostream>
#include <cstdio>
using namespace std;
int number[10000001];
int question[100001];
int ans[10000001];
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> number[i];
		cout
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> question[i];
	}
	for (int i = 0; i < q; i++) {
		for (int j = 0; j < n; j++) {
			if (question[i] == number[j]) {
				ans[i] = 1;
			}
		}
		if (ans[i] != 1) {
			ans[i] = 0;
		}
	}
	for (int i = 0; i < q; i++) {
		cout << ans[i]<<" ";
	}
	cout << "\n";
	return 0;
}