#include <iostream>
#include <string>
#include <stack>
using namespace std;
stack<char> L, R;
int main() {
	
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		L.push(str[i]);
	}

	int N;
	cin >> N;

	while (N--) {
		string c;
		cin >> c;
		if (c == "L") {
			//L�� ��������� R�� 1�� �ű�
			if (!L.empty()) {
				R.push(L.top());
				L.pop();
			}
		}
		else if (c == "D") {
			//R�� ��������� L�� 1�� �ű�
			if (!R.empty()) {
				L.push(R.top());
				R.pop();
			}
		}
		else if (c == "B") {
			//L�� ��������� 1�� pop
			if (!L.empty()) {
				L.pop();
			}
		}
		else if (c == "P") {
			char additional;
			cin >> additional;
			//L�� �߰�
			L.push(additional);
		}
	}
	while(!L.empty()){
		R.push(L.top());
		L.pop();
	}
	while(!R.empty()){
		cout << R.top();
		R.pop();
	}
	cout << "hhe";
}