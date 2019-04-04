#include <iostream>
#include <cstdio>
using namespace std;
int number[10000001];
int question[100001];
int ans[10000001] = { 0, };
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> number[i];
		ans[number[i]] = 1;
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> question[i];
	}
	for (int i = 0; i < q; i++) {
		cout << ans[question[i]] << " ";
	}
	cout << "\n";
	return 0;
}