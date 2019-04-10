#include <iostream>
#include <cstring>
using namespace std;
int alpha[26];
int main() {
	int n; int i; char str[101]; char result[4];
	char maxAlpha, minAlpha;
	cin >> n;
	while (n--) {
		memset(alpha, 0, sizeof(alpha));
		memset(str, 0, sizeof(str));
		cin >> str;
		i = 0; maxAlpha = -1; minAlpha = 127;
		while (str[i] != '\0') { //Memoization
			 maxAlpha = maxAlpha < str[i] ? str[i] : maxAlpha;
			 minAlpha = minAlpha > str[i] ? str[i] : minAlpha;
			 alpha[(int)str[i] - 97]++;
			 i++;
		}
		strcpy(result, "yes");
		for (i = (int)minAlpha - 97; i <= (int)maxAlpha - 97; i++) {
			if (1 != (int)alpha[i]) {
				strcpy(result, "no");
			}
		}
		cout << result << '\n';
	}
	return 0;
}