#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, x, y, i, cnt=0;
	string input;
	cin >> n >> x >> y;
	cin >> input;

	for (i = n - x; i < n; i++) {
		if (i == n - y - 1) {
			if ('0' == input[i]) {
				input[i] = '1';
				cnt++;
			}
		}
		else if (i != n - y - 1) {
			if ('1' == input[i]) {
				input[i] = '0';
				cnt++;
			}
		}
	}

	cout << cnt;
	return 0;
}