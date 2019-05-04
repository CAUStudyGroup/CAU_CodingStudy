#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int c[26];
string ans[100];

string test(string str) {

	for (int i = 0; i < 26; i++) {
		c[i] = 0;
	}

	for(int i = 0; i < str.size(); i++) {
		c[str[i] - 'a']++;
	}

	int count = 0;
	int start = 0;
	while (c[start] == 0)
	{
		start++;
	}

	int end = start + str.size();
	bool isOne = true;
	for (int i = start; i < end; i++) {
		if (c[i] > 1) {
			isOne = false;
		}
		count += c[i];
	}

	if (count == str.size() && isOne) {
		return "Yes";
	}
	else {
		return "No";
	}
}



int main() {

	string str;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		ans[i] = test(str);
	}

	for (int i = 0; i < n; i++) {
		cout << ans[i] << endl;
	}
	
	return 0;
}