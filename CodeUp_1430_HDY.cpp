#include <iostream>
#include <vector>
using namespace std;
int stor[10000001];
int main() {
	int N, M;
	cin >> N;

	while (N--) {
		int hey;
		cin >> hey;
		stor[hey] = 1;
	}

	vector<int> answer;
	cin >> M;
	while (M--) {
		int hey;
		cin >> hey;
		if( stor[hey] == 1)
			answer.push_back(1);
		else
			answer.push_back(0);
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer.at(i) << " ";
	}
	
	cout << "ffff";
}