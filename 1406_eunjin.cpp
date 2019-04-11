//1406���� �� ����, ����Ʈ�� Ǯ���� ����� �����߽��ϴ�.

#include<iostream>
#include<string>
#include<list>
using namespace std;
int main() {
	int n;
	string s;
	cin >> s>> n;

	list<char> editor(s.begin(), s.end());
	auto cursor = editor.end();
	while (n--) {
		char cmd;
		cin >> cmd;
		if (cmd == 'L') {
			if (cursor != editor.begin()) {
				cursor--;
			}
		}
		else if (cmd == 'D') {
			if (cursor != editor.end()) {
					cursor++;
			}
		}
		else if (cmd == 'B') {
			if (cursor != editor.begin()) {
					cursor = editor.erase(--cursor);
			}
		}
		else if (cmd == 'P') {
			char x;
			cin >> x;
			editor.insert(cursor, x);
		}
	}
	for (cursor = editor.begin(); cursor != editor.end(); cursor++) {
		cout << *cursor;
	}
}