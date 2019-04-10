#include <iostream>
#include <string>
using namespace std;
int main() {
	int n;
	cin >> n;
	while (n--) {
		string str;
		cin >> str;
		int abc[26] = { 0, };
		for (int i = 0; i < str.size(); i++) {
			abc[str[i] - 'a']++;
		}

		//111100000011111000002 ==> 10102 로 줄이기
		string checkstr = to_string(abc[0]);
		int checkcount = 0;
		bool status = true;
		for (int i = 0; i < 26; i++) {
			if (abc[i] > 1){
				status = false;
				break;
			}
			if (to_string(abc[i]) != checkstr.substr(checkstr.length() - 1)) {
				checkstr = checkstr + to_string(abc[i]);
			}
		}

		for (int i = 0; i < checkstr.length(); i++) {
			if (checkstr[i] == '1')
				checkcount++;
			if (checkcount > 1) {
				status = false;
				break;
			}
		}


		if (status)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}