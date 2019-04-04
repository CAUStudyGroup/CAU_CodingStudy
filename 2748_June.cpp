#include <iostream>
#include <vector>
using namespace std;
//2748 피보나치 수 2
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, i;
	cin >> N;
	vector<unsigned long long> fibo;
	fibo.push_back(0); fibo.push_back(1);
	for (i = 2; i <= N; i++) {
		fibo.push_back(fibo[i - 1] + fibo[i - 2]);
	}
	cout << fibo[N];
	return 0;
}