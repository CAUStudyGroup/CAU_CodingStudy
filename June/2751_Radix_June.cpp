#include <iostream>
#include <vector>
using namespace std;
void radixSort(vector<int>& arr, int d) {

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, num, i, d=0, _max = 0;
	cin >> N;
	vector<int> arr(N, 0);
	for (i = 0; i < N; i++) {
		cin >> num;
		_max = _max < num ? num : _max;
		arr[i] = num;
	}
	while (_max != 0) {
		_max /= 10;
		d++;
	}
	radixSort(arr, d);

	for (i = 0; i < N; i++) {
		cout << arr[i] << '\n';
	}
	return 0;
}
