#include <iostream>
#include <string>
using namespace std;
int a[26] = {0,};
string ans="Yes";
int main() {
	int t;
	cin >> t;
	while (t--) {
		memset(a, 0, sizeof(a));
		ans = "Yes";
		string s;
		cin >> s;
		for (int i = 0; i < s.size(); i++) {
			int temp = s[i] - 97;
			a[temp]++;
		}
		for (int i = 0; i < 26; i++) {
			cout << a[i] << " ";
		}
		cout << "\n";
		for (int i = 0; i < 25; i++) {
			if (a[i] > 1) {
				ans = "No";
				break;
			}
			if (a[i] == 1) {
				if (a[i + 1] == 0) {
					for (int j = i + 1; j < 26; j++) {
						if(a[j]!=0){
							ans = "No";
							break;
						}
							
					}
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}