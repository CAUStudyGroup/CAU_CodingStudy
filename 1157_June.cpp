#include <iostream>
#include <string>
using namespace std;
//1157 단어 공부
int main() {
	string str;
	int Alphafreq[26] = { 0 };
	int _maxCount = -1, _maxIdx=0, anotherMax = -1, i;
	char answer;
	cin >> str;
	//Convert all LowerCase to UpperCase
	for (auto &s : str) {
		if (s > 96) s -= 32; //lower - 32 = upper
		Alphafreq[s - 65]++;
	}

	for (i = 0; i < sizeof(Alphafreq) / sizeof(int); i++) {
		if (_maxCount == Alphafreq[i]) {
			anotherMax = Alphafreq[i];
		}
		else if (_maxCount < Alphafreq[i]) {
			_maxCount = Alphafreq[i];
			_maxIdx = i;
		}
	}
	_maxIdx += 65;
	if (_maxCount == anotherMax) answer = '?';
	else answer = (char)_maxIdx;
	cout << answer;
	return 0;
}