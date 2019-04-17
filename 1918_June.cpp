#include <iostream>
#include <stack>
#include<vector>
using namespace std;
int getPriority(char op) {
	switch (op)
	{
	case '(': 
		return 1;
	case '+': case '-':
		return 2;
	case '*': case '/':	
		return 3;
	}
}

int priCompare(char op1, char op2) {
	return getPriority(op1) - getPriority(op2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	stack<char> s;
	int i;
	char str[101];
	vector<char>resultStr;
	cin >> str;
	i = 0;
	while (str[i] != '\0') {
		switch (str[i])
		{
		case '(':
			s.push(str[i]);
			break;
		case ')':
			while (true) {
				if (s.top() == '(') {
					s.pop();
					break;
				}
				resultStr.push_back(s.top());
				s.pop();
			}
			break;
		case '+': case '-': case '*': case '/':
			while (!s.empty() && priCompare(s.top(), str[i]) >= 0) {
				resultStr.push_back(s.top());
				s.pop();
			}
			s.push(str[i]);
			break;
		default:
			resultStr.push_back(str[i]);
			break;
		}
		i++;
	}
	while (!s.empty()) {
		resultStr.push_back(s.top());
		s.pop();
	}
	for (auto s : resultStr) {
		cout << s;
	}
	return 0;
}