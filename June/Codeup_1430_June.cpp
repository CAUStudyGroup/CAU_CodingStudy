#include <iostream>
#include <vector>
using namespace std;
int main() {
	int num, qnum;
	vector<int> v_num;
	vector<int> v_qnum;
	int N, M, result; //Number of input, question
	cin >> N;
	while (N--) {
		cin >> num;
		v_num.push_back(num);
	}
	cin >> M;
	while (M--) {
		cin >> qnum;
		v_qnum.push_back(qnum);
	}
	for (auto &n : v_qnum) {
		for (auto &s : v_num) {
			if (s == n) {
				result = 1; 
				break;
			}
			result = 0;
		}
		cout << result << ' ';
	}
	return 0;
}