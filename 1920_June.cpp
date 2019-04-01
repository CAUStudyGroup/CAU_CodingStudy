#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int N, num, M;
	vector<int> arr;
	vector<int> answer;
	cin >> N;
	while (N--) {
		cin >> num;
		arr.push_back(num);
	}
	sort(arr.begin(), arr.end());

	cin >> M;
	while (M--) {
		cin >> num;
		if (binary_search(arr.begin(), arr.end(), num))
			answer.push_back(1);
		else 
			answer.push_back(0);
	}
	for (auto s : answer) cout << s << '\n';

	return 0;
}