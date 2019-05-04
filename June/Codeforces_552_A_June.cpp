#include <iostream>
#include <vector>
#define SWAP(a, b)((a) != (b) ? ((a) ^= (b), (b) ^= (a), (a) ^= (b)) : ((a), (b)))
#define MAX(a, b)((a) > (b) ? (a) : (b))
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T = 4;
	long long input[4];
	vector<long long> results;
	long long max = -1;
	int maxIdx;
	while (T--) {
		cin >> input[T];
	}

	for (int i = 0; i < 4; i++) {
		if (max < input[i]) {
			maxIdx = i;
			max = input[i];
		}
	}

	for (int i = 0; i < 4; i++) {
		if (i == maxIdx)
			continue;
		results.push_back(max - input[i]);
	}

	for (auto s : results) {
		cout << s << ' ';
	}
	return 0;
} //Accepted