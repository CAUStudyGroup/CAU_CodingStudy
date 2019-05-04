#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> arr[1000001];
bool compare(const pair<int, int>& a, const pair<int, int>&b) {
	//첫번째 수가 같다면
	if (a.first == b.first)
		return a.second < b.second; //두번째 수로 오름차순
	return a.first < b.first; //오름차순
}
int main() {
	
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr, arr + N, compare);

	for(int i=0;i<N;i++){
		cout << arr[i].first << " " << arr[i].second << "\n";
	}
}
