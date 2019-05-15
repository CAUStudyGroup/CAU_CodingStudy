#include <iostream>
using namespace std;
int arr[1000002];
void shellSort() {

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, num, i;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> num;
		arr[i] = num;
	}

	shellSort();

	for (i = 0; i < N; i++) {
		cout << arr[i] << '\n';
	}
	return 0;
}
