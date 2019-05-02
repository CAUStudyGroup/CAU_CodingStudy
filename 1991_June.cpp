#include <iostream>

using namespace std;
char BiTree[27];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	for (int i = 1; i <= 3*N; i+=3) {
		cin >> BiTree[i];
		cin >> BiTree[i * 2];
		cin >> BiTree[(i * 2) + 1];
	}

	for (auto s : BiTree) {
		cout << s << ' ';
	}
	return 0;
}