#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main() {
	string str;
	cin >> str;
	int i = 0;
	stack<char> oper;
	while (i < str.size()) {
		if (str[i] == '(') {
			oper.push(str[i]);
		}
		else if (str[i] == ')') {
			while(!oper.empty()  && oper.top() != '('){
				cout << oper.top();
				oper.pop();
			}
			if (oper.top() == '(')
				oper.pop();
		}
		else if (str[i] == '*' || str[i] == '/' ) {
			while (!oper.empty() && (oper.top() == '*' || oper.top() == '/')) {
				cout << oper.top();
				oper.pop();
			}
			oper.push(str[i]);
		}
		else if ( str[i] == '+' || str[i] == '-') {
			
				while (!oper.empty() && (oper.top() == '*' || oper.top() == '/' || oper.top() == '+' || oper.top() == '-') ){
					cout << oper.top();
					oper.pop();
				}
			
			oper.push(str[i]);
		}
		else{
			cout << str[i];
		}
		i++;
	}
	
	while (!oper.empty()) {
		cout << oper.top();
		oper.pop();
	}
}