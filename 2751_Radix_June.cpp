#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int arr[1000002];
void radixSort(int d) {

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, num, i, d=0, _max = 0;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> num;
		arr[i] = num;
	}
	_max = *max_element(arr, arr + N);
	string strMax;
	strMax = to_string(_max);
	d = strMax.length();
	/*
	radixSort(d);

	for (i = 0; i < N; i++) {
		cout << arr[i] << '\n';
	}*/
	return 0;
}
