#include <iostream>
#include <cstring>
using namespace std;
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int result[26];
	char alpha[26] = { 0 };
	char str[100];
	int i=0;
	memset(result, -1, sizeof(result));
	cin >> str;
	while(str[i] != '\0') {
		str[i] -= 'a';
		if (alpha[str[i]] == 0) {
			alpha[str[i]]++;
		}
		else {
			i++;
			continue;
		}
		result[str[i]] = i;
		i++;
	}
	for (auto s : result) {
		cout << s << ' ';
	}
	return 0;
}
