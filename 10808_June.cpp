#include <iostream>

using namespace std;
int alpha[26];
int main() {
	int i = 0;
	char S[100];
	cin >> S;
	while (S[i] != '\0') {
		alpha[(int)S[i] - 97]++;
		i++;
	}

	for (auto s : alpha) {
		cout << s << ' ';
	}
	return 0;
}