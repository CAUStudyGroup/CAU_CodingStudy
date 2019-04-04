#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
	int total, K;
	int student[6][2] = { 0, }; //1-6ÇÐ³â, ³²1³à0

	cin >> total >> K;
	for (int i = 0; i < total; i++) {
		int sex, grade;
		cin >> sex >> grade;
		student[grade - 1][sex]++;
	}

	int cnt = 0;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 2; j++) {
			if (student[i][j] % K == 0)
				cnt = cnt + (int)(student[i][j] / K);
			else
				cnt = cnt + (int)(student[i][j] / K) + 1;
		}
	}

	cout << cnt;
}