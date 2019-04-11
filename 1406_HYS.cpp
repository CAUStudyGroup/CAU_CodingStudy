#include <iostream>
#include <string>
#include <list>
using namespace std;

void print(list<char> &temp) {
	list<char>::iterator itr = temp.begin();
	list<char>::iterator end = temp.end();

	for (itr; itr != end; itr++) {
		cout << *itr;
	}
}

void task(list<char> &temp, char &command, char &input, list<char>::iterator &itr) {
	

	switch (command)
	{
	case 'L':
		if (itr != temp.begin()) {
			itr--;
		}
		break;
	case 'D':
		if (itr != temp.end()) {
			itr++;
		}
		break;
	case 'B':
		itr = temp.erase(itr);
		break;
	case 'P':
		temp.insert(itr, input);
		break;
	default:
		break;
	}
}

int main() {

	//리스트에 입력값 저장
	string str;
	list<char> temp;

	getline(cin, str);

	for (int i = 0; i < str.size(); i++) {
		temp.push_back(str[i]);
	}

	int n;
	cin >> n;
	
	char command;
	char input;
	list<char>::iterator itr = temp.end();
	for (int i = 0; i < n; i++) {
		cin >> command;
		if (command == 'P') {
			cin >> input;
		}
		task(temp, command, input, itr);
	}

	//출력
	print(temp);

	return 0;
}