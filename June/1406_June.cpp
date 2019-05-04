#include <iostream>
#include <string>
#include <list>
//BOJ 1406 Editor
//500,000 * 600,000 ��ǲ������ O(1)�� �ذ��ؾ��ϴ� ����(C/C++ ����)
using namespace std;
int main() {
	ios::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string str;
	list<char> lstr;
	list<char>::iterator curIt;
	int N;
	char command, letter;
	cin >> str;
	for (char c : str)
		lstr.push_back(c);
	curIt = lstr.end(); //'\0'�� ��ġ�� ������ �ε���
	cin >> N;
	while (N--) {
		cin >> command;
		switch (command)
		{
		case 'L':
			curIt = curIt != lstr.begin() ? --curIt : curIt; //0�� �ε������� �� �� ����
			break;
		case 'D':
			curIt = curIt != lstr.end() ? ++curIt : curIt; //�������ε���('\0') ���� �� �� ����
			break;
		case 'B':
			if (curIt != lstr.begin() && curIt != lstr.end()) {
				curIt = lstr.erase(--curIt);
			}
			else if(curIt == lstr.begin()){
				break;
			}
			else if(curIt == lstr.end()){
				curIt = lstr.erase(--curIt);
			}
			break;
		case 'P'://P $ $��� ���ڸ� Ŀ�� ���ʿ� �߰���
			cin >> letter;
			lstr.insert(curIt, letter);
			break;
		default:
			break;
		}
	}
	for (char c : lstr)
		cout << c;
	return 0;
}