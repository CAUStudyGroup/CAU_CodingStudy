#include <iostream>
#include <cstring>
using namespace std;
//2675 문자열 반복
int main() {
	int T, R, i, j, k;
	char str[21];
	char R_str[161];
	cin >> T;
	while (T--) {
		i = 0, j = 0, k = 0; memset(R_str, NULL, sizeof(R_str));
		cin >> R;
		cin >> str;
		while(str[i] != '\0'){
			for (j = 0; j < R; j++) {
				R_str[k++] = str[i];
			}
			i++;
		}
		k = 0;
		while (R_str[k] != '\0') {
			cout << R_str[k++];
		}
		cout << '\n';
	}
	return 0;
}