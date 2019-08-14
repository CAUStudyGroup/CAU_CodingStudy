#include <iostream>
//#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	std:: vector <int> arr;
	int input;
	int tmp;
	cin >> input;

	for (int i = 0; i < input; i++) {
		cin >> tmp;
		arr.push_back(tmp);
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < input; i++) {
		cout << arr[i] << "\n";
	}
	return 0;



}