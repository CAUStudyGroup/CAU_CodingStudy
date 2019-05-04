#include <iostream>
#include <string>
#include <list>
//BOJ 1406 Editor
//500,000 * 600,000 인풋때문에 O(1)로 해결해야하는 문제(C/C++ 기준)
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
	curIt = lstr.end(); //'\0'이 위치한 마지막 인덱스
	cin >> N;
	while (N--) {
		cin >> command;
		switch (command)
		{
		case 'L':
			curIt = curIt != lstr.begin() ? --curIt : curIt; //0번 인덱스까지 갈 수 있음
			break;
		case 'D':
			curIt = curIt != lstr.end() ? ++curIt : curIt; //마지막인덱스('\0') 까지 갈 수 있음
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
		case 'P'://P $ $라는 문자를 커서 왼쪽에 추가함
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